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
#define	DOUBLE_LITERAL	263
#define	INTEGER_LITERAL	264
#define	STRING_LITERAL	265
#define	IDENTIFIER	266
#define	RIGHT_PAREN	267
#define	LEFT_BRACE	268
#define	RIGHT_BRACE	269
#define	SEMICOLON	270
#define	COMMA	271
#define	ASSIGN	272
#define	ADD	273
#define	SUB	274
#define	MUL	275
#define	DIV	276
#define	IFX	277
#define	ELSE	278
#define	LEFT_PAREN	279


extern YYSTYPE yylval;
