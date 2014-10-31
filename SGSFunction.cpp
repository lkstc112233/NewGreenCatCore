#include "StdAfx.h"
#include "SGSFunction.h"
#include "SGSExpression.h"
#include "SGSStatement.h"
#include "SGSValue.h"
#include "SGSVirtualMachine.h"

std::string addTab(std::string &strIn);
namespace NullObjects
{
SGSFunction r_nullFunction;
}
SGSFunction* nullFunction = &NullObjects::r_nullFunction;

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
int SGSParameters::operator[](int i)
{
	if (i<0)
		return -1;
	if (static_cast<int>(argumentsIds.size())>i)
		return argumentsIds[i];
	return -1;
}
std::string SGSParameters::getDebugString()
{
	std::string toReturn;
	for (auto argumentsId=argumentsIds.begin();argumentsId!= argumentsIds.end();++argumentsId)
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
	for(auto expression=expressions.begin();expressions.end()!=expression;++expression)
		delete *expression;
}
void SGSArguments::addArgument(SGSExpression* expression)
{
	expressions.push_back(expression);
}
SGSExpression* SGSArguments::operator[](int i)
{
	if (i<0)
		return nullExpression;
	if (static_cast<int>(expressions.size())>i)
		return expressions[i];
	return nullExpression;
}
std::string SGSArguments::getDebugString()
{
	std::string toReturn;
	for (std::vector<SGSExpression*>::iterator expression=expressions.begin();expression!= expressions.end();++expression)
		toReturn+=(*expression)->getDebugString();
	return toReturn;
}

//SGSFunction::SGSFunction()
//	: parameter(NULL)
//	, statements(new SGSEmptyStatement)
//{
//}
SGSFunction::SGSFunction(SGSStatement *sta,SGSParameters *param)
	: parameter(param)
	, statements(sta)
{
	if (!sta)
		statements=new SGSEmptyStatement;
}
SGSFunction::~SGSFunction(void)
{
	delete parameter;
	delete statements;
}
std::string SGSFunction::getDebugString()
{
	std::string toReturn="Type : FunctionDefinition\n";
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
	s_virtualMachine->runStatement(statements);
	return SGSValue();
}

SGSNativeFunction::SGSNativeFunction(SGSValue (*sta)(SGSValue))
	: SGSFunction(NULL)
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
		return pfunc(SGSValue());
	else
		return pfunc(s_virtualMachine->runExpression((*args)[0]));
}
