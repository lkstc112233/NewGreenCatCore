%{
#include <stdlib.h>
#include "SGSAnalyzerYacc.h"
#include "SGSAnalyzerWarper.h"
int yywrap(void);
%}
%start COMMENT_SINGLE_LINE COMMENT_MULTIPLE_LINES STRING_LITERAL_STATE
%%
<INITIAL>"("							return LEFT_PAREN;
<INITIAL>")"							return RIGHT_PAREN;
<INITIAL>"{"							return LEFT_BRACE;
<INITIAL>"}"							return RIGHT_BRACE;
<INITIAL>"if"							return IF;
<INITIAL>"else"							return ELSE;
<INITIAL>"for"							return FOR;
<INITIAL>"while"						return WHILE;
<INITIAL>"do"							return DO;
<INITIAL>"function"						return FUNCTION;
<INITIAL>"var"							return VAR;
<INITIAL>"return"						return RETURN;
<INITIAL>"+"							return ADD;
<INITIAL>"-"							return SUB;
<INITIAL>"*"							return MUL;
<INITIAL>"/"							return DIV;
<INITIAL>"="							return ASSIGN;
<INITIAL>"<"							return LESS;
<INITIAL>">"							return MORE;
<INITIAL>","							return COMMA;
<INITIAL>";"							return SEMICOLON;
<INITIAL>[A-Za-z_][A-Za-z0-9_]*			yylval.identifier_id = getIdentifierId(yytext);return IDENTIFIER;
<INITIAL>[0-9]+							yylval.integer_value = strtol(yytext,NULL,10);return INTEGER_LITERAL;
<INITIAL>[0-9]+\.|[0-9]*\.[0-9]+		yylval.float_value = strtod(yytext,NULL);return DOUBLE_LITERAL;
<INITIAL>\"								clearStringLiteralCache();BEGIN STRING_LITERAL_STATE;
<INITIAL>"//"							BEGIN COMMENT_SINGLE_LINE;
<INITIAL>"/*"							BEGIN COMMENT_MULTIPLE_LINES;
<INITIAL>\n								lineNumberUp();
<INITIAL>.								;/* Skipped. */
<COMMENT_SINGLE_LINE>\n					lineNumberUp();BEGIN INITIAL;
<COMMENT_SINGLE_LINE>.					;/* Skipped. */
<COMMENT_MULTIPLE_LINES>"*/"			BEGIN INITIAL;
<COMMENT_MULTIPLE_LINES>\n				lineNumberUp();
<COMMENT_MULTIPLE_LINES>.				;/* Skipped. */
<STRING_LITERAL_STATE>\"				/*yylval.string_value=getStringLiteralCache();*/BEGIN INITIAL;return STRING_LITERAL;
<STRING_LITERAL_STATE>\\\\				addStringLiteralCharacter('\\');
<STRING_LITERAL_STATE>\\n				addStringLiteralCharacter('\n');
<STRING_LITERAL_STATE>\\\"				addStringLiteralCharacter('\"');
<STRING_LITERAL_STATE>\\t				addStringLiteralCharacter('\t');
<STRING_LITERAL_STATE>\\'				addStringLiteralCharacter('\'');
<STRING_LITERAL_STATE>\n				lineNumberUp();addStringLiteralCharacter('\n');
<STRING_LITERAL_STATE>.					addStringLiteralCharacter(yytext[0]);
%%
int yywrap(void)
{
	return 1;
}
