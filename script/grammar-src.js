// References:
// [1] Apple II Applesoft BASIC Programmer's Reference Manual, Volume 1, Apple Computer, Inc., Cupertino, 1982
// [2] Apple II Applesoft BASIC Programmer's Reference Manual, Volume 2, Apple Computer, Inc., Cupertino, 1982

// grammar-src.js is for human editing
// grammar.js is the actual grammar
// After editing this file run `build.py` to regenerate all the products

// The term TOKEN may be used in two senses herein: Tokens recognized by the Apple II ROM,
// vs. tokens defined by Tree-sitter.  The token_processor.py program is
// concerned with the former.

// This grammar follows Ref. 2 closely.
// Ref. 1 is used mainly to construct tests (see ./test/corpus/*)
// Limits of a real Apple II that are not imposed here:
// * parenthesis to 36 levels
// * line numbers cannot exceed 63999
// * subscripts limited to 89 dimensions
// * nested loops limited to 10 levels
// * length of a line limited to 239 characters

function regex_or(lst)
{
	let ans = lst[0];
	lst.slice(1).forEach(r => {
		ans = new RegExp(ans.source + '|' + r.source);
	});
	return ans;
}

// Define constants for use in forming terminal nodes.
// These are named after their equivalents in Ref. 2 Appendix B

// Do not set this flag manually, let `build.py` handle it
const allow_lower_case = true;
const language_name = allow_lower_case ? 'applesoft' : 'applesoftcasesens'

// This real number excludes ------------------s, unlike Ref. 2 p. 237
// Following captures the zero valued cases in the first table on p. 237
let REAL_DOT = /([+-] *)?[0-9]?[0-9 ]*\.[0-9 ]*(E *[+-]? *([0-9] *[0-9]?)?)?/;
// Following captures forms without the decimal point
let REAL_E = /([+-] *)?[0-9][0-9 ]*(E *[+-]? *([0-9] *[0-9]?)?)/;

// Real numbers in DATA have greater syntactic range, but lower case is never allowed.
const REAL_DATA_DOT = REAL_DOT;
const REAL_DATA_E = REAL_E;
const REAL_DATA_BARE = /([+-]|[+-]? *E *[+-]?)/;

if (allow_lower_case)
{
	REAL_DOT = new RegExp(REAL_DOT.source.replace('E','[Ee]'));
	REAL_E = new RegExp(REAL_E.source.replace('E','[Ee]'));
}

