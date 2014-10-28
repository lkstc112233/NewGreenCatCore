%{
#include <stdlib.h>
#include "SGSAnalyzerWarper.h"
/*#include "AnalyzerExpression.h"*/
int yyerror(char *s);
int yylex(void);
%}
%union
{
	void				*pointer;
	long long			integer_value;
	long double			float_value;
	char*				string_value;
	int					identifier_id;
}
%token					IF FOR WHILE DO FUNCTION VAR
%token	<float_value>	DOUBLE_LITERAL
%token	<integer_value>	INTEGER_LITERAL
%token	<string_value>	STRING_LITERAL
%token	<identifier_id>	IDENTIFIER
%type	<pointer>		expression statement statements_list arguments parameters
%token					RIGHT_PAREN LEFT_BRACE RIGHT_BRACE SEMICOLON COMMA
%right					ASSIGN
%left					ADD SUB 
%left					MUL DIV 
%nonassoc				IFX
%nonassoc				ELSE
%left					LEFT_PAREN

%%
final 
	: statement										{ addStatement($1); }
	| final statement								{ addStatement($2); }
	;

statements_list 
	: statement										{ $$ = getStatementsBlockStatement($1); }
	| statements_list statement						{ $$ = addStatementToStatementsBlock($1,$2); }
	;

parameters
	: IDENTIFIER									{ $$ = getParametersList($1); }
	| parameters COMMA IDENTIFIER					{ $$ = addParameterToParametersList($1,$3); }
	;

arguments
	: expression									{ $$ = getArgumentsList($1); }
	| arguments COMMA expression					{ $$ = addParameterToArgumentsList($1,$3); }
	;

statement 
	: SEMICOLON										{ $$ = getEmptyStatement(); }
	| LEFT_BRACE RIGHT_BRACE						{ $$ = getEmptyStatement(); }
	| expression SEMICOLON							{ $$ = getExpressionStatement($1); }
	| LEFT_BRACE statements_list RIGHT_BRACE		{ $$ = $2; }
	| VAR IDENTIFIER SEMICOLON						{ $$ = getVariableDefineStatement($2); }
	| VAR IDENTIFIER ASSIGN expression SEMICOLON	{ $$ = getVariableDefineAndInitializeStatement($2,$4); }
	| IF LEFT_PAREN expression RIGHT_PAREN statement %prec IFX
	{
		$$ = getIfStatement($3,$5); 
	}
	| IF LEFT_PAREN expression RIGHT_PAREN statement ELSE statement
	{
		$$ = getIfxStatement($3,$5,$7);
	}
	| FOR LEFT_PAREN expression SEMICOLON expression SEMICOLON expression RIGHT_PAREN statement
	{
		$$ = getForStatement($3,$5,$7,$9);
	}
	| WHILE LEFT_PAREN expression RIGHT_PAREN statement
	{
		$$ = getWhileStatement($3,$5);
	}
	| DO statement WHILE LEFT_PAREN expression RIGHT_PAREN SEMICOLON
	{
		$$ = getDoStatement($5,$2);
	}
	;

expression 
	: DOUBLE_LITERAL								{ $$ = getFloatExpression($1); }
	| INTEGER_LITERAL								{ $$ = getIntegerExpression($1); }
	| STRING_LITERAL								{ $$ = getStringExpression($1); }
	| IDENTIFIER									{ $$ = getIdentifierExpression($1); }
	| FUNCTION IDENTIFIER LEFT_PAREN parameters RIGHT_PAREN statement
	{
		$$ = getAssignOperatorExpression(getIdentifierExpression($2),getFunctionExpression(makeFunctionWithParameters($6,$4)));
	}
	| FUNCTION IDENTIFIER LEFT_PAREN RIGHT_PAREN statement
	{
		$$ = getAssignOperatorExpression(getIdentifierExpression($2),getFunctionExpression(makeFunctionWithoutParameters($5)));
	}
	| FUNCTION LEFT_PAREN parameters RIGHT_PAREN statement
	{
		$$ = getFunctionExpression(makeFunctionWithParameters($5,$3));
	}
	| FUNCTION LEFT_PAREN RIGHT_PAREN statement
	{
		$$ = getFunctionExpression(makeFunctionWithoutParameters($4));
	}
	| LEFT_PAREN expression RIGHT_PAREN				{ $$ = $2; }
	| expression LEFT_PAREN RIGHT_PAREN				{ $$ = getFunctionCallFunctionWithoutArguments($1); }
	| expression LEFT_PAREN arguments RIGHT_PAREN	{ $$ = getFunctionCallFunctionWithArguments($1,$3); }
	| expression ADD expression						{ $$ = getAddOperatorExpression($1,$3); }
	| expression SUB expression						{ $$ = getSubOperatorExpression($1,$3); }
	| expression MUL expression						{ $$ = getMulOperatorExpression($1,$3); }
	| expression DIV expression						{ $$ = getDivOperatorExpression($1,$3); }
	| expression ASSIGN expression					{ $$ = getAssignOperatorExpression($1,$3); }
	;

%%
int yyerror(char *s)
{
	return fprintf(stderr,"%s\n",s);
}
