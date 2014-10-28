
/*  A Bison parser, made from sgsanalyzer.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

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

#line 1 "sgsanalyzer.y"

#include <stdlib.h>
#include "SGSAnalyzerWarper.h"
/*#include "AnalyzerExpression.h"*/
int yyerror(char *s);
int yylex(void);

#line 8 "sgsanalyzer.y"
typedef union
{
	void				*pointer;
	long long			integer_value;
	long double			float_value;
	char*				string_value;
	int					identifier_id;
} YYSTYPE;
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		89
#define	YYFLAG		-32768
#define	YYNTBASE	26

#define YYTRANSLATE(x) ((unsigned)(x) <= 279 ? yytranslate[x] : 32)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     5,     7,    10,    12,    16,    18,    22,    24,
    27,    30,    34,    38,    44,    50,    58,    68,    74,    82,
    84,    86,    88,    90,    97,   103,   109,   114,   118,   122,
   127,   131,   135,   139,   143
};

static const short yyrhs[] = {    30,
     0,    26,    30,     0,    30,     0,    27,    30,     0,    12,
     0,    28,    17,    12,     0,    31,     0,    29,    17,    31,
     0,    16,     0,    14,    15,     0,    31,    16,     0,    14,
    27,    15,     0,     8,    12,    16,     0,     8,    12,    18,
    31,    16,     0,     3,    25,    31,    13,    30,     0,     3,
    25,    31,    13,    30,    24,    30,     0,     4,    25,    31,
    16,    31,    16,    31,    13,    30,     0,     5,    25,    31,
    13,    30,     0,     6,    30,     5,    25,    31,    13,    16,
     0,     9,     0,    10,     0,    11,     0,    12,     0,     7,
    12,    25,    28,    13,    30,     0,     7,    12,    25,    13,
    30,     0,     7,    25,    28,    13,    30,     0,     7,    25,
    13,    30,     0,    25,    31,    13,     0,    31,    25,    13,
     0,    31,    25,    29,    13,     0,    31,    19,    31,     0,
    31,    20,    31,     0,    31,    21,    31,     0,    31,    22,
    31,     0,    31,    18,    31,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    32,    33,    37,    38,    42,    43,    47,    48,    52,    53,
    54,    55,    56,    57,    58,    62,    66,    70,    74,    81,
    82,    83,    84,    85,    89,    93,    97,   101,   102,   103,
   104,   105,   106,   107,   108
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","IF","FOR",
"WHILE","DO","FUNCTION","VAR","DOUBLE_LITERAL","INTEGER_LITERAL","STRING_LITERAL",
"IDENTIFIER","RIGHT_PAREN","LEFT_BRACE","RIGHT_BRACE","SEMICOLON","COMMA","ASSIGN",
"ADD","SUB","MUL","DIV","IFX","ELSE","LEFT_PAREN","final","statements_list",
"parameters","arguments","statement","expression", NULL
};
#endif

static const short yyr1[] = {     0,
    26,    26,    27,    27,    28,    28,    29,    29,    30,    30,
    30,    30,    30,    30,    30,    30,    30,    30,    30,    31,
    31,    31,    31,    31,    31,    31,    31,    31,    31,    31,
    31,    31,    31,    31,    31
};

static const short yyr2[] = {     0,
     1,     2,     1,     2,     1,     3,     1,     3,     1,     2,
     2,     3,     3,     5,     5,     7,     9,     5,     7,     1,
     1,     1,     1,     6,     5,     5,     4,     3,     3,     4,
     3,     3,     3,     3,     3
};

static const short yydefact[] = {     0,
     0,     0,     0,     0,     0,     0,    20,    21,    22,    23,
     0,     9,     0,     0,     1,     0,     0,     0,     0,     0,
     0,     0,     0,    10,     0,     3,     0,     2,    11,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     5,     0,     0,    13,     0,    12,     4,    28,    35,    31,
    32,    33,    34,    29,     0,     7,     0,     0,     0,     0,
     0,     0,    27,     0,     0,     0,    30,     0,    15,     0,
    18,     0,    25,     0,    26,     6,    14,     8,     0,     0,
     0,    24,    16,     0,    19,     0,    17,     0,     0
};

