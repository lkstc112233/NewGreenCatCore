#include "StdAfx.h"

#pragma warning (disable: 4800)

#include <cstdlib>
#include <algorithm>

#include "SGSValue.h"
#include "SGSStrings.h"
#include "SGSExceptions.h"
#include "SGSFunction.h"
#include "SGSVirtualMachine.h"

SGSValue::SGSValue(const SGSValue& c)
	: valueStorage(c.valueStorage)
	, valueType(c.valueType)
{
	switch (valueType)
	{
	case VTString:
		valueStorage.stringValue=new std::string(*valueStorage.stringValue);
	case VTArray:
		valueStorage.arrayValue=new std::map<int,SGSValue>(*valueStorage.arrayValue);
	default:
		break;
	}
}
SGSValue::SGSValue()
	: valueType(VTNull)
{
}
SGSValue::SGSValue(long long i)
	: valueType(VTInteger)
{
	valueStorage.integerValue=i;
}
SGSValue::SGSValue(long double d)
	: valueType(VTFloat)
{
	valueStorage.floatValue=d;
}
SGSValue::SGSValue(const char* c)
	: valueType(VTString)
{
	valueStorage.stringValue=new std::string(c);
}
SGSValue::SGSValue(std::string& c)
	: valueType(VTString)
{
	valueStorage.stringValue=new std::string(c);
}
SGSValue::SGSValue(SGSFunction* fun)
	: valueType(VTFunction)
{
	valueStorage.functionValue=fun;
}
SGSValue::SGSValue(SGSValue* val)
	: valueType(VTLeftValue)
{
	valueStorage.leftSgsValue=val;
}
SGSValue::SGSValue(std::map<int,SGSValue>& list)
	: valueType(VTArray)
{
	valueStorage.arrayValue=new std::map<int,SGSValue>(list);
}
SGSValue::~SGSValue(void)
{
	clearStorage();
}

void SGSValue::clearStorage(void)
{
	switch(valueType)
	{
	case VTString:
		delete valueStorage.stringValue;
		break;
	case VTArray:
		delete valueStorage.arrayValue;
		break;
	default:
		break;
	}
}

SGSValue::operator bool()
{
	switch (valueType)
	{
	case VTNull:
		return false;
	case VTInteger:
		return static_cast<bool>(valueStorage.integerValue);
	case VTFloat:
		return static_cast<bool>(valueStorage.floatValue);
	case VTString:
		if((*valueStorage.stringValue)=="true")
			return true;
		return false;
	case VTFunction:
		return true;
	case VTArray:
		return static_cast<bool>(valueStorage.arrayValue->size());
	case VTLeftValue:
		return *valueStorage.leftSgsValue;
	default:
		throw SGSInvalidTypeException(SGSStrings::INVALID_TYPE.c_str());
	}
}
SGSValue::operator long long()
{
	switch (valueType)
	{
	case VTNull:
		return 0;
	case VTInteger:
		return valueStorage.integerValue;
	case VTFloat:
		return static_cast<long long>(valueStorage.floatValue);
	case VTString:
		return std::stoll(*valueStorage.stringValue);
	case VTFunction:
		return 1;
	case VTArray:
		return 0;
	case VTLeftValue:
		return *valueStorage.leftSgsValue;
	default:
		throw SGSInvalidTypeException(SGSStrings::INVALID_TYPE.c_str());
	}
}
SGSValue::operator long double()
{
	switch (valueType)
	{
	case VTNull:
		return 0;
	case VTInteger:
		return static_cast<long double>(valueStorage.integerValue);
	case VTFloat:
		return valueStorage.floatValue;
	case VTString:
		return strtod(valueStorage.stringValue->c_str(),NULL);
	case VTFunction:
		return 1;
	case VTArray:
		return 0;
	case VTLeftValue:
		return *valueStorage.leftSgsValue;
	default:
		throw SGSInvalidTypeException(SGSStrings::INVALID_TYPE.c_str());
	}
}
SGSValue::operator std::string()
{
	switch (valueType)
	{
	case VTNull:
		return "";
	case VTInteger:
		return std::to_string(valueStorage.integerValue);
	case VTFloat:
		return std::to_string(valueStorage.floatValue);
	case VTString:
		return *valueStorage.stringValue;
	case VTFunction:
		return "Function";
	case VTArray:
		return "Array";
	case VTLeftValue:
		return *valueStorage.leftSgsValue;
	default:
		throw SGSInvalidTypeException(SGSStrings::INVALID_TYPE.c_str());
	}
}
SGSValue::operator SGSFunction*()
{
	switch (valueType)
	{
	case VTNull:
	case VTInteger:
	case VTFloat:
	case VTString:
	case VTArray://?
		return nullFunction;
	case VTFunction:
		return valueStorage.functionValue;
	case VTLeftValue:
		return *valueStorage.leftSgsValue;
	default:
		throw SGSInvalidTypeException(SGSStrings::INVALID_TYPE.c_str());
	}
}

