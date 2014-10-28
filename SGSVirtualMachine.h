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
	std::vector<SGSFunction*> nativeFunctions;
	void pushFrame(SGSStackFrame *f);
	void popFrame();
public:
	SGSVirtualMachine(SGSAnalyzer* analyzer);
	~SGSVirtualMachine(void);
	void registerFunction(std::string name,SGSValue (*pfunc)(SGSValue arg));
	inline SGSStackFrame& getFrameStackBottom(){return *frameStack.front();}
	inline SGSStackFrame& getFrameStackTop(){return *frameStack.back();}
	int run();
	SGSValue runExpression(SGSExpression* expression);
	int runStatement(SGSStatement* statement);
	SGSValue runFunction(int id,SGSArguments *args);
	SGSValue runFunction(std::string functionName,SGSArguments *args);
	SGSValue runFunction(SGSFunction* function,SGSArguments *args);
};

SGSVirtualMachine* createNewVirtualMachine(SGSAnalyzer *analyzer);
extern SGSVirtualMachine* s_virtualMachine;