const
	DIGIT = /[0-9]/,
	LETTER = /[A-Za-z]/,
	INTEGER = /[+-]?[0-9]([0-9 ]*[0-9])?/,
	QUOTE = /"/,
	SPACE = / /,
	COMMA = /,/,
	COLON = /:/,
	// Ref. 2 includes any control character in SPCHAR, while we exclude NULL, LF, CR.
	SPCHAR_NO_SEP = /[+\-*\/^=<>().;%$#?&'@!\[\]{}\\|_`~\x01-\x09\x0b\x0c\x0e-\x1f]/,
	SPCHAR = regex_or([SPCHAR_NO_SEP,COMMA,COLON]),
	SCHAR = regex_or([LETTER,DIGIT,SPCHAR,SPACE]),
	// DCHAR_1 and DCHAR_N replace `character` from Ref. 2, used for DATA literal
	// Ref. 2 erroneously allows commas and colons in DATA literals.
	// Also, leading spaces are ignored, but trailing spaces are included.
	// This treatment of spaces is consistent with READ but not the tokenizer.
	DCHAR_1 = regex_or([LETTER,DIGIT,SPCHAR_NO_SEP]),
	DCHAR_N = regex_or([DCHAR_1,QUOTE,SPACE]);

// Tree-sitter grammar definition

module.exports = grammar({
	name: language_name,
	extras: $ => [' '],
	// "name" is the term given in Ref. 2 for an identifier.
	// external scanner is used to forbid keywords from appearing anywhere in the name.
	externals: $ => [ $._ext_name ],
	//conflicts: $ => [
	//	[ $.statement,$.terminal_statement ],
	//],

	rules: {
		source_file: $ => repeat(choice($.line,$._empty_line)),
		
		// Program lines - differs from Appendix B due to terminal strings
		line: $ => seq($.linenum,
			repeat(':'),
			repeat(seq($.statement,repeat1(':'))),
			choice(seq($.statement,repeat(':')),$.terminal_statement),
			$._newline),
		linenum: $ => / *[0-9][0-9 ]*/,
		_newline: $ => /\r?\n/,
		_empty_line: $ => /\r?\n/, // Would not exist on real Apple II

		// Assign a rule to all tokenized statements and functions
		// These are taken from Table H-3 in Ref. 2

		// token rules go here DO NOT EDIT this line

		// Statements from Appendix A

		statement: $ => choice(
			$.assignment,
			// Optional string after CALL is to allow for the CHAIN pattern
			seq('CALL',$._aexpr,optional($.str)),
			'CLEAR',
			seq('COLOR=',$._aexpr),
			'CONT',
			seq('DATA',optional($._data_item),repeat(seq(',',optional($._data_item)))),
			seq('DEF','FN',alias($.name_real,$.name_fn),'(',alias($._real_scalar,$.var_real),')','=',$._aexpr),
			seq('DEL',$.linenum,',',$.linenum),
			seq('DIM',$.dim_item,repeat(seq(',',$.dim_item))),
			seq('DRAW',$._aexpr,optional(seq('AT',$._aexpr,',',$._aexpr))),
			'END',
			'FLASH',
			seq('FOR',alias($._real_scalar,$.var_real),'=',$._aexpr,'TO',$._aexpr,optional(seq('STEP',$._aexpr))),
			seq('GET',$._var,repeat(seq(',',$._var))),
			seq('GOSUB',$.linenum),
			seq('GOTO',$.linenum),
			'GR',
			seq('HCOLOR=',$._aexpr),
			'HGR',
			'HGR2',
			seq('HIMEM:',$._aexpr),
			seq('HLIN',$._aexpr,',',$._aexpr,'AT',$._aexpr),
			'HOME',
			seq('HPLOT',optional('TO'),$._aexpr,',',$._aexpr,repeat(seq('TO',$._aexpr,',',$._aexpr))),
			seq('HTAB',$._aexpr),
			// Ref. 2 explicitly has the compound statement, but this is implied
			seq('IF',$._expr,'THEN',$.statement),
			seq('IF',$._expr,'THEN',$.linenum),
			seq('IF',$._expr,'GOTO',$.linenum),
			seq('IN#',$._aexpr),
			seq('INPUT',optional(seq($._sexpr,';')),$._var,repeat(seq(',',$._var))),
			'INVERSE',
			'LOAD', // cassette tape
			seq('LIST',optional($.linenum),optional(seq(choice('-',','),optional($.linenum)))),
			seq('LOMEM:',$._aexpr),
			'NEW',
			seq('NEXT',optional(seq($._avar,repeat(seq(',',$._avar))))),
			'NORMAL',
			'NOTRACE',
			seq('ON',$._aexpr,choice('GOTO','GOSUB'),$.linenum,repeat(seq(',',$.linenum))),
			seq('ONERR','GOTO',$.linenum),
			seq('PLOT',$._aexpr,',',$._aexpr),
			seq('POKE',$._aexpr,',',$._aexpr),
			'POP',
			seq('PR#',$._aexpr),
			seq('PRINT',repeat((choice(',',';',$._expr)))),
			seq('READ',$._var,repeat(seq(',',$._var))),
			seq('RECALL',choice(alias($._int_scalar,$.var_int),alias($._real_scalar,$.var_real))), // cassette tape, subscript omitted
			seq('REM',optional($.comment_text)),
			'RESTORE',
			'RESUME',
			'RETURN',
			seq('ROT=',$._aexpr),
			seq('RUN',optional($.linenum)),
			'SAVE', // cassette tape
			seq('SCALE=',$._aexpr),
			'SHLOAD', // cassette tape
			seq('SPEED=',$._aexpr),
			'STOP',
			seq('STORE',choice(alias($._int_scalar,$.var_int),alias($._real_scalar,$.var_real))), // cassette tape, subscript omitted
			'TEXT',
			'TRACE',
			seq('VLIN',$._aexpr,',',$._aexpr,'AT',$._aexpr),
			seq('VTAB',$._aexpr),
			seq('WAIT',$._aexpr,',',$._aexpr,optional(seq(',',$._aexpr))),
			seq('XDRAW',$._aexpr,optional(seq('AT',$._aexpr,',',$._aexpr))),
			seq('&',$.str),
			seq('&','(',$._expr,repeat(seq(',',$._expr)),')')
		),

		// terminal_statement rule is used to handle strings without closing quotes,
		// which are legal at the end of a line.
		terminal_statement: $ => choice(
			seq('IF',$._expr,'THEN',$.terminal_statement),
			seq('CALL',$._aexpr,$.terminal_str),
			seq('DATA',optional($._data_item),repeat(seq(',',optional($._data_item))),$.terminal_str),
			seq('PRINT',repeat((choice(',',';',$._expr))),$.terminal_str),
			seq('&',$.terminal_str)
		),

		comment_text: $ => /.+/,

		assignment: $ => choice(
			seq(optional('LET'),$._avar,'=',$._aexpr),
			seq(optional('LET'),$.var_str,'=',$._sexpr)
		),

		// Numerical functions from Appendix A
		// N.b. some have left parenthesis as part of the token

		// following is the general fcall from Ref. 2 (not used)
		//fcall: $=> seq($.name,'(',repeat(seq($._expr,',')),$._expr,')'),
		fcall: $ => choice(
			seq('ABS','(',$._aexpr,')'),
			seq('ASC','(',$._sexpr,')'),
			seq('ATN','(',$._aexpr,')'),
			seq('COS','(',$._aexpr,')'),
			seq('EXP','(',$._aexpr,')'),
			seq('FN',alias($.name_real,$.name_fn),'(',$._aexpr,')'),
			seq('FRE','(',$._expr,')'),
			seq('INT','(',$._aexpr,')'),
			seq('LEN','(',$._sexpr,')'),
			seq('LOG','(',$._aexpr,')'),
			seq('PDL','(',$._aexpr,')'),
			seq('PEEK','(',$._aexpr,')'),
			seq('POS','(',$._expr,')'),
			seq('RND','(',$._aexpr,')'),
			seq('SCRN(',$._aexpr,',',$._aexpr,')'),
			seq('SGN','(',$._aexpr,')'),
			seq('SIN','(',$._aexpr,')'),
			seq('SQR','(',$._aexpr,')'),
			seq('TAN','(',$._aexpr,')'),
			seq('USR','(',$._aexpr,')'),
			seq('VAL','(',$._sexpr,')')
		),

		// String functions from Appendix A
		// N.b. some have left parenthesis as part of the token

		// following is the general sfcall from Ref. 2 (not used)
		//sfcall: $ => seq($.name_str,'(',repeat(seq($._expr,',')),$._expr,')'),
		sfcall: $ => choice(
			seq('CHR$','(',$._aexpr,')'),
			seq('LEFT$','(',$._sexpr,',',$._aexpr,')'),
			seq('MID$','(',$._sexpr,',',$._aexpr,optional(seq(',',$._aexpr)),')'),
			seq('RIGHT$','(',$._sexpr,',',$._aexpr,')'),
			seq('SPC(',$._aexpr,')'),
			seq('STR$','(',$._aexpr,')'),
			seq('TAB(',$._aexpr,')')
		),

		// Expressions from Appendix B

		_expr: $ => choice($._aexpr,$._sexpr),

		_aexpr: $ => choice(
			$.real,
			$.int,
			$._avar,
			$.fcall,
			$.unary_aexpr,
			$.binary_aexpr,
			$._parenthesized_aexpr
			// following are the way unary and binary aexpr defined in Ref. 2 (not used)
			//seq($.unop,$._aexpr),
			//seq($._aexpr,$.alop,$._aexpr),
			//seq($._sexpr,$._relop,$._sexpr),
		),
		unary_aexpr: $ => prec(7,choice(
			seq('+',$._aexpr),
			seq('-',$._aexpr),
			seq('NOT',$._aexpr)
		)),
		binary_aexpr: $ => choice(
			prec.left(6,seq($._aexpr,'^',$._aexpr)),
			prec.left(5,seq($._aexpr,choice('*','/'),$._aexpr)),
			prec.left(4,seq($._aexpr,choice('+','-'),$._aexpr)),
			prec.left(3,seq($._aexpr,$._relop,$._aexpr)),
			prec.left(3,seq($._sexpr,$._relop,$._sexpr)),
			prec.left(2,seq($._aexpr,'AND',$._aexpr)),
			prec.left(1,seq($._aexpr,'OR',$._aexpr))
		),
		_parenthesized_aexpr: $ => prec(1,seq('(',$._aexpr,')')),
		_relop: $ => choice('=','<','>',
			seq('<','='),seq('=','<'),
			seq('>','='),seq('=','>'),
			seq('<','>'),seq('>','<')),
		// following are some operator groups defined by Ref.2 but not used here
		//alop: $ => choice($.aop,$._relop,$.lop),
		//aop: $ => choice('+','-','*','/','^'),
		//lop: $ => choice('AND','OR'),
		//unop: $ => choice('+','-','NOT'),

		_sexpr: $ => choice(
			$.str,
			$.var_str,
			$.sfcall,
			$.binary_sexpr,
			$._parenthesized_sexpr
		),
		binary_sexpr: $ => prec.left(1,seq($._sexpr,$._sop,$._sexpr)),
		_parenthesized_sexpr: $ => seq('(',$._sexpr,')'),
		_sop: $ => '+',

		// Variables from Appendix B
		// Renamed: intvar -> var_int, realvar -> var_real, svar -> var_str

		_var: $ => choice($._avar,$.var_str),
		_avar: $ => choice($.var_real,$.var_int),
		var_int: $ => choice($.name_int,$._int_array),
		var_real: $ => choice($.name_real,$._real_array),
		var_str: $ => choice($.name_str,$._str_array),
		subscript: $ => seq('(',$._aexpr,repeat(seq(',',$._aexpr)),')'),
		dim_item: $ => choice(
			alias($._int_array, $.var_int),
			alias($._real_array, $.var_real),
			alias($._str_array, $.var_str)),

		// DATA items
		// DATA is rather tricky because it is parsed in 2 or 3 different ways:
		// by the tokenizer, by READ, and possibly by the execution parser.
		// Unfortunately these are not consistent.  This parser emulates
		// READ, and therefore not the tokenizer.  Downstream tools need to
		// be aware of this.  The authors of Appendix B did not address this,
		// and their definition of the `literal` is surely problematic.

		_data_item: $ => choice(alias($.str,$.data_str),$.data_literal,$.data_int,$.data_real),
		data_int: $ => INTEGER,
		data_real: $ => choice(REAL_DATA_DOT,REAL_DATA_E,REAL_DATA_BARE),
		data_literal: $ => token(prec(0,seq(DCHAR_1,repeat(DCHAR_N)))),

		// Literals from Appendix B

		int: $ => token(prec(1,INTEGER)),
		real: $ => token(prec(1,choice(REAL_DOT,REAL_E))),
		str: $ => token(prec(1,seq('"',repeat(SCHAR),'"'))),

		// "Extra" items not in Appendix B
		// These are added for convenience or to account for certain exceptions

		terminal_str: $ => token(prec(1, seq('"', repeat(SCHAR)))),
		name_real: $ => $._name,
		name_int: $ => seq($._name,'%'),
		name_str: $ => seq($._name,'$'),
		_real_array: $ => prec(1,seq($.name_real,$.subscript)),
		_int_array: $ => prec(1,seq($.name_int,$.subscript)),
		_str_array: $ => prec(1, seq($.name_str,$.subscript)),
		_real_scalar: $ => $.name_real,
		_int_scalar: $ => $.name_int,

		// This is the rule that triggers the external scanner.
		// Due to tree-sitter design, lexing a variable name requires two stages:
		// (i) lookahead: find maximum run of a valid variable name, and return empty token
		// (ii) advance: add the actual characters
		_name: $ => seq($._ext_name,$._ext_name)
	}
});
