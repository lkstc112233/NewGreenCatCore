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
	bool returning;
	bool breaking;
	bool continuing;
	SGSValue* returnValue;
public:
	SGSVirtualMachine(SGSAnalyzer* analyzer);
	~SGSVirtualMachine(void);

	void registerFunction(std::string name,SGSValue (*pfunc)(SGSValue arg));

	int getIdentifierId(std::string name);

	inline SGSStackFrame& getFrameStackBottom(){return *frameStack.front();}
	inline SGSStackFrame& getFrameStackTop(){return *frameStack.back();}
	SGSValue getValue(int id);
	SGSValue getValue(std::string name);

	int run();
	SGSValue runExpression(SGSExpression* expression);
	int runStatement(SGSStatement* statement);
	SGSValue runFunction(int id,SGSArguments *args);
	SGSValue runFunction(std::string functionName,SGSArguments *args);
	SGSValue runFunction(SGSFunction* function,SGSArguments *args);

	void setContinue();
	void setBreak();
	void setReturn(SGSValue retValue);
	inline bool isReturning(){return returning;}
	inline bool isBreaking(){return breaking;}
	inline bool isContinuing(){return continuing;}
	inline bool isSkipping(){return isReturning()||isBreaking()||isContinuing();}
	SGSValue getReturnValue();
	inline void unsetContinue(){continuing=false;}
	inline void unsetBreak(){breaking=false;}
};

SGSVirtualMachine* createNewVirtualMachine(SGSAnalyzer *analyzer);
extern SGSVirtualMachine* s_virtualMachine;
