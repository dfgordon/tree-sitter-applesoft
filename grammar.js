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

		end_tok: $ => token(prec(2,/E *N *D/)),
		for_tok: $ => token(prec(2,/F *O *R/)),
		next_tok: $ => token(prec(2,/N *E *X *T/)),
		data_tok: $ => token(prec(2,/D *A *T *A/)),
		input_tok: $ => token(prec(2,/I *N *P *U *T/)),
		del_tok: $ => token(prec(2,/D *E *L/)),
		dim_tok: $ => token(prec(2,/D *I *M/)),
		read_tok: $ => token(prec(2,/R *E *A *D/)),
		gr_tok: $ => token(prec(2,/G *R/)),
		text_tok: $ => token(prec(2,/T *E *X *T/)),
		prn_tok: $ => token(prec(2,/P *R *#/)),
		inn_tok: $ => token(prec(2,/I *N *#/)),
		call_tok: $ => token(prec(2,/C *A *L *L/)),
		plot_tok: $ => token(prec(2,/P *L *O *T/)),
		hlin_tok: $ => token(prec(2,/H *L *I *N/)),
		vlin_tok: $ => token(prec(2,/V *L *I *N/)),
		hgr2_tok: $ => token(prec(2,/H *G *R *2/)),
		hgr_tok: $ => token(prec(2,/H *G *R/)),
		hcoloreq_tok: $ => token(prec(2,/H *C *O *L *O *R *=/)),
		hplot_tok: $ => token(prec(2,/H *P *L *O *T/)),
		draw_tok: $ => token(prec(2,/D *R *A *W/)),
		xdraw_tok: $ => token(prec(2,/X *D *R *A *W/)),
		htab_tok: $ => token(prec(2,/H *T *A *B/)),
		home_tok: $ => token(prec(2,/H *O *M *E/)),
		roteq_tok: $ => token(prec(2,/R *O *T *=/)),
		scaleeq_tok: $ => token(prec(2,/S *C *A *L *E *=/)),
		shload_tok: $ => token(prec(2,/S *H *L *O *A *D/)),
		trace_tok: $ => token(prec(2,/T *R *A *C *E/)),
		notrace_tok: $ => token(prec(2,/N *O *T *R *A *C *E/)),
		normal_tok: $ => token(prec(2,/N *O *R *M *A *L/)),
		inverse_tok: $ => token(prec(2,/I *N *V *E *R *S *E/)),
		flash_tok: $ => token(prec(2,/F *L *A *S *H/)),
		coloreq_tok: $ => token(prec(2,/C *O *L *O *R *=/)),
		pop_tok: $ => token(prec(2,/P *O *P/)),
		vtab_tok: $ => token(prec(2,/V *T *A *B/)),
		himem_tok: $ => token(prec(2,/H *I *M *E *M *:/)),
		lomem_tok: $ => token(prec(2,/L *O *M *E *M *:/)),
		onerr_tok: $ => token(prec(2,/O *N *E *R *R/)),
		resume_tok: $ => token(prec(2,/R *E *S *U *M *E/)),
		recall_tok: $ => token(prec(2,/R *E *C *A *L *L/)),
		store_tok: $ => token(prec(2,/S *T *O *R *E/)),
		speedeq_tok: $ => token(prec(2,/S *P *E *E *D *=/)),
		let_tok: $ => token(prec(2,/L *E *T/)),
		goto_tok: $ => token(prec(2,/G *O *T *O/)),
		run_tok: $ => token(prec(2,/R *U *N/)),
		if_tok: $ => token(prec(2,/I *F/)),
		restore_tok: $ => token(prec(2,/R *E *S *T *O *R *E/)),
		amp_tok: $ => token(prec(2,'&')),
		gosub_tok: $ => token(prec(2,/G *O *S *U *B/)),
		return_tok: $ => token(prec(2,/R *E *T *U *R *N/)),
		rem_tok: $ => token(prec(2,/R *E *M/)),
		stop_tok: $ => token(prec(2,/S *T *O *P/)),
		on_tok: $ => token(prec(2,/O *N/)),
		wait_tok: $ => token(prec(2,/W *A *I *T/)),
		load_tok: $ => token(prec(2,/L *O *A *D/)),
		save_tok: $ => token(prec(2,/S *A *V *E/)),
		def_tok: $ => token(prec(2,/D *E *F/)),
		poke_tok: $ => token(prec(2,/P *O *K *E/)),
		print_tok: $ => token(prec(2,/P *R *I *N *T/)),
		cont_tok: $ => token(prec(2,/C *O *N *T/)),
		list_tok: $ => token(prec(2,/L *I *S *T/)),
		clear_tok: $ => token(prec(2,/C *L *E *A *R/)),
		get_tok: $ => token(prec(2,/G *E *T/)),
		new_tok: $ => token(prec(2,/N *E *W/)),
		tab_tok: $ => token(prec(2,/T *A *B/)),
		to_tok: $ => token(prec(2,/T *O/)),
		fn_tok: $ => token(prec(2,/F *N/)),
		spc_tok: $ => token(prec(2,/S *P *C/)),
		then_tok: $ => token(prec(2,/T *H *E *N/)),
		at_tok: $ => token(prec(2,/A *T/)),
		not_tok: $ => token(prec(2,/N *O *T/)),
		step_tok: $ => token(prec(2,/S *T *E *P/)),
		plus_tok: $ => token(prec(2,'+')),
		minus_tok: $ => token(prec(2,'-')),
		times_tok: $ => token(prec(2,'*')),
		div_tok: $ => token(prec(2,'/')),
		pow_tok: $ => token(prec(2,'^')),
		and_tok: $ => token(prec(2,/A *N *D/)),
		or_tok: $ => token(prec(2,/O *R/)),
		gtr_tok: $ => token(prec(2,'>')),
		eq_tok: $ => token(prec(2,'=')),
		less_tok: $ => token(prec(2,'<')),
		sgn_tok: $ => token(prec(2,/S *G *N/)),
		int_tok: $ => token(prec(2,/I *N *T/)),
		abs_tok: $ => token(prec(2,/A *B *S/)),
		usr_tok: $ => token(prec(2,/U *S *R/)),
		fre_tok: $ => token(prec(2,/F *R *E/)),
		scrn_tok: $ => token(prec(2,/S *C *R *N/)),
		pdl_tok: $ => token(prec(2,/P *D *L/)),
		pos_tok: $ => token(prec(2,/P *O *S/)),
		sqr_tok: $ => token(prec(2,/S *Q *R/)),
		rnd_tok: $ => token(prec(2,/R *N *D/)),
		log_tok: $ => token(prec(2,/L *O *G/)),
		exp_tok: $ => token(prec(2,/E *X *P/)),
		cos_tok: $ => token(prec(2,/C *O *S/)),
		sin_tok: $ => token(prec(2,/S *I *N/)),
		tan_tok: $ => token(prec(2,/T *A *N/)),
		atn_tok: $ => token(prec(2,/A *T *N/)),
		peek_tok: $ => token(prec(2,/P *E *E *K/)),
		len_tok: $ => token(prec(2,/L *E *N/)),
		str_tok: $ => token(prec(2,/S *T *R *\$/)),
		val_tok: $ => token(prec(2,/V *A *L/)),
		asc_tok: $ => token(prec(2,/A *S *C/)),
		chr_tok: $ => token(prec(2,/C *H *R *\$/)),
		left_tok: $ => token(prec(2,/L *E *F *T *\$/)),
		right_tok: $ => token(prec(2,/R *I *G *H *T *\$/)),
		mid_tok: $ => token(prec(2,/M *I *D *\$/)),


		// Statements from Appendix A

		statement: $ => choice(
			$.assignment,
			seq($.call_tok,$._aexpr),
			$.clear_tok,
			seq($.coloreq_tok,$._aexpr),
			seq($.data_tok,$._data_item,repeat(seq(',',$._data_item))),
			seq($.def_tok,$.fn_tok,$.real_scalar,'(',$.real_scalar,')',$.eq_tok,$._aexpr),
			//seq($.del_tok,$.linenum,',',$.linenum),
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
			seq($.hplot_tok,$._aexpr,',',$._aexpr,optional(seq($.to_tok,$._aexpr,',',$._aexpr))),
			seq($.htab_tok,$._aexpr),
			// Ref. 2 explicitly has the compound statement, but this is implied
			seq($.if_tok,$._expr,$.then_tok,$.statement),
			seq($.if_tok,$._expr,$.then_tok,$.linenum),
			seq($.if_tok,$._expr,$.goto_tok,$.linenum),
			seq($.inn_tok,$._aexpr),
			seq($.input_tok,optional(seq($._sexpr,';')),$._var,repeat(seq(',',$._var))),
			$.inverse_tok,
			//seq($.list_tok,optional($.linenum),optional(seq(choice($.minus_tok,','),$.linenum))),
			seq($.lomem_tok,$._aexpr),
			//$.new_tok,
			seq($.next_tok,optional(seq($._avar,repeat(seq(',',$._avar))))),
			$.normal_tok,
			//$.notrace_tok,
			seq($.on_tok,$._aexpr,choice($.goto_tok,$.gosub_tok),$.linenum,repeat(seq(',',$.linenum))),
			seq($.onerr_tok,$.goto_tok,$.linenum),
			seq($.plot_tok,$._aexpr,',',$._aexpr),
			seq($.poke_tok,$._aexpr,',',$._aexpr),
			$.pop_tok,
			seq($.prn_tok,$._aexpr),
			// following differs from the reference, which seems to allow dropping the delimiter
			seq($.print_tok,optional($._expr),repeat(seq(choice(',',';'),$._expr)),optional(';')),
			seq($.read_tok,$._var,repeat(seq(',',$._var))),
			seq($.rem_tok,repeat(CHARACTER)),
			$.restore_tok,
			$.resume_tok,
			$.return_tok,
			seq($.roteq_tok,$._aexpr),
			//seq($.run_tok,optional(choice($.linenum,NAME))),
			seq($.scaleeq_tok,$._aexpr),
			seq($.speedeq_tok,$._aexpr),
			$.stop_tok,
			$.text_tok,
			//$.trace_tok,
			seq($.usr_tok,'(',$._aexpr,')'),
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

		// following is the general fcall from Ref. 2 (not used)
		//fcall: $=> seq(NAME,'(',repeat(seq($._expr,',')),$._expr,')'),
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
			seq($.scrn_tok,'(',$._aexpr,',',$._aexpr,')'),
			seq($.sgn_tok,'(',$._aexpr,')'),
			seq($.sin_tok,'(',$._aexpr,')'),
			seq($.sqr_tok,'(',$._aexpr,')'),
			seq($.tan_tok,'(',$._aexpr,')'),
			seq($.val_tok,'(',$._sexpr,')')
		),

		// String functions from Appendix A

		// following is the general sfcall from Ref. 2 (not used)
		//sfcall: $ => seq(NAME,'$','(',repeat(seq($._expr,',')),$._expr,')'),
		sfcall: $ => choice(
			seq($.chr_tok,'(',$._aexpr,')'),
			seq($.left_tok,'(',$._sexpr,',',$._aexpr,')'),
			seq($.mid_tok,'(',$._sexpr,',',$._aexpr,optional(seq(',',$._aexpr)),')'),
			seq($.right_tok,'(',$._sexpr,',',$._aexpr,')'),
			seq($.spc_tok,'(',$._aexpr,')'),
			seq($.str_tok,'(',$._aexpr,')'),
			seq($.tab_tok,'(',$._aexpr,')')
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