static const short yydefgoto[] = {    14,
    25,    43,    55,    15,    16
};

static const short yypact[] = {   149,
   -23,   -12,    12,   149,    -3,     8,-32768,-32768,-32768,-32768,
   103,-32768,    -6,    80,-32768,    79,    -6,    -6,    -6,    40,
    17,    13,    18,-32768,   126,-32768,   151,-32768,-32768,    -6,
    -6,    -6,    -6,    -6,    37,   162,   200,   172,    26,    28,
-32768,   149,    -5,-32768,    -6,-32768,-32768,-32768,   102,     2,
     2,    27,    27,-32768,     1,   102,   149,    -6,   149,    -6,
   149,    22,-32768,   149,    42,   208,-32768,    -6,    35,   216,
-32768,   182,-32768,   149,-32768,-32768,-32768,   102,   149,    -6,
    45,-32768,-32768,   192,-32768,   149,-32768,    63,-32768
};

static const short yypgoto[] = {-32768,
-32768,    24,-32768,    -4,    -2
};


#define	YYLAST		241


static const short yytable[] = {    20,
     5,    17,     7,     8,     9,    10,    26,    64,    21,    28,
    27,    65,    18,    67,    36,    37,    38,    68,    13,    23,
    47,    22,    33,    34,    41,    42,    35,    49,    50,    51,
    52,    53,    56,    44,    74,    45,    19,    63,    65,    41,
    61,    40,    66,     5,    39,     7,     8,     9,    10,    54,
    60,    35,    69,    76,    71,    70,    73,    72,    79,    75,
    85,    13,    89,    62,     0,    78,     0,     0,     0,    82,
     0,     0,     0,     0,    83,     0,     0,    84,     0,    88,
     0,    87,     1,     2,     3,     4,     5,     6,     7,     8,
     9,    10,     0,    11,    29,    12,    30,    31,    32,    33,
    34,     0,     0,    35,    13,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,     0,    11,    24,    12,    30,
    31,    32,    33,    34,     0,     0,    35,    13,     1,     2,
     3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
    46,    12,     0,     0,     0,     0,     0,     0,     0,     0,
    13,     1,     2,     3,     4,     5,     6,     7,     8,     9,
    10,     0,    11,    48,    12,     0,     0,     0,    30,    31,
    32,    33,    34,    13,    57,    35,     0,     0,     0,    30,
    31,    32,    33,    34,    59,     0,    35,     0,     0,    30,
    31,    32,    33,    34,    81,     0,    35,     0,     0,    30,
    31,    32,    33,    34,    86,     0,    35,     0,     0,    30,
    31,    32,    33,    34,     0,    58,    35,    30,    31,    32,
    33,    34,     0,    77,    35,    30,    31,    32,    33,    34,
     0,    80,    35,    30,    31,    32,    33,    34,     0,     0,
    35
};