SGSValue& SGSValue::convert(ValueType type)
{
	if(type==valueType)
		return *this;
	switch(type)
	{
	case VTNull:
		clearStorage();
		valueType=VTNull;
		break;
	case VTInteger:
		{
			auto temp=this->operator long long();
			clearStorage();
			valueType=VTInteger;
			valueStorage.integerValue=temp;
			break;
		}
	case VTFloat:
		{
			auto temp=this->operator long double();
			clearStorage();
			valueType=VTFloat;
			valueStorage.floatValue=temp;
			break;
		}
	case VTString:
		{
			auto temp=this->operator std::string();
			clearStorage();
			valueType=VTString;
			valueStorage.stringValue=new decltype(temp)(temp);
			break;
		}
	case VTFunction:
		{
			clearStorage();
			valueType=VTFunction;
			valueStorage.functionValue=nullFunction;
			break;
		}
	case VTArray:
		{
			clearStorage();
			valueType=VTArray;
			valueStorage.arrayValue=new std::map<int,SGSValue>();
			break;
		}
	case VTLeftValue:
	default:
		throw SGSInvalidTypeException("SGSValue::convert");
	}
	return *this;
}

SGSValue& SGSValue::operator=(const SGSValue& v)
{
	valueStorage=v.valueStorage;
	valueType=v.valueType;
	switch (valueType)
	{
	case VTString:
		valueStorage.stringValue=new std::string(*valueStorage.stringValue);
	case VTArray:
		valueStorage.arrayValue=new std::map<int,SGSValue>(*valueStorage.arrayValue);
	default:
		break;
	}
	return *this;
}

SGSValue SGSValue::operatorDot(int id)
{
	convert(VTArray);
	auto result=valueStorage.arrayValue->find(id);
	if (result!=valueStorage.arrayValue->end())
		return SGSValue(&result->second);
	valueStorage.arrayValue->insert(std::make_pair(id,SGSValue()));
	result=valueStorage.arrayValue->find(id);
	return SGSValue(&result->second);
}
SGSValue SGSValue::operatorDot(SGSValue &exp)
{
	return operatorDot(s_virtualMachine->getIdentifierId(exp.operator std::string()));
}

