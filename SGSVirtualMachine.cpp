#include "StdAfx.h"

#include <algorithm>
#include <cstdlib>

#include "SGSVirtualMachine.h"
#include "SGSStackFrame.h"
#include "SGSExpression.h"
#include "SGSStatement.h"
#include "SGSAnalyzer.h"

SGSVirtualMachine* s_virtualMachine=NULL;

SGSVirtualMachine* createNewVirtualMachine(SGSAnalyzer *analyzer)
{
	if (s_virtualMachine)
		delete s_virtualMachine;
	return s_virtualMachine=new SGSVirtualMachine(analyzer);
}

SGSVirtualMachine::SGSVirtualMachine(SGSAnalyzer* analyzer)
	: m_analyzer(*analyzer)
{
	frameStack.push_back(new SGSAncestorStackFrame);
}
SGSVirtualMachine::~SGSVirtualMachine(void)
{
	std::for_each(frameStack.begin(),frameStack.end(),[](SGSStackFrame* i){delete i;});
}
void SGSVirtualMachine::registerFunction(std::string name,SGSValue (*pfunc)(SGSValue arg))
{
	SGSNativeFunction* nf=new SGSNativeFunction(pfunc);
	nativeFunctions.push_back(nf);
	(*getFrameStackBottom().getValue(m_analyzer.getIdentifierId(name.c_str())))=SGSValue(nf);
}
void SGSVirtualMachine::pushFrame(SGSStackFrame *f)
{
	if (f)
		frameStack.push_back(f);
}

void SGSVirtualMachine::popFrame()
{
	if (frameStack.size()>1)
	{
		delete frameStack.back();
		frameStack.pop_back();
	}
}

int SGSVirtualMachine::run()
{
	std::for_each(m_analyzer.getStatements().begin(),m_analyzer.getStatements().end()
		,[this](SGSStatement *statement)
	{
		this->runStatement(statement);
	});
	return 0;
}
SGSValue SGSVirtualMachine::runExpression(SGSExpression* expression)
{
	return expression->run();
}
int SGSVirtualMachine::runStatement(SGSStatement* statement)
{
	SGSStatementStackFrameBase* frame=statement->getStackFrame();
	frame->setParentFrame(&getFrameStackTop());
	pushFrame(frame);
	int result=statement->run();
	popFrame();
	return result;
}
SGSValue SGSVirtualMachine::runFunction(int id,SGSArguments *args)
{
	return runFunction(getFrameStackTop().getValue(id)->operator SGSFunction *(),args);
}
SGSValue SGSVirtualMachine::runFunction(std::string functionName,SGSArguments *args)
{
	return runFunction(getFrameStackTop().getValue(m_analyzer.getIdentifierId(functionName.c_str()))->operator SGSFunction *(),args);
}
SGSValue SGSVirtualMachine::runFunction(SGSFunction* function,SGSArguments *args)
{
	SGSStatementStackFrameBase* frame=new SGSFunctionStackFrame();
	frame->setParentFrame(&getFrameStackTop());
	int sumMax=std::max(args->count(),function->getParameter()->count());
	for (int i=0;i<sumMax;++i)
		frame->registerValue((*function->getParameter())[i],this->runExpression((*args)[i]));
	pushFrame(frame);
	SGSValue result=function->run(args);
	popFrame();
	return result;
}