static const short yycheck[] = {     4,
     7,    25,     9,    10,    11,    12,    11,    13,    12,    14,
    13,    17,    25,    13,    17,    18,    19,    17,    25,    12,
    25,    25,    21,    22,    12,    13,    25,    30,    31,    32,
    33,    34,    35,    16,    13,    18,    25,    42,    17,    12,
    13,    25,    45,     7,     5,     9,    10,    11,    12,    13,
    25,    25,    57,    12,    59,    58,    61,    60,    24,    64,
    16,    25,     0,    40,    -1,    68,    -1,    -1,    -1,    74,
    -1,    -1,    -1,    -1,    79,    -1,    -1,    80,    -1,     0,
    -1,    86,     3,     4,     5,     6,     7,     8,     9,    10,
    11,    12,    -1,    14,    16,    16,    18,    19,    20,    21,
    22,    -1,    -1,    25,    25,     3,     4,     5,     6,     7,
     8,     9,    10,    11,    12,    -1,    14,    15,    16,    18,
    19,    20,    21,    22,    -1,    -1,    25,    25,     3,     4,
     5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    25,     3,     4,     5,     6,     7,     8,     9,    10,    11,
    12,    -1,    14,    13,    16,    -1,    -1,    -1,    18,    19,
    20,    21,    22,    25,    13,    25,    -1,    -1,    -1,    18,
    19,    20,    21,    22,    13,    -1,    25,    -1,    -1,    18,
    19,    20,    21,    22,    13,    -1,    25,    -1,    -1,    18,
    19,    20,    21,    22,    13,    -1,    25,    -1,    -1,    18,
    19,    20,    21,    22,    -1,    16,    25,    18,    19,    20,
    21,    22,    -1,    16,    25,    18,    19,    20,    21,    22,
    -1,    16,    25,    18,    19,    20,    21,    22,    -1,    -1,
    25
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Bob Corbett and Richard Stallman

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 1, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */


#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc)
#include <alloca.h>
#else /* not sparc */
#if (defined (MSDOS) || defined(WIN32)) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#define YYLEX		yylex(&yylval, &yylloc)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_bcopy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_bcopy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_bcopy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif


#line 169 "bison.simple"
int
yyparse()
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
#ifdef YYLSP_NEEDED
		 &yyls1, size * sizeof (*yylsp),
#endif
		 &yystacksize);

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_bcopy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_bcopy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_bcopy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 32 "sgsanalyzer.y"
{ addStatement(yyvsp[0].pointer); ;
    break;}
case 2:
#line 33 "sgsanalyzer.y"
{ addStatement(yyvsp[0].pointer); ;
    break;}
case 3:
#line 37 "sgsanalyzer.y"
{ yyval.pointer = getStatementsBlockStatement(yyvsp[0].pointer); ;
    break;}
case 4:
#line 38 "sgsanalyzer.y"
{ yyval.pointer = addStatementToStatementsBlock(yyvsp[-1].pointer,yyvsp[0].pointer); ;
    break;}
case 5:
#line 42 "sgsanalyzer.y"
{ yyval.pointer = getParametersList(yyvsp[0].identifier_id); ;
    break;}
case 6:
#line 43 "sgsanalyzer.y"
{ yyval.pointer = addParameterToParametersList(yyvsp[-2].pointer,yyvsp[0].identifier_id); ;
    break;}
case 7:
#line 47 "sgsanalyzer.y"
{ yyval.pointer = getArgumentsList(yyvsp[0].pointer); ;
    break;}
case 8:
#line 48 "sgsanalyzer.y"
{ yyval.pointer = addParameterToArgumentsList(yyvsp[-2].pointer,yyvsp[0].pointer); ;
    break;}
case 9:
#line 52 "sgsanalyzer.y"
{ yyval.pointer = getEmptyStatement(); ;
    break;}
case 10:
#line 53 "sgsanalyzer.y"
{ yyval.pointer = getEmptyStatement(); ;
    break;}
case 11:
#line 54 "sgsanalyzer.y"
{ yyval.pointer = getExpressionStatement(yyvsp[-1].pointer); ;
    break;}
case 12:
#line 55 "sgsanalyzer.y"
{ yyval.pointer = yyvsp[-1].pointer; ;
    break;}
case 13:
#line 56 "sgsanalyzer.y"
{ yyval.pointer = getVariableDefineStatement(yyvsp[-1].identifier_id); ;
    break;}
case 14:
#line 57 "sgsanalyzer.y"
{ yyval.pointer = getVariableDefineAndInitializeStatement(yyvsp[-3].identifier_id,yyvsp[-1].pointer); ;
    break;}
case 15:
#line 59 "sgsanalyzer.y"
{
		yyval.pointer = getIfStatement(yyvsp[-2].pointer,yyvsp[0].pointer); 
	;
    break;}
case 16:
#line 63 "sgsanalyzer.y"
{
		yyval.pointer = getIfxStatement(yyvsp[-4].pointer,yyvsp[-2].pointer,yyvsp[0].pointer);
	;
    break;}
