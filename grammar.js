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

// This real number excludes integers, unlike Ref. 2 p. 237
// Following captures the zero valued cases in the first table on p. 237
// There are no negative numbers outside of unary expressions (DATA might be viewed as an exception)
let POS_REAL_DOT = /[0-9]?[0-9 ]*\.[0-9 ]*(E *[+-]? *([0-9] *[0-9]?)?)?/;
// Following captures forms without the decimal point
let POS_REAL_E = /[0-9][0-9 ]*(E *[+-]? *([0-9] *[0-9]?)?)/;

// Real numbers in DATA have greater syntactic range, but lower case is never allowed (E not e).
// Also for data allow the sign to be part of the number, since we don't have expressions.
const REAL_DATA_DOT = /([+-] *)?[0-9]?[0-9 ]*\.[0-9 ]*(E *[+-]? *([0-9] *[0-9]?)?)?/;
const REAL_DATA_E = /([+-] *)?[0-9][0-9 ]*(E *[+-]? *([0-9] *[0-9]?)?)/;
const REAL_DATA_BARE = /([+-]|[+-]? *E *[+-]?)/;
const INTEGER_DATA = /([+-] *)?[0-9]([0-9 ]*[0-9])?/;

if (allow_lower_case)
{
	POS_REAL_DOT = new RegExp(POS_REAL_DOT.source.replace('E','[Ee]'));
	POS_REAL_E = new RegExp(POS_REAL_E.source.replace('E','[Ee]'));
}

