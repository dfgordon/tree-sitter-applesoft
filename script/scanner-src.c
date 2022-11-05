// This scanner excludes keywords from identifiers.
// This is supposed to emulate the behavior of the Apple II ROM (A2ROM).
// In particular, the A2ROM tokenizes these keywords first without regard to context.
// Therefore any variable name must terminate before any keyword begins.

#include <memory.h>
#include <tree_sitter/parser.h>

// scanner-src.c is for human editing.
// scanner.c is generated by token_processor.py

enum TokenType {
  NAME, // label is carried over from legacy docs, this is an identifier
  NONE
};

typedef struct
{
  char a2token[7]; // string with the excluded token
  int matches; // how many characters have been matched; don't confuse with token matches
  int len; // length of string
  int start; // offset to first matching character
} exclusion;
void create_exclusion(exclusion *x,const char *tok,int l)
{
  x->start = 0;
  x->matches = 0;
  x->len = l;
  for (int i = 0; i < x->len; i++)
    x->a2token[i] = tok[i];
}
void reset_exclusion(exclusion *x)
{
  x->start = 0;
  x->matches = 0;
}
void next_exclusion(exclusion *x,int32_t c,int pos)
{
  if (c==' ' || x->matches==x->len)
    return;
  if (x->a2token[x->matches]==c)
    x->matches++;
  else
    x->matches = (x->a2token[0]==c);
  if (x->matches==1)
    x->start = pos;
}
void finish_exclusion(exclusion *x,int *min_start)
{
  if (x->start<*min_start && x->matches==x->len)
    *min_start = x->start;
}

typedef struct
{
  // Special handling for the AT keyword is needed to emulate A2ROM behavior.
  // AT and TO are resolved as follows: /A *TO/ = (A)(TO) ; /A *T +O/ = (AT)(O)
  // To match this behavior, we only need to worry about matching AT, since if AT
  // matches, then the subsequent false match of TO is harmless to this scanner.
  int matches; // how many characters have been matched; don't confuse with token matches
  int start; // offset to first matching character
  int end; // offset to last matching character
} at_exclusion;
void create_at_exclusion(at_exclusion *x)
{
  x->start = 0;
  x->end = 0;
  x->matches = 0;
}
void reset_at_exclusion(at_exclusion *x)
{
  x->start = 0;
  x->end = 0;
  x->matches = 0;
}
void next_at_exclusion(at_exclusion *x,int32_t c,int pos)
{
  if (x->matches==2 && c=='O' && pos==x->end+1)
    reset_at_exclusion(x);
  if (c==' ' || x->matches==2)
    return;
  if (x->matches==1 && c=='T')
  {
    x->matches = 2;
    x->end = pos;
  }
  else
    x->matches = (c=='A');
  if (x->matches==1)
    x->start = pos;
}
void finish_at_exclusion(at_exclusion *x,int *min_start)
{
  if (x->start<*min_start && x->matches==2)
    *min_start = x->start;
}

typedef struct
{
  // Code to build exclusions is auto-generated by token-processor.py
  exclusion exclusions[128];
  unsigned num_exclusions;
  at_exclusion at_excl;
  int id_end;
  bool allow_lower_case;
} Scanner;

void create_scanner(Scanner *s)
{
  s->id_end = -1;
  s->allow_lower_case = true;
  create_at_exclusion(&s->at_excl);
  // Build exclusions - DO NOT EDIT line
}

bool is_alpha(int32_t c)
{
  return c >= 65 && c <= 90;
}

bool is_alphanumeric(int32_t c)
{
  return (c >= 65 && c <= 90) || (c >= 48 && c <= 57);
}

int32_t adj_case(Scanner *s,int32_t c)
{
  return (c >= 97 && c <= 122 && s->allow_lower_case) ? c - 32 : c;
}

bool first_pass(Scanner *s,TSLexer *lexer, const bool *valid_symbols)
{
  // First pass detects all A2ROM keyword tokens, and saves the position of the
  // identifier end, or the first keyword start, whichever is smaller.

  int32_t c;  // shorthand for the current lookahead character
  int id_pos=0; // not counting spaces
  int tot_pos=0; // counting spaces
  bool identifier_matching = false;

  // skip leading spaces
  while (lexer->lookahead==' ')
    lexer->advance(lexer,true);

  lexer->mark_end(lexer); // force another pass
  do
  {
    c = adj_case(s,lexer->lookahead);
    // loop to accumulate keyword matches
    for (unsigned i = 0; i < s->num_exclusions; i++)
      next_exclusion(&s->exclusions[i],c,tot_pos);
    next_at_exclusion(&s->at_excl,c,tot_pos);
    identifier_matching = ((id_pos==0 && is_alpha(c)) || (id_pos>0 && is_alphanumeric(c)) || c==' ');
    if (identifier_matching)
    {
      lexer->advance(lexer,false);
      tot_pos++;
      id_pos += (c!=' ');
    }
  } while(identifier_matching);
  s->id_end = tot_pos;
  // loop to rewind position to left-most keyword match
  for (unsigned i = 0; i < s->num_exclusions; i++)
    finish_exclusion(&s->exclusions[i],&s->id_end);
  finish_at_exclusion(&s->at_excl,&s->id_end);
  if (s->id_end>0 && id_pos>0)
  {
    lexer->result_symbol = NAME;
    return true;
  }
  else
  {
    // n.b. serialize will not be called
    lexer->result_symbol = NONE;
    return false;
  }
}

bool second_pass(Scanner *s,TSLexer *lexer, const bool *valid_symbols)
{
  // Lexing is already done. We just have to set the marker.
  for (int i=0;i<s->id_end;i++)
    lexer->advance(lexer,false);
  s->id_end = -1;
  lexer->result_symbol = NAME;
  return true;
}

void *tree_sitter_applesoft_external_scanner_create() {
  void *ans = malloc(sizeof(Scanner));
  create_scanner(ans);
  return ans;
}

bool tree_sitter_applesoft_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
  Scanner *scanner = (Scanner*)payload;
  if (!valid_symbols[NAME])
  {
    lexer->result_symbol = NONE;
    return false;
  }
  if (scanner->id_end<0)
    return first_pass(scanner,lexer,valid_symbols);
  else
    return second_pass(scanner,lexer,valid_symbols);
}

unsigned tree_sitter_applesoft_external_scanner_serialize(void *payload, char *buffer) {
  Scanner *s = (Scanner*)payload;
  char *src = (char*)&s->id_end;
  for (unsigned i=0;i<sizeof(int);i++)
    buffer[i] = src[i];
  return sizeof(int);
}

void tree_sitter_applesoft_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
  Scanner *s = (Scanner*)payload;
  for (unsigned i = 0; i < s->num_exclusions; i++)
    reset_exclusion(&s->exclusions[i]);
  reset_at_exclusion(&s->at_excl);
  s->id_end = -1;
  if (length==sizeof(int))
  {
    char *dst = (char*)&s->id_end;
    for (unsigned i=0;i<sizeof(int);i++)
      dst[i] = buffer[i];
  }
}

void tree_sitter_applesoft_external_scanner_destroy(void *payload) {
  free(payload);
}
