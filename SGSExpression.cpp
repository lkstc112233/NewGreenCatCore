#include "StdAfx.h"

#include <algorithm>

#include "SGSExpression.h"
#include "SGSStrings.h"
#include "SGSFunction.h"
#include "SGSValue.h"
#include "SGSVirtualMachine.h"
#include "SGSStackFrame.h"

std::string addTab(std::string &strIn);
namespace NullObjects
{
SGSLiteralExpression r_nullExpression;
}
SGSExpression* nullExpression=&NullObjects::r_nullExpression;

SGSExpression::SGSExpression()
{
}

SGSLiteralExpression::SGSLiteralExpression(void)
	: type(ETNull)
{
}
SGSLiteralExpression::SGSLiteralExpression(long long i)
	: type(ETInteger)
{
	value.integerValue=i;
}
SGSLiteralExpression::SGSLiteralExpression(long double d)
	: type(ETFloat)
{
	value.floatValue=d;
}
SGSLiteralExpression::SGSLiteralExpression(const char* c)
	: type(ETString)
{
	char* cache=new char[strlen(c)+1];
	strcpy(cache,c);
	value.stringValue=cache;
}
SGSLiteralExpression::SGSLiteralExpression(int id)
	: type(ETIdentifier)
{
	value.identifierId=id;
}
SGSLiteralExpression::SGSLiteralExpression(SGSFunction* fun)
	: type(ETFunction)
{
	value.function=fun;
}
SGSLiteralExpression::~SGSLiteralExpression(void)
{
	switch(type)
	{
	case ETString:
		delete[] value.stringValue;
		break;
	case ETFunction:
		delete value.function;
		break;
	default:
		break;
	}
}
long long SGSLiteralExpression::toInteger()
{
	switch(type)
	{
	case ETNull:
		type=ETInteger;
		return value.integerValue=0;
	case ETString:
		type=ETInteger;
		delete[] value.stringValue;
		return value.integerValue=std::stoll(value.stringValue);
	case ETInteger:
		return value.integerValue;
	case ETFloat:
		type=ETInteger;
		return value.integerValue=static_cast<long long>(value.floatValue);
	case ETFunction:
		type=ETInteger;
		delete value.function;
		return value.integerValue=0;
	case ETIdentifier:
	default:
		throw SGSInvalidTypeException(SGSStrings::INVALID_TYPE.c_str());
	}
}
long double SGSLiteralExpression::toFloat()
{
	switch(type)
	{
	case ETNull:
		type=ETFloat;
		return value.floatValue=0;
	case ETString:
		type=ETFloat;
		delete[] value.stringValue;
		return value.floatValue=strtod(value.stringValue,NULL);
	case ETInteger:
		type=ETFloat;
		return value.floatValue=static_cast<long double>(value.integerValue);
	case ETFloat:
		return value.floatValue;
	case ETFunction:
		type=ETFloat;
		delete value.function;
		return value.floatValue=0;
	case ETIdentifier:
	default:
		throw SGSInvalidTypeException(SGSStrings::INVALID_TYPE.c_str());
	}
}
std::string SGSLiteralExpression::toString()
{
	switch(type)
	{
	case ETNull:
		type=ETString;
		{
			char *dest=new char[1];
			dest[0]='\0';
			value.stringValue=dest;
		}
		return value.stringValue;
	case ETString:
		return value.stringValue;
	case ETInteger:
		type=ETString;
		{
			std::string dest=std::to_string(value.integerValue);
			char* cache=new char[dest.length()+1];
			strcpy(cache,dest.c_str());
			value.stringValue=cache;
			return dest;
		}
	case ETFloat:
		type=ETString;
		{
			std::string dest=std::to_string(value.floatValue);
			char* cache=new char[dest.length()+1];
			strcpy(cache,dest.c_str());
			value.stringValue=cache;
			return dest;
		}
	case ETFunction:
		type=ETString;
		{
			char *dest=new char[9];
			strcpy(dest,"function");
			value.stringValue=dest;
		}
		return value.stringValue;
	case ETIdentifier:
	default:
		throw SGSInvalidTypeException(SGSStrings::INVALID_TYPE.c_str());
	}
}
SGSFunction* SGSLiteralExpression::toFunction()
{
	switch(type)
	{
	case ETNull:
		type=ETFunction;
		return value.function=new SGSFunction();
	case ETString:
		type=ETFunction;
		delete value.stringValue;
		return value.function=new SGSFunction();
	case ETInteger:
		type=ETFunction;
		return value.function=new SGSFunction();
	case ETFloat:
		type=ETFunction;
		return value.function=new SGSFunction();
	case ETFunction:
		return value.function;
	case ETIdentifier:
	default:
		throw SGSInvalidTypeException(SGSStrings::INVALID_TYPE.c_str());
	}
}
void SGSLiteralExpression::toNull()
{
	switch(type)
	{
	case ETNull:
	case ETInteger:
	case ETFloat:
		break;
	case ETString:
		delete[] value.stringValue;
		break;
	case ETFunction:
		delete value.function;
		break;
	case ETIdentifier:
	default:
		throw SGSInvalidTypeException(SGSStrings::INVALID_TYPE.c_str());
	}
	type=ETNull;
}
void SGSLiteralExpression::convertToType(LiteralExpressionType tp)
{
	switch(tp)
	{
	case ETNull:
		toNull();
		return;
	case ETInteger:
		toInteger();
		return;
	case ETFloat:
		toFloat();
		return;
	case ETString:
		toString();
		return;
	case ETFunction:
		toFunction();
		return;
	case ETIdentifier:
	default:
		throw SGSInvalidTypeException(SGSStrings::INVALID_TYPE.c_str());
	}
}
SGSLiteralExpression* SGSLiteralExpression::operator+(SGSLiteralExpression *exp)
{
	switch(type)
	{
	case ETNull:
		if (exp->type<=type)
		{
			type=exp->type;
			value=exp->value;
		}
		else
		{
			convertToType(exp->type);
			return operator+(exp);
		}
		break;
	case ETString:
		if (exp->type<=type)
		{
			std::string strCache=exp->toString();
			char *dest=new char[strlen(value.stringValue)+strCache.length()+1];
			strcpy(dest,value.stringValue);
			strcat(dest,strCache.c_str());
			delete[] value.stringValue;
			value.stringValue=dest;
		}
		else
		{
			convertToType(exp->type);
			return operator+(exp);
		}
		break;
	case ETInteger:
		if (exp->type<=type)
			value.integerValue+=exp->toInteger();
		else
		{
			convertToType(exp->type);
			return operator+(exp);
		}
		break;
	case ETFloat:
		if (exp->type<=type)
			value.floatValue+=exp->toFloat();
		else
		{
			convertToType(exp->type);
			return operator+(exp);
		}
		break;
	case ETFunction:
		if (exp->type<=type)
			;
		else
		{
			convertToType(exp->type);
			return operator+(exp);
		}
		break;
	default:
	case ETIdentifier:
		throw SGSInvalidTypeException(SGSStrings::INVALID_TYPE.c_str());
	}
	delete exp;
	return this;
}
SGSLiteralExpression* SGSLiteralExpression::operator-(SGSLiteralExpression *exp)
{
	switch(type)
	{
	case ETNull:
		if (exp->type<=type)
		{
			type=exp->type;
			value=exp->value;
		}
		else
		{
			convertToType(exp->type);
			return operator-(exp);
		}
		break;
	case ETString:
		if (exp->type<=type)
		{
			std::string strCache=exp->toString();
			char *dest=new char[strlen(value.stringValue)+strCache.length()+1];
			strcpy(dest,value.stringValue);
			strcat(dest,strCache.c_str());
			delete[] value.stringValue;
			value.stringValue=dest;
		}
		else
		{
			convertToType(exp->type);
			return operator-(exp);
		}
		break;
	case ETInteger:
		if (exp->type<=type)
			value.integerValue-=exp->toInteger();
		else
		{
			convertToType(exp->type);
			return operator-(exp);
		}
		break;
	case ETFloat:
		if (exp->type<=type)
			value.floatValue-=exp->toFloat();
		else
		{
			convertToType(exp->type);
			return operator-(exp);
		}
		break;
	case ETFunction:
		if (exp->type<=type)
			;
		else
		{
			convertToType(exp->type);
			return operator-(exp);
		}
		break;
	default:
	case ETIdentifier:
		throw SGSInvalidTypeException(SGSStrings::INVALID_TYPE.c_str());
	}
	delete exp;
	return this;
}
SGSLiteralExpression* SGSLiteralExpression::operator*(SGSLiteralExpression *exp)
{
	switch(type)
	{
	case ETNull:
		if (exp->type<=type)
		{
			type=exp->type;
			value=exp->value;
		}
		else
		{
			convertToType(exp->type);
			return operator*(exp);
		}
		break;
	case ETString:
		if (exp->type<=type)
		{
			std::string strCache=exp->toString();
			char *dest=new char[strlen(value.stringValue)+strCache.length()+1];
			strcpy(dest,value.stringValue);
			strcat(dest,strCache.c_str());
			delete[] value.stringValue;
			value.stringValue=dest;
		}
		else
		{
			convertToType(exp->type);
			return operator*(exp);
		}
		break;
	case ETInteger:
		if (exp->type<=type)
			value.integerValue*=exp->toInteger();
		else
		{
			convertToType(exp->type);
			return operator*(exp);
		}
		break;
	case ETFloat:
		if (exp->type<=type)
			value.floatValue*=exp->toFloat();
		else
		{
			convertToType(exp->type);
			return operator*(exp);
		}
		break;
	case ETFunction:
		if (exp->type<=type)
			;
		else
		{
			convertToType(exp->type);
			return operator*(exp);
		}
		break;
	default:
	case ETIdentifier:
		throw SGSInvalidTypeException(SGSStrings::INVALID_TYPE.c_str());
	}
	delete exp;
	return this;
}
SGSLiteralExpression* SGSLiteralExpression::operator/(SGSLiteralExpression *exp)
{
	switch(type)
	{
	case ETNull:
		if (exp->type<=type)
		{
			type=exp->type;
			value=exp->value;
		}
		else
		{
			convertToType(exp->type);
			return operator/(exp);
		}
		break;
	case ETString:
		if (exp->type<=type)
		{
			std::string strCache=exp->toString();
			char *dest=new char[strlen(value.stringValue)+strCache.length()+1];
			strcpy(dest,value.stringValue);
			strcat(dest,strCache.c_str());
			delete[] value.stringValue;
			value.stringValue=dest;
		}
		else
		{
			convertToType(exp->type);
			return operator/(exp);
		}
		break;
	case ETInteger:
		if (exp->type<=type)
			value.integerValue/=exp->toInteger();
		else
		{
			convertToType(exp->type);
			return operator/(exp);
		}
		break;
	case ETFloat:
		if (exp->type<=type)
			value.floatValue/=exp->toFloat();
		else
		{
			convertToType(exp->type);
			return operator/(exp);
		}
		break;
	case ETFunction:
		if (exp->type<=type)
			;
		else
		{
			convertToType(exp->type);
			return operator/(exp);
		}
		break;
	default:
	case ETIdentifier:
		throw SGSInvalidTypeException(SGSStrings::INVALID_TYPE.c_str());
	}
	delete exp;
	return this;
}
SGSValue SGSLiteralExpression::run()
{
	switch(type)
	{
	case ETString:
		return SGSValue(value.stringValue);
	case ETInteger:
		return SGSValue(value.integerValue);
	case ETFloat:
		return SGSValue(value.floatValue);
	case ETIdentifier:
		return SGSValue(s_virtualMachine->getFrameStackTop().getValue(value.identifierId));
	case ETFunction:
		return SGSValue(value.function);
	default:
		throw SGSInvalidTypeException("SGSLiteralExpression::run");
	}
}
std::string SGSLiteralExpression::getDebugString()
{
	std::string toReturn="Type : ";
	switch(type)
	{
	case ETString:
		toReturn+="ETString\n";
		toReturn+="	Value=";
		toReturn+=value.stringValue;
		toReturn+="\n";
		break;
	case ETInteger:
		toReturn+="ETInteger\n";
		toReturn+="	Value=";
		toReturn+=std::to_string(value.integerValue);
		toReturn+="\n";
		break;
	case ETFloat:
		toReturn+="ETFloat\n";
		toReturn+="	Value=";
		toReturn+=std::to_string(value.floatValue);
		toReturn+="\n";
		break;
	case ETIdentifier:
		{
			toReturn+="ETIdentifier\n";
			toReturn+="	IdentifierId=";
			char cache[12];
			toReturn+=_itoa(value.identifierId,cache,10);
			toReturn+="\n";
		}
		break;
	case ETFunction:
		toReturn+="ETFunction\n";
		toReturn+=addTab(value.function->getDebugString());
		toReturn+="EndOf : ETFunction\n";
		break;
	}
	return toReturn;
}

