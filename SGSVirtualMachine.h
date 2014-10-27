#pragma once
#include <vector>

class SGSAnalyzer;
class SGSStatement;
class SGSStackFrame;
class SGSExpression;
class SGSArguments;
class SGSFunction;
class SGSValue;

class SGSVirtualMachine
{
private:
	SGSAnalyzer& m_analyzer;
	std::vector<SGSStackFrame*> frameStack;
	std::vector<SGSStatement*> statementStack;
	inline void pushFrame(SGSStackFrame *f){if (f)frameStack.push_back(f);}
	inline void popFrame(){frameStack.size()<=1?1==1:frameStack.pop_back();}
public:
	SGSVirtualMachine(SGSAnalyzer* analyzer);
	~SGSVirtualMachine(void);
	inline SGSStackFrame& getFrameStackTop(){return *frameStack.front();}
	inline SGSStackFrame& getFrameStackBottom(){return *frameStack.back();}
	int run();
	SGSValue runExpression(SGSExpression* expression);
	int runStatement(SGSStatement* statement);
	int runFunction(int id,SGSArguments *args);
	int runFunction(std::string functionName,SGSArguments *args);
	int runFunction(SGSFunction function,SGSArguments *args);
};

extern SGSVirtualMachine* s_virtualMachine;