const
	DIGIT = /[0-9]/,
	LETTER = /[A-Za-z]/,
	POS_INTEGER = /[0-9]([0-9 ]*[0-9])?/,
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

			tok_end: $ => /[Ee] *[Nn] *[Dd]/,
			tok_for: $ => /[Ff] *[Oo] *[Rr]/,
			tok_next: $ => /[Nn] *[Ee] *[Xx] *[Tt]/,
			tok_data: $ => /[Dd] *[Aa] *[Tt] *[Aa]/,
			tok_input: $ => /[Ii] *[Nn] *[Pp] *[Uu] *[Tt]/,
			tok_del: $ => /[Dd] *[Ee] *[Ll]/,
			tok_dim: $ => /[Dd] *[Ii] *[Mm]/,
			tok_read: $ => /[Rr] *[Ee] *[Aa] *[Dd]/,
			tok_gr: $ => /[Gg] *[Rr]/,
			tok_text: $ => /[Tt] *[Ee] *[Xx] *[Tt]/,
			tok_prn: $ => /[Pp] *[Rr] *[##]/,
			tok_inn: $ => /[Ii] *[Nn] *[##]/,
			tok_call: $ => /[Cc] *[Aa] *[Ll] *[Ll]/,
			tok_plot: $ => /[Pp] *[Ll] *[Oo] *[Tt]/,
			tok_hlin: $ => /[Hh] *[Ll] *[Ii] *[Nn]/,
			tok_vlin: $ => /[Vv] *[Ll] *[Ii] *[Nn]/,
			tok_hgr2: $ => /[Hh] *[Gg] *[Rr] *[22]/,
			tok_hgr: $ => /[Hh] *[Gg] *[Rr]/,
			tok_hcoloreq: $ => /[Hh] *[Cc] *[Oo] *[Ll] *[Oo] *[Rr] *[==]/,
			tok_hplot: $ => /[Hh] *[Pp] *[Ll] *[Oo] *[Tt]/,
			tok_draw: $ => /[Dd] *[Rr] *[Aa] *[Ww]/,
			tok_xdraw: $ => /[Xx] *[Dd] *[Rr] *[Aa] *[Ww]/,
			tok_htab: $ => /[Hh] *[Tt] *[Aa] *[Bb]/,
			tok_home: $ => /[Hh] *[Oo] *[Mm] *[Ee]/,
			tok_roteq: $ => /[Rr] *[Oo] *[Tt] *[==]/,
			tok_scaleeq: $ => /[Ss] *[Cc] *[Aa] *[Ll] *[Ee] *[==]/,
			tok_shload: $ => /[Ss] *[Hh] *[Ll] *[Oo] *[Aa] *[Dd]/,
			tok_trace: $ => /[Tt] *[Rr] *[Aa] *[Cc] *[Ee]/,
			tok_notrace: $ => /[Nn] *[Oo] *[Tt] *[Rr] *[Aa] *[Cc] *[Ee]/,
			tok_normal: $ => /[Nn] *[Oo] *[Rr] *[Mm] *[Aa] *[Ll]/,
			tok_inverse: $ => /[Ii] *[Nn] *[Vv] *[Ee] *[Rr] *[Ss] *[Ee]/,
			tok_flash: $ => /[Ff] *[Ll] *[Aa] *[Ss] *[Hh]/,
			tok_coloreq: $ => /[Cc] *[Oo] *[Ll] *[Oo] *[Rr] *[==]/,
			tok_pop: $ => /[Pp] *[Oo] *[Pp]/,
			tok_vtab: $ => /[Vv] *[Tt] *[Aa] *[Bb]/,
			tok_himem: $ => /[Hh] *[Ii] *[Mm] *[Ee] *[Mm] *[::]/,
			tok_lomem: $ => /[Ll] *[Oo] *[Mm] *[Ee] *[Mm] *[::]/,
			tok_onerr: $ => /[Oo] *[Nn] *[Ee] *[Rr] *[Rr]/,
			tok_resume: $ => /[Rr] *[Ee] *[Ss] *[Uu] *[Mm] *[Ee]/,
			tok_recall: $ => /[Rr] *[Ee] *[Cc] *[Aa] *[Ll] *[Ll]/,
			tok_store: $ => /[Ss] *[Tt] *[Oo] *[Rr] *[Ee]/,
			tok_speedeq: $ => /[Ss] *[Pp] *[Ee] *[Ee] *[Dd] *[==]/,
			tok_let: $ => /[Ll] *[Ee] *[Tt]/,
			tok_goto: $ => /[Gg] *[Oo] *[Tt] *[Oo]/,
			tok_run: $ => /[Rr] *[Uu] *[Nn]/,
			tok_if: $ => /[Ii] *[Ff]/,
			tok_restore: $ => /[Rr] *[Ee] *[Ss] *[Tt] *[Oo] *[Rr] *[Ee]/,
			tok_amp: $ => '&',
			tok_gosub: $ => /[Gg] *[Oo] *[Ss] *[Uu] *[Bb]/,
			tok_return: $ => /[Rr] *[Ee] *[Tt] *[Uu] *[Rr] *[Nn]/,
			tok_rem: $ => /[Rr] *[Ee] *[Mm]/,
			tok_stop: $ => /[Ss] *[Tt] *[Oo] *[Pp]/,
			tok_on: $ => /[Oo] *[Nn]/,
			tok_wait: $ => /[Ww] *[Aa] *[Ii] *[Tt]/,
			tok_load: $ => /[Ll] *[Oo] *[Aa] *[Dd]/,
			tok_save: $ => /[Ss] *[Aa] *[Vv] *[Ee]/,
			tok_def: $ => /[Dd] *[Ee] *[Ff]/,
			tok_poke: $ => /[Pp] *[Oo] *[Kk] *[Ee]/,
			tok_print: $ => /[Pp] *[Rr] *[Ii] *[Nn] *[Tt]|\?/,
			tok_cont: $ => /[Cc] *[Oo] *[Nn] *[Tt]/,
			tok_list: $ => /[Ll] *[Ii] *[Ss] *[Tt]/,
			tok_clear: $ => /[Cc] *[Ll] *[Ee] *[Aa] *[Rr]/,
			tok_get: $ => /[Gg] *[Ee] *[Tt]/,
			tok_new: $ => /[Nn] *[Ee] *[Ww]/,
			tok_tabp: $ => /[Tt] *[Aa] *[Bb] *[\(\(]/,
			tok_to: $ => /[Tt] *[Oo]/,
			tok_fn: $ => /[Ff] *[Nn]/,
			tok_spcp: $ => /[Ss] *[Pp] *[Cc] *[\(\(]/,
			tok_then: $ => /[Tt] *[Hh] *[Ee] *[Nn]/,
			tok_at: $ => /[Aa] *[Tt]/,
			tok_not: $ => /[Nn] *[Oo] *[Tt]/,
			tok_step: $ => /[Ss] *[Tt] *[Ee] *[Pp]/,
			tok_plus: $ => '+',
			tok_minus: $ => '-',
			tok_times: $ => '*',
			tok_div: $ => '/',
			tok_pow: $ => '^',
			tok_and: $ => /[Aa] *[Nn] *[Dd]/,
			tok_or: $ => /[Oo] *[Rr]/,
			tok_gtr: $ => '>',
			tok_eq: $ => '=',
			tok_less: $ => '<',
			tok_sgn: $ => /[Ss] *[Gg] *[Nn]/,
			tok_int: $ => /[Ii] *[Nn] *[Tt]/,
			tok_abs: $ => /[Aa] *[Bb] *[Ss]/,
			tok_usr: $ => /[Uu] *[Ss] *[Rr]/,
			tok_fre: $ => /[Ff] *[Rr] *[Ee]/,
			tok_scrnp: $ => /[Ss] *[Cc] *[Rr] *[Nn] *[\(\(]/,
			tok_pdl: $ => /[Pp] *[Dd] *[Ll]/,
			tok_pos: $ => /[Pp] *[Oo] *[Ss]/,
			tok_sqr: $ => /[Ss] *[Qq] *[Rr]/,
			tok_rnd: $ => /[Rr] *[Nn] *[Dd]/,
			tok_log: $ => /[Ll] *[Oo] *[Gg]/,
			tok_exp: $ => /[Ee] *[Xx] *[Pp]/,
			tok_cos: $ => /[Cc] *[Oo] *[Ss]/,
			tok_sin: $ => /[Ss] *[Ii] *[Nn]/,
			tok_tan: $ => /[Tt] *[Aa] *[Nn]/,
			tok_atn: $ => /[Aa] *[Tt][Nn]/,
			tok_peek: $ => /[Pp] *[Ee] *[Ee] *[Kk]/,
			tok_len: $ => /[Ll] *[Ee] *[Nn]/,
			tok_str: $ => /[Ss] *[Tt] *[Rr] *[\$\$]/,
			tok_val: $ => /[Vv] *[Aa] *[Ll]/,
			tok_asc: $ => /[Aa] *[Ss] *[Cc]/,
			tok_chr: $ => /[Cc] *[Hh] *[Rr] *[\$\$]/,
			tok_left: $ => /[Ll] *[Ee] *[Ff] *[Tt] *[\$\$]/,
			tok_right: $ => /[Rr] *[Ii] *[Gg] *[Hh] *[Tt] *[\$\$]/,
			tok_mid: $ => /[Mm] *[Ii] *[Dd] *[\$\$]/,


		// Statements from Appendix A

		statement: $ => choice(
			$.assignment,
			// Optional string after CALL is to allow for the CHAIN pattern
			seq($.tok_call,$._aexpr,optional($.str)),
			$.tok_clear,
			seq($.tok_coloreq,$._aexpr),
			$.tok_cont,
			seq($.tok_data,optional($._data_item),repeat(seq(',',optional($._data_item)))),
			seq($.tok_def,$.tok_fn,alias($.name_real,$.name_fn),'(',alias($._real_scalar,$.var_real),')',$.tok_eq,$._aexpr),
			seq($.tok_del,$.linenum,',',$.linenum),
			seq($.tok_dim,$.dim_item,repeat(seq(',',$.dim_item))),
			seq($.tok_draw,$._aexpr,optional(seq($.tok_at,$._aexpr,',',$._aexpr))),
			$.tok_end,
			$.tok_flash,
			seq($.tok_for,alias($._real_scalar,$.var_real),$.tok_eq,$._aexpr,$.tok_to,$._aexpr,optional(seq($.tok_step,$._aexpr))),
			seq($.tok_get,$._var,repeat(seq(',',$._var))),
			seq($.tok_gosub,$.linenum),
			seq($.tok_goto,$.linenum),
			$.tok_gr,
			seq($.tok_hcoloreq,$._aexpr),
			$.tok_hgr,
			$.tok_hgr2,
			seq($.tok_himem,$._aexpr),
			seq($.tok_hlin,$._aexpr,',',$._aexpr,$.tok_at,$._aexpr),
			$.tok_home,
			seq($.tok_hplot,optional($.tok_to),$._aexpr,',',$._aexpr,repeat(seq($.tok_to,$._aexpr,',',$._aexpr))),
			seq($.tok_htab,$._aexpr),
			// Ref. 2 explicitly has the compound statement, but this is implied
			seq($.tok_if,$._expr,$.tok_then,$.statement),
			seq($.tok_if,$._expr,$.tok_then,$.linenum),
			seq($.tok_if,$._expr,$.tok_goto,$.linenum),
			seq($.tok_inn,$._aexpr),
			seq($.tok_input,optional(seq($._sexpr,';')),$._var,repeat(seq(',',$._var))),
			$.tok_inverse,
			$.tok_load, // cassette tape
			seq($.tok_list,optional($.linenum),optional(seq(choice($.tok_minus,','),optional($.linenum)))),
			seq($.tok_lomem,$._aexpr),
			$.tok_new,
			seq($.tok_next,optional(seq($._avar,repeat(seq(',',$._avar))))),
			$.tok_normal,
			$.tok_notrace,
			seq($.tok_on,$._aexpr,choice($.tok_goto,$.tok_gosub),$.linenum,repeat(seq(',',$.linenum))),
			seq($.tok_onerr,$.tok_goto,$.linenum),
			seq($.tok_plot,$._aexpr,',',$._aexpr),
			seq($.tok_poke,$._aexpr,',',$._aexpr),
			$.tok_pop,
			seq($.tok_prn,$._aexpr),
			seq($.tok_print,repeat((choice(',',';',$._expr)))),
			seq($.tok_read,$._var,repeat(seq(',',$._var))),
			seq($.tok_recall,choice(alias($._int_scalar,$.var_int),alias($._real_scalar,$.var_real))), // cassette tape, subscript omitted
			seq($.tok_rem,optional($.comment_text)),
			$.tok_restore,
			$.tok_resume,
			$.tok_return,
			seq($.tok_roteq,$._aexpr),
			seq($.tok_run,optional($.linenum)),
			$.tok_save, // cassette tape
			seq($.tok_scaleeq,$._aexpr),
			$.tok_shload, // cassette tape
			seq($.tok_speedeq,$._aexpr),
			$.tok_stop,
			seq($.tok_store,choice(alias($._int_scalar,$.var_int),alias($._real_scalar,$.var_real))), // cassette tape, subscript omitted
			$.tok_text,
			$.tok_trace,
			seq($.tok_vlin,$._aexpr,',',$._aexpr,$.tok_at,$._aexpr),
			seq($.tok_vtab,$._aexpr),
			seq($.tok_wait,$._aexpr,',',$._aexpr,optional(seq(',',$._aexpr))),
			seq($.tok_xdraw,$._aexpr,optional(seq($.tok_at,$._aexpr,',',$._aexpr))),
			seq($.tok_amp,$.str),
			seq($.tok_amp,'(',$._expr,repeat(seq(',',$._expr)),')')
		),

		// terminal_statement rule is used to handle strings without closing quotes,
		// which are legal at the end of a line.
		terminal_statement: $ => choice(
			seq($.tok_if,$._expr,$.tok_then,$.terminal_statement),
			seq($.tok_call,$._aexpr,$.terminal_str),
			seq($.tok_data,optional($._data_item),repeat(seq(',',optional($._data_item))),$.terminal_str),
			seq($.tok_print,repeat((choice(',',';',$._expr))),$.terminal_str),
			seq($.tok_amp,$.terminal_str)
		),

		comment_text: $ => /.+/,

		assignment: $ => choice(
			seq(optional($.tok_let),$._avar,$.tok_eq,$._aexpr),
			seq(optional($.tok_let),$.var_str,$.tok_eq,$._sexpr)
		),

		// Numerical functions from Appendix A
		// N.b. some have left parenthesis as part of the token

		// following is the general fcall from Ref. 2 (not used)
		//fcall: $=> seq($.name,'(',repeat(seq($._expr,',')),$._expr,')'),
		fcall: $ => choice(
			seq($.tok_abs,'(',$._aexpr,')'),
			seq($.tok_asc,'(',$._sexpr,')'),
			seq($.tok_atn,'(',$._aexpr,')'),
			seq($.tok_cos,'(',$._aexpr,')'),
			seq($.tok_exp,'(',$._aexpr,')'),
			seq($.tok_fn,alias($.name_real,$.name_fn),'(',$._aexpr,')'),
			seq($.tok_fre,'(',$._expr,')'),
			seq($.tok_int,'(',$._aexpr,')'),
			seq($.tok_len,'(',$._sexpr,')'),
			seq($.tok_log,'(',$._aexpr,')'),
			seq($.tok_pdl,'(',$._aexpr,')'),
			seq($.tok_peek,'(',$._aexpr,')'),
			seq($.tok_pos,'(',$._expr,')'),
			seq($.tok_rnd,'(',$._aexpr,')'),
			seq($.tok_scrnp,$._aexpr,',',$._aexpr,')'),
			seq($.tok_sgn,'(',$._aexpr,')'),
			seq($.tok_sin,'(',$._aexpr,')'),
			seq($.tok_sqr,'(',$._aexpr,')'),
			seq($.tok_tan,'(',$._aexpr,')'),
			seq($.tok_usr,'(',$._aexpr,')'),
			seq($.tok_val,'(',$._sexpr,')')
		),

		// String functions from Appendix A
		// N.b. some have left parenthesis as part of the token

		// following is the general sfcall from Ref. 2 (not used)
		//sfcall: $ => seq($.name_str,'(',repeat(seq($._expr,',')),$._expr,')'),
		sfcall: $ => choice(
			seq($.tok_chr,'(',$._aexpr,')'),
			seq($.tok_left,'(',$._sexpr,',',$._aexpr,')'),
			seq($.tok_mid,'(',$._sexpr,',',$._aexpr,optional(seq(',',$._aexpr)),')'),
			seq($.tok_right,'(',$._sexpr,',',$._aexpr,')'),
			seq($.tok_spcp,$._aexpr,')'),
			seq($.tok_str,'(',$._aexpr,')'),
			seq($.tok_tabp,$._aexpr,')')
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
			seq($.tok_plus,$._aexpr),
			seq($.tok_minus,$._aexpr),
			seq($.tok_not,$._aexpr)
		)),
		binary_aexpr: $ => choice(
			prec.left(6,seq($._aexpr,$.tok_pow,$._aexpr)),
			prec.left(5,seq($._aexpr,choice($.tok_times,$.tok_div),$._aexpr)),
			prec.left(4,seq($._aexpr,choice($.tok_plus,$.tok_minus),$._aexpr)),
			prec.left(3,seq($._aexpr,$._relop,$._aexpr)),
			prec.left(3,seq($._sexpr,$._relop,$._sexpr)),
			prec.left(2,seq($._aexpr,$.tok_and,$._aexpr)),
			prec.left(1,seq($._aexpr,$.tok_or,$._aexpr))
		),
		_parenthesized_aexpr: $ => prec(1,seq('(',$._aexpr,')')),
		_relop: $ => choice($.tok_eq,$.tok_less,$.tok_gtr,
			seq($.tok_less,$.tok_eq),seq($.tok_eq,$.tok_less),
			seq($.tok_gtr,$.tok_eq),seq($.tok_eq,$.tok_gtr),
			seq($.tok_less,$.tok_gtr),seq($.tok_gtr,$.tok_less)),
		// following are some operator groups defined by Ref.2 but not used here
		//alop: $ => choice($.aop,$._relop,$.lop),
		//aop: $ => choice($.tok_plus,$.tok_minus,$.tok_times,$.tok_div,$.tok_pow),
		//lop: $ => choice($.tok_and,$.tok_or),
		//unop: $ => choice($.tok_plus,$.tok_minus,$.tok_not),

		_sexpr: $ => choice(
			$.str,
			$.var_str,
			$.sfcall,
			$.binary_sexpr,
			$._parenthesized_sexpr
		),
		binary_sexpr: $ => prec.left(1,seq($._sexpr,$._sop,$._sexpr)),
		_parenthesized_sexpr: $ => seq('(',$._sexpr,')'),
		_sop: $ => $.tok_plus,

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
		data_int: $ => INTEGER_DATA,
		data_real: $ => choice(REAL_DATA_DOT,REAL_DATA_E,REAL_DATA_BARE),
		data_literal: $ => token(prec(0,seq(DCHAR_1,repeat(DCHAR_N)))),

		// Literals from Appendix B

		int: $ => token(prec(1,POS_INTEGER)),
		real: $ => token(prec(1,choice(POS_REAL_DOT,POS_REAL_E))),
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