SGSOperateExpression::SGSOperateExpression(OperateExpressionType typ)
	: type(typ)
{
}
SGSOperateExpression::~SGSOperateExpression(void)
{
	std::for_each(args.begin(),args.end(),[](SGSExpression*e){delete e;});
}
void SGSOperateExpression::addArgument(SGSExpression *exp)
{
	args.push_back(exp);
}
SGSValue SGSOperateExpression::run()
{
	switch(type)
	{
	case OTAdd:
		return s_virtualMachine->runExpression(args[0])
			.operatorAdd(s_virtualMachine->runExpression(args[1]));
	case OTSub:
		return s_virtualMachine->runExpression(args[0])
			.operatorSub(s_virtualMachine->runExpression(args[1]));
	case OTMul:
		return s_virtualMachine->runExpression(args[0])
			.operatorMul(s_virtualMachine->runExpression(args[1]));
	case OTDiv:
		return s_virtualMachine->runExpression(args[0])
			.operatorDiv(s_virtualMachine->runExpression(args[1]));
	case OTAssign:
		return s_virtualMachine->runExpression(args[0])
			.operatorAssign(s_virtualMachine->runExpression(args[1]));
	default:
		throw SGSInvalidTypeException("SGSOperateExpression::run");
	}
}
std::string SGSOperateExpression::getDebugString()
{
	std::string typeName;
	switch(type)
	{
	case OTAdd:
		typeName="OTAdd\n";
		break;
	case OTSub:
		typeName="OTSub\n";
		break;
	case OTMul:
		typeName="OTMul\n";
		break;
	case OTDiv:
		typeName="OTDiv\n";
		break;
	case OTAssign:
		typeName="OTAssign\n";
		break;
	}
	std::string toReturn="Type : ";
	toReturn += typeName;
	for (auto arg=args.begin();args.end()!=arg;++arg)
		toReturn+=addTab((*arg)->getDebugString());
	toReturn+="Endof : ";
	toReturn += typeName;
	return toReturn;
}

SGSFunctionCallExpression::SGSFunctionCallExpression(SGSExpression* fun, SGSArguments *args)
	: function(fun)
	, arguments(args)
{
}
SGSFunctionCallExpression::~SGSFunctionCallExpression(void)
{
	delete function;
	delete arguments;
}
std::string SGSFunctionCallExpression::getDebugString()
{
	std::string toReturn="Type : FunctionCall\n";
	toReturn+="	Function:\n";
	toReturn+=addTab(addTab(function->getDebugString()));
	if (arguments)
	{
		toReturn+="	Arguments:\n";
		toReturn+=addTab(addTab(arguments->getDebugString()));
	}
	toReturn+="Endof : Function:\n";
	return toReturn;
}
SGSValue SGSFunctionCallExpression::run()
{
	return s_virtualMachine->runFunction((s_virtualMachine->runExpression(function).operator SGSFunction*()),arguments);
}
