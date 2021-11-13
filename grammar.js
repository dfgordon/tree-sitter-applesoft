// References:
// [1] Apple II Applesoft BASIC Programmer's Reference Manual, Volume 1
// [2] Apple II Applesoft BASIC Programmer's Reference Manual, Volume 2

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
// * length of a line limited to 239 characters

// Define constants for use in forming terminal nodes.
// These are named after their equivalents in Ref. 2 Appendix B

const
	// Apple II interpreter ignores spaces expect in a few special cases
	// This real number excludes integers, unlike Ref. 2 p. 237
	// Following captures the zero valued cases in the first table on p. 237
	REAL_DOT = /([+-] *)?[0-9]?[0-9 ]*\.[0-9 ]*(E *[+-]? *([0-9] *[0-9]?)?)?/,
	// Following captures forms without the decimal point
	REAL_E = /([+-] *)?[0-9][0-9 ]*(E *[+-]? *([0-9] *[0-9]?)?)/,
	// The following additional real numbers are acceptable in DATA statements
	REAL_DATA = /([+-]|[+-]? *E *[+-]?)/,
	// Remaining constants come from Ref. 2 Appendix B
	SPCHAR = /[\+\-\*\/\^=<>\(\),\.:;%\$\#\?\&\'@\!\[\]\{\}\\\|_`\~]/,
	DIGIT = /[0-9]/,
	LETTER = /[A-Za-z]/,
	INTEGER = /[+-]?[0-9]([0-9 ]*[0-9])?/,
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
	name: 'applesoft',
	extras: $ => [' '],
	// "name" is the term given in Ref. 2 for an identifier.
	// external scanner is used to forbid keywords from appearing anywhere in the name.
	externals: $ => [ $._ext_name ],

	rules: {
		source_file: $ => repeat(choice($.line,$._empty_line)),

		// Assign a rule to all tokenized statements and functions
		// These are taken from Table H-3 in Ref. 2

			end_tok: $ => /E *N *D/,
			for_tok: $ => /F *O *R/,
			next_tok: $ => /N *E *X *T/,
			data_tok: $ => /D *A *T *A/,
			input_tok: $ => /I *N *P *U *T/,
			del_tok: $ => /D *E *L/,
			dim_tok: $ => /D *I *M/,
			read_tok: $ => /R *E *A *D/,
			gr_tok: $ => /G *R/,
			text_tok: $ => /T *E *X *T/,
			prn_tok: $ => /P *R *#/,
			inn_tok: $ => /I *N *#/,
			call_tok: $ => /C *A *L *L/,
			plot_tok: $ => /P *L *O *T/,
			hlin_tok: $ => /H *L *I *N/,
			vlin_tok: $ => /V *L *I *N/,
			hgr2_tok: $ => /H *G *R *2/,
			hgr_tok: $ => /H *G *R/,
			hcoloreq_tok: $ => /H *C *O *L *O *R *=/,
			hplot_tok: $ => /H *P *L *O *T/,
			draw_tok: $ => /D *R *A *W/,
			xdraw_tok: $ => /X *D *R *A *W/,
			htab_tok: $ => /H *T *A *B/,
			home_tok: $ => /H *O *M *E/,
			roteq_tok: $ => /R *O *T *=/,
			scaleeq_tok: $ => /S *C *A *L *E *=/,
			shload_tok: $ => /S *H *L *O *A *D/,
			trace_tok: $ => /T *R *A *C *E/,
			notrace_tok: $ => /N *O *T *R *A *C *E/,
			normal_tok: $ => /N *O *R *M *A *L/,
			inverse_tok: $ => /I *N *V *E *R *S *E/,
			flash_tok: $ => /F *L *A *S *H/,
			coloreq_tok: $ => /C *O *L *O *R *=/,
			pop_tok: $ => /P *O *P/,
			vtab_tok: $ => /V *T *A *B/,
			himem_tok: $ => /H *I *M *E *M *:/,
			lomem_tok: $ => /L *O *M *E *M *:/,
			onerr_tok: $ => /O *N *E *R *R/,
			resume_tok: $ => /R *E *S *U *M *E/,
			recall_tok: $ => /R *E *C *A *L *L/,
			store_tok: $ => /S *T *O *R *E/,
			speedeq_tok: $ => /S *P *E *E *D *=/,
			let_tok: $ => /L *E *T/,
			goto_tok: $ => /G *O *T *O/,
			run_tok: $ => /R *U *N/,
			if_tok: $ => /I *F/,
			restore_tok: $ => /R *E *S *T *O *R *E/,
			amp_tok: $ => '&',
			gosub_tok: $ => /G *O *S *U *B/,
			return_tok: $ => /R *E *T *U *R *N/,
			rem_tok: $ => /R *E *M/,
			stop_tok: $ => /S *T *O *P/,
			on_tok: $ => /O *N/,
			wait_tok: $ => /W *A *I *T/,
			load_tok: $ => /L *O *A *D/,
			save_tok: $ => /S *A *V *E/,
			def_tok: $ => /D *E *F/,
			poke_tok: $ => /P *O *K *E/,
			print_tok: $ => /P *R *I *N *T/,
			cont_tok: $ => /C *O *N *T/,
			list_tok: $ => /L *I *S *T/,
			clear_tok: $ => /C *L *E *A *R/,
			get_tok: $ => /G *E *T/,
			new_tok: $ => /N *E *W/,
			tabp_tok: $ => /T *A *B *\(/,
			to_tok: $ => /T *O/,
			fn_tok: $ => /F *N/,
			spcp_tok: $ => /S *P *C *\(/,
			then_tok: $ => /T *H *E *N/,
			at_tok: $ => /A *T/,
			not_tok: $ => /N *O *T/,
			step_tok: $ => /S *T *E *P/,
			plus_tok: $ => '+',
			minus_tok: $ => '-',
			times_tok: $ => '*',
			div_tok: $ => '/',
			pow_tok: $ => '^',
			and_tok: $ => /A *N *D/,
			or_tok: $ => /O *R/,
			gtr_tok: $ => '>',
			eq_tok: $ => '=',
			less_tok: $ => '<',
			sgn_tok: $ => /S *G *N/,
			int_tok: $ => /I *N *T/,
			abs_tok: $ => /A *B *S/,
			usr_tok: $ => /U *S *R/,
			fre_tok: $ => /F *R *E/,
			scrnp_tok: $ => /S *C *R *N *\(/,
			pdl_tok: $ => /P *D *L/,
			pos_tok: $ => /P *O *S/,
			sqr_tok: $ => /S *Q *R/,
			rnd_tok: $ => /R *N *D/,
			log_tok: $ => /L *O *G/,
			exp_tok: $ => /E *X *P/,
			cos_tok: $ => /C *O *S/,
			sin_tok: $ => /S *I *N/,
			tan_tok: $ => /T *A *N/,
			atn_tok: $ => /A *TN/,
			peek_tok: $ => /P *E *E *K/,
			len_tok: $ => /L *E *N/,
			str_tok: $ => /S *T *R *\$/,
			val_tok: $ => /V *A *L/,
			asc_tok: $ => /A *S *C/,
			chr_tok: $ => /C *H *R *\$/,
			left_tok: $ => /L *E *F *T *\$/,
			right_tok: $ => /R *I *G *H *T *\$/,
			mid_tok: $ => /M *I *D *\$/,


		// Statements from Appendix A

		statement: $ => choice(
			$.assignment,
			seq($.call_tok,$._aexpr),
			$.clear_tok,
			seq($.coloreq_tok,$._aexpr),
			$.cont_tok,
			seq($.data_tok,$._data_item,repeat(seq(',',$._data_item))),
			seq($.def_tok,$.fn_tok,$.real_scalar,'(',$.real_scalar,')',$.eq_tok,$._aexpr),
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
			// the following differs from Ref. 2 in that we require the delimiter
			seq($.print_tok,optional($._expr),repeat(seq(choice(',',';'),$._expr)),optional(choice(',',';'))),
			seq($.read_tok,$._var,repeat(seq(',',$._var))),
			seq($.recall_tok,choice($.int_scalar,$.real_scalar)), // cassette tape, subscript omitted
			seq($.rem_tok,/.*/),
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
			seq($.xdraw_tok,$._aexpr,optional(seq($.at_tok,$._aexpr,',',$._aexpr)))
		),

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
			seq($.fn_tok,$.real_scalar,'(',$._aexpr,')'),
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
		// following are some operator groups defined by Ref.1 but not used here
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
		_dim_item: $ => choice($.intvar,$.realvar,$.svar),

		// Literals from Appendix B

		_data_item: $ => choice($.string,$.real,$.integer,$.literal,$.real_data_item),
		integer: $ => token(prec(1,INTEGER)),
		// Unlike Ref. 2 the following disallows commas
		// So far this has been needed to parse some forms of the DATA statement
		literal: $ => token(prec(0,repeat1(DCHAR))),
		real: $ => token(prec(1,choice(REAL_DOT,REAL_E))),
		real_data_item: $ => token(prec(1,REAL_DATA)),
		string: $ => token(prec(1,seq('"',repeat(SCHAR),'"'))),

		// Items not in Appendix B added for convenience
		// These are involved with the keyword exclusion scanner

		_name: $ => seq($._ext_name,$._ext_name), // two stage external lexer
		real_scalar: $ => $._name,
		_real_scalar: $ => $._name,
		int_scalar: $ => seq($._name,'%'),
		_int_scalar: $ => seq($._name,'%'),
		_string_scalar: $ => seq($._name,'$'),
		_real_array: $ => seq($._name,$.subscript),
		_int_array: $ => seq($._name,'%',$.subscript),
		_string_array: $ => seq($._name,'$',$.subscript)
	}
});
