#pragma once
#include <vector>

class SGSArguments;
class SGSFunction;
class SGSValue;

enum LiteralExpressionType
{
	ETNull,ETInteger,ETFloat,ETString,ETIdentifier,ETFunction,
};

enum OperateExpressionType
{
	OTAdd,OTSub,OTMul,OTDiv,OTAssign,
};

class SGSExpression
{
public:
	SGSExpression();
	virtual ~SGSExpression(void){}
	virtual SGSValue run()=0;
	virtual bool isLiteral()=0;
public:
	virtual std::string getDebugString(){throw false;}
};

class SGSLiteralExpression : public SGSExpression
{
private:
	enum LiteralExpressionType	type;
	union {
		long long		integerValue;
		long double		floatValue;
		char*			stringValue;
		int			identifierId;
		SGSFunction*		function;
	}				value;
public:
	SGSLiteralExpression();					//Null Literal
	SGSLiteralExpression(long long i);			//Integer Literal Constructor
	SGSLiteralExpression(long double f);			//Float Literal Constructor
	SGSLiteralExpression(const char* c);			//String Literal Constructor
	SGSLiteralExpression(int id);				//Identifier Constructor
	SGSLiteralExpression(SGSFunction* fun);			//Function Literal Constructor
	virtual ~SGSLiteralExpression(void);
	long long toInteger();
	long double toFloat();
	std::string toString();
	SGSFunction* toFunction();
	void toNull();
	void convertToType(LiteralExpressionType tp);
	SGSLiteralExpression* operator+(SGSLiteralExpression *exp);
	SGSLiteralExpression* operator-(SGSLiteralExpression *exp);
	SGSLiteralExpression* operator*(SGSLiteralExpression *exp);
	SGSLiteralExpression* operator/(SGSLiteralExpression *exp);
	virtual SGSValue run();
	virtual bool isLiteral(){return type!=ETIdentifier;}
public:
	virtual std::string getDebugString();
};

class SGSOperateExpression : public SGSExpression
{
private:
	enum OperateExpressionType	type;
	std::vector<SGSExpression*>	args;
public:
	SGSOperateExpression(OperateExpressionType type);
	virtual ~SGSOperateExpression(void);
	void addArgument(SGSExpression *exp);
	virtual SGSValue run();
	virtual bool isLiteral(){return false;}
public:
	virtual std::string getDebugString();
};

class SGSFunctionCallExpression : public SGSExpression
{
private:
	SGSExpression*			function;
	SGSArguments*			arguments;
public:
	SGSFunctionCallExpression(SGSExpression* fun, SGSArguments *args=NULL);
	virtual ~SGSFunctionCallExpression(void);
	virtual SGSValue run();
	virtual bool isLiteral(){return false;}
public:
	virtual std::string getDebugString();
};

extern SGSExpression* nullExpression;