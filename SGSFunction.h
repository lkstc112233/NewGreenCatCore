#pragma once
#include <vector>

class SGSStatement;
class SGSExpression;
class SGSValue;

class SGSParameters
{
private:
	std::vector<int> argumentsIds;
public:
	SGSParameters(void);
	~SGSParameters(void);
	void addParameter(int argumentId);
public:
	virtual std::string getDebugString();
};


class SGSArguments
{
private:
	std::vector<SGSExpression*> expressions;
public:
	SGSArguments(void);
	~SGSArguments(void);
	void addArgument(SGSExpression* expression);
	int count(){return expressions.size();}
	SGSExpression* operator[](int i);
public:
	virtual std::string getDebugString();
};

class SGSFunction
{
protected:
	SGSParameters *parameter;
	SGSStatement *statements;
public:
	SGSFunction();
	SGSFunction(SGSStatement *sta,SGSParameters *param=NULL);
	~SGSFunction(void);
	virtual SGSValue run(SGSArguments *args);
public:
	virtual std::string getDebugString();
};
class SGSNativeFunction : public SGSFunction
{
protected:
	SGSValue (*pfunc)(void* arg);
public:
	SGSNativeFunction(SGSValue (*sta)(void*));
	~SGSNativeFunction(void);
	virtual SGSValue run(SGSArguments *args);
public:
	virtual std::string getDebugString();
};

extern SGSFunction* nullFunction;