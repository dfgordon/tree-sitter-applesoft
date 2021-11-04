// References:
// [1] Apple II AppleSoft BASIC Programmer's Reference Manual, Volume 1
// [2] Apple II AppleSoft BASIC Programmer's Reference Manual, Volume 2

// grammar-src.js is for human editing
// grammar.js is the actual grammar (created by token_processor.py)

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

// Define constants for use in forming terminal nodes.
// These are named after their equivalents in Ref. 2 Appendix B
// N.B. (it appears) we can only use the token() function on rules composed of terminal symbols.

const
	// Apple II interpreter ignores spaces expect in a few special cases
	// Apple II allows real numbers such as ".", "E", ".E", etc.
	// Labels come from Ref. 2 Appendix B
	REAL_DOT = /(\+|\-)?[0-9 ]*\.[0-9 ]*E?([0-9 ]*[0-9])?/,
	REAL_E = /(\+|\-)?[0-9 ]*\.?[0-9 ]*E([0-9 ]*[0-9])?/,
	SPCHAR = /[\+\-\*\/\^=<>\(\),\.:;%\$\#\?\&\'@\!\[\]\{\}\\\|_`\~]/,
	DIGIT = /[0-9]/,
	LETTER = /[A-Za-z]/,
	INTEGER = /(\+|\-)?[0-9]([0-9 ]*[0-9])?/,
	// We have to forbid spaces in NAME in order to succeed at present
	NAME = /[A-Z][A-Z0-9]*/,
	QUOTE = /"/,
	SPACE = / /,
	// schar = letter,digit,space,spchar
	SCHAR = /[0-9A-Za-z \+\-\*\/\^=<>\(\),\.:;%\$\#\?\&\'@\!\[\]\{\}\\\|_`\~]/,
	// character = letter,digit,space,spchar,quote
	CHARACTER = /[0-9A-Za-z" \+\-\*\/\^=<>\(\),\.:;%\$\#\?\&\'@\!\[\]\{\}\\\|_`\~]/,
	// dchar = character without the comma (not in Ref. 2, using this to parse DATA statements)
	DCHAR = /[0-9A-Za-z" \+\-\*\/\^=<>\(\)\.:;%\$\#\?\&\'@\!\[\]\{\}\\\|_`\~]/

// Tree-sitter grammar definition

module.exports = grammar({
	name: 'AppleSoft',
	extras: $ => [' '],

	rules: {
		source_file: $ => repeat(choice($.line,$._empty_line)),

		// Assign a rule to all tokenized statements and functions
		// These are taken from Table H-3 in Ref. 2

		// token rules go here DO NOT EDIT this line

		// Statements from Appendix A

		statement: $ => choice(
			$.assignment,
			seq('CALL',$._aexpr),
			'CLEAR',
			seq('COLOR=',$._aexpr),
			seq('DATA',$._data_item,repeat(seq(',',$._data_item))),
			seq('DEF','FN',$.real_scalar,'(',$.real_scalar,')','=',$._aexpr),
			//seq('DEL',$.linenum,',',$.linenum),
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
			seq('HPLOT',$._aexpr,',',$._aexpr,optional(seq('TO',$._aexpr,',',$._aexpr))),
			seq('HTAB',$._aexpr),
			// Ref. 2 explicitly has the compound statement, but this is implied
			seq('IF',$._expr,'THEN',$.statement),
			seq('IF',$._expr,'THEN',$.linenum),
			seq('IF',$._expr,'GOTO',$.linenum),
			seq('IN#',$._aexpr),
			seq('INPUT',optional(seq($._sexpr,';')),$._var,repeat(seq(',',$._var))),
			'INVERSE',
			//seq('LIST',optional($.linenum),optional(seq(choice('-',','),$.linenum))),
			seq('LOMEM:',$._aexpr),
			//'NEW',
			seq('NEXT',optional(seq($._avar,repeat(seq(',',$._avar))))),
			'NORMAL',
			//'NOTRACE',
			seq('ON',$._aexpr,choice('GOTO','GOSUB'),$.linenum,repeat(seq(',',$.linenum))),
			seq('ONERR','GOTO',$.linenum),
			seq('PLOT',$._aexpr,',',$._aexpr),
			seq('POKE',$._aexpr,',',$._aexpr),
			'POP',
			seq('PR#',$._aexpr),
			// following differs from the reference, which seems to allow dropping the delimiter
			seq('PRINT',optional($._expr),repeat(seq(choice(',',';'),$._expr)),optional(';')),
			seq('READ',$._var,repeat(seq(',',$._var))),
			seq('REM',repeat(CHARACTER)),
			'RESTORE',
			'RESUME',
			'RETURN',
			seq('ROT=',$._aexpr),
			//seq('RUN',optional(choice($.linenum,NAME))),
			seq('SCALE=',$._aexpr),
			seq('SPEED=',$._aexpr),
			'STOP',
			'TEXT',
			//'TRACE',
			seq('USR','(',$._aexpr,')'),
			seq('VLIN',$._aexpr,',',$._aexpr,'AT',$._aexpr),
			seq('VTAB',$._aexpr),
			seq('WAIT',$._aexpr,',',$._aexpr,optional(seq(',',$._aexpr))),
			seq('XDRAW',$._aexpr,optional(seq('AT',$._aexpr,',',$._aexpr)))
		),

		assignment: $ => choice(
			seq(optional('LET'),$._avar,'=',$._aexpr),
			seq(optional('LET'),$.svar,'=',$._sexpr)
		),

		// Numerical functions from Appendix A

		// following is the general fcall from Ref. 2 (not used)
		//fcall: $=> seq(NAME,'(',repeat(seq($._expr,',')),$._expr,')'),
		fcall: $ => choice(
			seq('ABS','(',$._aexpr,')'),
			seq('ASC','(',$._sexpr,')'),
			seq('ATN','(',$._aexpr,')'),
			seq('COS','(',$._aexpr,')'),
			seq('EXP','(',$._aexpr,')'),
			seq('FN',$.real_scalar,'(',$._aexpr,')'),
			seq('FRE','(',$._expr,')'),
			seq('INT','(',$._aexpr,')'),
			seq('LEN','(',$._sexpr,')'),
			seq('LOG','(',$._aexpr,')'),
			seq('PDL','(',$._aexpr,')'),
			seq('PEEK','(',$._aexpr,')'),
			seq('POS','(',$._expr,')'),
			seq('RND','(',$._aexpr,')'),
			seq('SCRN','(',$._aexpr,',',$._aexpr,')'),
			seq('SGN','(',$._aexpr,')'),
			seq('SIN','(',$._aexpr,')'),
			seq('SQR','(',$._aexpr,')'),
			seq('TAN','(',$._aexpr,')'),
			seq('VAL','(',$._sexpr,')')
		),

		// String functions from Appendix A

		// following is the general sfcall from Ref. 2 (not used)
		//sfcall: $ => seq(NAME,'$','(',repeat(seq($._expr,',')),$._expr,')'),
		sfcall: $ => choice(
			seq('CHR$','(',$._aexpr,')'),
			seq('LEFT$','(',$._sexpr,',',$._aexpr,')'),
			seq('MID$','(',$._sexpr,',',$._aexpr,optional(seq(',',$._aexpr)),')'),
			seq('RIGHT$','(',$._sexpr,',',$._aexpr,')'),
			seq('SPC','(',$._aexpr,')'),
			seq('STR$','(',$._aexpr,')'),
			seq('TAB','(',$._aexpr,')')
		),

		// Program lines from Appendix B

		line: $ => seq($.linenum,repeat(seq($.statement,':')),$.statement,'\n'),
		_empty_line: $ => /\n/, // Would not exist on real Apple II
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
		// following are some operator groups defined by Ref.1 but not used here
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

		real_scalar: $ => token(prec(1,NAME)), // for interpretation, not in Ref. 2
		_var: $ => choice($._avar,$.svar),
		_avar: $ => choice($.realvar,$.intvar),
		intvar: $ => seq(NAME,'%',optional($.subscript)),
		realvar: $ => seq(NAME,optional($.subscript)),
		svar: $ => seq(NAME,'$',optional($.subscript)),
		subscript: $ => seq('(',$._aexpr,repeat(seq(',',$._aexpr)),')'),
		_dim_item: $ => choice($.intvar,$.realvar,$.svar),

		// Literals from Appendix B

		_data_item: $ => choice($.string,$.real,$.integer,$.literal),
		integer: $ => token(prec(1,INTEGER)),
		// Unlike Ref. 2 the following disallows commas
		// So far this has been needed to parse some forms of the DATA statement
		literal: $ => token(prec(0,repeat1(DCHAR))),
		real: $ => token(prec(1,choice(REAL_DOT,REAL_E))),
		string: $ => token(prec(1,seq('"',repeat(SCHAR),'"')))
	}
});
