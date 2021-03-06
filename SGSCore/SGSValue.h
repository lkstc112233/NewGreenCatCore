#pragma once

#include <string>
#include <map>

class SGSFunction;

enum ValueType
{
	VTNull,VTInteger,VTFloat,VTString,VTLeftValue,VTFunction,VTArray,
};

class SGSValue
{
public:
	union ValueStorage
	{
		long long integerValue;
		long double floatValue;
		std::string* stringValue;
		SGSFunction* functionValue;
		SGSValue* leftSgsValue;
		std::map<int,SGSValue> *arrayValue;
	};
private:
	ValueType valueType;
	ValueStorage valueStorage;
	void clearStorage();
public:
	SGSValue(const SGSValue& c);
	SGSValue(void);
	SGSValue(long long i);
	SGSValue(long double d);
	SGSValue(const char* c);
	SGSValue(std::string& c);
	SGSValue(SGSFunction* fun);
	SGSValue(SGSValue* c);
	SGSValue(std::map<int,SGSValue>& list);
	virtual ~SGSValue(void);
	operator bool();
	operator long long();
	operator long double();
	operator std::string();
	operator SGSFunction*();
	SGSValue& convert(ValueType type);
	SGSValue& operator=(const SGSValue& v);
	
	SGSValue operatorDot(int id);
	SGSValue operatorDot(SGSValue &exp);

	SGSValue operatorAssign(SGSValue &exp);
	SGSValue operatorAdd(SGSValue &exp);
	SGSValue operatorSub(SGSValue &exp);
	SGSValue operatorMul(SGSValue &exp);
	SGSValue operatorDiv(SGSValue &exp);
	SGSValue operatorMore(SGSValue &exp);
	SGSValue operatorLess(SGSValue &exp);
	SGSValue operatorEqual(SGSValue &exp);
};
