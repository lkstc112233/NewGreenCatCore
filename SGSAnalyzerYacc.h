typedef union
{
	void				*pointer;
	long long			integer_value;
	long double			float_value;
	char*				string_value;
} YYSTYPE;
#define	IF	257
#define	FOR	258
#define	WHILE	259
#define	DO	260
#define	FUNCTION	261
#define	VAR	262
#define	DOUBLE_LITERAL	263
#define	INTEGER_LITERAL	264
#define	STRING_LITERAL	265
#define	IDENTIFIER	266
#define	RIGHT_PAREN	267
#define	LEFT_BRACE	268
#define	RIGHT_BRACE	269
#define	SEMICOLON	270
#define	COMMA	271
#define	LIST_SEAT	272
#define	ASSIGN	273
#define	ADD	274
#define	SUB	275
#define	MUL	276
#define	DIV	277
#define	IFX	278
#define	ELSE	279
#define	LEFT_PAREN	280


extern YYSTYPE yylval;
