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

// This real number excludes integers, unlike Ref. 2 p. 237
// Following captures the zero valued cases in the first table on p. 237
let REAL_DOT = /([+-] *)?[0-9]?[0-9 ]*\.[0-9 ]*(E *[+-]? *([0-9] *[0-9]?)?)?/;
// Following captures forms without the decimal point
let REAL_E = /([+-] *)?[0-9][0-9 ]*(E *[+-]? *([0-9] *[0-9]?)?)/;
// The following additional real numbers are acceptable in DATA statements
let REAL_DATA = /([+-]|[+-]? *E *[+-]?)/;

if (allow_lower_case)
{
	// This real number excludes integers, unlike Ref. 2 p. 237
	// Following captures the zero valued cases in the first table on p. 237
	REAL_DOT = /([+-] *)?[0-9]?[0-9 ]*\.[0-9 ]*([Ee] *[+-]? *([0-9] *[0-9]?)?)?/;
	// Following captures forms without the decimal point
	REAL_E = /([+-] *)?[0-9][0-9 ]*([Ee] *[+-]? *([0-9] *[0-9]?)?)/;
	// The following additional real numbers are acceptable in DATA statements
	REAL_DATA = /([+-]|[+-]? *[Ee] *[+-]?)/;
}

const
	DIGIT = /[0-9]/,
	LETTER = /[A-Za-z]/,
	INTEGER = /[+-]?[0-9]([0-9 ]*[0-9])?/,
	QUOTE = /"/,
	SPACE = / /,
	COMMA = /,/,
	// Ref. 2 includes any control character in SPCHAR, while we exclude NULL, LF, CR.
	SPCHAR_NO_COMMA = /[+\-*\/^=<>().:;%$#?&'@!\[\]{}\\|_`~\x01-\x09\x0b\x0c\x0e-\x1f]/,
	SPCHAR = regex_or([SPCHAR_NO_COMMA,COMMA]),
	SCHAR = regex_or([LETTER,DIGIT,SPCHAR,SPACE]),
	// DCHAR_1 and DCHAR_N replace `character` from Ref. 2, used for DATA literal
	// Ref. 2 allows comma in `literal`, but this seems to be a mistake, so we do not.
	DCHAR_1 = regex_or([LETTER,DIGIT,SPCHAR_NO_COMMA,SPACE]),
	DCHAR_N = regex_or([DCHAR_1,QUOTE]);

// Tree-sitter grammar definition

module.exports = grammar({
	name: 'applesoft',
	extras: $ => [' '],
	// "name" is the term given in Ref. 2 for an identifier.
	// external scanner is used to forbid keywords from appearing anywhere in the name.
	externals: $ => [ $._ext_name ],

	rules: {
		source_file: $ => repeat(choice($.line,$._empty_line)),

		// Assign a rule to all tokenized statements and functions
		// These are taken from Table H-3 in Ref. 2

		// token rules go here DO NOT EDIT this line

		// Statements from Appendix A

		statement: $ => choice(
			$.assignment,
			// Optional string after CALL is to allow for the CHAIN pattern
			seq('CALL',$._aexpr,optional($.string)),
			'CLEAR',
			seq('COLOR=',$._aexpr),
			'CONT',
			seq('DATA',repeat(seq($._data_item,',')),$._data_item),
			seq('DEF','FN',$.fn_name,'(',$.real_scalar,')','=',$._aexpr),
			seq('DEL',$.linenum,',',$.linenum),
			seq('DIM',$._dim_item,repeat(seq(',',$._dim_item))),
			seq('DRAW',$._aexpr,optional(seq('AT',$._aexpr,',',$._aexpr))),
			'END',
			'FLASH',
			seq('FOR',$.real_scalar,'=',$._aexpr,'TO',$._aexpr,optional(seq('STEP',$._aexpr))),
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
			seq('PRINT',repeat(seq($._expr,optional(choice(',',';'))))),
			seq('READ',$._var,repeat(seq(',',$._var))),
			seq('RECALL',choice($.int_scalar,$.real_scalar)), // cassette tape, subscript omitted
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
			seq('STORE',choice($.int_scalar,$.real_scalar)), // cassette tape, subscript omitted
			'TEXT',
			'TRACE',
			seq('VLIN',$._aexpr,',',$._aexpr,'AT',$._aexpr),
			seq('VTAB',$._aexpr),
			seq('WAIT',$._aexpr,',',$._aexpr,optional(seq(',',$._aexpr))),
			seq('XDRAW',$._aexpr,optional(seq('AT',$._aexpr,',',$._aexpr))),
			seq('&',$.string),
			seq('&','(',$._expr,repeat(seq(',',$._expr)),')')
		),

		// terminal_statement rule is used to handle strings without closing quotes,
		// which are legal at the end of a line.
		terminal_statement: $ => choice(
			seq('CALL',$._aexpr,$.terminal_string),
			seq('DATA',repeat(seq($._data_item,',')),$.terminal_string),
			seq('PRINT',repeat(seq($._expr,optional(choice(',',';')))),$.terminal_string),
			seq('&',$.terminal_string)
		),

		comment_text: $ => /.+/,

		assignment: $ => choice(
			seq(optional('LET'),$._avar,'=',$._aexpr),
			seq(optional('LET'),$.svar,'=',$._sexpr)
		),

		// Numerical functions from Appendix A
		// N.b. some have left parenthesis as part of the token

		// following is the general fcall from Ref. 2 (not used)
		//fcall: $=> seq($._name,'(',repeat(seq($._expr,',')),$._expr,')'),
		fcall: $ => choice(
			seq('ABS','(',$._aexpr,')'),
			seq('ASC','(',$._sexpr,')'),
			seq('ATN','(',$._aexpr,')'),
			seq('COS','(',$._aexpr,')'),
			seq('EXP','(',$._aexpr,')'),
			seq('FN',$.fn_name,'(',$._aexpr,')'),
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
		//sfcall: $ => seq($._name,'$','(',repeat(seq($._expr,',')),$._expr,')'),
		sfcall: $ => choice(
			seq('CHR$','(',$._aexpr,')'),
			seq('LEFT$','(',$._sexpr,',',$._aexpr,')'),
			seq('MID$','(',$._sexpr,',',$._aexpr,optional(seq(',',$._aexpr)),')'),
			seq('RIGHT$','(',$._sexpr,',',$._aexpr,')'),
			seq('SPC(',$._aexpr,')'),
			seq('STR$','(',$._aexpr,')'),
			seq('TAB(',$._aexpr,')')
		),

		// Program lines from Appendix B

		line: $ => seq($.linenum,repeat(seq($.statement,':')),choice($.statement,$.terminal_statement),choice('\n','\r\n')),
		_empty_line: $ => /\r\n|\n/, // Would not exist on real Apple II
		linenum: $ => / *[0-9][0-9 ]*/,

		// Expressions from Appendix B

		_expr: $ => choice($._aexpr,$._sexpr),

		_aexpr: $ => choice(
			$.real,
			$.integer,
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
			$.string,
			$.svar,
			$.sfcall,
			$.binary_sexpr,
			$._parenthesized_sexpr
		),
		binary_sexpr: $ => prec.left(1,seq($._sexpr,$._sop,$._sexpr)),
		_parenthesized_sexpr: $ => seq('(',$._sexpr,')'),
		_sop: $ => '+',

		// Variables from Appendix B

		_var: $ => choice($._avar,$.svar),
		_avar: $ => choice($.realvar,$.intvar),
		intvar: $ => choice($._int_scalar,$._int_array),
		realvar: $ => choice($._real_scalar,$._real_array),
		svar: $ => choice($._string_scalar,$._string_array),
		subscript: $ => seq('(',$._aexpr,repeat(seq(',',$._aexpr)),')'),
		_dim_item: $ => choice($.int_array,$.real_array,$.string_array),

		// Literals from Appendix B

		_data_item: $ => choice($.string,$.real,$.integer,$.literal,$.real_data_item),
		integer: $ => token(prec(1,INTEGER)),
		// Unlike Ref. 2 the following disallows commas and cannot start with a quote
		// So far this has been needed to parse some forms of the DATA statement
		literal: $ => token(prec(0,seq(DCHAR_1,repeat(DCHAR_N)))),
		real: $ => token(prec(1,choice(REAL_DOT,REAL_E))),
		string: $ => token(prec(1,seq('"',repeat(SCHAR),'"'))),

		// "Extra" items not in Appendix B
		// These are added for convenience or to account for certain exceptions

		terminal_string: $ => token(prec(1,seq('"',repeat(SCHAR)))),
		real_data_item: $ => token(prec(1,REAL_DATA)),
		fn_name: $ => $._name,
		real_scalar: $ => $._name,
		_real_scalar: $ => $._name,
		int_scalar: $ => seq($._name,'%'),
		_int_scalar: $ => seq($._name,'%'),
		_string_scalar: $ => seq($._name,'$'),
		real_array: $ => prec(1,seq($._name,$.subscript)),
		_real_array: $ => prec(1,seq($._name,$.subscript)),
		int_array: $ => prec(1,seq($._name,'%',$.subscript)),
		_int_array: $ => prec(1,seq($._name,'%',$.subscript)),
		string_array: $ => prec(1,seq($._name,'$',$.subscript)),
		_string_array: $ => prec(1,seq($._name,'$',$.subscript)),

		// This is the rule that triggers the external scanner.
		// Due to tree-sitter design, lexing a variable name requires two stages:
		// (i) lookahead: find maximum run of a valid variable name, and return empty token
		// (ii) advance: add the actual characters
		_name: $ => seq($._ext_name,$._ext_name)
	}
});
