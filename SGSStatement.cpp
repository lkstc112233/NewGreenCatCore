#include "StdAfx.h"

#include <algorithm>

#include "SGSStatement.h"
#include "SGSExpression.h"
#include "SGSVirtualMachine.h"
#include "SGSStackFrame.h"
#include "SGSExceptions.h"

std::string addTab(std::string &strIn);

SGSStatement::SGSStatement(void)
{
}
SGSStatement::~SGSStatement(void)
{
}
SGSStackFrame* SGSStatement::getStackFrame()
{
	return new SGSStatementStackFrame();
}

SGSEmptyStatement::SGSEmptyStatement()
{
}
SGSEmptyStatement::~SGSEmptyStatement(void)
{
}
StatementType SGSEmptyStatement::getStatementType()
{
	return STEmpty;
}
std::string SGSEmptyStatement::getDebugString()
{
	std::string toReturn="Type : STEmpty\n";
	return toReturn;
}

SGSExpressionStatement::SGSExpressionStatement(SGSExpression* exp)
	: expression(exp)
{
}
SGSExpressionStatement::~SGSExpressionStatement(void)
{
	delete expression;
}
StatementType SGSExpressionStatement::getStatementType()
{
	return STExpression;
}
std::string SGSExpressionStatement::getDebugString()
{
	std::string toReturn="Type : STExpression\n";
	toReturn+=addTab(expression->getDebugString());
	toReturn+="Endof : STExpression\n";
	return toReturn;
}
int SGSExpressionStatement::run()
{
	// TODO;
	return 0;
}

SGSStatementBlockStatement::SGSStatementBlockStatement()
{
}
SGSStatementBlockStatement::~SGSStatementBlockStatement(void)
{
	std::for_each(statements.begin(),statements.end(),[](SGSStatement *s){delete s;});
}
void SGSStatementBlockStatement::addStatement(SGSStatement *statement)
{
	statements.push_back(statement);
}
StatementType SGSStatementBlockStatement::getStatementType()
{
	return STStatementBlock;
}
std::string SGSStatementBlockStatement::getDebugString()
{
	std::string toReturn="Type : STStatementBlock\n";
	for (std::vector<SGSStatement*>::iterator statement=statements.begin();statements.end()!=statement;++statement)
		toReturn+=addTab((*statement)->getDebugString());
	toReturn+="Endof : STStatementBlock\n";
	return toReturn;
}
int SGSStatementBlockStatement::run()
{
	try
	{
		std::for_each(statements.begin(),statements.end(),[](SGSStatement* s){s_virtualMachine->runStatement(s);});
	}
	catch(SGSWrongStatementException e)
	{
		return e.errCode;
	}
	return 0;
}

SGSVariableStatement::SGSVariableStatement(int varId,SGSExpression* exp)
	: expression(exp)
	, variableId(varId)
{
}
SGSVariableStatement::~SGSVariableStatement(void)
{
	delete expression;
}
StatementType SGSVariableStatement::getStatementType()
{
	return STVariable;
}
std::string SGSVariableStatement::getDebugString()
{
	std::string toReturn="Type : STVariable\n";
	toReturn+="	VariableId : ";
	char cache[12];
	toReturn+=_itoa(variableId,cache,10);
	toReturn+="\n";
	if (expression)
	{
		toReturn+="	Expression :\n";
		toReturn+=addTab(addTab(expression->getDebugString()));
	}
	toReturn+="Endof : STVariable\n";
	return toReturn;
}
int SGSVariableStatement::run()
{
	// TODO;
	return 0;
}