SGSValue SGSValue::operatorAssign(SGSValue &exp)
{
	switch(valueType)
	{
	case VTNull:
	case VTString:
	case VTInteger:
	case VTFloat:
	case VTFunction:
		return exp;
	case VTLeftValue:
		return *valueStorage.leftSgsValue=exp;
	default:
		throw SGSInvalidTypeException(SGSStrings::INVALID_TYPE.c_str());
	}
}
SGSValue SGSValue::operatorAdd(SGSValue &exp)
{
	switch(valueType)
	{
	case VTNull:
		return exp;
	case VTString:
		return SGSValue(*valueStorage.stringValue+exp.operator std::string());
	case VTInteger:
		return SGSValue(valueStorage.integerValue+exp.operator long long());
		//switch(exp.valueType)
		//{
		//case VTInteger:
		//	return SGSValue(valueStorage.integerValue+exp.operator long long());
		//case VTFloat:
		//	return SGSValue(operator long double()+exp.operator long double());
		//case VTString:
		//	return SGSValue(valueStorage.integerValue+exp.operator long long());
		//case VTFloat:
		//	return SGSValue(operator long double()+exp.operator long double());
		//}
	case VTFloat:
		return SGSValue(valueStorage.floatValue+exp.operator long double());
	case VTFunction:
		return *this;
	case VTLeftValue:
		return valueStorage.leftSgsValue->operatorAdd(exp);
	default:
		throw SGSInvalidTypeException(SGSStrings::INVALID_TYPE.c_str());
	}
}
SGSValue SGSValue::operatorSub(SGSValue &exp)
{
	switch(valueType)
	{
	case VTNull:
		return exp;
	case VTString:
		{
			std::string src=operator std::string();
			std::string des=exp.operator std::string();
			std::string::size_type pos = 0;
			std::string::size_type srcLen = src.size();
			std::string::size_type desLen = des.size();
			pos=src.find(src, pos); 
			while ((pos != std::string::npos))
			{
				src.replace(pos, srcLen, des);
				pos=src.find(src, (pos+desLen));
			}
			return SGSValue(src);
		}
	case VTInteger:
		return SGSValue(valueStorage.integerValue-exp.operator long long());
	case VTFloat:
		return SGSValue(valueStorage.floatValue-exp.operator long double());
	case VTFunction:
		return *this;
	case VTLeftValue:
		return valueStorage.leftSgsValue->operatorSub(exp);
	default:
		throw SGSInvalidTypeException(SGSStrings::INVALID_TYPE.c_str());
	}
}
SGSValue SGSValue::operatorMul(SGSValue &exp)
{
	switch(valueType)
	{
	case VTNull:
		return exp;
	case VTString:
		return SGSValue(*valueStorage.stringValue+exp.operator std::string());
	case VTInteger:
		return SGSValue(valueStorage.integerValue*exp.operator long long());
	case VTFloat:
		return SGSValue(valueStorage.floatValue*exp.operator long double());
	case VTFunction:
		return *this;
	case VTLeftValue:
		return valueStorage.leftSgsValue->operatorMul(exp);
	default:
		throw SGSInvalidTypeException(SGSStrings::INVALID_TYPE.c_str());
	}
}
SGSValue SGSValue::operatorDiv(SGSValue &exp)
{
	switch(valueType)
	{
	case VTNull:
		return exp;
	case VTString:
		{
			std::string src=operator std::string();
			std::string des=exp.operator std::string();
			std::string::size_type pos = 0;
			std::string::size_type srcLen = src.size();
			std::string::size_type desLen = des.size();
			pos=src.find(src, pos); 
			while ((pos != std::string::npos))
			{
				src.replace(pos, srcLen, des);
				pos=src.find(src, (pos+desLen));
			}
			return SGSValue(src);
		}
	case VTInteger:
		{
			long long ans=exp.operator long long();
			if (ans)
				return SGSValue(valueStorage.integerValue/ans);
			else
				throw SGSMathErrorException("");
		}
	case VTFloat:
		{
			long double ans=exp.operator long double();
			if (ans!=0)
				return SGSValue(valueStorage.integerValue/ans);
			else
				throw SGSMathErrorException("");
		}
	case VTFunction:
		return *this;
	case VTLeftValue:
		return valueStorage.leftSgsValue->operatorDiv(exp);
	default:
		throw SGSInvalidTypeException(SGSStrings::INVALID_TYPE.c_str());
	}
}
SGSValue SGSValue::operatorLess(SGSValue &exp)
{
	switch(valueType)
	{
	case VTNull:
		return exp;
	case VTString:
		return SGSValue(*valueStorage.stringValue+exp.operator std::string());
	case VTInteger:
		return SGSValue(valueStorage.integerValue<exp.operator long long()?1.l:0.l);
	case VTFloat:
		return SGSValue(valueStorage.floatValue<exp.operator long double()?1.l:0.l);
	case VTFunction:
		return *this;
	case VTLeftValue:
		return valueStorage.leftSgsValue->operatorLess(exp);
	default:
		throw SGSInvalidTypeException(SGSStrings::INVALID_TYPE.c_str());
	}
}
SGSValue SGSValue::operatorMore(SGSValue &exp)
{
	switch(valueType)
	{
	case VTNull:
		return exp;
	case VTString:
		return SGSValue(*valueStorage.stringValue+exp.operator std::string());
	case VTInteger:
		return SGSValue(valueStorage.integerValue>exp.operator long long()?1.l:0.l);
	case VTFloat:
		return SGSValue(valueStorage.floatValue>exp.operator long double()?1.l:0.l);
	case VTFunction:
		return *this;
	case VTLeftValue:
		return valueStorage.leftSgsValue->operatorMore(exp);
	default:
		throw SGSInvalidTypeException(SGSStrings::INVALID_TYPE.c_str());
	}
}
SGSValue SGSValue::operatorEqual(SGSValue &exp)
{
	switch(valueType)
	{
	case VTNull:
		return VTNull==exp.valueType?1.l:0.l;
	case VTString:
		return SGSValue(*valueStorage.stringValue==exp.operator std::string()?1.l:0.l);
	case VTInteger:
		return SGSValue(valueStorage.integerValue==exp.operator long long()?1.l:0.l);
	case VTFloat:
		return SGSValue(valueStorage.floatValue==exp.operator long double()?1.l:0.l);
	case VTFunction:
		return *this;
	case VTLeftValue:
		return valueStorage.leftSgsValue->operatorEqual(exp);
	default:
		throw SGSInvalidTypeException(SGSStrings::INVALID_TYPE.c_str());
	}
}
