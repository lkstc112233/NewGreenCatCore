#include "StdAfx.h"

#include <cstdlib>
#include <algorithm>

#include "SGSValue.h"
#include "SGSStrings.h"
#include "SGSExceptions.h"
#include "SGSFunction.h"

SGSValue::SGSValue(const SGSValue& c)
	: valueStorage(c.valueStorage)
	, valueType(c.valueType)
{
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
SGSValue::~SGSValue(void)
{
	switch(valueType)
	{
	case VTString:
		delete valueStorage.stringValue;
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
//	case ARRAY:
//		return static_cast<bool>(valueStorage.Array->size());
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
//	case ARRAY:
//		return valueStorage.Array->size();
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
//	case ARRAY:
//		return valueStorage.Array->size();
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
//	case ARRAY:
//		return "Array";
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
		return nullFunction;
	case VTFunction:
		return valueStorage.functionValue;
//	case ARRAY:
//		return "Array";
	case VTLeftValue:
		return *valueStorage.leftSgsValue;
	default:
		throw SGSInvalidTypeException(SGSStrings::INVALID_TYPE.c_str());
	}
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
