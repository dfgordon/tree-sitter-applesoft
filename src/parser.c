#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#ifdef _MSC_VER
#pragma optimize("", off)
#elif defined(__clang__)
#pragma clang optimize off
#elif defined(__GNUC__)
#pragma GCC optimize ("O0")
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 223
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 147
#define ALIAS_COUNT 0
#define TOKEN_COUNT 113
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 8
#define PRODUCTION_ID_COUNT 1

enum {
  sym_end_tok = 1,
  sym_for_tok = 2,
  sym_next_tok = 3,
  sym_data_tok = 4,
  sym_input_tok = 5,
  sym_dim_tok = 6,
  sym_read_tok = 7,
  sym_gr_tok = 8,
  sym_text_tok = 9,
  sym_prn_tok = 10,
  sym_inn_tok = 11,
  sym_call_tok = 12,
  sym_plot_tok = 13,
  sym_hlin_tok = 14,
  sym_vlin_tok = 15,
  sym_hgr2_tok = 16,
  sym_hgr_tok = 17,
  sym_hcoloreq_tok = 18,
  sym_hplot_tok = 19,
  sym_draw_tok = 20,
  sym_xdraw_tok = 21,
  sym_htab_tok = 22,
  sym_home_tok = 23,
  sym_roteq_tok = 24,
  sym_scaleeq_tok = 25,
  sym_normal_tok = 26,
  sym_inverse_tok = 27,
  sym_flash_tok = 28,
  sym_coloreq_tok = 29,
  sym_pop_tok = 30,
  sym_vtab_tok = 31,
  sym_himem_tok = 32,
  sym_lomem_tok = 33,
  sym_onerr_tok = 34,
  sym_resume_tok = 35,
  sym_speedeq_tok = 36,
  sym_let_tok = 37,
  sym_goto_tok = 38,
  sym_if_tok = 39,
  sym_restore_tok = 40,
  sym_amp_tok = 41,
  sym_gosub_tok = 42,
  sym_return_tok = 43,
  sym_rem_tok = 44,
  sym_stop_tok = 45,
  sym_on_tok = 46,
  sym_wait_tok = 47,
  sym_def_tok = 48,
  sym_poke_tok = 49,
  sym_print_tok = 50,
  sym_clear_tok = 51,
  sym_get_tok = 52,
  sym_tab_tok = 53,
  sym_to_tok = 54,
  sym_fn_tok = 55,
  sym_spc_tok = 56,
  sym_then_tok = 57,
  sym_at_tok = 58,
  sym_not_tok = 59,
  sym_step_tok = 60,
  sym_plus_tok = 61,
  sym_minus_tok = 62,
  sym_times_tok = 63,
  sym_div_tok = 64,
  sym_pow_tok = 65,
  sym_and_tok = 66,
  sym_or_tok = 67,
  sym_gtr_tok = 68,
  sym_eq_tok = 69,
  sym_less_tok = 70,
  sym_sgn_tok = 71,
  sym_int_tok = 72,
  sym_abs_tok = 73,
  sym_usr_tok = 74,
  sym_fre_tok = 75,
  sym_scrn_tok = 76,
  sym_pdl_tok = 77,
  sym_pos_tok = 78,
  sym_sqr_tok = 79,
  sym_rnd_tok = 80,
  sym_log_tok = 81,
  sym_exp_tok = 82,
  sym_cos_tok = 83,
  sym_sin_tok = 84,
  sym_tan_tok = 85,
  sym_atn_tok = 86,
  sym_peek_tok = 87,
  sym_len_tok = 88,
  sym_str_tok = 89,
  sym_val_tok = 90,
  sym_asc_tok = 91,
  sym_chr_tok = 92,
  sym_left_tok = 93,
  sym_right_tok = 94,
  sym_mid_tok = 95,
  anon_sym_COMMA = 96,
  anon_sym_LPAREN = 97,
  anon_sym_RPAREN = 98,
  anon_sym_SEMI = 99,
  aux_sym_statement_token1 = 100,
  anon_sym_COLON = 101,
  anon_sym_LF = 102,
  sym__empty_line = 103,
  sym_linenum = 104,
  sym_real_scalar = 105,
  aux_sym_intvar_token1 = 106,
  anon_sym_PERCENT = 107,
  anon_sym_DOLLAR = 108,
  sym_integer = 109,
  sym_literal = 110,
  sym_real = 111,
  sym_string = 112,
  sym_source_file = 113,
  sym_statement = 114,
  sym_assignment = 115,
  sym_fcall = 116,
  sym_sfcall = 117,
  sym_line = 118,
  sym__expr = 119,
  sym__aexpr = 120,
  sym_unary_aexpr = 121,
  sym_binary_aexpr = 122,
  sym__parenthesized_aexpr = 123,
  sym__relop = 124,
  sym__sexpr = 125,
  sym_binary_sexpr = 126,
  sym__parenthesized_sexpr = 127,
  sym__sop = 128,
  sym__var = 129,
  sym__avar = 130,
  sym_intvar = 131,
  sym_realvar = 132,
  sym_svar = 133,
  sym_subscript = 134,
  sym__dim_item = 135,
  sym__data_item = 136,
  aux_sym_source_file_repeat1 = 137,
  aux_sym_statement_repeat1 = 138,
  aux_sym_statement_repeat2 = 139,
  aux_sym_statement_repeat3 = 140,
  aux_sym_statement_repeat4 = 141,
  aux_sym_statement_repeat5 = 142,
  aux_sym_statement_repeat6 = 143,
  aux_sym_statement_repeat7 = 144,
  aux_sym_line_repeat1 = 145,
  aux_sym_subscript_repeat1 = 146,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_end_tok] = "end_tok",
  [sym_for_tok] = "for_tok",
  [sym_next_tok] = "next_tok",
  [sym_data_tok] = "data_tok",
  [sym_input_tok] = "input_tok",
  [sym_dim_tok] = "dim_tok",
  [sym_read_tok] = "read_tok",
  [sym_gr_tok] = "gr_tok",
  [sym_text_tok] = "text_tok",
  [sym_prn_tok] = "prn_tok",
  [sym_inn_tok] = "inn_tok",
  [sym_call_tok] = "call_tok",
  [sym_plot_tok] = "plot_tok",
  [sym_hlin_tok] = "hlin_tok",
  [sym_vlin_tok] = "vlin_tok",
  [sym_hgr2_tok] = "hgr2_tok",
  [sym_hgr_tok] = "hgr_tok",
  [sym_hcoloreq_tok] = "hcoloreq_tok",
  [sym_hplot_tok] = "hplot_tok",
  [sym_draw_tok] = "draw_tok",
  [sym_xdraw_tok] = "xdraw_tok",
  [sym_htab_tok] = "htab_tok",
  [sym_home_tok] = "home_tok",
  [sym_roteq_tok] = "roteq_tok",
  [sym_scaleeq_tok] = "scaleeq_tok",
  [sym_normal_tok] = "normal_tok",
  [sym_inverse_tok] = "inverse_tok",
  [sym_flash_tok] = "flash_tok",
  [sym_coloreq_tok] = "coloreq_tok",
  [sym_pop_tok] = "pop_tok",
  [sym_vtab_tok] = "vtab_tok",
  [sym_himem_tok] = "himem_tok",
  [sym_lomem_tok] = "lomem_tok",
  [sym_onerr_tok] = "onerr_tok",
  [sym_resume_tok] = "resume_tok",
  [sym_speedeq_tok] = "speedeq_tok",
  [sym_let_tok] = "let_tok",
  [sym_goto_tok] = "goto_tok",
  [sym_if_tok] = "if_tok",
  [sym_restore_tok] = "restore_tok",
  [sym_amp_tok] = "amp_tok",
  [sym_gosub_tok] = "gosub_tok",
  [sym_return_tok] = "return_tok",
  [sym_rem_tok] = "rem_tok",
  [sym_stop_tok] = "stop_tok",
  [sym_on_tok] = "on_tok",
  [sym_wait_tok] = "wait_tok",
  [sym_def_tok] = "def_tok",
  [sym_poke_tok] = "poke_tok",
  [sym_print_tok] = "print_tok",
  [sym_clear_tok] = "clear_tok",
  [sym_get_tok] = "get_tok",
  [sym_tab_tok] = "tab_tok",
  [sym_to_tok] = "to_tok",
  [sym_fn_tok] = "fn_tok",
  [sym_spc_tok] = "spc_tok",
  [sym_then_tok] = "then_tok",
  [sym_at_tok] = "at_tok",
  [sym_not_tok] = "not_tok",
  [sym_step_tok] = "step_tok",
  [sym_plus_tok] = "plus_tok",
  [sym_minus_tok] = "minus_tok",
  [sym_times_tok] = "times_tok",
  [sym_div_tok] = "div_tok",
  [sym_pow_tok] = "pow_tok",
  [sym_and_tok] = "and_tok",
  [sym_or_tok] = "or_tok",
  [sym_gtr_tok] = "gtr_tok",
  [sym_eq_tok] = "eq_tok",
  [sym_less_tok] = "less_tok",
  [sym_sgn_tok] = "sgn_tok",
  [sym_int_tok] = "int_tok",
  [sym_abs_tok] = "abs_tok",
  [sym_usr_tok] = "usr_tok",
  [sym_fre_tok] = "fre_tok",
  [sym_scrn_tok] = "scrn_tok",
  [sym_pdl_tok] = "pdl_tok",
  [sym_pos_tok] = "pos_tok",
  [sym_sqr_tok] = "sqr_tok",
  [sym_rnd_tok] = "rnd_tok",
  [sym_log_tok] = "log_tok",
  [sym_exp_tok] = "exp_tok",
  [sym_cos_tok] = "cos_tok",
  [sym_sin_tok] = "sin_tok",
  [sym_tan_tok] = "tan_tok",
  [sym_atn_tok] = "atn_tok",
  [sym_peek_tok] = "peek_tok",
  [sym_len_tok] = "len_tok",
  [sym_str_tok] = "str_tok",
  [sym_val_tok] = "val_tok",
  [sym_asc_tok] = "asc_tok",
  [sym_chr_tok] = "chr_tok",
  [sym_left_tok] = "left_tok",
  [sym_right_tok] = "right_tok",
  [sym_mid_tok] = "mid_tok",
  [anon_sym_COMMA] = ",",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_SEMI] = ";",
  [aux_sym_statement_token1] = "statement_token1",
  [anon_sym_COLON] = ":",
  [anon_sym_LF] = "\n",
  [sym__empty_line] = "_empty_line",
  [sym_linenum] = "linenum",
  [sym_real_scalar] = "real_scalar",
  [aux_sym_intvar_token1] = "intvar_token1",
  [anon_sym_PERCENT] = "%",
  [anon_sym_DOLLAR] = "$",
  [sym_integer] = "integer",
  [sym_literal] = "literal",
  [sym_real] = "real",
  [sym_string] = "string",
  [sym_source_file] = "source_file",
  [sym_statement] = "statement",
  [sym_assignment] = "assignment",
  [sym_fcall] = "fcall",
  [sym_sfcall] = "sfcall",
  [sym_line] = "line",
  [sym__expr] = "_expr",
  [sym__aexpr] = "_aexpr",
  [sym_unary_aexpr] = "unary_aexpr",
  [sym_binary_aexpr] = "binary_aexpr",
  [sym__parenthesized_aexpr] = "_parenthesized_aexpr",
  [sym__relop] = "_relop",
  [sym__sexpr] = "_sexpr",
  [sym_binary_sexpr] = "binary_sexpr",
  [sym__parenthesized_sexpr] = "_parenthesized_sexpr",
  [sym__sop] = "_sop",
  [sym__var] = "_var",
  [sym__avar] = "_avar",
  [sym_intvar] = "intvar",
  [sym_realvar] = "realvar",
  [sym_svar] = "svar",
  [sym_subscript] = "subscript",
  [sym__dim_item] = "_dim_item",
  [sym__data_item] = "_data_item",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_statement_repeat1] = "statement_repeat1",
  [aux_sym_statement_repeat2] = "statement_repeat2",
  [aux_sym_statement_repeat3] = "statement_repeat3",
  [aux_sym_statement_repeat4] = "statement_repeat4",
  [aux_sym_statement_repeat5] = "statement_repeat5",
  [aux_sym_statement_repeat6] = "statement_repeat6",
  [aux_sym_statement_repeat7] = "statement_repeat7",
  [aux_sym_line_repeat1] = "line_repeat1",
  [aux_sym_subscript_repeat1] = "subscript_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_end_tok] = sym_end_tok,
  [sym_for_tok] = sym_for_tok,
  [sym_next_tok] = sym_next_tok,
  [sym_data_tok] = sym_data_tok,
  [sym_input_tok] = sym_input_tok,
  [sym_dim_tok] = sym_dim_tok,
  [sym_read_tok] = sym_read_tok,
  [sym_gr_tok] = sym_gr_tok,
  [sym_text_tok] = sym_text_tok,
  [sym_prn_tok] = sym_prn_tok,
  [sym_inn_tok] = sym_inn_tok,
  [sym_call_tok] = sym_call_tok,
  [sym_plot_tok] = sym_plot_tok,
  [sym_hlin_tok] = sym_hlin_tok,
  [sym_vlin_tok] = sym_vlin_tok,
  [sym_hgr2_tok] = sym_hgr2_tok,
  [sym_hgr_tok] = sym_hgr_tok,
  [sym_hcoloreq_tok] = sym_hcoloreq_tok,
  [sym_hplot_tok] = sym_hplot_tok,
  [sym_draw_tok] = sym_draw_tok,
  [sym_xdraw_tok] = sym_xdraw_tok,
  [sym_htab_tok] = sym_htab_tok,
  [sym_home_tok] = sym_home_tok,
  [sym_roteq_tok] = sym_roteq_tok,
  [sym_scaleeq_tok] = sym_scaleeq_tok,
  [sym_normal_tok] = sym_normal_tok,
  [sym_inverse_tok] = sym_inverse_tok,
  [sym_flash_tok] = sym_flash_tok,
  [sym_coloreq_tok] = sym_coloreq_tok,
  [sym_pop_tok] = sym_pop_tok,
  [sym_vtab_tok] = sym_vtab_tok,
  [sym_himem_tok] = sym_himem_tok,
  [sym_lomem_tok] = sym_lomem_tok,
  [sym_onerr_tok] = sym_onerr_tok,
  [sym_resume_tok] = sym_resume_tok,
  [sym_speedeq_tok] = sym_speedeq_tok,
  [sym_let_tok] = sym_let_tok,
  [sym_goto_tok] = sym_goto_tok,
  [sym_if_tok] = sym_if_tok,
  [sym_restore_tok] = sym_restore_tok,
  [sym_amp_tok] = sym_amp_tok,
  [sym_gosub_tok] = sym_gosub_tok,
  [sym_return_tok] = sym_return_tok,
  [sym_rem_tok] = sym_rem_tok,
  [sym_stop_tok] = sym_stop_tok,
  [sym_on_tok] = sym_on_tok,
  [sym_wait_tok] = sym_wait_tok,
  [sym_def_tok] = sym_def_tok,
  [sym_poke_tok] = sym_poke_tok,
  [sym_print_tok] = sym_print_tok,
  [sym_clear_tok] = sym_clear_tok,
  [sym_get_tok] = sym_get_tok,
  [sym_tab_tok] = sym_tab_tok,
  [sym_to_tok] = sym_to_tok,
  [sym_fn_tok] = sym_fn_tok,
  [sym_spc_tok] = sym_spc_tok,
  [sym_then_tok] = sym_then_tok,
  [sym_at_tok] = sym_at_tok,
  [sym_not_tok] = sym_not_tok,
  [sym_step_tok] = sym_step_tok,
  [sym_plus_tok] = sym_plus_tok,
  [sym_minus_tok] = sym_minus_tok,
  [sym_times_tok] = sym_times_tok,
  [sym_div_tok] = sym_div_tok,
  [sym_pow_tok] = sym_pow_tok,
  [sym_and_tok] = sym_and_tok,
  [sym_or_tok] = sym_or_tok,
  [sym_gtr_tok] = sym_gtr_tok,
  [sym_eq_tok] = sym_eq_tok,
  [sym_less_tok] = sym_less_tok,
  [sym_sgn_tok] = sym_sgn_tok,
  [sym_int_tok] = sym_int_tok,
  [sym_abs_tok] = sym_abs_tok,
  [sym_usr_tok] = sym_usr_tok,
  [sym_fre_tok] = sym_fre_tok,
  [sym_scrn_tok] = sym_scrn_tok,
  [sym_pdl_tok] = sym_pdl_tok,
  [sym_pos_tok] = sym_pos_tok,
  [sym_sqr_tok] = sym_sqr_tok,
  [sym_rnd_tok] = sym_rnd_tok,
  [sym_log_tok] = sym_log_tok,
  [sym_exp_tok] = sym_exp_tok,
  [sym_cos_tok] = sym_cos_tok,
  [sym_sin_tok] = sym_sin_tok,
  [sym_tan_tok] = sym_tan_tok,
  [sym_atn_tok] = sym_atn_tok,
  [sym_peek_tok] = sym_peek_tok,
  [sym_len_tok] = sym_len_tok,
  [sym_str_tok] = sym_str_tok,
  [sym_val_tok] = sym_val_tok,
  [sym_asc_tok] = sym_asc_tok,
  [sym_chr_tok] = sym_chr_tok,
  [sym_left_tok] = sym_left_tok,
  [sym_right_tok] = sym_right_tok,
  [sym_mid_tok] = sym_mid_tok,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [aux_sym_statement_token1] = aux_sym_statement_token1,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_LF] = anon_sym_LF,
  [sym__empty_line] = sym__empty_line,
  [sym_linenum] = sym_linenum,
  [sym_real_scalar] = sym_real_scalar,
  [aux_sym_intvar_token1] = aux_sym_intvar_token1,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [anon_sym_DOLLAR] = anon_sym_DOLLAR,
  [sym_integer] = sym_integer,
  [sym_literal] = sym_literal,
  [sym_real] = sym_real,
  [sym_string] = sym_string,
  [sym_source_file] = sym_source_file,
  [sym_statement] = sym_statement,
  [sym_assignment] = sym_assignment,
  [sym_fcall] = sym_fcall,
  [sym_sfcall] = sym_sfcall,
  [sym_line] = sym_line,
  [sym__expr] = sym__expr,
  [sym__aexpr] = sym__aexpr,
  [sym_unary_aexpr] = sym_unary_aexpr,
  [sym_binary_aexpr] = sym_binary_aexpr,
  [sym__parenthesized_aexpr] = sym__parenthesized_aexpr,
  [sym__relop] = sym__relop,
  [sym__sexpr] = sym__sexpr,
  [sym_binary_sexpr] = sym_binary_sexpr,
  [sym__parenthesized_sexpr] = sym__parenthesized_sexpr,
  [sym__sop] = sym__sop,
  [sym__var] = sym__var,
  [sym__avar] = sym__avar,
  [sym_intvar] = sym_intvar,
  [sym_realvar] = sym_realvar,
  [sym_svar] = sym_svar,
  [sym_subscript] = sym_subscript,
  [sym__dim_item] = sym__dim_item,
  [sym__data_item] = sym__data_item,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_statement_repeat1] = aux_sym_statement_repeat1,
  [aux_sym_statement_repeat2] = aux_sym_statement_repeat2,
  [aux_sym_statement_repeat3] = aux_sym_statement_repeat3,
  [aux_sym_statement_repeat4] = aux_sym_statement_repeat4,
  [aux_sym_statement_repeat5] = aux_sym_statement_repeat5,
  [aux_sym_statement_repeat6] = aux_sym_statement_repeat6,
  [aux_sym_statement_repeat7] = aux_sym_statement_repeat7,
  [aux_sym_line_repeat1] = aux_sym_line_repeat1,
  [aux_sym_subscript_repeat1] = aux_sym_subscript_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_end_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_for_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_next_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_data_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_input_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_dim_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_read_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_gr_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_text_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_prn_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_inn_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_call_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_plot_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_hlin_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_vlin_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_hgr2_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_hgr_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_hcoloreq_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_hplot_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_draw_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_xdraw_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_htab_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_home_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_roteq_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_scaleeq_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_normal_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_inverse_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_flash_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_coloreq_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_pop_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_vtab_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_himem_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_lomem_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_onerr_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_resume_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_speedeq_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_let_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_goto_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_if_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_restore_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_amp_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_gosub_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_return_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_rem_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_stop_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_on_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_wait_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_def_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_poke_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_print_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_clear_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_get_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_tab_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_to_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_fn_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_spc_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_then_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_at_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_not_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_step_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_plus_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_minus_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_times_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_div_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_pow_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_and_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_or_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_gtr_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_eq_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_less_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_sgn_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_int_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_abs_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_usr_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_fre_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_scrn_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_pdl_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_pos_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_sqr_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_rnd_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_log_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_exp_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_cos_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_sin_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_tan_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_atn_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_peek_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_len_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_str_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_val_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_asc_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_chr_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_left_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_right_tok] = {
    .visible = true,
    .named = true,
  },
  [sym_mid_tok] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_statement_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LF] = {
    .visible = true,
    .named = false,
  },
  [sym__empty_line] = {
    .visible = false,
    .named = true,
  },
  [sym_linenum] = {
    .visible = true,
    .named = true,
  },
  [sym_real_scalar] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_intvar_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOLLAR] = {
    .visible = true,
    .named = false,
  },
  [sym_integer] = {
    .visible = true,
    .named = true,
  },
  [sym_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_real] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_assignment] = {
    .visible = true,
    .named = true,
  },
  [sym_fcall] = {
    .visible = true,
    .named = true,
  },
  [sym_sfcall] = {
    .visible = true,
    .named = true,
  },
  [sym_line] = {
    .visible = true,
    .named = true,
  },
  [sym__expr] = {
    .visible = false,
    .named = true,
  },
  [sym__aexpr] = {
    .visible = false,
    .named = true,
  },
  [sym_unary_aexpr] = {
    .visible = true,
    .named = true,
  },
  [sym_binary_aexpr] = {
    .visible = true,
    .named = true,
  },
  [sym__parenthesized_aexpr] = {
    .visible = false,
    .named = true,
  },
  [sym__relop] = {
    .visible = false,
    .named = true,
  },
  [sym__sexpr] = {
    .visible = false,
    .named = true,
  },
  [sym_binary_sexpr] = {
    .visible = true,
    .named = true,
  },
  [sym__parenthesized_sexpr] = {
    .visible = false,
    .named = true,
  },
  [sym__sop] = {
    .visible = false,
    .named = true,
  },
  [sym__var] = {
    .visible = false,
    .named = true,
  },
  [sym__avar] = {
    .visible = false,
    .named = true,
  },
  [sym_intvar] = {
    .visible = true,
    .named = true,
  },
  [sym_realvar] = {
    .visible = true,
    .named = true,
  },
  [sym_svar] = {
    .visible = true,
    .named = true,
  },
  [sym_subscript] = {
    .visible = true,
    .named = true,
  },
  [sym__dim_item] = {
    .visible = false,
    .named = true,
  },
  [sym__data_item] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_statement_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_statement_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_statement_repeat3] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_statement_repeat4] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_statement_repeat5] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_statement_repeat6] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_statement_repeat7] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_line_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_subscript_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(205);
      if (lookahead == '\n') ADVANCE(309);
      if (lookahead == ' ') ADVANCE(1);
      if (lookahead == '"') ADVANCE(203);
      if (lookahead == '$') ADVANCE(494);
      if (lookahead == '%') ADVANCE(493);
      if (lookahead == '&') ADVANCE(246);
      if (lookahead == '(') ADVANCE(303);
      if (lookahead == ')') ADVANCE(304);
      if (lookahead == '*') ADVANCE(269);
      if (lookahead == '+') ADVANCE(267);
      if (lookahead == ',') ADVANCE(302);
      if (lookahead == '-') ADVANCE(268);
      if (lookahead == '/') ADVANCE(270);
      if (lookahead == ':') ADVANCE(308);
      if (lookahead == ';') ADVANCE(305);
      if (lookahead == '<') ADVANCE(276);
      if (lookahead == '=') ADVANCE(275);
      if (lookahead == '>') ADVANCE(274);
      if (lookahead == '^') ADVANCE(271);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(495);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(313);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(309);
      if (lookahead == ' ') ADVANCE(1);
      if (lookahead == '"') ADVANCE(203);
      if (lookahead == '$') ADVANCE(494);
      if (lookahead == '%') ADVANCE(493);
      if (lookahead == '&') ADVANCE(246);
      if (lookahead == '(') ADVANCE(303);
      if (lookahead == ')') ADVANCE(304);
      if (lookahead == '*') ADVANCE(269);
      if (lookahead == '+') ADVANCE(267);
      if (lookahead == ',') ADVANCE(302);
      if (lookahead == '-') ADVANCE(268);
      if (lookahead == '/') ADVANCE(270);
      if (lookahead == ':') ADVANCE(308);
      if (lookahead == ';') ADVANCE(305);
      if (lookahead == '<') ADVANCE(276);
      if (lookahead == '=') ADVANCE(275);
      if (lookahead == '>') ADVANCE(274);
      if (lookahead == '^') ADVANCE(271);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(495);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(313);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(309);
      if (lookahead == ' ') ADVANCE(2);
      if (lookahead == '"') ADVANCE(203);
      if (lookahead == '%') ADVANCE(493);
      if (lookahead == '(') ADVANCE(303);
      if (lookahead == '+') ADVANCE(267);
      if (lookahead == ',') ADVANCE(302);
      if (lookahead == '-') ADVANCE(268);
      if (lookahead == '.') ADVANCE(505);
      if (lookahead == ':') ADVANCE(308);
      if (lookahead == ';') ADVANCE(305);
      if (lookahead == '<') ADVANCE(276);
      if (lookahead == '=') ADVANCE(275);
      if (lookahead == '>') ADVANCE(274);
      if (lookahead == 'A') ADVANCE(350);
      if (lookahead == 'C') ADVANCE(351);
      if (lookahead == 'E') ADVANCE(506);
      if (lookahead == 'F') ADVANCE(352);
      if (lookahead == 'I') ADVANCE(485);
      if (lookahead == 'L') ADVANCE(403);
      if (lookahead == 'M') ADVANCE(396);
      if (lookahead == 'N') ADVANCE(488);
      if (lookahead == 'P') ADVANCE(353);
      if (lookahead == 'R') ADVANCE(354);
      if (lookahead == 'S') ADVANCE(355);
      if (lookahead == 'T') ADVANCE(459);
      if (lookahead == 'V') ADVANCE(463);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(496);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(309);
      if (lookahead == ' ') SKIP(3)
      if (lookahead == '$') ADVANCE(494);
      if (lookahead == '%') ADVANCE(493);
      if (lookahead == '(') ADVANCE(303);
      if (lookahead == ')') ADVANCE(304);
      if (lookahead == '*') ADVANCE(269);
      if (lookahead == '+') ADVANCE(267);
      if (lookahead == ',') ADVANCE(302);
      if (lookahead == '-') ADVANCE(268);
      if (lookahead == '/') ADVANCE(270);
      if (lookahead == ':') ADVANCE(308);
      if (lookahead == ';') ADVANCE(305);
      if (lookahead == '<') ADVANCE(276);
      if (lookahead == '=') ADVANCE(275);
      if (lookahead == '>') ADVANCE(274);
      if (lookahead == 'A') ADVANCE(58);
      if (lookahead == 'G') ADVANCE(141);
      if (lookahead == 'O') ADVANCE(189);
      if (lookahead == 'S') ADVANCE(184);
      if (lookahead == 'T') ADVANCE(84);
      if (lookahead == '^') ADVANCE(271);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(309);
      if (lookahead == ' ') SKIP(4)
      if (lookahead == ':') ADVANCE(308);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(309);
      if (lookahead == ' ') ADVANCE(307);
      if (lookahead == ':') ADVANCE(308);
      if (('!' <= lookahead && lookahead <= '~')) ADVANCE(306);
      END_STATE();
    case 6:
      if (lookahead == '\n') ADVANCE(310);
      if (lookahead == ' ') ADVANCE(6);
      if (lookahead == 'C') ADVANCE(314);
      if (lookahead == 'D') ADVANCE(315);
      if (lookahead == 'E') ADVANCE(316);
      if (lookahead == 'F') ADVANCE(317);
      if (lookahead == 'G') ADVANCE(318);
      if (lookahead == 'H') ADVANCE(319);
      if (lookahead == 'I') ADVANCE(320);
      if (lookahead == 'L') ADVANCE(321);
      if (lookahead == 'N') ADVANCE(364);
      if (lookahead == 'O') ADVANCE(362);
      if (lookahead == 'P') ADVANCE(322);
      if (lookahead == 'R') ADVANCE(387);
      if (lookahead == 'S') ADVANCE(323);
      if (lookahead == 'T') ADVANCE(324);
      if (lookahead == 'U') ADVANCE(325);
      if (lookahead == 'V') ADVANCE(326);
      if (lookahead == 'W') ADVANCE(327);
      if (lookahead == 'X') ADVANCE(328);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(312);
      END_STATE();
    case 7:
      if (lookahead == ' ') ADVANCE(7);
      if (lookahead == 'A') ADVANCE(22);
      if (lookahead == 'L') ADVANCE(66);
      if (lookahead == 'O') ADVANCE(70);
      END_STATE();
    case 8:
      if (lookahead == ' ') ADVANCE(8);
      if (lookahead == 'A') ADVANCE(23);
      if (lookahead == 'E') ADVANCE(24);
      if (lookahead == 'I') ADVANCE(25);
      if (lookahead == 'R') ADVANCE(68);
      END_STATE();
    case 9:
      if (lookahead == ' ') ADVANCE(9);
      if (lookahead == 'N') ADVANCE(69);
      END_STATE();
    case 10:
      if (lookahead == ' ') ADVANCE(10);
      if (lookahead == 'L') ADVANCE(92);
      if (lookahead == 'O') ADVANCE(26);
      END_STATE();
    case 11:
      if (lookahead == ' ') ADVANCE(11);
      if (lookahead == 'E') ADVANCE(71);
      if (lookahead == 'O') ADVANCE(27);
      if (lookahead == 'R') ADVANCE(213);
      END_STATE();
    case 12:
      if (lookahead == ' ') ADVANCE(12);
      if (lookahead == 'C') ADVANCE(28);
      if (lookahead == 'G') ADVANCE(74);
      if (lookahead == 'I') ADVANCE(73);
      if (lookahead == 'L') ADVANCE(29);
      if (lookahead == 'O') ADVANCE(193);
      if (lookahead == 'P') ADVANCE(192);
      if (lookahead == 'T') ADVANCE(110);
      END_STATE();
    case 13:
      if (lookahead == ' ') ADVANCE(13);
      if (lookahead == 'F') ADVANCE(244);
      if (lookahead == 'N') ADVANCE(30);
      END_STATE();
    case 14:
      if (lookahead == ' ') ADVANCE(14);
      if (lookahead == 'E') ADVANCE(95);
      if (lookahead == 'O') ADVANCE(198);
      END_STATE();
    case 15:
      if (lookahead == ' ') ADVANCE(15);
      if (lookahead == 'L') ADVANCE(75);
      if (lookahead == 'O') ADVANCE(32);
      if (lookahead == 'R') ADVANCE(33);
      END_STATE();
    case 16:
      if (lookahead == ' ') ADVANCE(16);
      if (lookahead == 'C') ADVANCE(124);
      if (lookahead == 'P') ADVANCE(108);
      if (lookahead == 'T') ADVANCE(98);
      END_STATE();
    case 17:
      if (lookahead == ' ') ADVANCE(17);
      if (lookahead == 'E') ADVANCE(191);
      END_STATE();
    case 18:
      if (lookahead == ' ') ADVANCE(18);
      if (lookahead == 'S') ADVANCE(115);
      END_STATE();
    case 19:
      if (lookahead == ' ') ADVANCE(19);
      if (lookahead == 'L') ADVANCE(190);
      if (lookahead == 'T') ADVANCE(136);
      END_STATE();
    case 20:
      if (lookahead == ' ') ADVANCE(20);
      if (lookahead == 'A') ADVANCE(76);
      END_STATE();
    case 21:
      if (lookahead == ' ') ADVANCE(21);
      if (lookahead == 'D') ADVANCE(129);
      END_STATE();
    case 22:
      if (lookahead == ' ') ADVANCE(22);
      if (lookahead == 'L') ADVANCE(94);
      END_STATE();
    case 23:
      if (lookahead == ' ') ADVANCE(23);
      if (lookahead == 'T') ADVANCE(151);
      END_STATE();
    case 24:
      if (lookahead == ' ') ADVANCE(24);
      if (lookahead == 'F') ADVANCE(254);
      END_STATE();
    case 25:
      if (lookahead == ' ') ADVANCE(25);
      if (lookahead == 'M') ADVANCE(211);
      END_STATE();
    case 26:
      if (lookahead == ' ') ADVANCE(26);
      if (lookahead == 'R') ADVANCE(207);
      END_STATE();
    case 27:
      if (lookahead == ' ') ADVANCE(27);
      if (lookahead == 'S') ADVANCE(36);
      if (lookahead == 'T') ADVANCE(130);
      END_STATE();
    case 28:
      if (lookahead == ' ') ADVANCE(28);
      if (lookahead == 'O') ADVANCE(202);
      END_STATE();
    case 29:
      if (lookahead == ' ') ADVANCE(29);
      if (lookahead == 'I') ADVANCE(88);
      END_STATE();
    case 30:
      if (lookahead == ' ') ADVANCE(30);
      if (lookahead == '#') ADVANCE(216);
      if (lookahead == 'P') ADVANCE(78);
      if (lookahead == 'V') ADVANCE(195);
      END_STATE();
    case 31:
      if (lookahead == ' ') ADVANCE(31);
      if (lookahead == 'X') ADVANCE(127);
      END_STATE();
    case 32:
      if (lookahead == ' ') ADVANCE(32);
      if (lookahead == 'K') ADVANCE(150);
      if (lookahead == 'P') ADVANCE(235);
      END_STATE();
    case 33:
      if (lookahead == ' ') ADVANCE(33);
      if (lookahead == '#') ADVANCE(215);
      if (lookahead == 'I') ADVANCE(106);
      END_STATE();
    case 34:
      if (lookahead == ' ') ADVANCE(34);
      if (lookahead == 'A') ADVANCE(93);
      if (lookahead == 'M') ADVANCE(249);
      if (lookahead == 'S') ADVANCE(39);
      if (lookahead == 'T') ADVANCE(100);
      END_STATE();
    case 35:
      if (lookahead == ' ') ADVANCE(35);
      if (lookahead == 'W') ADVANCE(225);
      END_STATE();
    case 36:
      if (lookahead == ' ') ADVANCE(36);
      if (lookahead == 'U') ADVANCE(101);
      END_STATE();
    case 37:
      if (lookahead == ' ') ADVANCE(37);
      if (lookahead == 'B') ADVANCE(227);
      END_STATE();
    case 38:
      if (lookahead == ' ') ADVANCE(38);
      if (lookahead == '2') ADVANCE(221);
      END_STATE();
    case 39:
      if (lookahead == ' ') ADVANCE(39);
      if (lookahead == 'T') ADVANCE(200);
      if (lookahead == 'U') ADVANCE(201);
      END_STATE();
    case 40:
      if (lookahead == ' ') ADVANCE(40);
      if (lookahead == '=') ADVANCE(229);
      END_STATE();
    case 41:
      if (lookahead == ' ') ADVANCE(41);
      if (lookahead == 'P') ADVANCE(250);
      END_STATE();
    case 42:
      if (lookahead == ' ') ADVANCE(42);
      if (lookahead == 'H') ADVANCE(233);
      END_STATE();
    case 43:
      if (lookahead == ' ') ADVANCE(43);
      if (lookahead == ':') ADVANCE(237);
      END_STATE();
    case 44:
      if (lookahead == ' ') ADVANCE(44);
      if (lookahead == 'B') ADVANCE(109);
      if (lookahead == 'S') ADVANCE(53);
      if (lookahead == 'T') ADVANCE(142);
      END_STATE();
    case 45:
      if (lookahead == ' ') ADVANCE(45);
      if (lookahead == 'H') ADVANCE(179);
      if (lookahead == 'O') ADVANCE(123);
      END_STATE();
    case 46:
      if (lookahead == ' ') ADVANCE(46);
      if (lookahead == 'X') ADVANCE(81);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(507);
      END_STATE();
    case 47:
      if (lookahead == ' ') ADVANCE(47);
      if (lookahead == 'N') ADVANCE(261);
      if (lookahead == 'R') ADVANCE(177);
      END_STATE();
    case 48:
      if (lookahead == ' ') ADVANCE(48);
      if (lookahead == 'D') ADVANCE(138);
      if (lookahead == 'E') ADVANCE(180);
      if (lookahead == 'O') ADVANCE(135);
      END_STATE();
    case 49:
      if (lookahead == ' ') ADVANCE(49);
      if (lookahead == 'I') ADVANCE(86);
      if (lookahead == 'N') ADVANCE(137);
      END_STATE();
    case 50:
      if (lookahead == ' ') ADVANCE(50);
      if (lookahead == 'C') ADVANCE(182);
      if (lookahead == 'G') ADVANCE(149);
      if (lookahead == 'I') ADVANCE(154);
      if (lookahead == 'P') ADVANCE(85);
      if (lookahead == 'Q') ADVANCE(185);
      if (lookahead == 'T') ADVANCE(187);
      END_STATE();
    case 51:
      if (lookahead == ' ') ADVANCE(51);
      if (lookahead == '.') ADVANCE(505);
      if (lookahead == 'E') ADVANCE(507);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(496);
      END_STATE();
    case 52:
      if (lookahead == ' ') ADVANCE(52);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(507);
      END_STATE();
    case 53:
      if (lookahead == ' ') ADVANCE(53);
      if (lookahead == 'C') ADVANCE(297);
      END_STATE();
    case 54:
      if (lookahead == ' ') ADVANCE(54);
      if (lookahead == 'G') ADVANCE(287);
      END_STATE();
    case 55:
      if (lookahead == ' ') ADVANCE(55);
      if (lookahead == 'B') ADVANCE(259);
      if (lookahead == 'N') ADVANCE(291);
      END_STATE();
    case 56:
      if (lookahead == ' ') ADVANCE(56);
      if (lookahead == '$') ADVANCE(298);
      END_STATE();
    case 57:
      if (lookahead == ' ') ADVANCE(57);
      if (lookahead == 'K') ADVANCE(293);
      END_STATE();
    case 58:
      if (lookahead == ' ') ADVANCE(58);
      if (lookahead == 'N') ADVANCE(145);
      if (lookahead == 'T') ADVANCE(264);
      END_STATE();
    case 59:
      if (lookahead == ' ') SKIP(59)
      if (lookahead == '"') ADVANCE(203);
      if (lookahead == '(') ADVANCE(303);
      if (lookahead == '<') ADVANCE(276);
      if (lookahead == '=') ADVANCE(275);
      if (lookahead == '>') ADVANCE(274);
      if (lookahead == 'C') ADVANCE(400);
      if (lookahead == 'L') ADVANCE(478);
      if (lookahead == 'M') ADVANCE(396);
      if (lookahead == 'R') ADVANCE(413);
      if (lookahead == 'S') ADVANCE(361);
      if (lookahead == 'T') ADVANCE(467);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 60:
      if (lookahead == ' ') ADVANCE(60);
      if (lookahead == 'P') ADVANCE(85);
      if (lookahead == 'T') ADVANCE(187);
      END_STATE();
    case 61:
      if (lookahead == ' ') ADVANCE(498);
      if (lookahead == '"') ADVANCE(502);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(499);
      if (lookahead == '.') ADVANCE(509);
      if (lookahead == 'E') ADVANCE(508);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(497);
      if (('!' <= lookahead && lookahead <= '*') ||
          ('/' <= lookahead && lookahead <= '~')) ADVANCE(504);
      END_STATE();
    case 62:
      if (lookahead == ' ') SKIP(62)
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(313);
      END_STATE();
    case 63:
      if (lookahead == ' ') ADVANCE(63);
      if (lookahead == 'N') ADVANCE(252);
      END_STATE();
    case 64:
      if (lookahead == ' ') ADVANCE(64);
      if (lookahead == 'F') ADVANCE(178);
      if (lookahead == 'N') ADVANCE(294);
      END_STATE();
    case 65:
      if (lookahead == ' ') ADVANCE(65);
      if (lookahead == 'E') ADVANCE(31);
      if (lookahead == 'O') ADVANCE(97);
      END_STATE();
    case 66:
      if (lookahead == ' ') ADVANCE(66);
      if (lookahead == 'E') ADVANCE(144);
      END_STATE();
    case 67:
      if (lookahead == ' ') ADVANCE(67);
      if (lookahead == 'S') ADVANCE(42);
      END_STATE();
    case 68:
      if (lookahead == ' ') ADVANCE(68);
      if (lookahead == 'A') ADVANCE(35);
      END_STATE();
    case 69:
      if (lookahead == ' ') ADVANCE(69);
      if (lookahead == 'D') ADVANCE(206);
      END_STATE();
    case 70:
      if (lookahead == ' ') ADVANCE(70);
      if (lookahead == 'L') ADVANCE(116);
      END_STATE();
    case 71:
      if (lookahead == ' ') ADVANCE(71);
      if (lookahead == 'T') ADVANCE(258);
      END_STATE();
    case 72:
      if (lookahead == ' ') ADVANCE(72);
      if (lookahead == 'F') ADVANCE(178);
      END_STATE();
    case 73:
      if (lookahead == ' ') ADVANCE(73);
      if (lookahead == 'M') ADVANCE(122);
      END_STATE();
    case 74:
      if (lookahead == ' ') ADVANCE(74);
      if (lookahead == 'R') ADVANCE(222);
      END_STATE();
    case 75:
      if (lookahead == ' ') ADVANCE(75);
      if (lookahead == 'O') ADVANCE(139);
      END_STATE();
    case 76:
      if (lookahead == ' ') ADVANCE(76);
      if (lookahead == 'I') ADVANCE(152);
      END_STATE();
    case 77:
      if (lookahead == ' ') ADVANCE(77);
      if (lookahead == 'W') ADVANCE(226);
      END_STATE();
    case 78:
      if (lookahead == ' ') ADVANCE(78);
      if (lookahead == 'U') ADVANCE(162);
      END_STATE();
    case 79:
      if (lookahead == ' ') ADVANCE(79);
      if (lookahead == 'B') ADVANCE(236);
      END_STATE();
    case 80:
      if (lookahead == ' ') ADVANCE(80);
      if (lookahead == '=') ADVANCE(234);
      END_STATE();
    case 81:
      if (lookahead == ' ') ADVANCE(81);
      if (lookahead == 'P') ADVANCE(288);
      END_STATE();
    case 82:
      if (lookahead == ' ') ADVANCE(82);
      if (lookahead == 'H') ADVANCE(181);
      END_STATE();
    case 83:
      if (lookahead == ' ') ADVANCE(83);
      if (lookahead == ':') ADVANCE(238);
      END_STATE();
    case 84:
      if (lookahead == ' ') ADVANCE(84);
      if (lookahead == 'H') ADVANCE(186);
      if (lookahead == 'O') ADVANCE(260);
      END_STATE();
    case 85:
      if (lookahead == ' ') ADVANCE(85);
      if (lookahead == 'C') ADVANCE(262);
      END_STATE();
    case 86:
      if (lookahead == ' ') ADVANCE(86);
      if (lookahead == 'G') ADVANCE(82);
      END_STATE();
    case 87:
      if (lookahead == ' ') ADVANCE(87);
      if (lookahead == '$') ADVANCE(301);
      END_STATE();
    case 88:
      if (lookahead == ' ') ADVANCE(88);
      if (lookahead == 'N') ADVANCE(219);
      END_STATE();
    case 89:
      if (lookahead == ' ') ADVANCE(89);
      if (lookahead == 'E') ADVANCE(34);
      if (lookahead == 'O') ADVANCE(113);
      END_STATE();
    case 90:
      if (lookahead == ' ') ADVANCE(90);
      if (lookahead == 'E') ADVANCE(140);
      END_STATE();
    case 91:
      if (lookahead == ' ') ADVANCE(91);
      if (lookahead == 'S') ADVANCE(169);
      END_STATE();
    case 92:
      if (lookahead == ' ') ADVANCE(92);
      if (lookahead == 'A') ADVANCE(67);
      END_STATE();
    case 93:
      if (lookahead == ' ') ADVANCE(93);
      if (lookahead == 'D') ADVANCE(212);
      END_STATE();
    case 94:
      if (lookahead == ' ') ADVANCE(94);
      if (lookahead == 'L') ADVANCE(217);
      END_STATE();
    case 95:
      if (lookahead == ' ') ADVANCE(95);
      if (lookahead == 'T') ADVANCE(242);
      END_STATE();
    case 96:
      if (lookahead == ' ') ADVANCE(96);
      if (lookahead == 'M') ADVANCE(161);
      END_STATE();
    case 97:
      if (lookahead == ' ') ADVANCE(97);
      if (lookahead == 'R') ADVANCE(96);
      END_STATE();
    case 98:
      if (lookahead == ' ') ADVANCE(98);
      if (lookahead == 'O') ADVANCE(41);
      END_STATE();
    case 99:
      if (lookahead == ' ') ADVANCE(99);
      if (lookahead == 'I') ADVANCE(125);
      END_STATE();
    case 100:
      if (lookahead == ' ') ADVANCE(100);
      if (lookahead == 'U') ADVANCE(168);
      END_STATE();
    case 101:
      if (lookahead == ' ') ADVANCE(101);
      if (lookahead == 'B') ADVANCE(247);
      END_STATE();
    case 102:
      if (lookahead == ' ') ADVANCE(102);
      if (lookahead == '=') ADVANCE(230);
      END_STATE();
    case 103:
      if (lookahead == ' ') ADVANCE(103);
      if (lookahead == 'P') ADVANCE(266);
      END_STATE();
    case 104:
      if (lookahead == ' ') ADVANCE(104);
      if (lookahead == 'H') ADVANCE(179);
      END_STATE();
    case 105:
      if (lookahead == ' ') ADVANCE(105);
      if (lookahead == '$') ADVANCE(295);
      END_STATE();
    case 106:
      if (lookahead == ' ') ADVANCE(106);
      if (lookahead == 'N') ADVANCE(167);
      END_STATE();
    case 107:
      if (lookahead == ' ') ADVANCE(107);
      if (lookahead == 'E') ADVANCE(64);
      if (lookahead == 'O') ADVANCE(54);
      END_STATE();
    case 108:
      if (lookahead == ' ') ADVANCE(108);
      if (lookahead == 'E') ADVANCE(155);
      END_STATE();
    case 109:
      if (lookahead == ' ') ADVANCE(109);
      if (lookahead == 'S') ADVANCE(279);
      END_STATE();
    case 110:
      if (lookahead == ' ') ADVANCE(110);
      if (lookahead == 'A') ADVANCE(37);
      END_STATE();
    case 111:
      if (lookahead == ' ') ADVANCE(111);
      if (lookahead == 'D') ADVANCE(119);
      END_STATE();
    case 112:
      if (lookahead == ' ') ADVANCE(112);
      if (lookahead == 'L') ADVANCE(160);
      END_STATE();
    case 113:
      if (lookahead == ' ') ADVANCE(113);
      if (lookahead == 'T') ADVANCE(40);
      END_STATE();
    case 114:
      if (lookahead == ' ') ADVANCE(114);
      if (lookahead == 'M') ADVANCE(43);
      END_STATE();
    case 115:
      if (lookahead == ' ') ADVANCE(115);
      if (lookahead == 'R') ADVANCE(280);
      END_STATE();
    case 116:
      if (lookahead == ' ') ADVANCE(116);
      if (lookahead == 'O') ADVANCE(153);
      END_STATE();
    case 117:
      if (lookahead == ' ') ADVANCE(117);
      if (lookahead == 'I') ADVANCE(86);
      END_STATE();
    case 118:
      if (lookahead == ' ') ADVANCE(118);
      if (lookahead == 'B') ADVANCE(259);
      END_STATE();
    case 119:
      if (lookahead == ' ') ADVANCE(119);
      if (lookahead == '=') ADVANCE(241);
      END_STATE();
    case 120:
      if (lookahead == ' ') ADVANCE(120);
      if (lookahead == '$') ADVANCE(299);
      END_STATE();
    case 121:
      if (lookahead == ' ') ADVANCE(121);
      if (lookahead == 'N') ADVANCE(220);
      END_STATE();
    case 122:
      if (lookahead == ' ') ADVANCE(122);
      if (lookahead == 'E') ADVANCE(114);
      END_STATE();
    case 123:
      if (lookahead == ' ') ADVANCE(123);
      if (lookahead == 'S') ADVANCE(289);
      END_STATE();
    case 124:
      if (lookahead == ' ') ADVANCE(124);
      if (lookahead == 'A') ADVANCE(112);
      END_STATE();
    case 125:
      if (lookahead == ' ') ADVANCE(125);
      if (lookahead == 'D') ADVANCE(87);
      END_STATE();
    case 126:
      if (lookahead == ' ') ADVANCE(126);
      if (lookahead == 'L') ADVANCE(231);
      END_STATE();
    case 127:
      if (lookahead == ' ') ADVANCE(127);
      if (lookahead == 'T') ADVANCE(208);
      END_STATE();
    case 128:
      if (lookahead == ' ') ADVANCE(128);
      if (lookahead == 'M') ADVANCE(83);
      END_STATE();
    case 129:
      if (lookahead == ' ') ADVANCE(129);
      if (lookahead == 'R') ADVANCE(156);
      END_STATE();
    case 130:
      if (lookahead == ' ') ADVANCE(130);
      if (lookahead == 'O') ADVANCE(243);
      END_STATE();
    case 131:
      if (lookahead == ' ') ADVANCE(131);
      if (lookahead == '=') ADVANCE(223);
      END_STATE();
    case 132:
      if (lookahead == ' ') ADVANCE(132);
      if (lookahead == '$') ADVANCE(300);
      END_STATE();
    case 133:
      if (lookahead == ' ') ADVANCE(133);
      if (lookahead == 'N') ADVANCE(248);
      END_STATE();
    case 134:
      if (lookahead == ' ') ADVANCE(134);
      if (lookahead == 'E') ADVANCE(228);
      END_STATE();
    case 135:
      if (lookahead == ' ') ADVANCE(135);
      if (lookahead == 'S') ADVANCE(284);
      END_STATE();
    case 136:
      if (lookahead == ' ') ADVANCE(136);
      if (lookahead == 'A') ADVANCE(79);
      END_STATE();
    case 137:
      if (lookahead == ' ') ADVANCE(137);
      if (lookahead == 'D') ADVANCE(286);
      END_STATE();
    case 138:
      if (lookahead == ' ') ADVANCE(138);
      if (lookahead == 'L') ADVANCE(283);
      END_STATE();
    case 139:
      if (lookahead == ' ') ADVANCE(139);
      if (lookahead == 'T') ADVANCE(218);
      END_STATE();
    case 140:
      if (lookahead == ' ') ADVANCE(140);
      if (lookahead == 'R') ADVANCE(163);
      END_STATE();
    case 141:
      if (lookahead == ' ') ADVANCE(141);
      if (lookahead == 'O') ADVANCE(27);
      END_STATE();
    case 142:
      if (lookahead == ' ') ADVANCE(142);
      if (lookahead == 'N') ADVANCE(292);
      END_STATE();
    case 143:
      if (lookahead == ' ') ADVANCE(143);
      if (lookahead == 'E') ADVANCE(128);
      END_STATE();
    case 144:
      if (lookahead == ' ') ADVANCE(144);
      if (lookahead == 'A') ADVANCE(148);
      END_STATE();
    case 145:
      if (lookahead == ' ') ADVANCE(145);
      if (lookahead == 'D') ADVANCE(272);
      END_STATE();
    case 146:
      if (lookahead == ' ') ADVANCE(146);
      if (lookahead == 'L') ADVANCE(296);
      END_STATE();
    case 147:
      if (lookahead == ' ') ADVANCE(147);
      if (lookahead == 'T') ADVANCE(214);
      END_STATE();
    case 148:
      if (lookahead == ' ') ADVANCE(148);
      if (lookahead == 'R') ADVANCE(257);
      END_STATE();
    case 149:
      if (lookahead == ' ') ADVANCE(149);
      if (lookahead == 'N') ADVANCE(277);
      END_STATE();
    case 150:
      if (lookahead == ' ') ADVANCE(150);
      if (lookahead == 'E') ADVANCE(255);
      END_STATE();
    case 151:
      if (lookahead == ' ') ADVANCE(151);
      if (lookahead == 'A') ADVANCE(209);
      END_STATE();
    case 152:
      if (lookahead == ' ') ADVANCE(152);
      if (lookahead == 'T') ADVANCE(253);
      END_STATE();
    case 153:
      if (lookahead == ' ') ADVANCE(153);
      if (lookahead == 'R') ADVANCE(80);
      END_STATE();
    case 154:
      if (lookahead == ' ') ADVANCE(154);
      if (lookahead == 'N') ADVANCE(290);
      END_STATE();
    case 155:
      if (lookahead == ' ') ADVANCE(155);
      if (lookahead == 'E') ADVANCE(111);
      END_STATE();
    case 156:
      if (lookahead == ' ') ADVANCE(156);
      if (lookahead == 'A') ADVANCE(77);
      END_STATE();
    case 157:
      if (lookahead == ' ') ADVANCE(157);
      if (lookahead == 'T') ADVANCE(224);
      END_STATE();
    case 158:
      if (lookahead == ' ') ADVANCE(158);
      if (lookahead == 'R') ADVANCE(91);
      END_STATE();
    case 159:
      if (lookahead == ' ') ADVANCE(159);
      if (lookahead == 'N') ADVANCE(282);
      END_STATE();
    case 160:
      if (lookahead == ' ') ADVANCE(160);
      if (lookahead == 'E') ADVANCE(102);
      END_STATE();
    case 161:
      if (lookahead == ' ') ADVANCE(161);
      if (lookahead == 'A') ADVANCE(126);
      END_STATE();
    case 162:
      if (lookahead == ' ') ADVANCE(162);
      if (lookahead == 'T') ADVANCE(210);
      END_STATE();
    case 163:
      if (lookahead == ' ') ADVANCE(163);
      if (lookahead == 'R') ADVANCE(239);
      END_STATE();
    case 164:
      if (lookahead == ' ') ADVANCE(164);
      if (lookahead == 'N') ADVANCE(263);
      END_STATE();
    case 165:
      if (lookahead == ' ') ADVANCE(165);
      if (lookahead == 'E') ADVANCE(240);
      END_STATE();
    case 166:
      if (lookahead == ' ') ADVANCE(166);
      if (lookahead == 'A') ADVANCE(55);
      END_STATE();
    case 167:
      if (lookahead == ' ') ADVANCE(167);
      if (lookahead == 'T') ADVANCE(256);
      END_STATE();
    case 168:
      if (lookahead == ' ') ADVANCE(168);
      if (lookahead == 'R') ADVANCE(133);
      END_STATE();
    case 169:
      if (lookahead == ' ') ADVANCE(169);
      if (lookahead == 'E') ADVANCE(232);
      END_STATE();
    case 170:
      if (lookahead == ' ') ADVANCE(170);
      if (lookahead == 'A') ADVANCE(146);
      END_STATE();
    case 171:
      if (lookahead == ' ') ADVANCE(171);
      if (lookahead == 'T') ADVANCE(278);
      END_STATE();
    case 172:
      if (lookahead == ' ') ADVANCE(172);
      if (lookahead == 'R') ADVANCE(131);
      END_STATE();
    case 173:
      if (lookahead == ' ') ADVANCE(173);
      if (lookahead == 'E') ADVANCE(245);
      END_STATE();
    case 174:
      if (lookahead == ' ') ADVANCE(174);
      if (lookahead == 'A') ADVANCE(118);
      END_STATE();
    case 175:
      if (lookahead == ' ') ADVANCE(175);
      if (lookahead == 'T') ADVANCE(265);
      END_STATE();
    case 176:
      if (lookahead == ' ') ADVANCE(176);
      if (lookahead == 'R') ADVANCE(173);
      END_STATE();
    case 177:
      if (lookahead == ' ') ADVANCE(177);
      if (lookahead == 'E') ADVANCE(281);
      END_STATE();
    case 178:
      if (lookahead == ' ') ADVANCE(178);
      if (lookahead == 'T') ADVANCE(120);
      END_STATE();
    case 179:
      if (lookahead == ' ') ADVANCE(179);
      if (lookahead == 'R') ADVANCE(56);
      END_STATE();
    case 180:
      if (lookahead == ' ') ADVANCE(180);
      if (lookahead == 'E') ADVANCE(57);
      END_STATE();
    case 181:
      if (lookahead == ' ') ADVANCE(181);
      if (lookahead == 'T') ADVANCE(132);
      END_STATE();
    case 182:
      if (lookahead == ' ') ADVANCE(182);
      if (lookahead == 'R') ADVANCE(159);
      END_STATE();
    case 183:
      if (lookahead == ' ') ADVANCE(183);
      if (lookahead == 'E') ADVANCE(103);
      END_STATE();
    case 184:
      if (lookahead == ' ') ADVANCE(184);
      if (lookahead == 'T') ADVANCE(183);
      END_STATE();
    case 185:
      if (lookahead == ' ') ADVANCE(185);
      if (lookahead == 'R') ADVANCE(285);
      END_STATE();
    case 186:
      if (lookahead == ' ') ADVANCE(186);
      if (lookahead == 'E') ADVANCE(164);
      END_STATE();
    case 187:
      if (lookahead == ' ') ADVANCE(187);
      if (lookahead == 'R') ADVANCE(105);
      END_STATE();
    case 188:
      if (lookahead == ' ') ADVANCE(188);
      if (lookahead == 'E') ADVANCE(72);
      END_STATE();
    case 189:
      if (lookahead == ' ') ADVANCE(189);
      if (lookahead == 'R') ADVANCE(273);
      END_STATE();
    case 190:
      if (lookahead == ' ') ADVANCE(190);
      if (lookahead == 'I') ADVANCE(121);
      END_STATE();
    case 191:
      if (lookahead == ' ') ADVANCE(191);
      if (lookahead == 'X') ADVANCE(147);
      END_STATE();
    case 192:
      if (lookahead == ' ') ADVANCE(192);
      if (lookahead == 'L') ADVANCE(194);
      END_STATE();
    case 193:
      if (lookahead == ' ') ADVANCE(193);
      if (lookahead == 'M') ADVANCE(134);
      END_STATE();
    case 194:
      if (lookahead == ' ') ADVANCE(194);
      if (lookahead == 'O') ADVANCE(157);
      END_STATE();
    case 195:
      if (lookahead == ' ') ADVANCE(195);
      if (lookahead == 'E') ADVANCE(158);
      END_STATE();
    case 196:
      if (lookahead == ' ') ADVANCE(196);
      if (lookahead == 'N') ADVANCE(171);
      END_STATE();
    case 197:
      if (lookahead == ' ') ADVANCE(197);
      if (lookahead == 'O') ADVANCE(172);
      END_STATE();
    case 198:
      if (lookahead == ' ') ADVANCE(198);
      if (lookahead == 'M') ADVANCE(143);
      END_STATE();
    case 199:
      if (lookahead == ' ') ADVANCE(199);
      if (lookahead == 'O') ADVANCE(175);
      END_STATE();
    case 200:
      if (lookahead == ' ') ADVANCE(200);
      if (lookahead == 'O') ADVANCE(176);
      END_STATE();
    case 201:
      if (lookahead == ' ') ADVANCE(201);
      if (lookahead == 'M') ADVANCE(165);
      END_STATE();
    case 202:
      if (lookahead == ' ') ADVANCE(202);
      if (lookahead == 'L') ADVANCE(197);
      END_STATE();
    case 203:
      if (lookahead == '"') ADVANCE(510);
      if ((' ' <= lookahead && lookahead <= '~')) ADVANCE(203);
      END_STATE();
    case 204:
      if (eof) ADVANCE(205);
      if (lookahead == '\n') ADVANCE(310);
      if (lookahead == ' ') ADVANCE(6);
      if (lookahead == 'C') ADVANCE(314);
      if (lookahead == 'D') ADVANCE(315);
      if (lookahead == 'E') ADVANCE(316);
      if (lookahead == 'F') ADVANCE(317);
      if (lookahead == 'G') ADVANCE(318);
      if (lookahead == 'H') ADVANCE(319);
      if (lookahead == 'I') ADVANCE(320);
      if (lookahead == 'L') ADVANCE(321);
      if (lookahead == 'N') ADVANCE(364);
      if (lookahead == 'O') ADVANCE(362);
      if (lookahead == 'P') ADVANCE(322);
      if (lookahead == 'R') ADVANCE(387);
      if (lookahead == 'S') ADVANCE(323);
      if (lookahead == 'T') ADVANCE(324);
      if (lookahead == 'U') ADVANCE(325);
      if (lookahead == 'V') ADVANCE(326);
      if (lookahead == 'W') ADVANCE(327);
      if (lookahead == 'X') ADVANCE(328);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(312);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_end_tok);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym_for_tok);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym_next_tok);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym_data_tok);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_input_tok);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym_dim_tok);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_read_tok);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym_gr_tok);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym_text_tok);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym_prn_tok);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_inn_tok);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_call_tok);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_plot_tok);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_hlin_tok);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_vlin_tok);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_hgr2_tok);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_hgr_tok);
      if (lookahead == ' ') ADVANCE(38);
      if (lookahead == '2') ADVANCE(221);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym_hcoloreq_tok);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_hplot_tok);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_draw_tok);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym_xdraw_tok);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_htab_tok);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_home_tok);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_roteq_tok);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym_scaleeq_tok);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym_normal_tok);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym_inverse_tok);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym_flash_tok);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_coloreq_tok);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym_pop_tok);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym_vtab_tok);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(sym_himem_tok);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym_lomem_tok);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym_onerr_tok);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_resume_tok);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_speedeq_tok);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_let_tok);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_goto_tok);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_if_tok);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_restore_tok);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_amp_tok);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym_gosub_tok);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym_return_tok);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_rem_tok);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_stop_tok);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_on_tok);
      if (lookahead == ' ') ADVANCE(90);
      if (lookahead == 'E') ADVANCE(436);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_on_tok);
      if (lookahead == ' ') ADVANCE(90);
      if (lookahead == 'E') ADVANCE(140);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_wait_tok);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_def_tok);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_poke_tok);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym_print_tok);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_clear_tok);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_get_tok);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_tab_tok);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym_to_tok);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym_fn_tok);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_spc_tok);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(sym_then_tok);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(sym_at_tok);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym_not_tok);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_step_tok);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_plus_tok);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_minus_tok);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_times_tok);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_div_tok);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_pow_tok);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym_and_tok);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym_or_tok);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym_gtr_tok);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_eq_tok);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym_less_tok);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_sgn_tok);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_int_tok);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym_abs_tok);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym_usr_tok);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(sym_fre_tok);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(sym_scrn_tok);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(sym_pdl_tok);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(sym_pos_tok);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(sym_sqr_tok);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(sym_rnd_tok);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym_log_tok);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym_exp_tok);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym_cos_tok);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(sym_sin_tok);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_tan_tok);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym_atn_tok);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(sym_peek_tok);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(sym_len_tok);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(sym_str_tok);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(sym_val_tok);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(sym_asc_tok);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(sym_chr_tok);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(sym_left_tok);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(sym_right_tok);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(sym_mid_tok);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(aux_sym_statement_token1);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(aux_sym_statement_token1);
      if (lookahead == ' ') ADVANCE(307);
      if (lookahead == ':') ADVANCE(308);
      if (('!' <= lookahead && lookahead <= '~')) ADVANCE(306);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(anon_sym_LF);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(sym__empty_line);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(sym_linenum);
      if (lookahead == ' ') ADVANCE(311);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(495);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(sym_linenum);
      if (lookahead == ' ' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(312);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(sym_real_scalar);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(313);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(7);
      if (lookahead == 'A') ADVANCE(329);
      if (lookahead == 'L') ADVANCE(365);
      if (lookahead == 'O') ADVANCE(369);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(8);
      if (lookahead == 'A') ADVANCE(330);
      if (lookahead == 'E') ADVANCE(331);
      if (lookahead == 'I') ADVANCE(332);
      if (lookahead == 'R') ADVANCE(367);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(9);
      if (lookahead == 'N') ADVANCE(368);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(10);
      if (lookahead == 'L') ADVANCE(389);
      if (lookahead == 'O') ADVANCE(333);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(11);
      if (lookahead == 'E') ADVANCE(370);
      if (lookahead == 'O') ADVANCE(334);
      if (lookahead == 'R') ADVANCE(213);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(12);
      if (lookahead == 'C') ADVANCE(335);
      if (lookahead == 'G') ADVANCE(373);
      if (lookahead == 'I') ADVANCE(372);
      if (lookahead == 'L') ADVANCE(336);
      if (lookahead == 'O') ADVANCE(482);
      if (lookahead == 'P') ADVANCE(481);
      if (lookahead == 'T') ADVANCE(406);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(13);
      if (lookahead == 'F') ADVANCE(244);
      if (lookahead == 'N') ADVANCE(337);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(14);
      if (lookahead == 'E') ADVANCE(392);
      if (lookahead == 'O') ADVANCE(487);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(15);
      if (lookahead == 'L') ADVANCE(374);
      if (lookahead == 'O') ADVANCE(339);
      if (lookahead == 'R') ADVANCE(340);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(16);
      if (lookahead == 'C') ADVANCE(420);
      if (lookahead == 'P') ADVANCE(404);
      if (lookahead == 'T') ADVANCE(395);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(17);
      if (lookahead == 'E') ADVANCE(480);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(18);
      if (lookahead == 'S') ADVANCE(411);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(19);
      if (lookahead == 'L') ADVANCE(479);
      if (lookahead == 'T') ADVANCE(432);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(20);
      if (lookahead == 'A') ADVANCE(375);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(21);
      if (lookahead == 'D') ADVANCE(425);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(22);
      if (lookahead == 'L') ADVANCE(391);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 330:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(23);
      if (lookahead == 'T') ADVANCE(445);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 331:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(24);
      if (lookahead == 'F') ADVANCE(254);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 332:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(25);
      if (lookahead == 'M') ADVANCE(211);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 333:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(26);
      if (lookahead == 'R') ADVANCE(207);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 334:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(27);
      if (lookahead == 'S') ADVANCE(343);
      if (lookahead == 'T') ADVANCE(426);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 335:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(28);
      if (lookahead == 'O') ADVANCE(491);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 336:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(29);
      if (lookahead == 'I') ADVANCE(386);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 337:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(30);
      if (lookahead == '#') ADVANCE(216);
      if (lookahead == 'P') ADVANCE(377);
      if (lookahead == 'V') ADVANCE(484);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 338:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(31);
      if (lookahead == 'X') ADVANCE(423);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 339:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(32);
      if (lookahead == 'K') ADVANCE(444);
      if (lookahead == 'P') ADVANCE(235);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 340:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(33);
      if (lookahead == '#') ADVANCE(215);
      if (lookahead == 'I') ADVANCE(402);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 341:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(34);
      if (lookahead == 'A') ADVANCE(390);
      if (lookahead == 'M') ADVANCE(249);
      if (lookahead == 'S') ADVANCE(345);
      if (lookahead == 'T') ADVANCE(397);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 342:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(35);
      if (lookahead == 'W') ADVANCE(225);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 343:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(36);
      if (lookahead == 'U') ADVANCE(398);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 344:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(37);
      if (lookahead == 'B') ADVANCE(227);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 345:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(39);
      if (lookahead == 'T') ADVANCE(489);
      if (lookahead == 'U') ADVANCE(490);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 346:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(40);
      if (lookahead == '=') ADVANCE(229);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 347:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(41);
      if (lookahead == 'P') ADVANCE(250);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 348:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(42);
      if (lookahead == 'H') ADVANCE(233);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 349:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(43);
      if (lookahead == ':') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 350:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(44);
      if (lookahead == 'B') ADVANCE(405);
      if (lookahead == 'S') ADVANCE(356);
      if (lookahead == 'T') ADVANCE(437);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 351:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(45);
      if (lookahead == 'H') ADVANCE(472);
      if (lookahead == 'O') ADVANCE(419);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 352:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(47);
      if (lookahead == 'N') ADVANCE(261);
      if (lookahead == 'R') ADVANCE(470);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 353:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(48);
      if (lookahead == 'D') ADVANCE(434);
      if (lookahead == 'E') ADVANCE(473);
      if (lookahead == 'O') ADVANCE(431);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 354:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(49);
      if (lookahead == 'I') ADVANCE(384);
      if (lookahead == 'N') ADVANCE(433);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 355:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(50);
      if (lookahead == 'C') ADVANCE(475);
      if (lookahead == 'G') ADVANCE(443);
      if (lookahead == 'I') ADVANCE(448);
      if (lookahead == 'P') ADVANCE(383);
      if (lookahead == 'Q') ADVANCE(476);
      if (lookahead == 'T') ADVANCE(477);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 356:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(53);
      if (lookahead == 'C') ADVANCE(297);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 357:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(54);
      if (lookahead == 'G') ADVANCE(287);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 358:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(55);
      if (lookahead == 'B') ADVANCE(259);
      if (lookahead == 'N') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 359:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(56);
      if (lookahead == '$') ADVANCE(298);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 360:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(57);
      if (lookahead == 'K') ADVANCE(293);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 361:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(60);
      if (lookahead == 'P') ADVANCE(383);
      if (lookahead == 'T') ADVANCE(477);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 362:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(63);
      if (lookahead == 'N') ADVANCE(251);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 363:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(64);
      if (lookahead == 'F') ADVANCE(471);
      if (lookahead == 'N') ADVANCE(294);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 364:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(65);
      if (lookahead == 'E') ADVANCE(338);
      if (lookahead == 'O') ADVANCE(394);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 365:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(66);
      if (lookahead == 'E') ADVANCE(439);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 366:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(67);
      if (lookahead == 'S') ADVANCE(348);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 367:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(68);
      if (lookahead == 'A') ADVANCE(342);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 368:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(69);
      if (lookahead == 'D') ADVANCE(206);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 369:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(70);
      if (lookahead == 'L') ADVANCE(412);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 370:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(71);
      if (lookahead == 'T') ADVANCE(258);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 371:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(72);
      if (lookahead == 'F') ADVANCE(471);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 372:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(73);
      if (lookahead == 'M') ADVANCE(418);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 373:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(74);
      if (lookahead == 'R') ADVANCE(222);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 374:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(75);
      if (lookahead == 'O') ADVANCE(435);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 375:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(76);
      if (lookahead == 'I') ADVANCE(446);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 376:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(77);
      if (lookahead == 'W') ADVANCE(226);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 377:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(78);
      if (lookahead == 'U') ADVANCE(456);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 378:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(79);
      if (lookahead == 'B') ADVANCE(236);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 379:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(80);
      if (lookahead == '=') ADVANCE(234);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 380:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(81);
      if (lookahead == 'P') ADVANCE(288);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 381:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(82);
      if (lookahead == 'H') ADVANCE(474);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 382:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(83);
      if (lookahead == ':') ADVANCE(238);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 383:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(85);
      if (lookahead == 'C') ADVANCE(262);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 384:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(86);
      if (lookahead == 'G') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 385:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(87);
      if (lookahead == '$') ADVANCE(301);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 386:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(88);
      if (lookahead == 'N') ADVANCE(219);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 387:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(89);
      if (lookahead == 'E') ADVANCE(341);
      if (lookahead == 'O') ADVANCE(409);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 388:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(91);
      if (lookahead == 'S') ADVANCE(462);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 389:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(92);
      if (lookahead == 'A') ADVANCE(366);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 390:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(93);
      if (lookahead == 'D') ADVANCE(212);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 391:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(94);
      if (lookahead == 'L') ADVANCE(217);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 392:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(95);
      if (lookahead == 'T') ADVANCE(242);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 393:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(96);
      if (lookahead == 'M') ADVANCE(455);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 394:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(97);
      if (lookahead == 'R') ADVANCE(393);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 395:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(98);
      if (lookahead == 'O') ADVANCE(347);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 396:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(99);
      if (lookahead == 'I') ADVANCE(421);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 397:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(100);
      if (lookahead == 'U') ADVANCE(461);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 398:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(101);
      if (lookahead == 'B') ADVANCE(247);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 399:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(102);
      if (lookahead == '=') ADVANCE(230);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 400:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(104);
      if (lookahead == 'H') ADVANCE(472);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 401:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(105);
      if (lookahead == '$') ADVANCE(295);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 402:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(106);
      if (lookahead == 'N') ADVANCE(460);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 403:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(107);
      if (lookahead == 'E') ADVANCE(363);
      if (lookahead == 'O') ADVANCE(357);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 404:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(108);
      if (lookahead == 'E') ADVANCE(449);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 405:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(109);
      if (lookahead == 'S') ADVANCE(279);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 406:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(110);
      if (lookahead == 'A') ADVANCE(344);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 407:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(111);
      if (lookahead == 'D') ADVANCE(415);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 408:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(112);
      if (lookahead == 'L') ADVANCE(454);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 409:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(113);
      if (lookahead == 'T') ADVANCE(346);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 410:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(114);
      if (lookahead == 'M') ADVANCE(349);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 411:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(115);
      if (lookahead == 'R') ADVANCE(280);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 412:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(116);
      if (lookahead == 'O') ADVANCE(447);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 413:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(117);
      if (lookahead == 'I') ADVANCE(384);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 414:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(118);
      if (lookahead == 'B') ADVANCE(259);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 415:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(119);
      if (lookahead == '=') ADVANCE(241);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 416:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(120);
      if (lookahead == '$') ADVANCE(299);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 417:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(121);
      if (lookahead == 'N') ADVANCE(220);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 418:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(122);
      if (lookahead == 'E') ADVANCE(410);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 419:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(123);
      if (lookahead == 'S') ADVANCE(289);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 420:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(124);
      if (lookahead == 'A') ADVANCE(408);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 421:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(125);
      if (lookahead == 'D') ADVANCE(385);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 422:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(126);
      if (lookahead == 'L') ADVANCE(231);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 423:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(127);
      if (lookahead == 'T') ADVANCE(208);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 424:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(128);
      if (lookahead == 'M') ADVANCE(382);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 425:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(129);
      if (lookahead == 'R') ADVANCE(450);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 426:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(130);
      if (lookahead == 'O') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 427:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(131);
      if (lookahead == '=') ADVANCE(223);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 428:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(132);
      if (lookahead == '$') ADVANCE(300);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 429:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(133);
      if (lookahead == 'N') ADVANCE(248);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 430:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(134);
      if (lookahead == 'E') ADVANCE(228);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 431:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(135);
      if (lookahead == 'S') ADVANCE(284);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 432:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(136);
      if (lookahead == 'A') ADVANCE(378);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 433:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(137);
      if (lookahead == 'D') ADVANCE(286);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 434:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(138);
      if (lookahead == 'L') ADVANCE(283);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 435:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(139);
      if (lookahead == 'T') ADVANCE(218);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 436:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(140);
      if (lookahead == 'R') ADVANCE(457);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 437:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(142);
      if (lookahead == 'N') ADVANCE(292);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 438:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(143);
      if (lookahead == 'E') ADVANCE(424);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 439:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(144);
      if (lookahead == 'A') ADVANCE(442);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 440:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(146);
      if (lookahead == 'L') ADVANCE(296);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 441:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(147);
      if (lookahead == 'T') ADVANCE(214);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 442:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(148);
      if (lookahead == 'R') ADVANCE(257);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 443:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(149);
      if (lookahead == 'N') ADVANCE(277);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 444:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(150);
      if (lookahead == 'E') ADVANCE(255);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 445:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(151);
      if (lookahead == 'A') ADVANCE(209);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 446:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(152);
      if (lookahead == 'T') ADVANCE(253);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 447:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(153);
      if (lookahead == 'R') ADVANCE(379);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 448:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(154);
      if (lookahead == 'N') ADVANCE(290);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 449:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(155);
      if (lookahead == 'E') ADVANCE(407);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 450:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(156);
      if (lookahead == 'A') ADVANCE(376);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 451:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(157);
      if (lookahead == 'T') ADVANCE(224);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 452:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(158);
      if (lookahead == 'R') ADVANCE(388);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 453:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(159);
      if (lookahead == 'N') ADVANCE(282);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 454:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(160);
      if (lookahead == 'E') ADVANCE(399);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 455:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(161);
      if (lookahead == 'A') ADVANCE(422);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 456:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(162);
      if (lookahead == 'T') ADVANCE(210);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 457:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(163);
      if (lookahead == 'R') ADVANCE(239);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 458:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(165);
      if (lookahead == 'E') ADVANCE(240);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 459:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(166);
      if (lookahead == 'A') ADVANCE(358);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 460:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(167);
      if (lookahead == 'T') ADVANCE(256);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 461:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(168);
      if (lookahead == 'R') ADVANCE(429);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 462:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(169);
      if (lookahead == 'E') ADVANCE(232);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 463:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(170);
      if (lookahead == 'A') ADVANCE(440);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 464:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(171);
      if (lookahead == 'T') ADVANCE(278);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 465:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(172);
      if (lookahead == 'R') ADVANCE(427);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 466:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(173);
      if (lookahead == 'E') ADVANCE(245);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 467:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(174);
      if (lookahead == 'A') ADVANCE(414);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 468:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(175);
      if (lookahead == 'T') ADVANCE(265);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 469:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(176);
      if (lookahead == 'R') ADVANCE(466);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 470:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(177);
      if (lookahead == 'E') ADVANCE(281);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 471:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(178);
      if (lookahead == 'T') ADVANCE(416);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 472:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(179);
      if (lookahead == 'R') ADVANCE(359);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 473:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(180);
      if (lookahead == 'E') ADVANCE(360);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 474:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(181);
      if (lookahead == 'T') ADVANCE(428);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 475:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(182);
      if (lookahead == 'R') ADVANCE(453);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 476:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(185);
      if (lookahead == 'R') ADVANCE(285);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 477:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(187);
      if (lookahead == 'R') ADVANCE(401);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 478:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(188);
      if (lookahead == 'E') ADVANCE(371);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 479:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(190);
      if (lookahead == 'I') ADVANCE(417);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 480:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(191);
      if (lookahead == 'X') ADVANCE(441);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 481:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(192);
      if (lookahead == 'L') ADVANCE(483);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 482:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(193);
      if (lookahead == 'M') ADVANCE(430);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 483:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(194);
      if (lookahead == 'O') ADVANCE(451);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 484:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(195);
      if (lookahead == 'E') ADVANCE(452);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 485:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(196);
      if (lookahead == 'N') ADVANCE(464);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 486:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(197);
      if (lookahead == 'O') ADVANCE(465);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 487:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(198);
      if (lookahead == 'M') ADVANCE(438);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 488:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(199);
      if (lookahead == 'O') ADVANCE(468);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 489:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(200);
      if (lookahead == 'O') ADVANCE(469);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 490:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(201);
      if (lookahead == 'M') ADVANCE(458);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 491:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (lookahead == ' ') ADVANCE(202);
      if (lookahead == 'L') ADVANCE(486);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 492:
      ACCEPT_TOKEN(aux_sym_intvar_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(492);
      END_STATE();
    case 493:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 494:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      END_STATE();
    case 495:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == ' ') ADVANCE(311);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(495);
      END_STATE();
    case 496:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == ' ') ADVANCE(51);
      if (lookahead == '.') ADVANCE(505);
      if (lookahead == 'E') ADVANCE(507);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(496);
      END_STATE();
    case 497:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == ' ') ADVANCE(501);
      if (lookahead == '.') ADVANCE(509);
      if (lookahead == 'E') ADVANCE(508);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(497);
      END_STATE();
    case 498:
      ACCEPT_TOKEN(sym_literal);
      if (lookahead == ' ') ADVANCE(498);
      if (lookahead == '"') ADVANCE(502);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(499);
      if (lookahead == '.') ADVANCE(509);
      if (lookahead == 'E') ADVANCE(508);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(497);
      if (('!' <= lookahead && lookahead <= '*') ||
          ('/' <= lookahead && lookahead <= '~')) ADVANCE(504);
      END_STATE();
    case 499:
      ACCEPT_TOKEN(sym_literal);
      if (lookahead == ' ') ADVANCE(503);
      if (lookahead == '.') ADVANCE(509);
      if (lookahead == 'E') ADVANCE(508);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(497);
      if (('!' <= lookahead && lookahead <= '+') ||
          ('-' <= lookahead && lookahead <= '~')) ADVANCE(504);
      END_STATE();
    case 500:
      ACCEPT_TOKEN(sym_literal);
      if (lookahead == ' ') ADVANCE(500);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(508);
      if (('!' <= lookahead && lookahead <= '+') ||
          ('-' <= lookahead && lookahead <= '~')) ADVANCE(504);
      END_STATE();
    case 501:
      ACCEPT_TOKEN(sym_literal);
      if (lookahead == ' ') ADVANCE(501);
      if (lookahead == '.') ADVANCE(509);
      if (lookahead == 'E') ADVANCE(508);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(497);
      if (('!' <= lookahead && lookahead <= '+') ||
          ('-' <= lookahead && lookahead <= '~')) ADVANCE(504);
      END_STATE();
    case 502:
      ACCEPT_TOKEN(sym_literal);
      if (lookahead == '"') ADVANCE(510);
      if (lookahead == ',') ADVANCE(203);
      if ((' ' <= lookahead && lookahead <= '~')) ADVANCE(502);
      END_STATE();
    case 503:
      ACCEPT_TOKEN(sym_literal);
      if (lookahead == '.') ADVANCE(509);
      if (lookahead == 'E') ADVANCE(508);
      if (lookahead == ' ' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(503);
      if (('!' <= lookahead && lookahead <= '+') ||
          ('-' <= lookahead && lookahead <= '~')) ADVANCE(504);
      END_STATE();
    case 504:
      ACCEPT_TOKEN(sym_literal);
      if ((' ' <= lookahead && lookahead <= '+') ||
          ('-' <= lookahead && lookahead <= '~')) ADVANCE(504);
      END_STATE();
    case 505:
      ACCEPT_TOKEN(sym_real);
      if (lookahead == ' ') ADVANCE(505);
      if (lookahead == 'E') ADVANCE(507);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(505);
      END_STATE();
    case 506:
      ACCEPT_TOKEN(sym_real);
      if (lookahead == ' ') ADVANCE(46);
      if (lookahead == 'X') ADVANCE(380);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(507);
      END_STATE();
    case 507:
      ACCEPT_TOKEN(sym_real);
      if (lookahead == ' ') ADVANCE(52);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(507);
      END_STATE();
    case 508:
      ACCEPT_TOKEN(sym_real);
      if (lookahead == ' ') ADVANCE(500);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(508);
      END_STATE();
    case 509:
      ACCEPT_TOKEN(sym_real);
      if (lookahead == ' ') ADVANCE(509);
      if (lookahead == 'E') ADVANCE(508);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(509);
      END_STATE();
    case 510:
      ACCEPT_TOKEN(sym_string);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 204},
  [2] = {.lex_state = 204},
  [3] = {.lex_state = 204},
  [4] = {.lex_state = 204},
  [5] = {.lex_state = 204},
  [6] = {.lex_state = 2},
  [7] = {.lex_state = 204},
  [8] = {.lex_state = 2},
  [9] = {.lex_state = 2},
  [10] = {.lex_state = 2},
  [11] = {.lex_state = 2},
  [12] = {.lex_state = 2},
  [13] = {.lex_state = 2},
  [14] = {.lex_state = 2},
  [15] = {.lex_state = 2},
  [16] = {.lex_state = 2},
  [17] = {.lex_state = 2},
  [18] = {.lex_state = 2},
  [19] = {.lex_state = 2},
  [20] = {.lex_state = 2},
  [21] = {.lex_state = 2},
  [22] = {.lex_state = 2},
  [23] = {.lex_state = 2},
  [24] = {.lex_state = 2},
  [25] = {.lex_state = 2},
  [26] = {.lex_state = 2},
  [27] = {.lex_state = 2},
  [28] = {.lex_state = 2},
  [29] = {.lex_state = 2},
  [30] = {.lex_state = 2},
  [31] = {.lex_state = 2},
  [32] = {.lex_state = 2},
  [33] = {.lex_state = 2},
  [34] = {.lex_state = 2},
  [35] = {.lex_state = 2},
  [36] = {.lex_state = 2},
  [37] = {.lex_state = 2},
  [38] = {.lex_state = 2},
  [39] = {.lex_state = 2},
  [40] = {.lex_state = 2},
  [41] = {.lex_state = 2},
  [42] = {.lex_state = 2},
  [43] = {.lex_state = 2},
  [44] = {.lex_state = 2},
  [45] = {.lex_state = 2},
  [46] = {.lex_state = 2},
  [47] = {.lex_state = 2},
  [48] = {.lex_state = 2},
  [49] = {.lex_state = 2},
  [50] = {.lex_state = 2},
  [51] = {.lex_state = 2},
  [52] = {.lex_state = 2},
  [53] = {.lex_state = 2},
  [54] = {.lex_state = 2},
  [55] = {.lex_state = 2},
  [56] = {.lex_state = 3},
  [57] = {.lex_state = 3},
  [58] = {.lex_state = 3},
  [59] = {.lex_state = 3},
  [60] = {.lex_state = 3},
  [61] = {.lex_state = 3},
  [62] = {.lex_state = 3},
  [63] = {.lex_state = 3},
  [64] = {.lex_state = 3},
  [65] = {.lex_state = 3},
  [66] = {.lex_state = 3},
  [67] = {.lex_state = 3},
  [68] = {.lex_state = 3},
  [69] = {.lex_state = 3},
  [70] = {.lex_state = 3},
  [71] = {.lex_state = 3},
  [72] = {.lex_state = 3},
  [73] = {.lex_state = 3},
  [74] = {.lex_state = 3},
  [75] = {.lex_state = 3},
  [76] = {.lex_state = 3},
  [77] = {.lex_state = 3},
  [78] = {.lex_state = 3},
  [79] = {.lex_state = 3},
  [80] = {.lex_state = 3},
  [81] = {.lex_state = 59},
  [82] = {.lex_state = 3},
  [83] = {.lex_state = 59},
  [84] = {.lex_state = 59},
  [85] = {.lex_state = 59},
  [86] = {.lex_state = 59},
  [87] = {.lex_state = 59},
  [88] = {.lex_state = 59},
  [89] = {.lex_state = 59},
  [90] = {.lex_state = 59},
  [91] = {.lex_state = 3},
  [92] = {.lex_state = 3},
  [93] = {.lex_state = 3},
  [94] = {.lex_state = 3},
  [95] = {.lex_state = 3},
  [96] = {.lex_state = 3},
  [97] = {.lex_state = 3},
  [98] = {.lex_state = 3},
  [99] = {.lex_state = 3},
  [100] = {.lex_state = 3},
  [101] = {.lex_state = 3},
  [102] = {.lex_state = 3},
  [103] = {.lex_state = 3},
  [104] = {.lex_state = 3},
  [105] = {.lex_state = 3},
  [106] = {.lex_state = 3},
  [107] = {.lex_state = 3},
  [108] = {.lex_state = 3},
  [109] = {.lex_state = 3},
  [110] = {.lex_state = 3},
  [111] = {.lex_state = 3},
  [112] = {.lex_state = 3},
  [113] = {.lex_state = 3},
  [114] = {.lex_state = 3},
  [115] = {.lex_state = 59},
  [116] = {.lex_state = 3},
  [117] = {.lex_state = 3},
  [118] = {.lex_state = 3},
  [119] = {.lex_state = 3},
  [120] = {.lex_state = 3},
  [121] = {.lex_state = 3},
  [122] = {.lex_state = 3},
  [123] = {.lex_state = 3},
  [124] = {.lex_state = 59},
  [125] = {.lex_state = 59},
  [126] = {.lex_state = 59},
  [127] = {.lex_state = 0},
  [128] = {.lex_state = 4},
  [129] = {.lex_state = 4},
  [130] = {.lex_state = 4},
  [131] = {.lex_state = 0},
  [132] = {.lex_state = 2},
  [133] = {.lex_state = 4},
  [134] = {.lex_state = 204},
  [135] = {.lex_state = 204},
  [136] = {.lex_state = 2},
  [137] = {.lex_state = 2},
  [138] = {.lex_state = 61},
  [139] = {.lex_state = 4},
  [140] = {.lex_state = 2},
  [141] = {.lex_state = 2},
  [142] = {.lex_state = 2},
  [143] = {.lex_state = 4},
  [144] = {.lex_state = 61},
  [145] = {.lex_state = 4},
  [146] = {.lex_state = 2},
  [147] = {.lex_state = 4},
  [148] = {.lex_state = 2},
  [149] = {.lex_state = 5},
  [150] = {.lex_state = 2},
  [151] = {.lex_state = 2},
  [152] = {.lex_state = 2},
  [153] = {.lex_state = 2},
  [154] = {.lex_state = 2},
  [155] = {.lex_state = 2},
  [156] = {.lex_state = 2},
  [157] = {.lex_state = 2},
  [158] = {.lex_state = 2},
  [159] = {.lex_state = 2},
  [160] = {.lex_state = 2},
  [161] = {.lex_state = 2},
  [162] = {.lex_state = 2},
  [163] = {.lex_state = 2},
  [164] = {.lex_state = 2},
  [165] = {.lex_state = 5},
  [166] = {.lex_state = 2},
  [167] = {.lex_state = 2},
  [168] = {.lex_state = 2},
  [169] = {.lex_state = 5},
  [170] = {.lex_state = 2},
  [171] = {.lex_state = 2},
  [172] = {.lex_state = 0},
  [173] = {.lex_state = 0},
  [174] = {.lex_state = 2},
  [175] = {.lex_state = 2},
  [176] = {.lex_state = 0},
  [177] = {.lex_state = 0},
  [178] = {.lex_state = 0},
  [179] = {.lex_state = 204},
  [180] = {.lex_state = 0},
  [181] = {.lex_state = 0},
  [182] = {.lex_state = 204},
  [183] = {.lex_state = 2},
  [184] = {.lex_state = 2},
  [185] = {.lex_state = 2},
  [186] = {.lex_state = 2},
  [187] = {.lex_state = 2},
  [188] = {.lex_state = 2},
  [189] = {.lex_state = 2},
  [190] = {.lex_state = 3},
  [191] = {.lex_state = 204},
  [192] = {.lex_state = 0},
  [193] = {.lex_state = 204},
  [194] = {.lex_state = 2},
  [195] = {.lex_state = 62},
  [196] = {.lex_state = 204},
  [197] = {.lex_state = 0},
  [198] = {.lex_state = 0},
  [199] = {.lex_state = 0},
  [200] = {.lex_state = 0},
  [201] = {.lex_state = 0},
  [202] = {.lex_state = 0},
  [203] = {.lex_state = 0},
  [204] = {.lex_state = 204},
  [205] = {.lex_state = 62},
  [206] = {.lex_state = 0},
  [207] = {.lex_state = 62},
  [208] = {.lex_state = 0},
  [209] = {.lex_state = 0},
  [210] = {.lex_state = 0},
  [211] = {.lex_state = 0},
  [212] = {.lex_state = 0},
  [213] = {.lex_state = 204},
  [214] = {.lex_state = 0},
  [215] = {.lex_state = 0},
  [216] = {.lex_state = 0},
  [217] = {.lex_state = 204},
  [218] = {.lex_state = 0},
  [219] = {.lex_state = 0},
  [220] = {.lex_state = 0},
  [221] = {.lex_state = 0},
  [222] = {.lex_state = 62},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_amp_tok] = ACTIONS(1),
    [sym_plus_tok] = ACTIONS(1),
    [sym_minus_tok] = ACTIONS(1),
    [sym_times_tok] = ACTIONS(1),
    [sym_div_tok] = ACTIONS(1),
    [sym_pow_tok] = ACTIONS(1),
    [sym_gtr_tok] = ACTIONS(1),
    [sym_eq_tok] = ACTIONS(1),
    [sym_less_tok] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_LF] = ACTIONS(1),
    [sym__empty_line] = ACTIONS(1),
    [sym_linenum] = ACTIONS(1),
    [sym_real_scalar] = ACTIONS(1),
    [aux_sym_intvar_token1] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_DOLLAR] = ACTIONS(1),
    [sym_integer] = ACTIONS(1),
    [sym_string] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(197),
    [sym_line] = STATE(135),
    [aux_sym_source_file_repeat1] = STATE(135),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym__empty_line] = ACTIONS(5),
    [sym_linenum] = ACTIONS(7),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 29,
    ACTIONS(11), 1,
      sym_for_tok,
    ACTIONS(13), 1,
      sym_next_tok,
    ACTIONS(15), 1,
      sym_data_tok,
    ACTIONS(17), 1,
      sym_input_tok,
    ACTIONS(19), 1,
      sym_dim_tok,
    ACTIONS(29), 1,
      sym_hgr_tok,
    ACTIONS(31), 1,
      sym_hplot_tok,
    ACTIONS(35), 1,
      sym_onerr_tok,
    ACTIONS(37), 1,
      sym_let_tok,
    ACTIONS(41), 1,
      sym_if_tok,
    ACTIONS(43), 1,
      sym_rem_tok,
    ACTIONS(45), 1,
      sym_on_tok,
    ACTIONS(47), 1,
      sym_wait_tok,
    ACTIONS(49), 1,
      sym_def_tok,
    ACTIONS(51), 1,
      sym_print_tok,
    ACTIONS(53), 1,
      sym_usr_tok,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    STATE(4), 1,
      aux_sym_line_repeat1,
    STATE(188), 1,
      sym_statement,
    STATE(189), 1,
      sym_assignment,
    STATE(212), 1,
      sym_svar,
    ACTIONS(21), 2,
      sym_read_tok,
      sym_get_tok,
    ACTIONS(25), 2,
      sym_plot_tok,
      sym_poke_tok,
    ACTIONS(27), 2,
      sym_hlin_tok,
      sym_vlin_tok,
    ACTIONS(33), 2,
      sym_draw_tok,
      sym_xdraw_tok,
    ACTIONS(39), 2,
      sym_goto_tok,
      sym_gosub_tok,
    STATE(214), 3,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(23), 12,
      sym_prn_tok,
      sym_inn_tok,
      sym_call_tok,
      sym_hcoloreq_tok,
      sym_htab_tok,
      sym_roteq_tok,
      sym_scaleeq_tok,
      sym_coloreq_tok,
      sym_vtab_tok,
      sym_himem_tok,
      sym_lomem_tok,
      sym_speedeq_tok,
    ACTIONS(9), 14,
      sym_end_tok,
      sym_gr_tok,
      sym_text_tok,
      sym_hgr2_tok,
      sym_home_tok,
      sym_normal_tok,
      sym_inverse_tok,
      sym_flash_tok,
      sym_pop_tok,
      sym_resume_tok,
      sym_restore_tok,
      sym_return_tok,
      sym_stop_tok,
      sym_clear_tok,
  [119] = 29,
    ACTIONS(60), 1,
      sym_for_tok,
    ACTIONS(63), 1,
      sym_next_tok,
    ACTIONS(66), 1,
      sym_data_tok,
    ACTIONS(69), 1,
      sym_input_tok,
    ACTIONS(72), 1,
      sym_dim_tok,
    ACTIONS(87), 1,
      sym_hgr_tok,
    ACTIONS(90), 1,
      sym_hplot_tok,
    ACTIONS(96), 1,
      sym_onerr_tok,
    ACTIONS(99), 1,
      sym_let_tok,
    ACTIONS(105), 1,
      sym_if_tok,
    ACTIONS(108), 1,
      sym_rem_tok,
    ACTIONS(111), 1,
      sym_on_tok,
    ACTIONS(114), 1,
      sym_wait_tok,
    ACTIONS(117), 1,
      sym_def_tok,
    ACTIONS(120), 1,
      sym_print_tok,
    ACTIONS(123), 1,
      sym_usr_tok,
    ACTIONS(126), 1,
      aux_sym_intvar_token1,
    STATE(3), 1,
      aux_sym_line_repeat1,
    STATE(189), 1,
      sym_assignment,
    STATE(210), 1,
      sym_statement,
    STATE(212), 1,
      sym_svar,
    ACTIONS(75), 2,
      sym_read_tok,
      sym_get_tok,
    ACTIONS(81), 2,
      sym_plot_tok,
      sym_poke_tok,
    ACTIONS(84), 2,
      sym_hlin_tok,
      sym_vlin_tok,
    ACTIONS(93), 2,
      sym_draw_tok,
      sym_xdraw_tok,
    ACTIONS(102), 2,
      sym_goto_tok,
      sym_gosub_tok,
    STATE(214), 3,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(78), 12,
      sym_prn_tok,
      sym_inn_tok,
      sym_call_tok,
      sym_hcoloreq_tok,
      sym_htab_tok,
      sym_roteq_tok,
      sym_scaleeq_tok,
      sym_coloreq_tok,
      sym_vtab_tok,
      sym_himem_tok,
      sym_lomem_tok,
      sym_speedeq_tok,
    ACTIONS(57), 14,
      sym_end_tok,
      sym_gr_tok,
      sym_text_tok,
      sym_hgr2_tok,
      sym_home_tok,
      sym_normal_tok,
      sym_inverse_tok,
      sym_flash_tok,
      sym_pop_tok,
      sym_resume_tok,
      sym_restore_tok,
      sym_return_tok,
      sym_stop_tok,
      sym_clear_tok,
  [238] = 29,
    ACTIONS(11), 1,
      sym_for_tok,
    ACTIONS(13), 1,
      sym_next_tok,
    ACTIONS(15), 1,
      sym_data_tok,
    ACTIONS(17), 1,
      sym_input_tok,
    ACTIONS(19), 1,
      sym_dim_tok,
    ACTIONS(29), 1,
      sym_hgr_tok,
    ACTIONS(31), 1,
      sym_hplot_tok,
    ACTIONS(35), 1,
      sym_onerr_tok,
    ACTIONS(37), 1,
      sym_let_tok,
    ACTIONS(41), 1,
      sym_if_tok,
    ACTIONS(43), 1,
      sym_rem_tok,
    ACTIONS(45), 1,
      sym_on_tok,
    ACTIONS(47), 1,
      sym_wait_tok,
    ACTIONS(49), 1,
      sym_def_tok,
    ACTIONS(51), 1,
      sym_print_tok,
    ACTIONS(53), 1,
      sym_usr_tok,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    STATE(3), 1,
      aux_sym_line_repeat1,
    STATE(186), 1,
      sym_statement,
    STATE(189), 1,
      sym_assignment,
    STATE(212), 1,
      sym_svar,
    ACTIONS(21), 2,
      sym_read_tok,
      sym_get_tok,
    ACTIONS(25), 2,
      sym_plot_tok,
      sym_poke_tok,
    ACTIONS(27), 2,
      sym_hlin_tok,
      sym_vlin_tok,
    ACTIONS(33), 2,
      sym_draw_tok,
      sym_xdraw_tok,
    ACTIONS(39), 2,
      sym_goto_tok,
      sym_gosub_tok,
    STATE(214), 3,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(23), 12,
      sym_prn_tok,
      sym_inn_tok,
      sym_call_tok,
      sym_hcoloreq_tok,
      sym_htab_tok,
      sym_roteq_tok,
      sym_scaleeq_tok,
      sym_coloreq_tok,
      sym_vtab_tok,
      sym_himem_tok,
      sym_lomem_tok,
      sym_speedeq_tok,
    ACTIONS(9), 14,
      sym_end_tok,
      sym_gr_tok,
      sym_text_tok,
      sym_hgr2_tok,
      sym_home_tok,
      sym_normal_tok,
      sym_inverse_tok,
      sym_flash_tok,
      sym_pop_tok,
      sym_resume_tok,
      sym_restore_tok,
      sym_return_tok,
      sym_stop_tok,
      sym_clear_tok,
  [357] = 29,
    ACTIONS(11), 1,
      sym_for_tok,
    ACTIONS(13), 1,
      sym_next_tok,
    ACTIONS(15), 1,
      sym_data_tok,
    ACTIONS(17), 1,
      sym_input_tok,
    ACTIONS(19), 1,
      sym_dim_tok,
    ACTIONS(29), 1,
      sym_hgr_tok,
    ACTIONS(31), 1,
      sym_hplot_tok,
    ACTIONS(35), 1,
      sym_onerr_tok,
    ACTIONS(37), 1,
      sym_let_tok,
    ACTIONS(41), 1,
      sym_if_tok,
    ACTIONS(43), 1,
      sym_rem_tok,
    ACTIONS(45), 1,
      sym_on_tok,
    ACTIONS(47), 1,
      sym_wait_tok,
    ACTIONS(49), 1,
      sym_def_tok,
    ACTIONS(51), 1,
      sym_print_tok,
    ACTIONS(53), 1,
      sym_usr_tok,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(129), 1,
      sym_linenum,
    STATE(187), 1,
      sym_statement,
    STATE(189), 1,
      sym_assignment,
    STATE(212), 1,
      sym_svar,
    ACTIONS(21), 2,
      sym_read_tok,
      sym_get_tok,
    ACTIONS(25), 2,
      sym_plot_tok,
      sym_poke_tok,
    ACTIONS(27), 2,
      sym_hlin_tok,
      sym_vlin_tok,
    ACTIONS(33), 2,
      sym_draw_tok,
      sym_xdraw_tok,
    ACTIONS(39), 2,
      sym_goto_tok,
      sym_gosub_tok,
    STATE(214), 3,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(23), 12,
      sym_prn_tok,
      sym_inn_tok,
      sym_call_tok,
      sym_hcoloreq_tok,
      sym_htab_tok,
      sym_roteq_tok,
      sym_scaleeq_tok,
      sym_coloreq_tok,
      sym_vtab_tok,
      sym_himem_tok,
      sym_lomem_tok,
      sym_speedeq_tok,
    ACTIONS(9), 14,
      sym_end_tok,
      sym_gr_tok,
      sym_text_tok,
      sym_hgr2_tok,
      sym_home_tok,
      sym_normal_tok,
      sym_inverse_tok,
      sym_flash_tok,
      sym_pop_tok,
      sym_resume_tok,
      sym_restore_tok,
      sym_return_tok,
      sym_stop_tok,
      sym_clear_tok,
  [476] = 20,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(149), 1,
      anon_sym_COMMA,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(153), 1,
      anon_sym_SEMI,
    ACTIONS(159), 1,
      sym_string,
    STATE(141), 1,
      sym__expr,
    STATE(142), 1,
      aux_sym_statement_repeat6,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(155), 2,
      anon_sym_COLON,
      anon_sym_LF,
    ACTIONS(157), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(101), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(82), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [571] = 2,
    ACTIONS(163), 3,
      sym_hgr_tok,
      sym_on_tok,
      aux_sym_intvar_token1,
    ACTIONS(161), 50,
      sym_end_tok,
      sym_for_tok,
      sym_next_tok,
      sym_data_tok,
      sym_input_tok,
      sym_dim_tok,
      sym_read_tok,
      sym_gr_tok,
      sym_text_tok,
      sym_prn_tok,
      sym_inn_tok,
      sym_call_tok,
      sym_plot_tok,
      sym_hlin_tok,
      sym_vlin_tok,
      sym_hgr2_tok,
      sym_hcoloreq_tok,
      sym_hplot_tok,
      sym_draw_tok,
      sym_xdraw_tok,
      sym_htab_tok,
      sym_home_tok,
      sym_roteq_tok,
      sym_scaleeq_tok,
      sym_normal_tok,
      sym_inverse_tok,
      sym_flash_tok,
      sym_coloreq_tok,
      sym_pop_tok,
      sym_vtab_tok,
      sym_himem_tok,
      sym_lomem_tok,
      sym_onerr_tok,
      sym_resume_tok,
      sym_speedeq_tok,
      sym_let_tok,
      sym_goto_tok,
      sym_if_tok,
      sym_restore_tok,
      sym_gosub_tok,
      sym_return_tok,
      sym_rem_tok,
      sym_stop_tok,
      sym_wait_tok,
      sym_def_tok,
      sym_poke_tok,
      sym_print_tok,
      sym_clear_tok,
      sym_get_tok,
      sym_usr_tok,
  [629] = 17,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(159), 1,
      sym_string,
    STATE(166), 1,
      sym__expr,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(157), 2,
      sym_integer,
      sym_real,
    ACTIONS(165), 2,
      anon_sym_COLON,
      anon_sym_LF,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(101), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(82), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [715] = 17,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(159), 1,
      sym_string,
    STATE(166), 1,
      sym__expr,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(157), 2,
      sym_integer,
      sym_real,
    ACTIONS(167), 2,
      anon_sym_COLON,
      anon_sym_LF,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(101), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(82), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [801] = 17,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(159), 1,
      sym_string,
    STATE(166), 1,
      sym__expr,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(157), 2,
      sym_integer,
      sym_real,
    ACTIONS(169), 2,
      anon_sym_COLON,
      anon_sym_LF,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(101), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(82), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [887] = 16,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(159), 1,
      sym_string,
    STATE(190), 1,
      sym__expr,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(157), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(101), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(82), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [969] = 16,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(159), 1,
      sym_string,
    STATE(166), 1,
      sym__expr,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(157), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(101), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(82), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [1051] = 16,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(159), 1,
      sym_string,
    STATE(199), 1,
      sym__expr,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(157), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(101), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(82), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [1133] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(171), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(104), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [1212] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(175), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(112), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [1291] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(177), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(94), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [1370] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(179), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(103), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [1449] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(181), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(98), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [1528] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(183), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(119), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [1607] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(185), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(117), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [1686] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(187), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(110), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [1765] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(189), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(95), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [1844] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(191), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(118), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [1923] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(193), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(121), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [2002] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(195), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(96), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [2081] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(197), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(116), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [2160] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(199), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(92), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [2239] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(201), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(107), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [2318] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(203), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(91), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [2397] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(205), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(120), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [2476] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(207), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(108), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [2555] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(209), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(93), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [2634] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(211), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(123), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [2713] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(213), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(100), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [2792] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(215), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(67), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [2871] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(217), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(111), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [2950] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(219), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(99), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [3029] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(221), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(122), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [3108] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(223), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(65), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [3187] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(225), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(64), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [3266] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(227), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(63), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [3345] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(229), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(59), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [3424] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(231), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(102), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [3503] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(233), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(113), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [3582] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(235), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(105), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [3661] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(237), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(62), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [3740] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(239), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(114), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [3819] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(241), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(106), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [3898] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(243), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(97), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [3977] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(245), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(131), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(60), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [4056] = 15,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(133), 1,
      sym_fn_tok,
    ACTIONS(141), 1,
      sym_scrn_tok,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    ACTIONS(249), 1,
      sym_string,
    ACTIONS(139), 2,
      sym_fre_tok,
      sym_pos_tok,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(247), 2,
      sym_integer,
      sym_real,
    ACTIONS(135), 3,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(143), 3,
      sym_len_tok,
      sym_val_tok,
      sym_asc_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(127), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
    STATE(109), 8,
      sym_fcall,
      sym__aexpr,
      sym_unary_aexpr,
      sym_binary_aexpr,
      sym__parenthesized_aexpr,
      sym__avar,
      sym_intvar,
      sym_realvar,
    ACTIONS(137), 13,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_pdl_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
  [4135] = 3,
    ACTIONS(253), 2,
      sym_eq_tok,
      sym_less_tok,
    ACTIONS(255), 3,
      aux_sym_intvar_token1,
      sym_integer,
      sym_real,
    ACTIONS(251), 32,
      sym_tab_tok,
      sym_fn_tok,
      sym_spc_tok,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_fre_tok,
      sym_scrn_tok,
      sym_pdl_tok,
      sym_pos_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
      sym_len_tok,
      sym_str_tok,
      sym_val_tok,
      sym_asc_tok,
      sym_chr_tok,
      sym_left_tok,
      sym_right_tok,
      sym_mid_tok,
      anon_sym_LPAREN,
      sym_string,
  [4179] = 3,
    ACTIONS(253), 2,
      sym_gtr_tok,
      sym_less_tok,
    ACTIONS(255), 3,
      aux_sym_intvar_token1,
      sym_integer,
      sym_real,
    ACTIONS(251), 32,
      sym_tab_tok,
      sym_fn_tok,
      sym_spc_tok,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_fre_tok,
      sym_scrn_tok,
      sym_pdl_tok,
      sym_pos_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
      sym_len_tok,
      sym_str_tok,
      sym_val_tok,
      sym_asc_tok,
      sym_chr_tok,
      sym_left_tok,
      sym_right_tok,
      sym_mid_tok,
      anon_sym_LPAREN,
      sym_string,
  [4223] = 3,
    ACTIONS(253), 2,
      sym_gtr_tok,
      sym_eq_tok,
    ACTIONS(255), 3,
      aux_sym_intvar_token1,
      sym_integer,
      sym_real,
    ACTIONS(251), 32,
      sym_tab_tok,
      sym_fn_tok,
      sym_spc_tok,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_fre_tok,
      sym_scrn_tok,
      sym_pdl_tok,
      sym_pos_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
      sym_len_tok,
      sym_str_tok,
      sym_val_tok,
      sym_asc_tok,
      sym_chr_tok,
      sym_left_tok,
      sym_right_tok,
      sym_mid_tok,
      anon_sym_LPAREN,
      sym_string,
  [4267] = 2,
    ACTIONS(259), 3,
      aux_sym_intvar_token1,
      sym_integer,
      sym_real,
    ACTIONS(257), 32,
      sym_tab_tok,
      sym_fn_tok,
      sym_spc_tok,
      sym_not_tok,
      sym_plus_tok,
      sym_minus_tok,
      sym_sgn_tok,
      sym_int_tok,
      sym_abs_tok,
      sym_fre_tok,
      sym_scrn_tok,
      sym_pdl_tok,
      sym_pos_tok,
      sym_sqr_tok,
      sym_rnd_tok,
      sym_log_tok,
      sym_exp_tok,
      sym_cos_tok,
      sym_sin_tok,
      sym_tan_tok,
      sym_atn_tok,
      sym_peek_tok,
      sym_len_tok,
      sym_str_tok,
      sym_val_tok,
      sym_asc_tok,
      sym_chr_tok,
      sym_left_tok,
      sym_right_tok,
      sym_mid_tok,
      anon_sym_LPAREN,
      sym_string,
  [4307] = 5,
    ACTIONS(263), 1,
      anon_sym_LPAREN,
    ACTIONS(265), 1,
      anon_sym_PERCENT,
    ACTIONS(267), 1,
      anon_sym_DOLLAR,
    STATE(79), 1,
      sym_subscript,
    ACTIONS(261), 21,
      sym_goto_tok,
      sym_gosub_tok,
      sym_to_tok,
      sym_then_tok,
      sym_at_tok,
      sym_step_tok,
      sym_plus_tok,
      sym_minus_tok,
      sym_times_tok,
      sym_div_tok,
      sym_pow_tok,
      sym_and_tok,
      sym_or_tok,
      sym_gtr_tok,
      sym_eq_tok,
      sym_less_tok,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LF,
  [4343] = 3,
    ACTIONS(263), 1,
      anon_sym_LPAREN,
    STATE(78), 1,
      sym_subscript,
    ACTIONS(269), 21,
      sym_goto_tok,
      sym_gosub_tok,
      sym_to_tok,
      sym_then_tok,
      sym_at_tok,
      sym_step_tok,
      sym_plus_tok,
      sym_minus_tok,
      sym_times_tok,
      sym_div_tok,
      sym_pow_tok,
      sym_and_tok,
      sym_or_tok,
      sym_gtr_tok,
      sym_eq_tok,
      sym_less_tok,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LF,
  [4373] = 3,
    ACTIONS(263), 1,
      anon_sym_LPAREN,
    STATE(70), 1,
      sym_subscript,
    ACTIONS(271), 21,
      sym_goto_tok,
      sym_gosub_tok,
      sym_to_tok,
      sym_then_tok,
      sym_at_tok,
      sym_step_tok,
      sym_plus_tok,
      sym_minus_tok,
      sym_times_tok,
      sym_div_tok,
      sym_pow_tok,
      sym_and_tok,
      sym_or_tok,
      sym_gtr_tok,
      sym_eq_tok,
      sym_less_tok,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LF,
  [4403] = 3,
    ACTIONS(275), 1,
      sym_pow_tok,
    STATE(35), 1,
      sym__relop,
    ACTIONS(273), 20,
      sym_goto_tok,
      sym_gosub_tok,
      sym_to_tok,
      sym_then_tok,
      sym_at_tok,
      sym_step_tok,
      sym_plus_tok,
      sym_minus_tok,
      sym_times_tok,
      sym_div_tok,
      sym_and_tok,
      sym_or_tok,
      sym_gtr_tok,
      sym_eq_tok,
      sym_less_tok,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LF,
  [4432] = 4,
    ACTIONS(275), 1,
      sym_pow_tok,
    STATE(35), 1,
      sym__relop,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(273), 18,
      sym_goto_tok,
      sym_gosub_tok,
      sym_to_tok,
      sym_then_tok,
      sym_at_tok,
      sym_step_tok,
      sym_plus_tok,
      sym_minus_tok,
      sym_and_tok,
      sym_or_tok,
      sym_gtr_tok,
      sym_eq_tok,
      sym_less_tok,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LF,
  [4463] = 2,
    STATE(83), 1,
      sym__sop,
    ACTIONS(279), 21,
      sym_goto_tok,
      sym_gosub_tok,
      sym_to_tok,
      sym_then_tok,
      sym_at_tok,
      sym_step_tok,
      sym_plus_tok,
      sym_minus_tok,
      sym_times_tok,
      sym_div_tok,
      sym_pow_tok,
      sym_and_tok,
      sym_or_tok,
      sym_gtr_tok,
      sym_eq_tok,
      sym_less_tok,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LF,
  [4490] = 2,
    STATE(35), 1,
      sym__relop,
    ACTIONS(281), 21,
      sym_goto_tok,
      sym_gosub_tok,
      sym_to_tok,
      sym_then_tok,
      sym_at_tok,
      sym_step_tok,
      sym_plus_tok,
      sym_minus_tok,
      sym_times_tok,
      sym_div_tok,
      sym_pow_tok,
      sym_and_tok,
      sym_or_tok,
      sym_gtr_tok,
      sym_eq_tok,
      sym_less_tok,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LF,
  [4517] = 2,
    STATE(35), 1,
      sym__relop,
    ACTIONS(273), 21,
      sym_goto_tok,
      sym_gosub_tok,
      sym_to_tok,
      sym_then_tok,
      sym_at_tok,
      sym_step_tok,
      sym_plus_tok,
      sym_minus_tok,
      sym_times_tok,
      sym_div_tok,
      sym_pow_tok,
      sym_and_tok,
      sym_or_tok,
      sym_gtr_tok,
      sym_eq_tok,
      sym_less_tok,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LF,
  [4544] = 8,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    STATE(35), 1,
      sym__relop,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(273), 13,
      sym_goto_tok,
      sym_gosub_tok,
      sym_to_tok,
      sym_then_tok,
      sym_at_tok,
      sym_step_tok,
      sym_and_tok,
      sym_or_tok,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LF,
  [4583] = 9,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    STATE(35), 1,
      sym__relop,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(273), 12,
      sym_goto_tok,
      sym_gosub_tok,
      sym_to_tok,
      sym_then_tok,
      sym_at_tok,
      sym_step_tok,
      sym_or_tok,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LF,
  [4624] = 2,
    STATE(83), 1,
      sym__sop,
    ACTIONS(273), 21,
      sym_goto_tok,
      sym_gosub_tok,
      sym_to_tok,
      sym_then_tok,
      sym_at_tok,
      sym_step_tok,
      sym_plus_tok,
      sym_minus_tok,
      sym_times_tok,
      sym_div_tok,
      sym_pow_tok,
      sym_and_tok,
      sym_or_tok,
      sym_gtr_tok,
      sym_eq_tok,
      sym_less_tok,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LF,
  [4651] = 5,
    ACTIONS(275), 1,
      sym_pow_tok,
    STATE(35), 1,
      sym__relop,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(273), 16,
      sym_goto_tok,
      sym_gosub_tok,
      sym_to_tok,
      sym_then_tok,
      sym_at_tok,
      sym_step_tok,
      sym_and_tok,
      sym_or_tok,
      sym_gtr_tok,
      sym_eq_tok,
      sym_less_tok,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LF,
  [4684] = 1,
    ACTIONS(293), 21,
      sym_goto_tok,
      sym_gosub_tok,
      sym_to_tok,
      sym_then_tok,
      sym_at_tok,
      sym_step_tok,
      sym_plus_tok,
      sym_minus_tok,
      sym_times_tok,
      sym_div_tok,
      sym_pow_tok,
      sym_and_tok,
      sym_or_tok,
      sym_gtr_tok,
      sym_eq_tok,
      sym_less_tok,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LF,
  [4708] = 1,
    ACTIONS(295), 21,
      sym_goto_tok,
      sym_gosub_tok,
      sym_to_tok,
      sym_then_tok,
      sym_at_tok,
      sym_step_tok,
      sym_plus_tok,
      sym_minus_tok,
      sym_times_tok,
      sym_div_tok,
      sym_pow_tok,
      sym_and_tok,
      sym_or_tok,
      sym_gtr_tok,
      sym_eq_tok,
      sym_less_tok,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LF,
  [4732] = 1,
    ACTIONS(297), 21,
      sym_goto_tok,
      sym_gosub_tok,
      sym_to_tok,
      sym_then_tok,
      sym_at_tok,
      sym_step_tok,
      sym_plus_tok,
      sym_minus_tok,
      sym_times_tok,
      sym_div_tok,
      sym_pow_tok,
      sym_and_tok,
      sym_or_tok,
      sym_gtr_tok,
      sym_eq_tok,
      sym_less_tok,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LF,
  [4756] = 1,
    ACTIONS(299), 21,
      sym_goto_tok,
      sym_gosub_tok,
      sym_to_tok,
      sym_then_tok,
      sym_at_tok,
      sym_step_tok,
      sym_plus_tok,
      sym_minus_tok,
      sym_times_tok,
      sym_div_tok,
      sym_pow_tok,
      sym_and_tok,
      sym_or_tok,
      sym_gtr_tok,
      sym_eq_tok,
      sym_less_tok,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LF,
  [4780] = 1,
    ACTIONS(301), 21,
      sym_goto_tok,
      sym_gosub_tok,
      sym_to_tok,
      sym_then_tok,
      sym_at_tok,
      sym_step_tok,
      sym_plus_tok,
      sym_minus_tok,
      sym_times_tok,
      sym_div_tok,
      sym_pow_tok,
      sym_and_tok,
      sym_or_tok,
      sym_gtr_tok,
      sym_eq_tok,
      sym_less_tok,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LF,
  [4804] = 1,
    ACTIONS(303), 21,
      sym_goto_tok,
      sym_gosub_tok,
      sym_to_tok,
      sym_then_tok,
      sym_at_tok,
      sym_step_tok,
      sym_plus_tok,
      sym_minus_tok,
      sym_times_tok,
      sym_div_tok,
      sym_pow_tok,
      sym_and_tok,
      sym_or_tok,
      sym_gtr_tok,
      sym_eq_tok,
      sym_less_tok,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LF,
  [4828] = 1,
    ACTIONS(305), 21,
      sym_goto_tok,
      sym_gosub_tok,
      sym_to_tok,
      sym_then_tok,
      sym_at_tok,
      sym_step_tok,
      sym_plus_tok,
      sym_minus_tok,
      sym_times_tok,
      sym_div_tok,
      sym_pow_tok,
      sym_and_tok,
      sym_or_tok,
      sym_gtr_tok,
      sym_eq_tok,
      sym_less_tok,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LF,
  [4852] = 1,
    ACTIONS(307), 21,
      sym_goto_tok,
      sym_gosub_tok,
      sym_to_tok,
      sym_then_tok,
      sym_at_tok,
      sym_step_tok,
      sym_plus_tok,
      sym_minus_tok,
      sym_times_tok,
      sym_div_tok,
      sym_pow_tok,
      sym_and_tok,
      sym_or_tok,
      sym_gtr_tok,
      sym_eq_tok,
      sym_less_tok,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LF,
  [4876] = 1,
    ACTIONS(309), 21,
      sym_goto_tok,
      sym_gosub_tok,
      sym_to_tok,
      sym_then_tok,
      sym_at_tok,
      sym_step_tok,
      sym_plus_tok,
      sym_minus_tok,
      sym_times_tok,
      sym_div_tok,
      sym_pow_tok,
      sym_and_tok,
      sym_or_tok,
      sym_gtr_tok,
      sym_eq_tok,
      sym_less_tok,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LF,
  [4900] = 1,
    ACTIONS(311), 21,
      sym_goto_tok,
      sym_gosub_tok,
      sym_to_tok,
      sym_then_tok,
      sym_at_tok,
      sym_step_tok,
      sym_plus_tok,
      sym_minus_tok,
      sym_times_tok,
      sym_div_tok,
      sym_pow_tok,
      sym_and_tok,
      sym_or_tok,
      sym_gtr_tok,
      sym_eq_tok,
      sym_less_tok,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LF,
  [4924] = 1,
    ACTIONS(313), 21,
      sym_goto_tok,
      sym_gosub_tok,
      sym_to_tok,
      sym_then_tok,
      sym_at_tok,
      sym_step_tok,
      sym_plus_tok,
      sym_minus_tok,
      sym_times_tok,
      sym_div_tok,
      sym_pow_tok,
      sym_and_tok,
      sym_or_tok,
      sym_gtr_tok,
      sym_eq_tok,
      sym_less_tok,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LF,
  [4948] = 1,
    ACTIONS(315), 21,
      sym_goto_tok,
      sym_gosub_tok,
      sym_to_tok,
      sym_then_tok,
      sym_at_tok,
      sym_step_tok,
      sym_plus_tok,
      sym_minus_tok,
      sym_times_tok,
      sym_div_tok,
      sym_pow_tok,
      sym_and_tok,
      sym_or_tok,
      sym_gtr_tok,
      sym_eq_tok,
      sym_less_tok,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LF,
  [4972] = 1,
    ACTIONS(317), 21,
      sym_goto_tok,
      sym_gosub_tok,
      sym_to_tok,
      sym_then_tok,
      sym_at_tok,
      sym_step_tok,
      sym_plus_tok,
      sym_minus_tok,
      sym_times_tok,
      sym_div_tok,
      sym_pow_tok,
      sym_and_tok,
      sym_or_tok,
      sym_gtr_tok,
      sym_eq_tok,
      sym_less_tok,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LF,
  [4996] = 9,
    ACTIONS(55), 1,
      aux_sym_intvar_token1,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(319), 1,
      anon_sym_LPAREN,
    ACTIONS(321), 1,
      sym_string,
    STATE(140), 1,
      sym_svar,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(162), 4,
      sym__var,
      sym__avar,
      sym_intvar,
      sym_realvar,
    STATE(173), 4,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
  [5034] = 10,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    STATE(35), 1,
      sym__relop,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(323), 7,
      sym_goto_tok,
      sym_then_tok,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LF,
  [5073] = 7,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(319), 1,
      anon_sym_LPAREN,
    ACTIONS(327), 1,
      aux_sym_intvar_token1,
    ACTIONS(329), 1,
      sym_string,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(61), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
  [5103] = 7,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(319), 1,
      anon_sym_LPAREN,
    ACTIONS(327), 1,
      aux_sym_intvar_token1,
    ACTIONS(331), 1,
      sym_string,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(177), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
  [5133] = 7,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(319), 1,
      anon_sym_LPAREN,
    ACTIONS(327), 1,
      aux_sym_intvar_token1,
    ACTIONS(333), 1,
      sym_string,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(66), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
  [5163] = 7,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(319), 1,
      anon_sym_LPAREN,
    ACTIONS(327), 1,
      aux_sym_intvar_token1,
    ACTIONS(335), 1,
      sym_string,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(146), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
  [5193] = 7,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(319), 1,
      anon_sym_LPAREN,
    ACTIONS(327), 1,
      aux_sym_intvar_token1,
    ACTIONS(337), 1,
      sym_string,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(172), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
  [5223] = 7,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(319), 1,
      anon_sym_LPAREN,
    ACTIONS(327), 1,
      aux_sym_intvar_token1,
    ACTIONS(339), 1,
      sym_string,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(168), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
  [5253] = 7,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(319), 1,
      anon_sym_LPAREN,
    ACTIONS(327), 1,
      aux_sym_intvar_token1,
    ACTIONS(341), 1,
      sym_string,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(176), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
  [5283] = 7,
    ACTIONS(147), 1,
      sym_mid_tok,
    ACTIONS(319), 1,
      anon_sym_LPAREN,
    ACTIONS(327), 1,
      aux_sym_intvar_token1,
    ACTIONS(343), 1,
      sym_string,
    ACTIONS(145), 2,
      sym_left_tok,
      sym_right_tok,
    ACTIONS(131), 4,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
    STATE(181), 5,
      sym_sfcall,
      sym__sexpr,
      sym_binary_sexpr,
      sym__parenthesized_sexpr,
      sym_svar,
  [5313] = 12,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    ACTIONS(345), 1,
      anon_sym_COMMA,
    ACTIONS(347), 1,
      anon_sym_RPAREN,
    STATE(35), 1,
      sym__relop,
    STATE(180), 1,
      aux_sym_subscript_repeat1,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
  [5352] = 11,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    ACTIONS(349), 1,
      anon_sym_COMMA,
    STATE(35), 1,
      sym__relop,
    ACTIONS(169), 2,
      anon_sym_COLON,
      anon_sym_LF,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
  [5389] = 11,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    ACTIONS(351), 1,
      sym_to_tok,
    STATE(35), 1,
      sym__relop,
    ACTIONS(169), 2,
      anon_sym_COLON,
      anon_sym_LF,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
  [5426] = 11,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    ACTIONS(353), 1,
      sym_step_tok,
    STATE(35), 1,
      sym__relop,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(355), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [5463] = 11,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    ACTIONS(357), 1,
      sym_at_tok,
    STATE(35), 1,
      sym__relop,
    ACTIONS(165), 2,
      anon_sym_COLON,
      anon_sym_LF,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
  [5500] = 10,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    STATE(35), 1,
      sym__relop,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(359), 2,
      sym_goto_tok,
      sym_gosub_tok,
  [5534] = 10,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    STATE(35), 1,
      sym__relop,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(361), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [5568] = 10,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    STATE(35), 1,
      sym__relop,
    ACTIONS(165), 2,
      anon_sym_COLON,
      anon_sym_LF,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
  [5602] = 10,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    STATE(35), 1,
      sym__relop,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(363), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [5636] = 10,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    STATE(35), 1,
      sym__relop,
    ACTIONS(169), 2,
      anon_sym_COLON,
      anon_sym_LF,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
  [5670] = 7,
    ACTIONS(365), 1,
      sym_plus_tok,
    ACTIONS(367), 1,
      sym_gtr_tok,
    ACTIONS(369), 1,
      sym_eq_tok,
    ACTIONS(371), 1,
      sym_less_tok,
    STATE(83), 1,
      sym__sop,
    STATE(85), 1,
      sym__relop,
    ACTIONS(323), 7,
      sym_goto_tok,
      sym_then_tok,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LF,
  [5698] = 10,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    STATE(35), 1,
      sym__relop,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(355), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [5732] = 10,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    STATE(35), 1,
      sym__relop,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(373), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [5766] = 10,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    STATE(35), 1,
      sym__relop,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
    ACTIONS(375), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [5800] = 11,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    ACTIONS(377), 1,
      anon_sym_COMMA,
    ACTIONS(379), 1,
      anon_sym_RPAREN,
    STATE(35), 1,
      sym__relop,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
  [5836] = 10,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    ACTIONS(379), 1,
      anon_sym_RPAREN,
    STATE(35), 1,
      sym__relop,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
  [5869] = 10,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    ACTIONS(381), 1,
      anon_sym_RPAREN,
    STATE(35), 1,
      sym__relop,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
  [5902] = 10,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    ACTIONS(383), 1,
      anon_sym_RPAREN,
    STATE(35), 1,
      sym__relop,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
  [5935] = 10,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    ACTIONS(385), 1,
      anon_sym_RPAREN,
    STATE(35), 1,
      sym__relop,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
  [5968] = 10,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    ACTIONS(387), 1,
      anon_sym_COMMA,
    STATE(35), 1,
      sym__relop,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
  [6001] = 10,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    ACTIONS(389), 1,
      sym_to_tok,
    STATE(35), 1,
      sym__relop,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
  [6034] = 10,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    ACTIONS(391), 1,
      anon_sym_COMMA,
    STATE(35), 1,
      sym__relop,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
  [6067] = 10,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    ACTIONS(393), 1,
      anon_sym_RPAREN,
    STATE(35), 1,
      sym__relop,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
  [6100] = 10,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    ACTIONS(395), 1,
      anon_sym_RPAREN,
    STATE(35), 1,
      sym__relop,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
  [6133] = 3,
    ACTIONS(255), 1,
      aux_sym_intvar_token1,
    ACTIONS(397), 2,
      sym_eq_tok,
      sym_less_tok,
    ACTIONS(251), 9,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
      sym_left_tok,
      sym_right_tok,
      sym_mid_tok,
      anon_sym_LPAREN,
      sym_string,
  [6152] = 10,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    ACTIONS(399), 1,
      anon_sym_COMMA,
    STATE(35), 1,
      sym__relop,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
  [6185] = 10,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    ACTIONS(401), 1,
      anon_sym_COMMA,
    STATE(35), 1,
      sym__relop,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
  [6218] = 10,
    ACTIONS(129), 1,
      anon_sym_RPAREN,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    STATE(35), 1,
      sym__relop,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
  [6251] = 10,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    ACTIONS(403), 1,
      anon_sym_COMMA,
    STATE(35), 1,
      sym__relop,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
  [6284] = 10,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    ACTIONS(349), 1,
      anon_sym_COMMA,
    STATE(35), 1,
      sym__relop,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
  [6317] = 10,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    ACTIONS(405), 1,
      anon_sym_RPAREN,
    STATE(35), 1,
      sym__relop,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
  [6350] = 10,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    ACTIONS(353), 1,
      anon_sym_COMMA,
    STATE(35), 1,
      sym__relop,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
  [6383] = 10,
    ACTIONS(275), 1,
      sym_pow_tok,
    ACTIONS(285), 1,
      sym_gtr_tok,
    ACTIONS(287), 1,
      sym_eq_tok,
    ACTIONS(289), 1,
      sym_less_tok,
    ACTIONS(291), 1,
      sym_and_tok,
    ACTIONS(325), 1,
      sym_or_tok,
    ACTIONS(349), 1,
      sym_at_tok,
    STATE(35), 1,
      sym__relop,
    ACTIONS(277), 2,
      sym_times_tok,
      sym_div_tok,
    ACTIONS(283), 2,
      sym_plus_tok,
      sym_minus_tok,
  [6416] = 3,
    ACTIONS(255), 1,
      aux_sym_intvar_token1,
    ACTIONS(397), 2,
      sym_gtr_tok,
      sym_less_tok,
    ACTIONS(251), 9,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
      sym_left_tok,
      sym_right_tok,
      sym_mid_tok,
      anon_sym_LPAREN,
      sym_string,
  [6435] = 3,
    ACTIONS(255), 1,
      aux_sym_intvar_token1,
    ACTIONS(397), 2,
      sym_gtr_tok,
      sym_eq_tok,
    ACTIONS(251), 9,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
      sym_left_tok,
      sym_right_tok,
      sym_mid_tok,
      anon_sym_LPAREN,
      sym_string,
  [6454] = 2,
    ACTIONS(259), 1,
      aux_sym_intvar_token1,
    ACTIONS(257), 9,
      sym_tab_tok,
      sym_spc_tok,
      sym_str_tok,
      sym_chr_tok,
      sym_left_tok,
      sym_right_tok,
      sym_mid_tok,
      anon_sym_LPAREN,
      sym_string,
  [6469] = 7,
    ACTIONS(365), 1,
      sym_plus_tok,
    ACTIONS(367), 1,
      sym_gtr_tok,
    ACTIONS(369), 1,
      sym_eq_tok,
    ACTIONS(371), 1,
      sym_less_tok,
    ACTIONS(407), 1,
      anon_sym_RPAREN,
    STATE(83), 1,
      sym__sop,
    STATE(85), 1,
      sym__relop,
  [6491] = 2,
    ACTIONS(409), 1,
      aux_sym_intvar_token1,
    STATE(162), 5,
      sym__var,
      sym__avar,
      sym_intvar,
      sym_realvar,
      sym_svar,
  [6502] = 2,
    ACTIONS(409), 1,
      aux_sym_intvar_token1,
    STATE(170), 5,
      sym__var,
      sym__avar,
      sym_intvar,
      sym_realvar,
      sym_svar,
  [6513] = 3,
    ACTIONS(411), 1,
      aux_sym_intvar_token1,
    ACTIONS(155), 2,
      anon_sym_COLON,
      anon_sym_LF,
    STATE(164), 3,
      sym__avar,
      sym_intvar,
      sym_realvar,
  [6526] = 6,
    ACTIONS(365), 1,
      sym_plus_tok,
    ACTIONS(367), 1,
      sym_gtr_tok,
    ACTIONS(369), 1,
      sym_eq_tok,
    ACTIONS(371), 1,
      sym_less_tok,
    STATE(83), 1,
      sym__sop,
    STATE(85), 1,
      sym__relop,
  [6545] = 4,
    ACTIONS(263), 1,
      anon_sym_LPAREN,
    ACTIONS(265), 1,
      anon_sym_PERCENT,
    STATE(79), 1,
      sym_subscript,
    ACTIONS(261), 3,
      anon_sym_COMMA,
      anon_sym_COLON,
      anon_sym_LF,
  [6560] = 2,
    ACTIONS(409), 1,
      aux_sym_intvar_token1,
    STATE(152), 5,
      sym__var,
      sym__avar,
      sym_intvar,
      sym_realvar,
      sym_svar,
  [6571] = 4,
    ACTIONS(413), 1,
      ts_builtin_sym_end,
    ACTIONS(415), 1,
      sym__empty_line,
    ACTIONS(418), 1,
      sym_linenum,
    STATE(134), 2,
      sym_line,
      aux_sym_source_file_repeat1,
  [6585] = 4,
    ACTIONS(7), 1,
      sym_linenum,
    ACTIONS(421), 1,
      ts_builtin_sym_end,
    ACTIONS(423), 1,
      sym__empty_line,
    STATE(134), 2,
      sym_line,
      aux_sym_source_file_repeat1,
  [6599] = 4,
    ACTIONS(149), 1,
      anon_sym_COMMA,
    ACTIONS(425), 1,
      anon_sym_SEMI,
    STATE(137), 1,
      aux_sym_statement_repeat6,
    ACTIONS(167), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [6613] = 3,
    STATE(137), 1,
      aux_sym_statement_repeat6,
    ACTIONS(427), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
    ACTIONS(430), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [6625] = 2,
    STATE(163), 1,
      sym__data_item,
    ACTIONS(432), 4,
      sym_integer,
      sym_literal,
      sym_real,
      sym_string,
  [6635] = 3,
    ACTIONS(409), 1,
      aux_sym_intvar_token1,
    STATE(215), 1,
      sym_svar,
    STATE(216), 3,
      sym__avar,
      sym_intvar,
      sym_realvar,
  [6647] = 2,
    ACTIONS(434), 2,
      sym_plus_tok,
      anon_sym_SEMI,
    ACTIONS(436), 3,
      anon_sym_COMMA,
      anon_sym_COLON,
      anon_sym_LF,
  [6657] = 4,
    ACTIONS(149), 1,
      anon_sym_COMMA,
    ACTIONS(438), 1,
      anon_sym_SEMI,
    STATE(136), 1,
      aux_sym_statement_repeat6,
    ACTIONS(165), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [6671] = 4,
    ACTIONS(149), 1,
      anon_sym_COMMA,
    ACTIONS(438), 1,
      anon_sym_SEMI,
    STATE(137), 1,
      aux_sym_statement_repeat6,
    ACTIONS(165), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [6685] = 2,
    ACTIONS(409), 1,
      aux_sym_intvar_token1,
    STATE(161), 4,
      sym_intvar,
      sym_realvar,
      sym_svar,
      sym__dim_item,
  [6695] = 2,
    STATE(175), 1,
      sym__data_item,
    ACTIONS(440), 4,
      sym_integer,
      sym_literal,
      sym_real,
      sym_string,
  [6705] = 2,
    ACTIONS(409), 1,
      aux_sym_intvar_token1,
    STATE(171), 4,
      sym_intvar,
      sym_realvar,
      sym_svar,
      sym__dim_item,
  [6715] = 3,
    ACTIONS(365), 1,
      sym_plus_tok,
    STATE(83), 1,
      sym__sop,
    ACTIONS(361), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [6726] = 2,
    ACTIONS(411), 1,
      aux_sym_intvar_token1,
    STATE(183), 3,
      sym__avar,
      sym_intvar,
      sym_realvar,
  [6735] = 3,
    ACTIONS(442), 1,
      anon_sym_COMMA,
    STATE(148), 1,
      aux_sym_statement_repeat5,
    ACTIONS(445), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [6746] = 3,
    ACTIONS(447), 1,
      aux_sym_statement_token1,
    STATE(169), 1,
      aux_sym_statement_repeat7,
    ACTIONS(449), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [6757] = 3,
    ACTIONS(451), 1,
      anon_sym_COMMA,
    STATE(150), 1,
      aux_sym_statement_repeat1,
    ACTIONS(454), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [6768] = 3,
    ACTIONS(456), 1,
      anon_sym_COMMA,
    STATE(153), 1,
      aux_sym_statement_repeat4,
    ACTIONS(167), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [6779] = 3,
    ACTIONS(458), 1,
      anon_sym_COMMA,
    STATE(160), 1,
      aux_sym_statement_repeat3,
    ACTIONS(169), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [6790] = 3,
    ACTIONS(460), 1,
      anon_sym_COMMA,
    STATE(153), 1,
      aux_sym_statement_repeat4,
    ACTIONS(463), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [6801] = 3,
    ACTIONS(465), 1,
      anon_sym_COMMA,
    STATE(150), 1,
      aux_sym_statement_repeat1,
    ACTIONS(167), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [6812] = 3,
    ACTIONS(467), 1,
      anon_sym_COMMA,
    STATE(155), 1,
      aux_sym_statement_repeat3,
    ACTIONS(470), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [6823] = 3,
    ACTIONS(472), 1,
      anon_sym_COMMA,
    STATE(148), 1,
      aux_sym_statement_repeat5,
    ACTIONS(474), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [6834] = 3,
    ACTIONS(476), 1,
      anon_sym_COMMA,
    STATE(157), 1,
      aux_sym_statement_repeat2,
    ACTIONS(479), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [6845] = 3,
    ACTIONS(458), 1,
      anon_sym_COMMA,
    STATE(155), 1,
      aux_sym_statement_repeat3,
    ACTIONS(167), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [6856] = 3,
    ACTIONS(481), 1,
      anon_sym_COMMA,
    STATE(157), 1,
      aux_sym_statement_repeat2,
    ACTIONS(167), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [6867] = 3,
    ACTIONS(458), 1,
      anon_sym_COMMA,
    STATE(155), 1,
      aux_sym_statement_repeat3,
    ACTIONS(474), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [6878] = 3,
    ACTIONS(481), 1,
      anon_sym_COMMA,
    STATE(159), 1,
      aux_sym_statement_repeat2,
    ACTIONS(165), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [6889] = 3,
    ACTIONS(458), 1,
      anon_sym_COMMA,
    STATE(158), 1,
      aux_sym_statement_repeat3,
    ACTIONS(165), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [6900] = 3,
    ACTIONS(465), 1,
      anon_sym_COMMA,
    STATE(154), 1,
      aux_sym_statement_repeat1,
    ACTIONS(165), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [6911] = 3,
    ACTIONS(456), 1,
      anon_sym_COMMA,
    STATE(151), 1,
      aux_sym_statement_repeat4,
    ACTIONS(165), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [6922] = 3,
    ACTIONS(483), 1,
      aux_sym_statement_token1,
    STATE(149), 1,
      aux_sym_statement_repeat7,
    ACTIONS(485), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [6933] = 1,
    ACTIONS(430), 4,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LF,
  [6940] = 3,
    ACTIONS(472), 1,
      anon_sym_COMMA,
    STATE(156), 1,
      aux_sym_statement_repeat5,
    ACTIONS(169), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [6951] = 3,
    ACTIONS(365), 1,
      sym_plus_tok,
    STATE(83), 1,
      sym__sop,
    ACTIONS(375), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [6962] = 3,
    ACTIONS(487), 1,
      aux_sym_statement_token1,
    STATE(169), 1,
      aux_sym_statement_repeat7,
    ACTIONS(490), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [6973] = 1,
    ACTIONS(470), 3,
      anon_sym_COMMA,
      anon_sym_COLON,
      anon_sym_LF,
  [6979] = 1,
    ACTIONS(479), 3,
      anon_sym_COMMA,
      anon_sym_COLON,
      anon_sym_LF,
  [6985] = 3,
    ACTIONS(365), 1,
      sym_plus_tok,
    ACTIONS(381), 1,
      anon_sym_RPAREN,
    STATE(83), 1,
      sym__sop,
  [6995] = 3,
    ACTIONS(365), 1,
      sym_plus_tok,
    ACTIONS(492), 1,
      anon_sym_SEMI,
    STATE(83), 1,
      sym__sop,
  [7005] = 1,
    ACTIONS(445), 3,
      anon_sym_COMMA,
      anon_sym_COLON,
      anon_sym_LF,
  [7011] = 1,
    ACTIONS(454), 3,
      anon_sym_COMMA,
      anon_sym_COLON,
      anon_sym_LF,
  [7017] = 3,
    ACTIONS(365), 1,
      sym_plus_tok,
    ACTIONS(494), 1,
      anon_sym_COMMA,
    STATE(83), 1,
      sym__sop,
  [7027] = 3,
    ACTIONS(365), 1,
      sym_plus_tok,
    ACTIONS(407), 1,
      anon_sym_RPAREN,
    STATE(83), 1,
      sym__sop,
  [7037] = 3,
    ACTIONS(373), 1,
      anon_sym_RPAREN,
    ACTIONS(496), 1,
      anon_sym_COMMA,
    STATE(178), 1,
      aux_sym_subscript_repeat1,
  [7047] = 1,
    ACTIONS(499), 3,
      ts_builtin_sym_end,
      sym__empty_line,
      sym_linenum,
  [7053] = 3,
    ACTIONS(345), 1,
      anon_sym_COMMA,
    ACTIONS(501), 1,
      anon_sym_RPAREN,
    STATE(178), 1,
      aux_sym_subscript_repeat1,
  [7063] = 3,
    ACTIONS(365), 1,
      sym_plus_tok,
    ACTIONS(503), 1,
      anon_sym_COMMA,
    STATE(83), 1,
      sym__sop,
  [7073] = 1,
    ACTIONS(505), 3,
      ts_builtin_sym_end,
      sym__empty_line,
      sym_linenum,
  [7079] = 1,
    ACTIONS(463), 3,
      anon_sym_COMMA,
      anon_sym_COLON,
      anon_sym_LF,
  [7085] = 1,
    ACTIONS(167), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [7090] = 1,
    ACTIONS(165), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [7095] = 2,
    ACTIONS(507), 1,
      anon_sym_COLON,
    ACTIONS(509), 1,
      anon_sym_LF,
  [7102] = 1,
    ACTIONS(169), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [7107] = 2,
    ACTIONS(507), 1,
      anon_sym_COLON,
    ACTIONS(511), 1,
      anon_sym_LF,
  [7114] = 1,
    ACTIONS(155), 2,
      anon_sym_COLON,
      anon_sym_LF,
  [7119] = 2,
    ACTIONS(513), 1,
      sym_goto_tok,
    ACTIONS(515), 1,
      sym_then_tok,
  [7126] = 1,
    ACTIONS(517), 1,
      sym_goto_tok,
  [7130] = 1,
    ACTIONS(519), 1,
      anon_sym_LPAREN,
  [7134] = 1,
    ACTIONS(521), 1,
      sym_linenum,
  [7138] = 1,
    ACTIONS(523), 1,
      sym_fn_tok,
  [7142] = 1,
    ACTIONS(525), 1,
      sym_real_scalar,
  [7146] = 1,
    ACTIONS(527), 1,
      sym_linenum,
  [7150] = 1,
    ACTIONS(529), 1,
      ts_builtin_sym_end,
  [7154] = 1,
    ACTIONS(531), 1,
      anon_sym_RPAREN,
  [7158] = 1,
    ACTIONS(381), 1,
      anon_sym_RPAREN,
  [7162] = 1,
    ACTIONS(267), 1,
      anon_sym_DOLLAR,
  [7166] = 1,
    ACTIONS(533), 1,
      anon_sym_LPAREN,
  [7170] = 1,
    ACTIONS(535), 1,
      anon_sym_LPAREN,
  [7174] = 1,
    ACTIONS(537), 1,
      anon_sym_LPAREN,
  [7178] = 1,
    ACTIONS(539), 1,
      sym_linenum,
  [7182] = 1,
    ACTIONS(541), 1,
      sym_real_scalar,
  [7186] = 1,
    ACTIONS(543), 1,
      anon_sym_LPAREN,
  [7190] = 1,
    ACTIONS(545), 1,
      sym_real_scalar,
  [7194] = 1,
    ACTIONS(547), 1,
      anon_sym_LPAREN,
  [7198] = 1,
    ACTIONS(549), 1,
      sym_eq_tok,
  [7202] = 1,
    ACTIONS(507), 1,
      anon_sym_COLON,
  [7206] = 1,
    ACTIONS(353), 1,
      sym_eq_tok,
  [7210] = 1,
    ACTIONS(551), 1,
      sym_eq_tok,
  [7214] = 1,
    ACTIONS(129), 1,
      sym_linenum,
  [7218] = 1,
    ACTIONS(553), 1,
      sym_eq_tok,
  [7222] = 1,
    ACTIONS(555), 1,
      sym_eq_tok,
  [7226] = 1,
    ACTIONS(557), 1,
      sym_eq_tok,
  [7230] = 1,
    ACTIONS(559), 1,
      sym_linenum,
  [7234] = 1,
    ACTIONS(561), 1,
      anon_sym_LPAREN,
  [7238] = 1,
    ACTIONS(563), 1,
      anon_sym_LPAREN,
  [7242] = 1,
    ACTIONS(565), 1,
      anon_sym_LPAREN,
  [7246] = 1,
    ACTIONS(567), 1,
      anon_sym_LPAREN,
  [7250] = 1,
    ACTIONS(569), 1,
      sym_real_scalar,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 119,
  [SMALL_STATE(4)] = 238,
  [SMALL_STATE(5)] = 357,
  [SMALL_STATE(6)] = 476,
  [SMALL_STATE(7)] = 571,
  [SMALL_STATE(8)] = 629,
  [SMALL_STATE(9)] = 715,
  [SMALL_STATE(10)] = 801,
  [SMALL_STATE(11)] = 887,
  [SMALL_STATE(12)] = 969,
  [SMALL_STATE(13)] = 1051,
  [SMALL_STATE(14)] = 1133,
  [SMALL_STATE(15)] = 1212,
  [SMALL_STATE(16)] = 1291,
  [SMALL_STATE(17)] = 1370,
  [SMALL_STATE(18)] = 1449,
  [SMALL_STATE(19)] = 1528,
  [SMALL_STATE(20)] = 1607,
  [SMALL_STATE(21)] = 1686,
  [SMALL_STATE(22)] = 1765,
  [SMALL_STATE(23)] = 1844,
  [SMALL_STATE(24)] = 1923,
  [SMALL_STATE(25)] = 2002,
  [SMALL_STATE(26)] = 2081,
  [SMALL_STATE(27)] = 2160,
  [SMALL_STATE(28)] = 2239,
  [SMALL_STATE(29)] = 2318,
  [SMALL_STATE(30)] = 2397,
  [SMALL_STATE(31)] = 2476,
  [SMALL_STATE(32)] = 2555,
  [SMALL_STATE(33)] = 2634,
  [SMALL_STATE(34)] = 2713,
  [SMALL_STATE(35)] = 2792,
  [SMALL_STATE(36)] = 2871,
  [SMALL_STATE(37)] = 2950,
  [SMALL_STATE(38)] = 3029,
  [SMALL_STATE(39)] = 3108,
  [SMALL_STATE(40)] = 3187,
  [SMALL_STATE(41)] = 3266,
  [SMALL_STATE(42)] = 3345,
  [SMALL_STATE(43)] = 3424,
  [SMALL_STATE(44)] = 3503,
  [SMALL_STATE(45)] = 3582,
  [SMALL_STATE(46)] = 3661,
  [SMALL_STATE(47)] = 3740,
  [SMALL_STATE(48)] = 3819,
  [SMALL_STATE(49)] = 3898,
  [SMALL_STATE(50)] = 3977,
  [SMALL_STATE(51)] = 4056,
  [SMALL_STATE(52)] = 4135,
  [SMALL_STATE(53)] = 4179,
  [SMALL_STATE(54)] = 4223,
  [SMALL_STATE(55)] = 4267,
  [SMALL_STATE(56)] = 4307,
  [SMALL_STATE(57)] = 4343,
  [SMALL_STATE(58)] = 4373,
  [SMALL_STATE(59)] = 4403,
  [SMALL_STATE(60)] = 4432,
  [SMALL_STATE(61)] = 4463,
  [SMALL_STATE(62)] = 4490,
  [SMALL_STATE(63)] = 4517,
  [SMALL_STATE(64)] = 4544,
  [SMALL_STATE(65)] = 4583,
  [SMALL_STATE(66)] = 4624,
  [SMALL_STATE(67)] = 4651,
  [SMALL_STATE(68)] = 4684,
  [SMALL_STATE(69)] = 4708,
  [SMALL_STATE(70)] = 4732,
  [SMALL_STATE(71)] = 4756,
  [SMALL_STATE(72)] = 4780,
  [SMALL_STATE(73)] = 4804,
  [SMALL_STATE(74)] = 4828,
  [SMALL_STATE(75)] = 4852,
  [SMALL_STATE(76)] = 4876,
  [SMALL_STATE(77)] = 4900,
  [SMALL_STATE(78)] = 4924,
  [SMALL_STATE(79)] = 4948,
  [SMALL_STATE(80)] = 4972,
  [SMALL_STATE(81)] = 4996,
  [SMALL_STATE(82)] = 5034,
  [SMALL_STATE(83)] = 5073,
  [SMALL_STATE(84)] = 5103,
  [SMALL_STATE(85)] = 5133,
  [SMALL_STATE(86)] = 5163,
  [SMALL_STATE(87)] = 5193,
  [SMALL_STATE(88)] = 5223,
  [SMALL_STATE(89)] = 5253,
  [SMALL_STATE(90)] = 5283,
  [SMALL_STATE(91)] = 5313,
  [SMALL_STATE(92)] = 5352,
  [SMALL_STATE(93)] = 5389,
  [SMALL_STATE(94)] = 5426,
  [SMALL_STATE(95)] = 5463,
  [SMALL_STATE(96)] = 5500,
  [SMALL_STATE(97)] = 5534,
  [SMALL_STATE(98)] = 5568,
  [SMALL_STATE(99)] = 5602,
  [SMALL_STATE(100)] = 5636,
  [SMALL_STATE(101)] = 5670,
  [SMALL_STATE(102)] = 5698,
  [SMALL_STATE(103)] = 5732,
  [SMALL_STATE(104)] = 5766,
  [SMALL_STATE(105)] = 5800,
  [SMALL_STATE(106)] = 5836,
  [SMALL_STATE(107)] = 5869,
  [SMALL_STATE(108)] = 5902,
  [SMALL_STATE(109)] = 5935,
  [SMALL_STATE(110)] = 5968,
  [SMALL_STATE(111)] = 6001,
  [SMALL_STATE(112)] = 6034,
  [SMALL_STATE(113)] = 6067,
  [SMALL_STATE(114)] = 6100,
  [SMALL_STATE(115)] = 6133,
  [SMALL_STATE(116)] = 6152,
  [SMALL_STATE(117)] = 6185,
  [SMALL_STATE(118)] = 6218,
  [SMALL_STATE(119)] = 6251,
  [SMALL_STATE(120)] = 6284,
  [SMALL_STATE(121)] = 6317,
  [SMALL_STATE(122)] = 6350,
  [SMALL_STATE(123)] = 6383,
  [SMALL_STATE(124)] = 6416,
  [SMALL_STATE(125)] = 6435,
  [SMALL_STATE(126)] = 6454,
  [SMALL_STATE(127)] = 6469,
  [SMALL_STATE(128)] = 6491,
  [SMALL_STATE(129)] = 6502,
  [SMALL_STATE(130)] = 6513,
  [SMALL_STATE(131)] = 6526,
  [SMALL_STATE(132)] = 6545,
  [SMALL_STATE(133)] = 6560,
  [SMALL_STATE(134)] = 6571,
  [SMALL_STATE(135)] = 6585,
  [SMALL_STATE(136)] = 6599,
  [SMALL_STATE(137)] = 6613,
  [SMALL_STATE(138)] = 6625,
  [SMALL_STATE(139)] = 6635,
  [SMALL_STATE(140)] = 6647,
  [SMALL_STATE(141)] = 6657,
  [SMALL_STATE(142)] = 6671,
  [SMALL_STATE(143)] = 6685,
  [SMALL_STATE(144)] = 6695,
  [SMALL_STATE(145)] = 6705,
  [SMALL_STATE(146)] = 6715,
  [SMALL_STATE(147)] = 6726,
  [SMALL_STATE(148)] = 6735,
  [SMALL_STATE(149)] = 6746,
  [SMALL_STATE(150)] = 6757,
  [SMALL_STATE(151)] = 6768,
  [SMALL_STATE(152)] = 6779,
  [SMALL_STATE(153)] = 6790,
  [SMALL_STATE(154)] = 6801,
  [SMALL_STATE(155)] = 6812,
  [SMALL_STATE(156)] = 6823,
  [SMALL_STATE(157)] = 6834,
  [SMALL_STATE(158)] = 6845,
  [SMALL_STATE(159)] = 6856,
  [SMALL_STATE(160)] = 6867,
  [SMALL_STATE(161)] = 6878,
  [SMALL_STATE(162)] = 6889,
  [SMALL_STATE(163)] = 6900,
  [SMALL_STATE(164)] = 6911,
  [SMALL_STATE(165)] = 6922,
  [SMALL_STATE(166)] = 6933,
  [SMALL_STATE(167)] = 6940,
  [SMALL_STATE(168)] = 6951,
  [SMALL_STATE(169)] = 6962,
  [SMALL_STATE(170)] = 6973,
  [SMALL_STATE(171)] = 6979,
  [SMALL_STATE(172)] = 6985,
  [SMALL_STATE(173)] = 6995,
  [SMALL_STATE(174)] = 7005,
  [SMALL_STATE(175)] = 7011,
  [SMALL_STATE(176)] = 7017,
  [SMALL_STATE(177)] = 7027,
  [SMALL_STATE(178)] = 7037,
  [SMALL_STATE(179)] = 7047,
  [SMALL_STATE(180)] = 7053,
  [SMALL_STATE(181)] = 7063,
  [SMALL_STATE(182)] = 7073,
  [SMALL_STATE(183)] = 7079,
  [SMALL_STATE(184)] = 7085,
  [SMALL_STATE(185)] = 7090,
  [SMALL_STATE(186)] = 7095,
  [SMALL_STATE(187)] = 7102,
  [SMALL_STATE(188)] = 7107,
  [SMALL_STATE(189)] = 7114,
  [SMALL_STATE(190)] = 7119,
  [SMALL_STATE(191)] = 7126,
  [SMALL_STATE(192)] = 7130,
  [SMALL_STATE(193)] = 7134,
  [SMALL_STATE(194)] = 7138,
  [SMALL_STATE(195)] = 7142,
  [SMALL_STATE(196)] = 7146,
  [SMALL_STATE(197)] = 7150,
  [SMALL_STATE(198)] = 7154,
  [SMALL_STATE(199)] = 7158,
  [SMALL_STATE(200)] = 7162,
  [SMALL_STATE(201)] = 7166,
  [SMALL_STATE(202)] = 7170,
  [SMALL_STATE(203)] = 7174,
  [SMALL_STATE(204)] = 7178,
  [SMALL_STATE(205)] = 7182,
  [SMALL_STATE(206)] = 7186,
  [SMALL_STATE(207)] = 7190,
  [SMALL_STATE(208)] = 7194,
  [SMALL_STATE(209)] = 7198,
  [SMALL_STATE(210)] = 7202,
  [SMALL_STATE(211)] = 7206,
  [SMALL_STATE(212)] = 7210,
  [SMALL_STATE(213)] = 7214,
  [SMALL_STATE(214)] = 7218,
  [SMALL_STATE(215)] = 7222,
  [SMALL_STATE(216)] = 7226,
  [SMALL_STATE(217)] = 7230,
  [SMALL_STATE(218)] = 7234,
  [SMALL_STATE(219)] = 7238,
  [SMALL_STATE(220)] = 7242,
  [SMALL_STATE(221)] = 7246,
  [SMALL_STATE(222)] = 7250,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(189),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(195),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(189),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(193),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(165),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(194),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(192),
  [55] = {.entry = {.count = 1, .reusable = false}}, SHIFT(56),
  [57] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_line_repeat1, 2), SHIFT_REPEAT(189),
  [60] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_line_repeat1, 2), SHIFT_REPEAT(195),
  [63] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_line_repeat1, 2), SHIFT_REPEAT(130),
  [66] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_line_repeat1, 2), SHIFT_REPEAT(138),
  [69] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_line_repeat1, 2), SHIFT_REPEAT(81),
  [72] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_line_repeat1, 2), SHIFT_REPEAT(143),
  [75] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_line_repeat1, 2), SHIFT_REPEAT(128),
  [78] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_line_repeat1, 2), SHIFT_REPEAT(18),
  [81] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_line_repeat1, 2), SHIFT_REPEAT(19),
  [84] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_line_repeat1, 2), SHIFT_REPEAT(20),
  [87] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_line_repeat1, 2), SHIFT_REPEAT(189),
  [90] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_line_repeat1, 2), SHIFT_REPEAT(21),
  [93] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_line_repeat1, 2), SHIFT_REPEAT(22),
  [96] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_line_repeat1, 2), SHIFT_REPEAT(191),
  [99] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_line_repeat1, 2), SHIFT_REPEAT(139),
  [102] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_line_repeat1, 2), SHIFT_REPEAT(193),
  [105] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_line_repeat1, 2), SHIFT_REPEAT(11),
  [108] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_line_repeat1, 2), SHIFT_REPEAT(165),
  [111] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_line_repeat1, 2), SHIFT_REPEAT(25),
  [114] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_line_repeat1, 2), SHIFT_REPEAT(26),
  [117] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_line_repeat1, 2), SHIFT_REPEAT(194),
  [120] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_line_repeat1, 2), SHIFT_REPEAT(6),
  [123] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_line_repeat1, 2), SHIFT_REPEAT(192),
  [126] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_line_repeat1, 2), SHIFT_REPEAT(56),
  [129] = {.entry = {.count = 1, .reusable = true}}, SHIFT(187),
  [131] = {.entry = {.count = 1, .reusable = true}}, SHIFT(203),
  [133] = {.entry = {.count = 1, .reusable = true}}, SHIFT(222),
  [135] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(221),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(220),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(219),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(202),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(201),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement, 1),
  [157] = {.entry = {.count = 1, .reusable = false}}, SHIFT(82),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_line_repeat1, 2),
  [163] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_line_repeat1, 2),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement, 2),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement, 3),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement, 4),
  [171] = {.entry = {.count = 1, .reusable = false}}, SHIFT(104),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [175] = {.entry = {.count = 1, .reusable = false}}, SHIFT(112),
  [177] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [179] = {.entry = {.count = 1, .reusable = false}}, SHIFT(103),
  [181] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [183] = {.entry = {.count = 1, .reusable = false}}, SHIFT(119),
  [185] = {.entry = {.count = 1, .reusable = false}}, SHIFT(117),
  [187] = {.entry = {.count = 1, .reusable = false}}, SHIFT(110),
  [189] = {.entry = {.count = 1, .reusable = false}}, SHIFT(95),
  [191] = {.entry = {.count = 1, .reusable = false}}, SHIFT(118),
  [193] = {.entry = {.count = 1, .reusable = false}}, SHIFT(121),
  [195] = {.entry = {.count = 1, .reusable = false}}, SHIFT(96),
  [197] = {.entry = {.count = 1, .reusable = false}}, SHIFT(116),
  [199] = {.entry = {.count = 1, .reusable = false}}, SHIFT(92),
  [201] = {.entry = {.count = 1, .reusable = false}}, SHIFT(107),
  [203] = {.entry = {.count = 1, .reusable = false}}, SHIFT(91),
  [205] = {.entry = {.count = 1, .reusable = false}}, SHIFT(120),
  [207] = {.entry = {.count = 1, .reusable = false}}, SHIFT(108),
  [209] = {.entry = {.count = 1, .reusable = false}}, SHIFT(93),
  [211] = {.entry = {.count = 1, .reusable = false}}, SHIFT(123),
  [213] = {.entry = {.count = 1, .reusable = false}}, SHIFT(100),
  [215] = {.entry = {.count = 1, .reusable = false}}, SHIFT(67),
  [217] = {.entry = {.count = 1, .reusable = false}}, SHIFT(111),
  [219] = {.entry = {.count = 1, .reusable = false}}, SHIFT(99),
  [221] = {.entry = {.count = 1, .reusable = false}}, SHIFT(122),
  [223] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [225] = {.entry = {.count = 1, .reusable = false}}, SHIFT(64),
  [227] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [229] = {.entry = {.count = 1, .reusable = false}}, SHIFT(59),
  [231] = {.entry = {.count = 1, .reusable = false}}, SHIFT(102),
  [233] = {.entry = {.count = 1, .reusable = false}}, SHIFT(113),
  [235] = {.entry = {.count = 1, .reusable = false}}, SHIFT(105),
  [237] = {.entry = {.count = 1, .reusable = false}}, SHIFT(62),
  [239] = {.entry = {.count = 1, .reusable = false}}, SHIFT(114),
  [241] = {.entry = {.count = 1, .reusable = false}}, SHIFT(106),
  [243] = {.entry = {.count = 1, .reusable = false}}, SHIFT(97),
  [245] = {.entry = {.count = 1, .reusable = false}}, SHIFT(60),
  [247] = {.entry = {.count = 1, .reusable = false}}, SHIFT(109),
  [249] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [251] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__relop, 1),
  [253] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [255] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__relop, 1),
  [257] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__relop, 2),
  [259] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__relop, 2),
  [261] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_realvar, 1),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [265] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [267] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [269] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_svar, 2),
  [271] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_intvar, 2),
  [273] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_aexpr, 3),
  [275] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [277] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [279] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_sexpr, 3),
  [281] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unary_aexpr, 2),
  [283] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [285] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [289] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [291] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [293] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fcall, 5),
  [295] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_sfcall, 4),
  [297] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_intvar, 3),
  [299] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_sfcall, 8),
  [301] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_subscript, 4),
  [303] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__parenthesized_aexpr, 3),
  [305] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fcall, 4),
  [307] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fcall, 6),
  [309] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_sfcall, 6),
  [311] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__parenthesized_sexpr, 3),
  [313] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_svar, 3),
  [315] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_realvar, 2),
  [317] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_subscript, 3),
  [319] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(173),
  [323] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expr, 1),
  [325] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [327] = {.entry = {.count = 1, .reusable = false}}, SHIFT(200),
  [329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [331] = {.entry = {.count = 1, .reusable = true}}, SHIFT(177),
  [333] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
  [337] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [339] = {.entry = {.count = 1, .reusable = true}}, SHIFT(168),
  [341] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [343] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [345] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [347] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [349] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [351] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [353] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [355] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement, 6),
  [357] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [359] = {.entry = {.count = 1, .reusable = true}}, SHIFT(204),
  [361] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment, 3),
  [363] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement, 8),
  [365] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [367] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [369] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [371] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [373] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_subscript_repeat1, 2),
  [375] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment, 4),
  [377] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [379] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [381] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [383] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [385] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [387] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [389] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [391] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [393] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [395] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [397] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [399] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [401] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [403] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [405] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [407] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [409] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [411] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [413] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [415] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(134),
  [418] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(2),
  [421] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [423] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [425] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [427] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_statement_repeat6, 2), SHIFT_REPEAT(12),
  [430] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_statement_repeat6, 2),
  [432] = {.entry = {.count = 1, .reusable = false}}, SHIFT(163),
  [434] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__sexpr, 1),
  [436] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__var, 1),
  [438] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [440] = {.entry = {.count = 1, .reusable = false}}, SHIFT(175),
  [442] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_statement_repeat5, 2), SHIFT_REPEAT(196),
  [445] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_statement_repeat5, 2),
  [447] = {.entry = {.count = 1, .reusable = false}}, SHIFT(169),
  [449] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_statement, 2),
  [451] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_statement_repeat1, 2), SHIFT_REPEAT(144),
  [454] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_statement_repeat1, 2),
  [456] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [458] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [460] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_statement_repeat4, 2), SHIFT_REPEAT(147),
  [463] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_statement_repeat4, 2),
  [465] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [467] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_statement_repeat3, 2), SHIFT_REPEAT(129),
  [470] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_statement_repeat3, 2),
  [472] = {.entry = {.count = 1, .reusable = true}}, SHIFT(196),
  [474] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement, 5),
  [476] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_statement_repeat2, 2), SHIFT_REPEAT(145),
  [479] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_statement_repeat2, 2),
  [481] = {.entry = {.count = 1, .reusable = true}}, SHIFT(145),
  [483] = {.entry = {.count = 1, .reusable = false}}, SHIFT(149),
  [485] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_statement, 1),
  [487] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_statement_repeat7, 2), SHIFT_REPEAT(169),
  [490] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_statement_repeat7, 2),
  [492] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [494] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [496] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_subscript_repeat1, 2), SHIFT_REPEAT(17),
  [499] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_line, 3),
  [501] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [503] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [505] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_line, 4),
  [507] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [509] = {.entry = {.count = 1, .reusable = true}}, SHIFT(182),
  [511] = {.entry = {.count = 1, .reusable = true}}, SHIFT(179),
  [513] = {.entry = {.count = 1, .reusable = true}}, SHIFT(213),
  [515] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [517] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [519] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [521] = {.entry = {.count = 1, .reusable = true}}, SHIFT(185),
  [523] = {.entry = {.count = 1, .reusable = true}}, SHIFT(207),
  [525] = {.entry = {.count = 1, .reusable = true}}, SHIFT(209),
  [527] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [529] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [531] = {.entry = {.count = 1, .reusable = true}}, SHIFT(211),
  [533] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [535] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [537] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [539] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [541] = {.entry = {.count = 1, .reusable = true}}, SHIFT(198),
  [543] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [545] = {.entry = {.count = 1, .reusable = true}}, SHIFT(208),
  [547] = {.entry = {.count = 1, .reusable = true}}, SHIFT(205),
  [549] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [551] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [553] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [555] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [557] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [559] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [561] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [563] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [565] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [567] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [569] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_AppleSoft(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
