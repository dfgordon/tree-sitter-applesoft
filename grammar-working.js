// References:
// [1] Apple II AppleSoft BASIC Programmer's Reference Manual, Volume 2

// grammar-working.js is for human editing
// grammar.js is the actual grammar (created by token_processor.py)

// This grammar follows Ref. 1 closely.
// Limits of a real Apple II that are not imposed here:
// * parenthesis to 36 levels
// * line numbers cannot exceed 63999
// * subscripts limited to 89 dimensions

module.exports = grammar({
	name: 'AppleSoft',
	rules: {
		source_file: $ => repeat($.line),

		// Assign a rule to all tokenized statements and functions
		// These are taken from Table H-3 in Ref. 1
		// (Not strictly needed, but perhaps useful for some tasks)

		// token rules go here DO NOT EDIT this line

		// Statements from Appendix A

		statement: $ => choice(
			$.assignment,
			seq('CALL',$.aexpr),
			'CLEAR',
			seq('COLOR=',$.aexpr),
			seq('DATA',optional($.data_item),repeat(seq(',',$.data_item))),
			seq('DEF FN',$._name,'(',$._name,')','=',$.aexpr),
			//seq('DEL',$.linenum,',',$.linenum),
			seq('DIM',$.dim_item,repeat(seq(',',$.dim_item))),
			seq('DRAW',$.aexpr,optional(seq('AT',$.aexpr,',',$.aexpr))),
			'END',
			'FLASH',
			seq('FOR',$._name,'=',$.aexpr,'TO',$.aexpr,optional(seq('STEP',$.aexpr))),
			seq('GET',$.var),
			seq('GOSUB',$.linenum),
			seq('GOTO',$.linenum),
			'GR',
			seq('HCOLOR=',$.aexpr),
			'HGR',
			'HGR2',
			seq('HIMEM:',$.aexpr),
			seq('HLIN',$.aexpr,',',$.aexpr,'AT',$.aexpr),
			'HOME',
			seq('HPLOT',$.aexpr,',',$.aexpr,optional(seq('TO',$.aexpr,',',$.aexpr))),
			seq('HTAB',$.aexpr),
			// Ref. 1 explicitly has the compound statement, but this is implied
			seq('IF',$.expr,'THEN',$.statement),
			seq('IF',$.expr,'THEN',$.linenum),
			seq('IF',$.expr,'GOTO',$.linenum),
			//seq('IN#',$.aexpr),
			seq('INPUT',optional(seq($.sexpr,';')),$.var,repeat(seq(',',$.var))),
			'INVERSE',
			//seq('LIST',optional($.linenum),optional(seq(choice('-',','),$.linenum))),
			seq('LOMEM:',$.aexpr),
			//'NEW',
			seq('NEXT',optional(seq($.avar,repeat(seq(',',$.avar))))),
			'NORMAL',
			//'NOTRACE',
			seq('ON',$.aexpr,choice('GOTO','GOSUB'),$.linenum,repeat(seq(',',$.linenum))),
			seq('ONERR','GOTO',$.linenum),
			seq('PLOT',$.aexpr,',',$.aexpr),
			seq('POKE',$.aexpr,',',$.aexpr),
			'POP',
			//seq('PR#',$.aexpr),
			// following differs from the reference, which seems to allow dropping the delimiter
			seq('PRINT',optional($.expr),repeat(seq(choice(',',';'),$.expr)),optional(';')),
			seq('READ',$.var,repeat(seq(',',$.var))),
			seq('REM',repeat($._character)),
			'RESTORE',
			'RESUME',
			'RETURN',
			seq('ROT=',$.aexpr),
			//seq('RUN',optional(choice($.linenum,$._name))),
			seq('SCALE=',$.aexpr),
			seq('SPEED=',$.aexpr),
			'STOP',
			'TEXT',
			//'TRACE',
			seq('USR','(',$.aexpr,')'),
			seq('VLIN',$.aexpr,',',$.aexpr,'AT',$.aexpr),
			seq('VTAB',$.aexpr),
			seq('WAIT',$.aexpr,',',$.aexpr,optional(seq(',',$.aexpr))),
			seq('XDRAW',$.aexpr,optional(seq('AT',$.aexpr,',',$.aexpr)))
		),

		//data_item: $ => choice($.literal,$.string,$.real,$.integer),
		data_item: $ => choice($.string,$.real,$.integer),
		dim_item: $ => seq($._name,optional(choice('$','%')),$.subscript),

		assignment: $ => choice(
			seq(optional('LET'),$.avar,'=',$.aexpr),
			seq(optional('LET'),$.svar,'=',$.sexpr)
		),

		// Arithmetic functions from Appendix A

		// following is the general fcall from Ref. 1 (not used)
		//fcall: $=> seq($._name,'(',repeat(seq($.expr,',')),$.expr,')'),
		fcall: $ => choice(
			seq('ABS','(',$.aexpr,')'),
			seq('ASC','(',$.sexpr,')'),
			seq('ATN','(',$.aexpr,')'),
			seq('COS','(',$.aexpr,')'),
			seq('EXP','(',$.aexpr,')'),
			seq('FN',$._name,'(',$.aexpr,')'),
			seq('FRE','(',$.expr,')'),
			seq('INT','(',$.aexpr,')'),
			seq('LEN','(',$.sexpr,')'),
			seq('LOG','(',$.aexpr,')'),
			seq('PEEK','(',$.aexpr,')'),
			seq('POS','(',$.expr,')'),
			seq('RND','(',$.aexpr,')'),
			seq('SCRN','(',$.aexpr,',',$.aexpr,')'),
			seq('SGN','(',$.aexpr,')'),
			seq('SIN','(',$.aexpr,')'),
			seq('SQR','(',$.aexpr,')'),
			seq('TAN','(',$.aexpr,')'),
			seq('VAL','(',$.sexpr,')')
		),

		// String functions from Appendix A

		// following is the general sfcall from Ref. 1 (not used)
		//sfcall: $ => seq($._name,'$','(',repeat(seq($.expr,',')),$.expr,')'),
		sfcall: $ => choice(
			seq('CHR$','(',$.aexpr,')'),
			seq('LEFT$','(',$.sexpr,',',$.aexpr,')'),
			seq('MID$','(',$.sexpr,',',$.aexpr,optional(seq(',',$.aexpr)),')'),
			seq('RIGHT$','(',$.sexpr,',',$.aexpr,')'),
			seq('SPC','(',$.aexpr,')'),
			seq('STR$','(',$.aexpr,')'),
			seq('TAB','(',$.aexpr,')')
		),

		// Syntax definitions from Appendix B

		aexpr: $ => choice(
			$.real,
			$.raw_integer,
			$.avar,
			$.fcall,
			$.unary_aexpr,
			$.binary_aexpr,
			seq('(',$.aexpr,')')
			// following are the way unary and binary aexpr defined in Ref. 1 (not used)
			//seq($.unop,$.aexpr),
			//seq($.aexpr,$.alop,$.aexpr),
			//seq($.sexpr,$.relop,$.sexpr),
		),
		unary_aexpr: $ => prec(7,choice(
			seq('+',$.aexpr),
			seq('-',$.aexpr),
			seq('NOT',$.aexpr)
		)),
		binary_aexpr: $ => choice(
			prec.left(6,seq($.aexpr,'^',$.aexpr)),
			prec.left(5,seq($.aexpr,choice('*','/'),$.aexpr)),
			prec.left(4,seq($.aexpr,choice('+','-'),$.aexpr)),
			prec.left(3,seq($.aexpr,$.relop,$.aexpr)),
			prec.left(3,seq($.sexpr,$.relop,$.sexpr)),
			prec.left(2,seq($.aexpr,'AND',$.aexpr)),
			prec.left(1,seq($.aexpr,'OR',$.aexpr))
		),
		relop: $ => choice('=','<','>',/<\s*=/,/=\s*</,/>\s*=/,/=\s*>/,/<\s*>/,/>\s*</),
		// following are some operator groups defined by Ref.1 but not used here
		//alop: $ => choice($.aop,$.relop,$.lop),
		//aop: $ => choice('+','-','*','/','^'),
		//lop: $ => choice('AND','OR'),
		//unop: $ => prec(2,choice('+','-','NOT')),

		avar: $ => choice($.realvar,$.intvar),
		_character: $ => choice($._letter,$._digit,$._spchar,$.quote,$._space),
		_digit: $ => /[0-9]/,
		expr: $ => choice($.aexpr,$.sexpr),
		raw_integer: $ => prec.left(1,repeat1($._digit)),
		integer: $ => seq(optional(choice('+','-')),repeat1($._digit)),
		intvar: $ => prec.left(1,seq($._name,'%',optional($.subscript))),
		_letter: $ => /[A-Z]|[a-z]/,
		line: $ => seq($.linenum,repeat(seq($.statement,':')),$.statement,'\n'),
		linenum: $ => /[0-9]+/,
		literal: $ => repeat1($._character),
		lowercase: $ => /[a-z]/,
		_name: $ => /[A-Z]([A-Z]|[0-9])*/,
		quote: $ => '"',
		real: $ => /(\+|\-)?([0-9]+\.?[0-9]*|\.[0-9]+)(E(\+|\-)?[0-9]{1,2})?/,
		realvar: $ => prec.left(1,seq($._name,optional($.subscript))),
		_schar: $ => choice($._letter,$._digit,$._spchar,$._space),
		sexpr: $ => choice(
			$.string,
			$.svar,
			$.sfcall,
			prec.left(1,seq($.sexpr,$.sop,$.sexpr)),
			seq('(',$.sexpr,')')
		),
		sop: $ => '+',
		_space: $ => ' ',
		_spchar: $ => /[\+\-\*\/\^=<>\(\),\.:;%\$\#\?\&\'@\!\[\]\{\}\\\|_`\~]/,
		string: $ => prec(1,seq('"',repeat($._schar),'"')),
		subscript: $ => seq('(',$.aexpr,repeat(seq(',',$.aexpr)),')'),
		svar: $ => prec.left(1,seq($._name,'$',optional($.subscript))),
		uppercase: $ => /[A-Z]/,
		var: $ => choice($.avar,$.svar)
	}
});
