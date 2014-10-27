#include "StdAfx.h"
#include "SGSFunction.h"
#include "SGSExpression.h"
#include "SGSStatement.h"
#include "SGSValue.h"
#include "SGSVirtualMachine.h"

std::string addTab(std::string &strIn);
SGSFunction* null_Function=new SGSFunction;

SGSParameters::SGSParameters(void)
{
}
SGSParameters::~SGSParameters(void)
{
}
void SGSParameters::addParameter(int argumentId)
{
	argumentsIds.push_back(argumentId);
}
std::string SGSParameters::getDebugString()
{
	std::string toReturn;
	for (std::vector<int>::iterator argumentsId=argumentsIds.begin();argumentsId!= argumentsIds.end();++argumentsId)
	{
		toReturn+="IdentifierId=";
		char cache[12];
		toReturn+=_itoa(*argumentsId,cache,10);
		toReturn+="\n";
	}
	return toReturn;
}

SGSArguments::SGSArguments(void)
{
}
SGSArguments::~SGSArguments(void)
{
	for(std::vector<SGSExpression*>::iterator expression=expressions.begin();expressions.end()!=expression;++expression)
		delete *expression;
}
void SGSArguments::addArgument(SGSExpression* expression)
{
	expressions.push_back(expression);
}
SGSExpression* SGSArguments::operator[](int i)
{
	if (i<0)
		return SGSValue();
	if (expressions.size()>i)
		return expressions[i];
	return SGSValue();
}
std::string SGSArguments::getDebugString()
{
	std::string toReturn;
	for (std::vector<SGSExpression*>::iterator expression=expressions.begin();expression!= expressions.end();++expression)
		toReturn+=(*expression)->getDebugString();
	return toReturn;
}

SGSFunction::SGSFunction()
	: parameter(NULL)
	, statements(new SGSEmptyStatement)
{
}
SGSFunction::SGSFunction(int id,SGSStatement *sta,SGSParameters *param)
	: identifierId(id)
	, parameter(param)
	, statements(sta)
{
}
SGSFunction::~SGSFunction(void)
{
	delete parameter;
	delete statements;
}
std::string SGSFunction::getDebugString()
{
	std::string toReturn="Type : FunctionDefinition\n";
	if (identifierId<0)
		toReturn+="	No Name Function\n";
	else
	{
		toReturn+="	IdentifierId=";
		char cache[12];
		toReturn+=_itoa(identifierId,cache,10);
		toReturn+="\n";
	}
	if (parameter)
	{
		toReturn += "	Parameters : \n";
		toReturn += addTab(addTab(parameter->getDebugString()));
	}
	if (statements)
	{
		toReturn += "	Statements : \n";
		toReturn += addTab(addTab(statements->getDebugString()));
	}
	else
	{
		toReturn += "No Function Body\n";
	}
	toReturn+="Endof : FunctionDefinition\n";
	return toReturn;
}
SGSValue SGSFunction::run(SGSArguments *args)
{
	//args
}

SGSNativeFunction::SGSNativeFunction(int id,SGSValue (*sta)(void*))
	: SGSFunction(id,NULL,NULL)
	, pfunc(sta)
{
}
SGSNativeFunction::~SGSNativeFunction(void)
{
	delete parameter;
	delete statements;
}
std::string SGSNativeFunction::getDebugString()
{
	return "Type : NFunction\n";
}
SGSValue SGSNativeFunction::run(SGSArguments *args)
{
	if (!args||args->count()==0)
		return pfunc(NULL);
	else
		return pfunc(s_virtualMachine->runExpression(args[0]));
}
