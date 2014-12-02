#include "StdAfx.h"

#include <algorithm>

#include "SGSStatement.h"
#include "SGSExpression.h"
#include "SGSVirtualMachine.h"
#include "SGSStackFrame.h"
#include "SGSExceptions.h"
#include "SGSValue.h"

std::string addTab(std::string &strIn);

SGSStatement::SGSStatement(void)
{
}
SGSStatement::~SGSStatement(void)
{
}
SGSStatementStackFrameBase* SGSStatement::getStackFrame()
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
SGSStatementStackFrameBase* SGSEmptyStatement::getStackFrame()
{
	return new SGSThroughStackFrame();
}
int SGSEmptyStatement::run()
{
	return 0;
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
SGSStatementStackFrameBase* SGSExpressionStatement::getStackFrame()
{
	return new SGSThroughStackFrame();
}
int SGSExpressionStatement::run()
{
	if (s_virtualMachine->isSkipping())
		return 0;
	return s_virtualMachine->runExpression(expression);
}
std::string SGSExpressionStatement::getDebugString()
{
	std::string toReturn="Type : STExpression\n";
	toReturn+=addTab(expression->getDebugString());
	toReturn+="Endof : STExpression\n";
	return toReturn;
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
int SGSStatementBlockStatement::run()
{
	try
	{
		std::for_each(statements.begin(),statements.end(),[](SGSStatement* s)
		{
			if (s_virtualMachine->isSkipping())
				return;
			s_virtualMachine->runStatement(s);
		});
	}
	catch(SGSWrongStatementException e)
	{
		return e.errCode;
	}
	return 0;
}
std::string SGSStatementBlockStatement::getDebugString()
{
	std::string toReturn="Type : STStatementBlock\n";
	for (std::vector<SGSStatement*>::iterator statement=statements.begin();statements.end()!=statement;++statement)
		toReturn+=addTab((*statement)->getDebugString());
	toReturn+="Endof : STStatementBlock\n";
	return toReturn;
}

SGSVariableStatement::SGSVariableStatement(int varId,SGSExpression* exp)
	: expression(exp)
	, variableId(varId)
{
	if (NULL==exp)
		expression=new SGSLiteralExpression();
}
SGSVariableStatement::~SGSVariableStatement(void)
{
	delete expression;
}
StatementType SGSVariableStatement::getStatementType()
{
	return STVariable;
}
SGSStatementStackFrameBase* SGSVariableStatement::getStackFrame()
{
	return new SGSThroughStackFrame();
}
int SGSVariableStatement::run()
{
	if (s_virtualMachine->isSkipping())
		return 0;
	s_virtualMachine->getFrameStackTop().registerValue(variableId,s_virtualMachine->runExpression(expression));
	return 0;
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
int SGSIfxStatement::run()
{
	if (s_virtualMachine->isSkipping())
		return 0;
	if (s_virtualMachine->runExpression(expression))
		return s_virtualMachine->runStatement(statement_true);
	else
		return s_virtualMachine->runStatement(statement_false);
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
int SGSForStatement::run()
{
	for (s_virtualMachine->runExpression(expressionBefore);
		s_virtualMachine->runExpression(expressionCheck);
		s_virtualMachine->runExpression(expressionEveryTurn))
	{
		if (s_virtualMachine->isSkipping())
			if (s_virtualMachine->isBreaking())
			{
				s_virtualMachine->unsetBreak();
				break;
			}
			else if(s_virtualMachine->isContinuing())
			{
				s_virtualMachine->unsetContinue();
				continue;
			}
			else
				return 0;
		s_virtualMachine->runStatement(statement);
	}
	return 0;
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
int SGSWhileStatement::run()
{
	while (s_virtualMachine->runExpression(expressionCheck))
	{
		if (s_virtualMachine->isSkipping())
			if (s_virtualMachine->isBreaking())
			{
				s_virtualMachine->unsetBreak();
				break;
			}
			else if(s_virtualMachine->isContinuing())
			{
				s_virtualMachine->unsetContinue();
				continue;
			}
			else
				return 0;
		s_virtualMachine->runStatement(statement);
	}
	return 0;
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
int SGSDoStatement::run()
{
	do
	{
		if (s_virtualMachine->isSkipping())
			if (s_virtualMachine->isBreaking())
			{
				s_virtualMachine->unsetBreak();
				break;
			}
			else if(s_virtualMachine->isContinuing())
			{
				s_virtualMachine->unsetContinue();
				continue;
			}
			else
				return 0;
		s_virtualMachine->runStatement(statement);
	}
	while (s_virtualMachine->runExpression(expressionCheck));
	return 0;
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

SGSReturnStatement::SGSReturnStatement()
	: expression(new SGSLiteralExpression())
{
}
SGSReturnStatement::SGSReturnStatement(SGSExpression* exp)
	: expression(exp)
{
}
SGSReturnStatement::~SGSReturnStatement(void)
{
	delete expression;
}
StatementType SGSReturnStatement::getStatementType()
{
	return STReturn;
}
SGSStatementStackFrameBase* SGSReturnStatement::getStackFrame()
{
	return new SGSThroughStackFrame();
}
int SGSReturnStatement::run()
{
	if (s_virtualMachine->isSkipping())
		return 0;
	s_virtualMachine->setReturn(s_virtualMachine->runExpression(expression));
	return 0;
}
std::string SGSReturnStatement::getDebugString()
{
	std::string toReturn="Type : STReturn\n";
	toReturn+=addTab(expression->getDebugString());
	toReturn+="Endof : STExpression\n";
	return toReturn;
}
