#pragma once
#include <map>

class SGSValue;
class SGSStatement;

class SGSStackFrame
{
protected:
	std::map<int,SGSValue*> variables;
	SGSValue* getOldValue(int id);
	SGSValue* getNewValue(int id);
public:
	SGSStackFrame(void);
	virtual ~SGSStackFrame(void);
	virtual SGSValue* getValue(int id)=0;
	virtual SGSValue* getValueThrough(int id)=0;
};

class SGSAncestorStackFrame : public SGSStackFrame
{
public:
	virtual SGSValue* getValue(int id);
	virtual SGSValue* getValueThrough(int id){return getValue(id);}
};

class SGSStatementStackFrameBase : public SGSStackFrame
{
protected:
	SGSStackFrame* parent;
public:
	void setParentFrame(SGSStackFrame* f){ parent=f; }
	void registerValue(int id,SGSValue value);
	virtual SGSValue* getValueThrough(int id){return parent->getValueThrough(id);}
};

class SGSFunctionStackFrame : public SGSStatementStackFrameBase
{
public:
	virtual SGSValue* getValue(int id);
};

class SGSStatementStackFrame : public SGSStatementStackFrameBase
{
public:
	virtual SGSValue* getValue(int id);
};

class SGSThroughStackFrame : public SGSStatementStackFrameBase
{
public:
	virtual SGSValue* getValue(int id);
};
