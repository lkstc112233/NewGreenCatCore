#pragma once

#ifdef __cplusplus
extern "C" {  
#endif 
	struct Expression;
	int CreateAnalyzerInstance();
	void ReleaseAnalyzerInstance();
	void clearStringLiteralCache();
	void addStringLiteralCharacter(char c);
	const char* getStringLiteralCache();
	void lineNumberUp();
	void* getIntegerExpression(long long i);
	void* getFloatExpression(long double d);
	void* getStringExpression();
	int getIdentifierId(char* c);
	void* getIdentifierExpression(int id);
	void* getFunctionExpression(void* fun);
	void* getEmptyStatement();
	void* getExpressionStatement(void* e);
	void* getStatementsBlockStatement(void *statement);
	void* addStatementToStatementsBlock(void *statementBlock,void *statement);
	void* getVariableDefineStatement(int id);
	void* getVariableDefineAndInitializeStatement(int id,void *expression);
	void* getIfStatement(void *expression,void *statement);
	void* getIfxStatement(void *expression,void *stt,void *stf);
	void* getForStatement(void *exp1,void *exp2,void *exp3,void *statement);
	void* getWhileStatement(void *exp1,void *statement);
	void* getDoStatement(void *exp1,void *statement);
	void* getReturnStatementWithExpression(void* expression);
	void* getReturnStatementWithoutExpression();
	void* getParametersList(int id);
	void* addParameterToParametersList(void* parameterList,int id);
	void* getArgumentsList(void *arg);
	void* addParameterToArgumentsList(void* argumentsList,void *argument);
	void* makeFunctionWithParameters(void* statements,void* args);
	void* makeFunctionWithoutParameters(void* statements);
	void* getFunctionCallFunctionWithArguments(void* function,void* arguments);
	void* getFunctionCallFunctionWithoutArguments(void* function);
	void* getDotOperatorExpressionWithIdentifier(void* exp1,int exp2);
	void* getDotOperatorExpression(void* exp1,void* exp2);
	void* getAddOperatorExpression(void* exp1,void* exp2);
	void* getSubOperatorExpression(void* exp1,void* exp2);
	void* getMulOperatorExpression(void* exp1,void* exp2);
	void* getDivOperatorExpression(void* exp1,void* exp2);
	void* getLessOperatorExpression(void* exp1,void* exp2);
	void* getMoreOperatorExpression(void* exp1,void* exp2);
	void* getEqualOperatorExpression(void* exp1,void* exp2);
	void* getAssignOperatorExpression(void* exp1,void* exp2);
	void addStatement(void* p);
	void addFunction(void* p);
#ifdef __cplusplus
};
#endif  