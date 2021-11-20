// Overall structure copied from github.com/tree-sitter/tree-sitter-ruby
// This scanner excludes keywords from identifiers.
// This is supposed to approximate the behavior of the Apple II ROM (A2ROM).
// In particular, the A2ROM tokenizes these keywords first without regard to context.
// Therefore any variable name must terminate before any keyword begins.

#include <tree_sitter/parser.h>
#include <vector>
#include <string>

// scanner-src.cc is for human editing.
// scanner.cc is generated by token_processor.py

namespace
{

enum TokenType {
  NAME, // label is carried over from legacy docs, this is an identifier
  NONE
};

class exclusion
{
  char a2token[7]; // string with the excluded token
  int matches; // how many characters have been matched; don't confuse with token matches
  int len; // length of string
  int start; // offset to first matching character

public:

  exclusion(const char *tok,int l)
  {
    start = 0;
    matches = 0;
    len = l;
    for (int i=0;i<len;i++)
      a2token[i] = tok[i];
  }
  void reset()
  {
    start = 0;
    matches = 0;
  }
  void next(int32_t c,int pos)
  {
    if (c==' ' || matches==len)
      return;
    if (a2token[matches]==c)
      matches++;
    else
      matches = (a2token[0]==c);
    if (matches==1)
      start = pos;
  }
  void finish(int& min_start)
  {
    if (start<min_start && matches==len)
      min_start = start;
  }
};

class at_exclusion
{
  // Special handling for the AT keyword is needed to emulate A2ROM behavior.
  // AT and TO are resolved as follows: /A *TO/ = (A)(TO) ; /A *T +O/ = (AT)(O)
  // To match this behavior, we only need to worry about matching AT, since if AT
  // matches, then the subsequent false match of TO is harmless to this scanner.
  int matches; // how many characters have been matched; don't confuse with token matches
  int start; // offset to first matching character
  int end; // offset to last matching character

public:

  at_exclusion()
  {
    start = 0;
    end = 0;
    matches = 0;
  }
  void reset()
  {
    start = 0;
    end = 0;
    matches = 0;
  }
  void next(int32_t c,int pos)
  {
    if (matches==2 && c=='O' && pos==end+1)
      reset();
    if (c==' ' || matches==2)
      return;
    if (matches==1 && c=='T')
    {
      matches = 2;
      end = pos;
    }
    else
      matches = (c=='A');
    if (matches==1)
      start = pos;
  }
  void finish(int& min_start)
  {
    if (start<min_start && matches==2)
      min_start = start;
  }
};

struct Scanner
{
  // Code to build exclusions is auto-generated by token-processor.py
  std::vector<exclusion> exclusions;
  at_exclusion at_excl;
  int id_end;

  Scanner()
  {
    id_end = -1;
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

  unsigned serialize(char *buffer)
  {
    char *src = (char*)&id_end;
    for (unsigned i=0;i<sizeof(id_end);i++)
      buffer[i] = src[i];
    return sizeof(id_end);
  }

  void deserialize(const char *buffer, unsigned length)
  {
    for (auto & excl : exclusions)
      excl.reset();
    at_excl.reset();
    id_end = -1;
    if (length==sizeof(id_end))
    {
      char *dst = (char*)&id_end;
      for (unsigned i=0;i<sizeof(id_end);i++)
        dst[i] = buffer[i];
    }
  }

  bool first_pass(TSLexer *lexer, const bool *valid_symbols)
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
      c = lexer->lookahead;
      // loop to accumulate keyword matches
      for (auto & excl : exclusions)
        excl.next(c,tot_pos);
      at_excl.next(c,tot_pos);
      identifier_matching = ((id_pos==0 && is_alpha(c)) || (id_pos>0 && is_alphanumeric(c)) || c==' ');
      if (identifier_matching)
      {
        lexer->advance(lexer,false);
        tot_pos++;
        id_pos += (c!=' ');
      }
    } while(identifier_matching);
    id_end = tot_pos;
    // loop to rewind position to left-most keyword match
    for (auto & excl : exclusions)
      excl.finish(id_end);
    at_excl.finish(id_end);
    if (id_end>0 && id_pos>0)
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

  bool second_pass(TSLexer *lexer, const bool *valid_symbols)
  {
    // Lexing is already done. We just have to set the marker.
    for (int i=0;i<id_end;i++)
      lexer->advance(lexer,false);
    id_end = -1;
    lexer->result_symbol = NAME;
    return true;
  }

  bool scan(TSLexer *lexer, const bool *valid_symbols)
  {
    if (!valid_symbols[NAME])
    {
      lexer->result_symbol = NONE;
      return false;
    }
    if (id_end<0)
      return first_pass(lexer,valid_symbols);
    else
      return second_pass(lexer,valid_symbols);
  }
};

}

extern "C" {

void *tree_sitter_applesoft_external_scanner_create() {
  return new Scanner();
}

bool tree_sitter_applesoft_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
  Scanner *scanner = static_cast<Scanner *>(payload);
  return scanner->scan(lexer, valid_symbols);
}

unsigned tree_sitter_applesoft_external_scanner_serialize(void *payload, char *buffer) {
  Scanner *scanner = static_cast<Scanner *>(payload);
  return scanner->serialize(buffer);
}

void tree_sitter_applesoft_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
  Scanner *scanner = static_cast<Scanner *>(payload);
  scanner->deserialize(buffer, length);
}

void tree_sitter_applesoft_external_scanner_destroy(void *payload) {
  Scanner *scanner = static_cast<Scanner *>(payload);
  delete scanner;
}

}
