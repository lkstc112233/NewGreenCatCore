#include "StdAfx.h"
#include "SGSStackFrame.h"
#include "SGSValue.h"

#include <algorithm>

SGSStackFrame::SGSStackFrame(void)
{
}
SGSStackFrame::~SGSStackFrame(void)
{
	std::for_each(variables.begin(),variables.end(),[](std::pair<int,SGSValue*> p){delete p.second;});
}
void SGSStackFrame::registerValue(int id)
{
	getNewValue(id);
}
void SGSStackFrame::registerValue(int id,SGSValue value)
{
	*(getNewValue(id))=value;
}
SGSValue* SGSStackFrame::getOldValue(int id)
{
	std::map<int,SGSValue*>::iterator value=variables.find(id);
	if (value!=variables.end())
		return value->second;
	return NULL;
}
SGSValue* SGSStackFrame::getNewValue(int id)
{
	SGSValue* toReturn=getOldValue(id);
	if (toReturn)
		return toReturn;
	toReturn=new SGSValue();
	variables.insert(std::make_pair(id,toReturn));
	return toReturn;
}

SGSValue* SGSAncestorStackFrame::getValue(int id)
{
	return getNewValue(id);
}

SGSValue* SGSFunctionStackFrame::getValue(int id)
{
	SGSValue* toReturn=getOldValue(id);
	if (toReturn)
		return toReturn;
	return parent->getValueThrough(id);
}

SGSValue* SGSStatementStackFrame::getValue(int id)
{
	SGSValue* toReturn=getOldValue(id);
	if (toReturn)
		return toReturn;
	return parent->getValue(id);
}

SGSValue* SGSThroughStackFrame::getValue(int id)
{
	return parent->getValue(id);
}
void SGSThroughStackFrame::registerValue(int id)
{
	parent->registerValue(id);
}
void SGSThroughStackFrame::registerValue(int id,SGSValue value)
{
	parent->registerValue(id,value);
}
