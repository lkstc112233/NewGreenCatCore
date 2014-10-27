#pragma once
#include <vector>
enum StatementType
{
	STEmpty,STExpression,STStatementBlock,STVariable,
	STIf,STIfx,STFor,STWhile,STDo
};

class SGSExpression;
class SGSStackFrame;

class SGSStatement
{
public:
	SGSStatement(void);
	virtual ~SGSStatement(void);
	virtual StatementType getStatementType()=0;
	virtual SGSStackFrame* getStackFrame();
	virtual int run(){return 0;}
public:
	virtual std::string getDebugString(){throw false;}
};

class SGSEmptyStatement : public SGSStatement
{
public:
	SGSEmptyStatement();
	virtual ~SGSEmptyStatement(void);
	virtual StatementType getStatementType();
	virtual SGSStackFrame* getStackFrame(){return NULL;}
public:
	virtual std::string getDebugString();
};

class SGSExpressionStatement : public SGSStatement
{
private:
	SGSExpression *expression;
public:
	SGSExpressionStatement(SGSExpression*);
	virtual ~SGSExpressionStatement(void);
	virtual StatementType getStatementType();
	virtual SGSStackFrame* getStackFrame(){return NULL;}
	virtual int run();
public:
	virtual std::string getDebugString();
};

class SGSStatementBlockStatement : public SGSStatement
{
private:
	std::vector<SGSStatement*> statements;
public:
	SGSStatementBlockStatement();
	virtual ~SGSStatementBlockStatement(void);
	void addStatement(SGSStatement *statement);
	virtual StatementType getStatementType();
	virtual int run();
public:
	virtual std::string getDebugString();
};

class SGSVariableStatement : public SGSStatement
{
private:
	int variableId;
	SGSExpression *expression;
public:
	SGSVariableStatement(int varId,SGSExpression *exp=NULL);
	virtual ~SGSVariableStatement(void);
	virtual StatementType getStatementType();
	virtual SGSStackFrame* getStackFrame(){return NULL;}
	virtual int run();
public:
	virtual std::string getDebugString();
};

class SGSIfxStatement : public SGSStatement
{
private:
	SGSExpression *expression;
	SGSStatement *statement_true;
	SGSStatement *statement_false;
public:
	SGSIfxStatement(SGSExpression *exp,SGSStatement *s_true,SGSStatement *s_false=NULL);
	virtual ~SGSIfxStatement(void);
	virtual StatementType getStatementType();
	virtual int run();
public:
	virtual std::string getDebugString();
};

class SGSForStatement : public SGSStatement
{
private:
	SGSExpression *expressionBefore;
	SGSExpression *expressionCheck;
	SGSExpression *expressionEveryTurn;
	SGSStatement *statement;
public:
	SGSForStatement(SGSExpression *exp1,SGSExpression *exp2,SGSExpression *exp3,SGSStatement *sta);
	virtual ~SGSForStatement(void);
	virtual StatementType getStatementType();
	virtual int run();
public:
	virtual std::string getDebugString();
};

class SGSWhileStatement : public SGSStatement
{
private:
	SGSExpression *expressionCheck;
	SGSStatement *statement;
public:
	SGSWhileStatement(SGSExpression *exp,SGSStatement *sta);
	virtual ~SGSWhileStatement(void);
	virtual StatementType getStatementType();
	virtual int run();
public:
	virtual std::string getDebugString();
};

class SGSDoStatement : public SGSStatement
{
private:
	SGSExpression *expressionCheck;
	SGSStatement *statement;
public:
	SGSDoStatement(SGSExpression *exp,SGSStatement *sta);
	virtual ~SGSDoStatement(void);
	virtual StatementType getStatementType();
	virtual int run();
public:
	virtual std::string getDebugString();
};