module.exports = grammar({
	name: 'tinybasic',
	extras: $ => [' '],
	word: $ => $.then_tok,
	rules: {
		source_file: $ => repeat($.line),
		line: $ => seq($.linenum,$.if_tok,$.realvar,$.then_tok,$.linenum,'\n'),
		if_tok: $ => /I *F/,
		then_tok: $ => /T *H *E *N/,
		linenum: $ => /[0-9]([0-9 ]*[0-9])?/,
		realvar: $ => /[A-Z]([A-Z0-9 ]*[A-Z0-9])?/
	}
});
