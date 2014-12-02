typedef union
{
	void				*pointer;
	long long			integer_value;
	long double			float_value;
	char*				string_value;
	int					identifier_id;
} YYSTYPE;
#define	IF	257
#define	FOR	258
#define	WHILE	259
#define	DO	260
#define	FUNCTION	261
#define	VAR	262
#define	RETURN	263
#define	DOUBLE_LITERAL	264
#define	INTEGER_LITERAL	265
#define	STRING_LITERAL	266
#define	IDENTIFIER	267
#define	RIGHT_PAREN	268
#define	LEFT_BRACE	269
#define	RIGHT_BRACE	270
#define	SEMICOLON	271
#define	COMMA	272
#define	ASSIGN	273
#define	LESS	274
#define	MORE	275
#define	ADD	276
#define	SUB	277
#define	MUL	278
#define	DIV	279
#define	LEFT_PAREN	280
#define	DOT	281
#define	IFX	282
#define	ELSE	283
#define	DOTED	284


extern YYSTYPE yylval;