SGSIfxStatement::SGSIfxStatement(SGSExpression *exp,SGSStatement *s_true,SGSStatement *s_false)
	: expression(exp)
	, statement_true(s_true)
	, statement_false(s_false)
{
}
SGSIfxStatement::~SGSIfxStatement(void)
{
	delete expression;
	delete statement_true;
	delete statement_false;
}
StatementType SGSIfxStatement::getStatementType()
{
	if (statement_false)
		return STIfx;
	else
		return STIf;
}
std::string SGSIfxStatement::getDebugString()
{
	std::string toReturn;
	if (statement_false)
		toReturn="Type : STIfx\n";
	else
		toReturn="Type : STIf\n";
	toReturn += "	Expression : \n";
	toReturn += addTab(addTab(expression->getDebugString()));
	toReturn += "	StatementTrue : \n";
	toReturn += addTab(addTab(statement_true->getDebugString()));
	if (statement_false)
	{
		toReturn += "	StatementFalse : \n";
		toReturn += addTab(addTab(statement_false->getDebugString()));
	}
	if (statement_false)
		toReturn+="Endof : STIfx\n";
	else
		toReturn+="Endof : STIf\n";
	return toReturn;
}
int SGSIfxStatement::run()
{
	// TODO;
	return 0;
}

SGSForStatement::SGSForStatement(SGSExpression *exp1,SGSExpression *exp2,SGSExpression *exp3,SGSStatement *sta)
	: expressionBefore(exp1)
	, expressionCheck(exp2)
	, expressionEveryTurn(exp3)
	, statement(sta)
{
}
SGSForStatement::~SGSForStatement(void)
{
	delete expressionBefore;
	delete expressionCheck;
	delete expressionEveryTurn;
	delete statement;
}
StatementType SGSForStatement::getStatementType()
{
	return STFor;
}
std::string SGSForStatement::getDebugString()
{
	std::string toReturn="Type : STFor\n";
	toReturn += "	Expression1 : \n";
	toReturn += addTab(addTab(expressionBefore->getDebugString()));
	toReturn += "	Expression2 : \n";
	toReturn += addTab(addTab(expressionCheck->getDebugString()));
	toReturn += "	Expression3 : \n";
	toReturn += addTab(addTab(expressionEveryTurn->getDebugString()));
	toReturn += "	Statement : \n";
	toReturn += addTab(addTab(statement->getDebugString()));
	toReturn+="Endof : STFor\n";
	return toReturn;
}
int SGSForStatement::run()
{
	// TODO;
	return 0;
}

SGSWhileStatement::SGSWhileStatement(SGSExpression *exp,SGSStatement *sta)
	: expressionCheck(exp)
	, statement(sta)
{
}
SGSWhileStatement::~SGSWhileStatement(void)
{
	delete expressionCheck;
	delete statement;
}
StatementType SGSWhileStatement::getStatementType()
{
	return STWhile;
}
std::string SGSWhileStatement::getDebugString()
{
	std::string toReturn="Type : STWhile\n";
	toReturn += "	Expression : \n";
	toReturn += addTab(addTab(expressionCheck->getDebugString()));
	toReturn += "	Statement : \n";
	toReturn += addTab(addTab(statement->getDebugString()));
	toReturn+="Endof : STWhile\n";
	return toReturn;
}
int SGSWhileStatement::run()
{
	// TODO;
	return 0;
}

SGSDoStatement::SGSDoStatement(SGSExpression *exp,SGSStatement *sta)
	: expressionCheck(exp)
	, statement(sta)
{
}
SGSDoStatement::~SGSDoStatement(void)
{
	delete expressionCheck;
	delete statement;
}
StatementType SGSDoStatement::getStatementType()
{
	return STDo;
}
std::string SGSDoStatement::getDebugString()
{
	std::string toReturn="Type : STDo\n";
	toReturn += "	Expression : \n";
	toReturn += addTab(addTab(expressionCheck->getDebugString()));
	toReturn += "	Statement : \n";
	toReturn += addTab(addTab(statement->getDebugString()));
	toReturn+="Endof : STDo\n";
	return toReturn;
}
int SGSDoStatement::run()
{
	// TODO;
	return 0;
}
