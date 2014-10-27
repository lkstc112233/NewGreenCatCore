#include "stdafx.h"

#include "SGSAnalyzer.h"
#include "SGSAnalyzerWarper.h"
#include "SGSExpression.h"
#include "SGSStatement.h"
#include "SGSFunction.h"
//#include "AnalyzerExpression.h"

SGSAnalyzer *s_analyzerVector=NULL;
#ifdef __cplusplus 
extern "C" {
#endif 
	int CreateAnalyzerInstance()
	{
		if (s_analyzerVector)
			delete s_analyzerVector;
		s_analyzerVector = new SGSAnalyzer;
		return s_analyzerVector!=0;
	}
	void ReleaseAnalyzerInstance() 
	{ 
		delete s_analyzerVector;
	} 
	void clearStringLiteralCache() 
	{
		s_analyzerVector->clearStringLiteralCache(); 
	}
	void addStringLiteralCharacter(char c)
	{ 
		s_analyzerVector->addStringLiteralCharacter(c); 
	}
	void lineNumberUp()
	{
		s_analyzerVector->lineNumberUp();
	}
	void* getIntegerExpression(long long i)
	{
		return new SGSLiteralExpression(i);
	}
	void* getFloatExpression(long double d)
	{
		return new SGSLiteralExpression(d);
	}
	void* getStringExpression()
	{
		return new SGSLiteralExpression(s_analyzerVector->getStringLiteralCache());
	}
	int getIdentifierId(char* c)
	{
		return s_analyzerVector->getIdentifierId(c);
	}
	void* getIdentifierExpression(char* c)
	{
		return new SGSLiteralExpression(s_analyzerVector->getIdentifierId(c));
	}
	void* getFunctionExpression(void* fun)
	{
		return new SGSLiteralExpression((SGSFunction*)fun);
	}
	void* getEmptyStatement()
	{
		return new SGSEmptyStatement();
	}
	void* getExpressionStatement(void* p)
	{
		return new SGSExpressionStatement((SGSExpression*)p);
	}
	void* getStatementsBlockStatement(void *statement)
	{
		SGSStatementBlockStatement* toReturn=new SGSStatementBlockStatement();
		toReturn->addStatement((SGSStatement*)statement);
		return toReturn;
	}
	void* addStatementToStatementsBlock(void *statementBlock,void *statement)
	{
		((SGSStatementBlockStatement*)statementBlock)->addStatement((SGSStatement*)statement);
		return statementBlock;
	}
	void* getVariableDefineStatement(int id)
	{
		return new SGSVariableStatement(id);
	}
	void* getVariableDefineAndInitializeStatement(int id,void *expression)
	{
		return new SGSVariableStatement(id,(SGSExpression*)expression);
	}
	void* getIfStatement(void *expression,void *statement)
	{
		return new SGSIfxStatement((SGSExpression*)expression,(SGSStatement*)statement);
	}
	void* getIfxStatement(void *expression,void *stt,void *stf)
	{
		return new SGSIfxStatement((SGSExpression*)expression,(SGSStatement*)stt,(SGSStatement*)stf);
	}
	void* getForStatement(void *exp1, void *exp2,void *exp3,void *statement)
	{
		return new SGSForStatement((SGSExpression*)exp1,(SGSExpression*)exp2,(SGSExpression*)exp3,(SGSStatement*)statement);
	}
	void* getWhileStatement(void *exp1,void *statement)
	{
		return new SGSWhileStatement((SGSExpression*)exp1,(SGSStatement*)statement);
	}
	void* getDoStatement(void *exp1,void *statement)
	{
		return new SGSDoStatement((SGSExpression*)exp1,(SGSStatement*)statement);
	}
	void* getParametersList(int id)
	{
		SGSParameters* list = new SGSParameters();
		list->addParameter(id);
		return list;
	}
	void* addParameterToParametersList(void* parameterList,int id)
	{
		((SGSParameters*)parameterList)->addParameter(id);
		return parameterList;
	}
	void* getArgumentsList(void *arg)
	{
		SGSArguments* list = new SGSArguments();
		list->addArgument((SGSExpression*)arg);
		return list;
	}
	void* addParameterToArgumentsList(void* argumentsList,void* argument)
	{
		((SGSArguments*)argumentsList)->addArgument((SGSExpression*)argument);
		return argumentsList;
	}
	void* makeFunctionWithParameters(int id,void* statements,void* args)
	{
		//TODO
		return new SGSFunction((SGSStatement*)statements,(SGSParameters*)args);
	}
	void* makeFunctionWithoutParameters(int id,void* statements)
	{
		//TODO
		return new SGSFunction((SGSStatement*)statements);
	}
	void* getFunctionCallFunctionWithArguments(void* function,void* arguments)
	{
		return new SGSFunctionCallExpression((SGSExpression*)function,(SGSArguments*)arguments);
	}
	void* getFunctionCallFunctionWithoutArguments(void* function)
	{
		return new SGSFunctionCallExpression((SGSExpression*)function);
	}
	void* getAddOperatorExpression(void* exp1,void* exp2)
	{
		if (((SGSExpression*)exp1)->isLiteral()&&((SGSExpression*)exp2)->isLiteral())
			return *((SGSLiteralExpression*)exp1)+(SGSLiteralExpression*)exp2;
		else
		{
			SGSOperateExpression* toReturn=new SGSOperateExpression(OTAdd);
			toReturn->addArgument((SGSExpression*)exp1);
			toReturn->addArgument((SGSExpression*)exp2);
			return toReturn;
		}
	}
	void* getSubOperatorExpression(void* exp1,void* exp2)
	{
		if (((SGSExpression*)exp1)->isLiteral()&&((SGSExpression*)exp2)->isLiteral())
			return *((SGSLiteralExpression*)exp1)-(SGSLiteralExpression*)exp2;
		else
		{
			SGSOperateExpression* toReturn=new SGSOperateExpression(OTSub);
			toReturn->addArgument((SGSExpression*)exp1);
			toReturn->addArgument((SGSExpression*)exp2);
			return toReturn;
		}
	}
	void* getMulOperatorExpression(void* exp1,void* exp2)
	{
		if (((SGSExpression*)exp1)->isLiteral()&&((SGSExpression*)exp2)->isLiteral())
			return *((SGSLiteralExpression*)exp1)*(SGSLiteralExpression*)exp2;
		else
		{
			SGSOperateExpression* toReturn=new SGSOperateExpression(OTMul);
			toReturn->addArgument((SGSExpression*)exp1);
			toReturn->addArgument((SGSExpression*)exp2);
			return toReturn;
		}
	}
	void* getDivOperatorExpression(void* exp1,void* exp2)
	{
		if (((SGSExpression*)exp1)->isLiteral()&&((SGSExpression*)exp2)->isLiteral())
			return *((SGSLiteralExpression*)exp1)/(SGSLiteralExpression*)exp2;
		else
		{
			SGSOperateExpression* toReturn=new SGSOperateExpression(OTDiv);
			toReturn->addArgument((SGSExpression*)exp1);
			toReturn->addArgument((SGSExpression*)exp2);
			return toReturn;
		}
	}
	void* getAssignOperatorExpression(void* exp1,void* exp2)
	{
		SGSOperateExpression* toReturn=new SGSOperateExpression(OTAssign);
		toReturn->addArgument((SGSExpression*)exp1);
		toReturn->addArgument((SGSExpression*)exp2);
		return toReturn;
	}
	void addStatement(void* p)
	{
		s_analyzerVector->addStatement((SGSStatement*)p);
	}
	void addFunction(void* p)
	{
		s_analyzerVector->addFunction((SGSFunction*)p);
	}
#ifdef __cplusplus 
}; 
#endif