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
	COLON = /:/,
	// Ref. 2 includes any control character in SPCHAR, while we exclude NULL, LF, CR.
	SPCHAR_NO_SEP = /[+\-*\/^=<>().;%$#?&'@!\[\]{}\\|_`~\x01-\x09\x0b\x0c\x0e-\x1f]/,
	SPCHAR = regex_or([SPCHAR_NO_SEP,COMMA,COLON]),
	SCHAR = regex_or([LETTER,DIGIT,SPCHAR,SPACE]),
	// DCHAR_1 and DCHAR_N replace `character` from Ref. 2, used for DATA literal
	// Ref. 2 erroneously allows commas and colons in DATA literals.
	// Also, leading spaces are ignored, but trailing spaces are included.
	DCHAR_1 = regex_or([LETTER,DIGIT,SPCHAR_NO_SEP]),
	DCHAR_N = regex_or([DCHAR_1,QUOTE,SPACE]);

// Tree-sitter grammar definition

module.exports = grammar({
	name: language_name,
	extras: $ => [' '],
	// "name" is the term given in Ref. 2 for an identifier.
	// external scanner is used to forbid keywords from appearing anywhere in the name.
	externals: $ => [ $._ext_name ],

	rules: {
		source_file: $ => repeat(choice($.line,$._empty_line)),

		// Assign a rule to all tokenized statements and functions
		// These are taken from Table H-3 in Ref. 2

			end_tok: $ => /[Ee] *[Nn] *[Dd]/,
			for_tok: $ => /[Ff] *[Oo] *[Rr]/,
			next_tok: $ => /[Nn] *[Ee] *[Xx] *[Tt]/,
			data_tok: $ => /[Dd] *[Aa] *[Tt] *[Aa]/,
			input_tok: $ => /[Ii] *[Nn] *[Pp] *[Uu] *[Tt]/,
			del_tok: $ => /[Dd] *[Ee] *[Ll]/,
			dim_tok: $ => /[Dd] *[Ii] *[Mm]/,
			read_tok: $ => /[Rr] *[Ee] *[Aa] *[Dd]/,
			gr_tok: $ => /[Gg] *[Rr]/,
			text_tok: $ => /[Tt] *[Ee] *[Xx] *[Tt]/,
			prn_tok: $ => /[Pp] *[Rr] *[##]/,
			inn_tok: $ => /[Ii] *[Nn] *[##]/,
			call_tok: $ => /[Cc] *[Aa] *[Ll] *[Ll]/,
			plot_tok: $ => /[Pp] *[Ll] *[Oo] *[Tt]/,
			hlin_tok: $ => /[Hh] *[Ll] *[Ii] *[Nn]/,
			vlin_tok: $ => /[Vv] *[Ll] *[Ii] *[Nn]/,
			hgr2_tok: $ => /[Hh] *[Gg] *[Rr] *[22]/,
			hgr_tok: $ => /[Hh] *[Gg] *[Rr]/,
			hcoloreq_tok: $ => /[Hh] *[Cc] *[Oo] *[Ll] *[Oo] *[Rr] *[==]/,
			hplot_tok: $ => /[Hh] *[Pp] *[Ll] *[Oo] *[Tt]/,
			draw_tok: $ => /[Dd] *[Rr] *[Aa] *[Ww]/,
			xdraw_tok: $ => /[Xx] *[Dd] *[Rr] *[Aa] *[Ww]/,
			htab_tok: $ => /[Hh] *[Tt] *[Aa] *[Bb]/,
			home_tok: $ => /[Hh] *[Oo] *[Mm] *[Ee]/,
			roteq_tok: $ => /[Rr] *[Oo] *[Tt] *[==]/,
			scaleeq_tok: $ => /[Ss] *[Cc] *[Aa] *[Ll] *[Ee] *[==]/,
			shload_tok: $ => /[Ss] *[Hh] *[Ll] *[Oo] *[Aa] *[Dd]/,
			trace_tok: $ => /[Tt] *[Rr] *[Aa] *[Cc] *[Ee]/,
			notrace_tok: $ => /[Nn] *[Oo] *[Tt] *[Rr] *[Aa] *[Cc] *[Ee]/,
			normal_tok: $ => /[Nn] *[Oo] *[Rr] *[Mm] *[Aa] *[Ll]/,
			inverse_tok: $ => /[Ii] *[Nn] *[Vv] *[Ee] *[Rr] *[Ss] *[Ee]/,
			flash_tok: $ => /[Ff] *[Ll] *[Aa] *[Ss] *[Hh]/,
			coloreq_tok: $ => /[Cc] *[Oo] *[Ll] *[Oo] *[Rr] *[==]/,
			pop_tok: $ => /[Pp] *[Oo] *[Pp]/,
			vtab_tok: $ => /[Vv] *[Tt] *[Aa] *[Bb]/,
			himem_tok: $ => /[Hh] *[Ii] *[Mm] *[Ee] *[Mm] *[::]/,
			lomem_tok: $ => /[Ll] *[Oo] *[Mm] *[Ee] *[Mm] *[::]/,
			onerr_tok: $ => /[Oo] *[Nn] *[Ee] *[Rr] *[Rr]/,
			resume_tok: $ => /[Rr] *[Ee] *[Ss] *[Uu] *[Mm] *[Ee]/,
			recall_tok: $ => /[Rr] *[Ee] *[Cc] *[Aa] *[Ll] *[Ll]/,
			store_tok: $ => /[Ss] *[Tt] *[Oo] *[Rr] *[Ee]/,
			speedeq_tok: $ => /[Ss] *[Pp] *[Ee] *[Ee] *[Dd] *[==]/,
			let_tok: $ => /[Ll] *[Ee] *[Tt]/,
			goto_tok: $ => /[Gg] *[Oo] *[Tt] *[Oo]/,
			run_tok: $ => /[Rr] *[Uu] *[Nn]/,
			if_tok: $ => /[Ii] *[Ff]/,
			restore_tok: $ => /[Rr] *[Ee] *[Ss] *[Tt] *[Oo] *[Rr] *[Ee]/,
			amp_tok: $ => '&',
			gosub_tok: $ => /[Gg] *[Oo] *[Ss] *[Uu] *[Bb]/,
			return_tok: $ => /[Rr] *[Ee] *[Tt] *[Uu] *[Rr] *[Nn]/,
			rem_tok: $ => /[Rr] *[Ee] *[Mm]/,
			stop_tok: $ => /[Ss] *[Tt] *[Oo] *[Pp]/,
			on_tok: $ => /[Oo] *[Nn]/,
			wait_tok: $ => /[Ww] *[Aa] *[Ii] *[Tt]/,
			load_tok: $ => /[Ll] *[Oo] *[Aa] *[Dd]/,
			save_tok: $ => /[Ss] *[Aa] *[Vv] *[Ee]/,
			def_tok: $ => /[Dd] *[Ee] *[Ff]/,
			poke_tok: $ => /[Pp] *[Oo] *[Kk] *[Ee]/,
			print_tok: $ => /[Pp] *[Rr] *[Ii] *[Nn] *[Tt]|\?/,
			cont_tok: $ => /[Cc] *[Oo] *[Nn] *[Tt]/,
			list_tok: $ => /[Ll] *[Ii] *[Ss] *[Tt]/,
			clear_tok: $ => /[Cc] *[Ll] *[Ee] *[Aa] *[Rr]/,
			get_tok: $ => /[Gg] *[Ee] *[Tt]/,
			new_tok: $ => /[Nn] *[Ee] *[Ww]/,
			tabp_tok: $ => /[Tt] *[Aa] *[Bb] *[\(\(]/,
			to_tok: $ => /[Tt] *[Oo]/,
			fn_tok: $ => /[Ff] *[Nn]/,
			spcp_tok: $ => /[Ss] *[Pp] *[Cc] *[\(\(]/,
			then_tok: $ => /[Tt] *[Hh] *[Ee] *[Nn]/,
			at_tok: $ => /[Aa] *[Tt]/,
			not_tok: $ => /[Nn] *[Oo] *[Tt]/,
			step_tok: $ => /[Ss] *[Tt] *[Ee] *[Pp]/,
			plus_tok: $ => '+',
			minus_tok: $ => '-',
			times_tok: $ => '*',
			div_tok: $ => '/',
			pow_tok: $ => '^',
			and_tok: $ => /[Aa] *[Nn] *[Dd]/,
			or_tok: $ => /[Oo] *[Rr]/,
			gtr_tok: $ => '>',
			eq_tok: $ => '=',
			less_tok: $ => '<',
			sgn_tok: $ => /[Ss] *[Gg] *[Nn]/,
			int_tok: $ => /[Ii] *[Nn] *[Tt]/,
			abs_tok: $ => /[Aa] *[Bb] *[Ss]/,
			usr_tok: $ => /[Uu] *[Ss] *[Rr]/,
			fre_tok: $ => /[Ff] *[Rr] *[Ee]/,
			scrnp_tok: $ => /[Ss] *[Cc] *[Rr] *[Nn] *[\(\(]/,
			pdl_tok: $ => /[Pp] *[Dd] *[Ll]/,
			pos_tok: $ => /[Pp] *[Oo] *[Ss]/,
			sqr_tok: $ => /[Ss] *[Qq] *[Rr]/,
			rnd_tok: $ => /[Rr] *[Nn] *[Dd]/,
			log_tok: $ => /[Ll] *[Oo] *[Gg]/,
			exp_tok: $ => /[Ee] *[Xx] *[Pp]/,
			cos_tok: $ => /[Cc] *[Oo] *[Ss]/,
			sin_tok: $ => /[Ss] *[Ii] *[Nn]/,
			tan_tok: $ => /[Tt] *[Aa] *[Nn]/,
			atn_tok: $ => /[Aa] *[Tt][Nn]/,
			peek_tok: $ => /[Pp] *[Ee] *[Ee] *[Kk]/,
			len_tok: $ => /[Ll] *[Ee] *[Nn]/,
			str_tok: $ => /[Ss] *[Tt] *[Rr] *[\$\$]/,
			val_tok: $ => /[Vv] *[Aa] *[Ll]/,
			asc_tok: $ => /[Aa] *[Ss] *[Cc]/,
			chr_tok: $ => /[Cc] *[Hh] *[Rr] *[\$\$]/,
			left_tok: $ => /[Ll] *[Ee] *[Ff] *[Tt] *[\$\$]/,
			right_tok: $ => /[Rr] *[Ii] *[Gg] *[Hh] *[Tt] *[\$\$]/,
			mid_tok: $ => /[Mm] *[Ii] *[Dd] *[\$\$]/,


		// Statements from Appendix A

		statement: $ => choice(
			$.assignment,
			// Optional string after CALL is to allow for the CHAIN pattern
			seq($.call_tok,$._aexpr,optional($.string)),
			$.clear_tok,
			seq($.coloreq_tok,$._aexpr),
			$.cont_tok,
			seq($.data_tok,optional($._data_item),repeat(seq(',',optional($._data_item)))),
			seq($.def_tok,$.fn_tok,$.fn_name,'(',$.real_scalar,')',$.eq_tok,$._aexpr),
			seq($.del_tok,$.linenum,',',$.linenum),
			seq($.dim_tok,$._dim_item,repeat(seq(',',$._dim_item))),
			seq($.draw_tok,$._aexpr,optional(seq($.at_tok,$._aexpr,',',$._aexpr))),
			$.end_tok,
			$.flash_tok,
			seq($.for_tok,$.real_scalar,$.eq_tok,$._aexpr,$.to_tok,$._aexpr,optional(seq($.step_tok,$._aexpr))),
			seq($.get_tok,$._var,repeat(seq(',',$._var))),
			seq($.gosub_tok,$.linenum),
			seq($.goto_tok,$.linenum),
			$.gr_tok,
			seq($.hcoloreq_tok,$._aexpr),
			$.hgr_tok,
			$.hgr2_tok,
			seq($.himem_tok,$._aexpr),
			seq($.hlin_tok,$._aexpr,',',$._aexpr,$.at_tok,$._aexpr),
			$.home_tok,
			seq($.hplot_tok,optional($.to_tok),$._aexpr,',',$._aexpr,repeat(seq($.to_tok,$._aexpr,',',$._aexpr))),
			seq($.htab_tok,$._aexpr),
			// Ref. 2 explicitly has the compound statement, but this is implied
			seq($.if_tok,$._expr,$.then_tok,$.statement),
			seq($.if_tok,$._expr,$.then_tok,$.linenum),
			seq($.if_tok,$._expr,$.goto_tok,$.linenum),
			seq($.inn_tok,$._aexpr),
			seq($.input_tok,optional(seq($._sexpr,';')),$._var,repeat(seq(',',$._var))),
			$.inverse_tok,
			$.load_tok, // cassette tape
			seq($.list_tok,optional($.linenum),optional(seq(choice($.minus_tok,','),optional($.linenum)))),
			seq($.lomem_tok,$._aexpr),
			$.new_tok,
			seq($.next_tok,optional(seq($._avar,repeat(seq(',',$._avar))))),
			$.normal_tok,
			$.notrace_tok,
			seq($.on_tok,$._aexpr,choice($.goto_tok,$.gosub_tok),$.linenum,repeat(seq(',',$.linenum))),
			seq($.onerr_tok,$.goto_tok,$.linenum),
			seq($.plot_tok,$._aexpr,',',$._aexpr),
			seq($.poke_tok,$._aexpr,',',$._aexpr),
			$.pop_tok,
			seq($.prn_tok,$._aexpr),
			seq($.print_tok,repeat((choice(',',';',$._expr)))),
			seq($.read_tok,$._var,repeat(seq(',',$._var))),
			seq($.recall_tok,choice($.int_scalar,$.real_scalar)), // cassette tape, subscript omitted
			seq($.rem_tok,optional($.comment_text)),
			$.restore_tok,
			$.resume_tok,
			$.return_tok,
			seq($.roteq_tok,$._aexpr),
			seq($.run_tok,optional($.linenum)),
			$.save_tok, // cassette tape
			seq($.scaleeq_tok,$._aexpr),
			$.shload_tok, // cassette tape
			seq($.speedeq_tok,$._aexpr),
			$.stop_tok,
			seq($.store_tok,choice($.int_scalar,$.real_scalar)), // cassette tape, subscript omitted
			$.text_tok,
			$.trace_tok,
			seq($.vlin_tok,$._aexpr,',',$._aexpr,$.at_tok,$._aexpr),
			seq($.vtab_tok,$._aexpr),
			seq($.wait_tok,$._aexpr,',',$._aexpr,optional(seq(',',$._aexpr))),
			seq($.xdraw_tok,$._aexpr,optional(seq($.at_tok,$._aexpr,',',$._aexpr))),
			seq($.amp_tok,$.string),
			seq($.amp_tok,'(',$._expr,repeat(seq(',',$._expr)),')')
		),

		// terminal_statement rule is used to handle strings without closing quotes,
		// which are legal at the end of a line.
		terminal_statement: $ => choice(
			seq($.if_tok,$._expr,$.then_tok,$.terminal_statement),
			seq($.call_tok,$._aexpr,$.terminal_string),
			seq($.data_tok,optional($._data_item),repeat(seq(',',optional($._data_item))),$.terminal_string),
			seq($.print_tok,repeat((choice(',',';',$._expr))),$.terminal_string),
			seq($.amp_tok,$.terminal_string)
		),

		comment_text: $ => /.+/,

		assignment: $ => choice(
			seq(optional($.let_tok),$._avar,$.eq_tok,$._aexpr),
			seq(optional($.let_tok),$.svar,$.eq_tok,$._sexpr)
		),

		// Numerical functions from Appendix A
		// N.b. some have left parenthesis as part of the token

		// following is the general fcall from Ref. 2 (not used)
		//fcall: $=> seq($._name,'(',repeat(seq($._expr,',')),$._expr,')'),
		fcall: $ => choice(
			seq($.abs_tok,'(',$._aexpr,')'),
			seq($.asc_tok,'(',$._sexpr,')'),
			seq($.atn_tok,'(',$._aexpr,')'),
			seq($.cos_tok,'(',$._aexpr,')'),
			seq($.exp_tok,'(',$._aexpr,')'),
			seq($.fn_tok,$.fn_name,'(',$._aexpr,')'),
			seq($.fre_tok,'(',$._expr,')'),
			seq($.int_tok,'(',$._aexpr,')'),
			seq($.len_tok,'(',$._sexpr,')'),
			seq($.log_tok,'(',$._aexpr,')'),
			seq($.pdl_tok,'(',$._aexpr,')'),
			seq($.peek_tok,'(',$._aexpr,')'),
			seq($.pos_tok,'(',$._expr,')'),
			seq($.rnd_tok,'(',$._aexpr,')'),
			seq($.scrnp_tok,$._aexpr,',',$._aexpr,')'),
			seq($.sgn_tok,'(',$._aexpr,')'),
			seq($.sin_tok,'(',$._aexpr,')'),
			seq($.sqr_tok,'(',$._aexpr,')'),
			seq($.tan_tok,'(',$._aexpr,')'),
			seq($.usr_tok,'(',$._aexpr,')'),
			seq($.val_tok,'(',$._sexpr,')')
		),

		// String functions from Appendix A
		// N.b. some have left parenthesis as part of the token

		// following is the general sfcall from Ref. 2 (not used)
		//sfcall: $ => seq($._name,'$','(',repeat(seq($._expr,',')),$._expr,')'),
		sfcall: $ => choice(
			seq($.chr_tok,'(',$._aexpr,')'),
			seq($.left_tok,'(',$._sexpr,',',$._aexpr,')'),
			seq($.mid_tok,'(',$._sexpr,',',$._aexpr,optional(seq(',',$._aexpr)),')'),
			seq($.right_tok,'(',$._sexpr,',',$._aexpr,')'),
			seq($.spcp_tok,$._aexpr,')'),
			seq($.str_tok,'(',$._aexpr,')'),
			seq($.tabp_tok,$._aexpr,')')
		),

		// Program lines - differs from Appendix B due to terminal strings
		line: $ => seq($.linenum,
			repeat(':'),
			repeat(seq($.statement,repeat1(':'))),
			choice(seq($.statement,repeat(':')),$.terminal_statement),
			$._newline),
		linenum: $ => / *[0-9][0-9 ]*/,
		_newline: $ => /\r?\n/,
		_empty_line: $ => /\r?\n/, // Would not exist on real Apple II

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
			seq($.plus_tok,$._aexpr),
			seq($.minus_tok,$._aexpr),
			seq($.not_tok,$._aexpr)
		)),
		binary_aexpr: $ => choice(
			prec.left(6,seq($._aexpr,$.pow_tok,$._aexpr)),
			prec.left(5,seq($._aexpr,choice($.times_tok,$.div_tok),$._aexpr)),
			prec.left(4,seq($._aexpr,choice($.plus_tok,$.minus_tok),$._aexpr)),
			prec.left(3,seq($._aexpr,$._relop,$._aexpr)),
			prec.left(3,seq($._sexpr,$._relop,$._sexpr)),
			prec.left(2,seq($._aexpr,$.and_tok,$._aexpr)),
			prec.left(1,seq($._aexpr,$.or_tok,$._aexpr))
		),
		_parenthesized_aexpr: $ => prec(1,seq('(',$._aexpr,')')),
		_relop: $ => choice($.eq_tok,$.less_tok,$.gtr_tok,
			seq($.less_tok,$.eq_tok),seq($.eq_tok,$.less_tok),
			seq($.gtr_tok,$.eq_tok),seq($.eq_tok,$.gtr_tok),
			seq($.less_tok,$.gtr_tok),seq($.gtr_tok,$.less_tok)),
		// following are some operator groups defined by Ref.2 but not used here
		//alop: $ => choice($.aop,$._relop,$.lop),
		//aop: $ => choice($.plus_tok,$.minus_tok,$.times_tok,$.div_tok,$.pow_tok),
		//lop: $ => choice($.and_tok,$.or_tok),
		//unop: $ => choice($.plus_tok,$.minus_tok,$.not_tok),

		_sexpr: $ => choice(
			$.string,
			$.svar,
			$.sfcall,
			$.binary_sexpr,
			$._parenthesized_sexpr
		),
		binary_sexpr: $ => prec.left(1,seq($._sexpr,$._sop,$._sexpr)),
		_parenthesized_sexpr: $ => seq('(',$._sexpr,')'),
		_sop: $ => $.plus_tok,

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