case 17:
#line 67 "sgsanalyzer.y"
{
		yyval.pointer = getForStatement(yyvsp[-6].pointer,yyvsp[-4].pointer,yyvsp[-2].pointer,yyvsp[0].pointer);
	;
    break;}
case 18:
#line 71 "sgsanalyzer.y"
{
		yyval.pointer = getWhileStatement(yyvsp[-2].pointer,yyvsp[0].pointer);
	;
    break;}
case 19:
#line 75 "sgsanalyzer.y"
{
		yyval.pointer = getDoStatement(yyvsp[-2].pointer,yyvsp[-5].pointer);
	;
    break;}
case 20:
#line 81 "sgsanalyzer.y"
{ yyval.pointer = getFloatExpression(yyvsp[0].float_value); ;
    break;}
case 21:
#line 82 "sgsanalyzer.y"
{ yyval.pointer = getIntegerExpression(yyvsp[0].integer_value); ;
    break;}
case 22:
#line 83 "sgsanalyzer.y"
{ yyval.pointer = getStringExpression(yyvsp[0].string_value); ;
    break;}
case 23:
#line 84 "sgsanalyzer.y"
{ yyval.pointer = getIdentifierExpression(yyvsp[0].identifier_id); ;
    break;}
case 24:
#line 86 "sgsanalyzer.y"
{
		yyval.pointer = getAssignOperatorExpression(getIdentifierExpression(yyvsp[-4].identifier_id),getFunctionExpression(makeFunctionWithParameters(yyvsp[0].pointer,yyvsp[-2].pointer)));
	;
    break;}
case 25:
#line 90 "sgsanalyzer.y"
{
		yyval.pointer = getAssignOperatorExpression(getIdentifierExpression(yyvsp[-3].identifier_id),getFunctionExpression(makeFunctionWithoutParameters(yyvsp[0].pointer)));
	;
    break;}
case 26:
#line 94 "sgsanalyzer.y"
{
		yyval.pointer = getFunctionExpression(makeFunctionWithParameters(yyvsp[0].pointer,yyvsp[-2].pointer));
	;
    break;}
case 27:
#line 98 "sgsanalyzer.y"
{
		yyval.pointer = getFunctionExpression(makeFunctionWithoutParameters(yyvsp[0].pointer));
	;
    break;}
case 28:
#line 101 "sgsanalyzer.y"
{ yyval.pointer = yyvsp[-1].pointer; ;
    break;}
case 29:
#line 102 "sgsanalyzer.y"
{ yyval.pointer = getFunctionCallFunctionWithoutArguments(yyvsp[-2].pointer); ;
    break;}
case 30:
#line 103 "sgsanalyzer.y"
{ yyval.pointer = getFunctionCallFunctionWithArguments(yyvsp[-3].pointer,yyvsp[-1].pointer); ;
    break;}
case 31:
#line 104 "sgsanalyzer.y"
{ yyval.pointer = getAddOperatorExpression(yyvsp[-2].pointer,yyvsp[0].pointer); ;
    break;}
case 32:
#line 105 "sgsanalyzer.y"
{ yyval.pointer = getSubOperatorExpression(yyvsp[-2].pointer,yyvsp[0].pointer); ;
    break;}
case 33:
#line 106 "sgsanalyzer.y"
{ yyval.pointer = getMulOperatorExpression(yyvsp[-2].pointer,yyvsp[0].pointer); ;
    break;}
case 34:
#line 107 "sgsanalyzer.y"
{ yyval.pointer = getDivOperatorExpression(yyvsp[-2].pointer,yyvsp[0].pointer); ;
    break;}
case 35:
#line 108 "sgsanalyzer.y"
{ yyval.pointer = getAssignOperatorExpression(yyvsp[-2].pointer,yyvsp[0].pointer); ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 442 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  for (x = 0; x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = 0; x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 111 "sgsanalyzer.y"

int yyerror(char *s)
{
	return fprintf(stderr,"%s\n",s);
}
