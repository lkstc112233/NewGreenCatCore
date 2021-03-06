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
	int count(){return argumentsIds.size();}
	inline std::vector<int>& getArgumentsIds(){return argumentsIds;}
	int operator[](int i);
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
	//SGSFunction();
	SGSFunction(SGSStatement *sta=NULL,SGSParameters *param=new SGSParameters());
	~SGSFunction(void);
	virtual SGSValue run();
	inline SGSParameters *getParameter(){return parameter;}
public:
	virtual std::string getDebugString();
};
class SGSNativeFunction : public SGSFunction
{
protected:
	SGSValue (*pfunc)(SGSValue);
public:
	SGSNativeFunction(SGSValue (*sta)(SGSValue));
	~SGSNativeFunction(void);
	virtual SGSValue run();
public:
	virtual std::string getDebugString();
};

extern SGSFunction* nullFunction;