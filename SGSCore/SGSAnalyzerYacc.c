
/*  A Bison parser, made from sgsanalyzer.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

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



#define	YYFINAL		102
#define	YYFLAG		-32768
#define	YYNTBASE	31

#define YYTRANSLATE(x) ((unsigned)(x) <= 284 ? yytranslate[x] : 37)

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
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     5,     7,    10,    12,    16,    18,    22,    24,
    27,    30,    34,    38,    44,    50,    58,    68,    74,    82,
    85,    89,    91,    93,    95,    97,   104,   110,   116,   121,
   125,   129,   134,   140,   144,   148,   152,   156,   160,   164,
   168
};

static const short yyrhs[] = {    35,
     0,    31,    35,     0,    35,     0,    32,    35,     0,    13,
     0,    33,    18,    13,     0,    36,     0,    34,    18,    36,
     0,    17,     0,    15,    16,     0,    36,    17,     0,    15,
    32,    16,     0,     8,    13,    17,     0,     8,    13,    19,
    36,    17,     0,     3,    26,    36,    14,    35,     0,     3,
    26,    36,    14,    35,    29,    35,     0,     4,    26,    36,
    17,    36,    17,    36,    14,    35,     0,     5,    26,    36,
    14,    35,     0,     6,    35,     5,    26,    36,    14,    17,
     0,     9,    17,     0,     9,    36,    17,     0,    10,     0,
    11,     0,    12,     0,    13,     0,     7,    13,    26,    33,
    14,    35,     0,     7,    13,    26,    14,    35,     0,     7,
    26,    33,    14,    35,     0,     7,    26,    14,    35,     0,
    26,    36,    14,     0,    36,    26,    14,     0,    36,    26,
    34,    14,     0,    36,    27,    26,    36,    14,     0,    36,
    27,    13,     0,    36,    22,    36,     0,    36,    23,    36,
     0,    36,    24,    36,     0,    36,    25,    36,     0,    36,
    20,    36,     0,    36,    21,    36,     0,    36,    19,    36,
     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    35,    36,    40,    41,    45,    46,    50,    51,    55,    56,
    57,    58,    59,    60,    61,    65,    69,    73,    77,    81,
    82,    86,    87,    88,    89,    90,    94,    98,   102,   106,
   107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
   117
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","IF","FOR",
"WHILE","DO","FUNCTION","VAR","RETURN","DOUBLE_LITERAL","INTEGER_LITERAL","STRING_LITERAL",
"IDENTIFIER","RIGHT_PAREN","LEFT_BRACE","RIGHT_BRACE","SEMICOLON","COMMA","ASSIGN",
"LESS","MORE","ADD","SUB","MUL","DIV","LEFT_PAREN","DOT","IFX","ELSE","DOTED",
"final","statements_list","parameters","arguments","statement","expression", NULL
};
#endif

static const short yyr1[] = {     0,
    31,    31,    32,    32,    33,    33,    34,    34,    35,    35,
    35,    35,    35,    35,    35,    35,    35,    35,    35,    35,
    35,    36,    36,    36,    36,    36,    36,    36,    36,    36,
    36,    36,    36,    36,    36,    36,    36,    36,    36,    36,
    36
};

static const short yyr2[] = {     0,
     1,     2,     1,     2,     1,     3,     1,     3,     1,     2,
     2,     3,     3,     5,     5,     7,     9,     5,     7,     2,
     3,     1,     1,     1,     1,     6,     5,     5,     4,     3,
     3,     4,     5,     3,     3,     3,     3,     3,     3,     3,
     3
};

static const short yydefact[] = {     0,
     0,     0,     0,     0,     0,     0,     0,    22,    23,    24,
    25,     0,     9,     0,     0,     1,     0,     0,     0,     0,
     0,     0,     0,     0,    20,     0,    10,     0,     3,     0,
     2,    11,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     5,     0,     0,    13,
     0,    21,    12,     4,    30,    41,    39,    40,    35,    36,
    37,    38,    31,     0,     7,    34,     0,     0,     0,     0,
     0,     0,     0,    29,     0,     0,     0,    32,     0,     0,
    15,     0,    18,     0,    27,     0,    28,     6,    14,     8,
    33,     0,     0,     0,    26,    16,     0,    19,     0,    17,
     0,     0
};

static const short yydefgoto[] = {    15,
    28,    49,    64,    16,    17
};

static const short yypact[] = {   165,
   -19,     4,    17,   165,   -12,    37,    35,-32768,-32768,-32768,
-32768,   117,-32768,    44,    93,-32768,   254,    44,    44,    44,
    54,    27,   -10,    41,-32768,   265,-32768,   141,-32768,   173,
-32768,-32768,    44,    44,    44,    44,    44,    44,    44,    15,
   -11,   187,   276,   201,    36,     7,-32768,   165,    -8,-32768,
    44,-32768,-32768,-32768,-32768,   307,    89,    89,    48,    48,
    13,    13,-32768,    -5,   307,-32768,    44,   165,    44,   165,
    44,   165,     5,-32768,   165,    50,   287,-32768,    44,   215,
    47,   298,-32768,   229,-32768,   165,-32768,-32768,-32768,   307,
-32768,   165,    44,    61,-32768,-32768,   243,-32768,   165,-32768,
    79,-32768
};

static const short yypgoto[] = {-32768,
-32768,    34,-32768,    -4,    -2
};


#define	YYLAST		334


static const short yytable[] = {    21,
    22,    66,    47,    48,    26,    75,    18,    29,    78,    76,
    31,    30,    79,    23,    67,    42,    43,    44,    86,    47,
    72,     5,    76,    54,     8,     9,    10,    11,    63,    19,
    56,    57,    58,    59,    60,    61,    62,    65,    40,    41,
    14,     5,    20,    74,     8,     9,    10,    11,    77,    24,
     5,    25,    46,     8,     9,    10,    11,    50,    45,    51,
    14,    71,    88,    81,    80,    83,    82,    85,    84,    14,
    87,    38,    39,    40,    41,    92,    90,    98,   102,    73,
     0,    95,     0,     0,     0,     0,     0,    96,     0,     0,
    97,     0,   101,     0,   100,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,     0,    12,     0,    13,
    36,    37,    38,    39,    40,    41,     0,     0,    14,     1,
     2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
     0,    12,    27,    13,     0,     0,     0,     0,     0,     0,
     0,     0,    14,     1,     2,     3,     4,     5,     6,     7,
     8,     9,    10,    11,     0,    12,    53,    13,     0,     0,
     0,     0,     0,     0,     0,     0,    14,     1,     2,     3,
     4,     5,     6,     7,     8,     9,    10,    11,     0,    12,
     0,    13,     0,     0,     0,     0,    55,     0,     0,     0,
    14,    33,    34,    35,    36,    37,    38,    39,    40,    41,
    68,     0,     0,     0,     0,    33,    34,    35,    36,    37,
    38,    39,    40,    41,    70,     0,     0,     0,     0,    33,
    34,    35,    36,    37,    38,    39,    40,    41,    91,     0,
     0,     0,     0,    33,    34,    35,    36,    37,    38,    39,
    40,    41,    94,     0,     0,     0,     0,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    99,     0,     0,     0,
     0,    33,    34,    35,    36,    37,    38,    39,    40,    41,
    32,     0,    33,    34,    35,    36,    37,    38,    39,    40,
    41,    52,     0,    33,    34,    35,    36,    37,    38,    39,
    40,    41,    69,     0,    33,    34,    35,    36,    37,    38,
    39,    40,    41,    89,     0,    33,    34,    35,    36,    37,
    38,    39,    40,    41,    93,     0,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    33,    34,    35,    36,    37,
    38,    39,    40,    41
};

static const short yycheck[] = {     4,
    13,    13,    13,    14,     7,    14,    26,    12,    14,    18,
    15,    14,    18,    26,    26,    18,    19,    20,    14,    13,
    14,     7,    18,    28,    10,    11,    12,    13,    14,    26,
    33,    34,    35,    36,    37,    38,    39,    40,    26,    27,
    26,     7,    26,    48,    10,    11,    12,    13,    51,    13,
     7,    17,    26,    10,    11,    12,    13,    17,     5,    19,
    26,    26,    13,    68,    67,    70,    69,    72,    71,    26,
    75,    24,    25,    26,    27,    29,    79,    17,     0,    46,
    -1,    86,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
    93,    -1,     0,    -1,    99,     3,     4,     5,     6,     7,
     8,     9,    10,    11,    12,    13,    -1,    15,    -1,    17,
    22,    23,    24,    25,    26,    27,    -1,    -1,    26,     3,
     4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
    -1,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    26,     3,     4,     5,     6,     7,     8,     9,
    10,    11,    12,    13,    -1,    15,    16,    17,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    26,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
    -1,    17,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,
    26,    19,    20,    21,    22,    23,    24,    25,    26,    27,
    14,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
    24,    25,    26,    27,    14,    -1,    -1,    -1,    -1,    19,
    20,    21,    22,    23,    24,    25,    26,    27,    14,    -1,
    -1,    -1,    -1,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    14,    -1,    -1,    -1,    -1,    19,    20,    21,
    22,    23,    24,    25,    26,    27,    14,    -1,    -1,    -1,
    -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
    17,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    17,    -1,    19,    20,    21,    22,    23,    24,
    25,    26,    27,    17,    -1,    19,    20,    21,    22,    23,
    24,    25,    26,    27,    17,    -1,    19,    20,    21,    22,
    23,    24,    25,    26,    27,    19,    20,    21,    22,    23,
    24,    25,    26,    27
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
#line 35 "sgsanalyzer.y"
{ addStatement(yyvsp[0].pointer); ;
    break;}
case 2:
#line 36 "sgsanalyzer.y"
{ addStatement(yyvsp[0].pointer); ;
    break;}
case 3:
#line 40 "sgsanalyzer.y"
{ yyval.pointer = getStatementsBlockStatement(yyvsp[0].pointer); ;
    break;}
case 4:
#line 41 "sgsanalyzer.y"
{ yyval.pointer = addStatementToStatementsBlock(yyvsp[-1].pointer,yyvsp[0].pointer); ;
    break;}
case 5:
#line 45 "sgsanalyzer.y"
{ yyval.pointer = getParametersList(yyvsp[0].identifier_id); ;
    break;}
case 6:
#line 46 "sgsanalyzer.y"
{ yyval.pointer = addParameterToParametersList(yyvsp[-2].pointer,yyvsp[0].identifier_id); ;
    break;}
case 7:
#line 50 "sgsanalyzer.y"
{ yyval.pointer = getArgumentsList(yyvsp[0].pointer); ;
    break;}
case 8:
#line 51 "sgsanalyzer.y"
{ yyval.pointer = addParameterToArgumentsList(yyvsp[-2].pointer,yyvsp[0].pointer); ;
    break;}
case 9:
#line 55 "sgsanalyzer.y"
{ yyval.pointer = getEmptyStatement(); ;
    break;}
case 10:
#line 56 "sgsanalyzer.y"
{ yyval.pointer = getEmptyStatement(); ;
    break;}
case 11:
#line 57 "sgsanalyzer.y"
{ yyval.pointer = getExpressionStatement(yyvsp[-1].pointer); ;
    break;}
case 12:
#line 58 "sgsanalyzer.y"
{ yyval.pointer = yyvsp[-1].pointer; ;
    break;}
case 13:
#line 59 "sgsanalyzer.y"
{ yyval.pointer = getVariableDefineStatement(yyvsp[-1].identifier_id); ;
    break;}
case 14:
#line 60 "sgsanalyzer.y"
{ yyval.pointer = getVariableDefineAndInitializeStatement(yyvsp[-3].identifier_id,yyvsp[-1].pointer); ;
    break;}
case 15:
#line 62 "sgsanalyzer.y"
{
		yyval.pointer = getIfStatement(yyvsp[-2].pointer,yyvsp[0].pointer); 
	;
    break;}
case 16:
#line 66 "sgsanalyzer.y"
{
		yyval.pointer = getIfxStatement(yyvsp[-4].pointer,yyvsp[-2].pointer,yyvsp[0].pointer);
	;
    break;}
case 17:
#line 70 "sgsanalyzer.y"
{
		yyval.pointer = getForStatement(yyvsp[-6].pointer,yyvsp[-4].pointer,yyvsp[-2].pointer,yyvsp[0].pointer);
	;
    break;}
case 18:
#line 74 "sgsanalyzer.y"
{
		yyval.pointer = getWhileStatement(yyvsp[-2].pointer,yyvsp[0].pointer);
	;
    break;}
case 19:
#line 78 "sgsanalyzer.y"
{
		yyval.pointer = getDoStatement(yyvsp[-2].pointer,yyvsp[-5].pointer);
	;
    break;}
case 20:
#line 81 "sgsanalyzer.y"
{ yyval.pointer = getReturnStatementWithoutExpression(); ;
    break;}
case 21:
#line 82 "sgsanalyzer.y"
{ yyval.pointer = getReturnStatementWithExpression(yyvsp[-1].pointer); ;
    break;}
case 22:
#line 86 "sgsanalyzer.y"
{ yyval.pointer = getFloatExpression(yyvsp[0].float_value); ;
    break;}
case 23:
#line 87 "sgsanalyzer.y"
{ yyval.pointer = getIntegerExpression(yyvsp[0].integer_value); ;
    break;}
case 24:
#line 88 "sgsanalyzer.y"
{ yyval.pointer = getStringExpression(yyvsp[0].string_value); ;
    break;}
case 25:
#line 89 "sgsanalyzer.y"
{ yyval.pointer = getIdentifierExpression(yyvsp[0].identifier_id); ;
    break;}
case 26:
#line 91 "sgsanalyzer.y"
{
		yyval.pointer = getAssignOperatorExpression(getIdentifierExpression(yyvsp[-4].identifier_id),getFunctionExpression(makeFunctionWithParameters(yyvsp[0].pointer,yyvsp[-2].pointer)));
	;
    break;}
case 27:
#line 95 "sgsanalyzer.y"
{
		yyval.pointer = getAssignOperatorExpression(getIdentifierExpression(yyvsp[-3].identifier_id),getFunctionExpression(makeFunctionWithoutParameters(yyvsp[0].pointer)));
	;
    break;}
case 28:
#line 99 "sgsanalyzer.y"
{
		yyval.pointer = getFunctionExpression(makeFunctionWithParameters(yyvsp[0].pointer,yyvsp[-2].pointer));
	;
    break;}
case 29:
#line 103 "sgsanalyzer.y"
{
		yyval.pointer = getFunctionExpression(makeFunctionWithoutParameters(yyvsp[0].pointer));
	;
    break;}
case 30:
#line 106 "sgsanalyzer.y"
{ yyval.pointer = yyvsp[-1].pointer; ;
    break;}
case 31:
#line 107 "sgsanalyzer.y"
{ yyval.pointer = getFunctionCallFunctionWithoutArguments(yyvsp[-2].pointer); ;
    break;}
case 32:
#line 108 "sgsanalyzer.y"
{ yyval.pointer = getFunctionCallFunctionWithArguments(yyvsp[-3].pointer,yyvsp[-1].pointer); ;
    break;}
case 33:
#line 109 "sgsanalyzer.y"
{ yyval.pointer = getDotOperatorExpression(yyvsp[-4].pointer,yyvsp[-1].pointer); ;
    break;}
case 34:
#line 110 "sgsanalyzer.y"
{ yyval.pointer = getDotOperatorExpressionWithIdentifier(yyvsp[-2].pointer,yyvsp[0].identifier_id); ;
    break;}
case 35:
#line 111 "sgsanalyzer.y"
{ yyval.pointer = getAddOperatorExpression(yyvsp[-2].pointer,yyvsp[0].pointer); ;
    break;}
case 36:
#line 112 "sgsanalyzer.y"
{ yyval.pointer = getSubOperatorExpression(yyvsp[-2].pointer,yyvsp[0].pointer); ;
    break;}
case 37:
#line 113 "sgsanalyzer.y"
{ yyval.pointer = getMulOperatorExpression(yyvsp[-2].pointer,yyvsp[0].pointer); ;
    break;}
case 38:
#line 114 "sgsanalyzer.y"
{ yyval.pointer = getDivOperatorExpression(yyvsp[-2].pointer,yyvsp[0].pointer); ;
    break;}
case 39:
#line 115 "sgsanalyzer.y"
{ yyval.pointer = getLessOperatorExpression(yyvsp[-2].pointer,yyvsp[0].pointer); ;
    break;}
case 40:
#line 116 "sgsanalyzer.y"
{ yyval.pointer = getMoreOperatorExpression(yyvsp[-2].pointer,yyvsp[0].pointer); ;
    break;}
case 41:
#line 117 "sgsanalyzer.y"
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
#line 120 "sgsanalyzer.y"

int yyerror(char *s)
{
	return fprintf(stderr,"%s\n",s);
}
