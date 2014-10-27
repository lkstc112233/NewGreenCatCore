#include "StdAfx.h"

#include <algorithm>

#include "SGSVirtualMachine.h"
#include "SGSStackFrame.h"
#include "SGSExpression.h"
#include "SGSAnalyzer.h"

SGSVirtualMachine* s_virtualMachine;

SGSVirtualMachine::SGSVirtualMachine(SGSAnalyzer* analyzer)
	: m_analyzer(*analyzer)
{
	frameStack.push_back(new SGSAncestorStackFrame);
}
SGSVirtualMachine::~SGSVirtualMachine(void)
{
	std::for_each(frameStack.begin(),frameStack.end(),[](SGSStackFrame* i){delete i;});
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
	return 0;
}
int SGSVirtualMachine::runFunction(int id,SGSArguments *args)
{

	return 0;
}
int SGSVirtualMachine::runFunction(std::string functionName,SGSArguments *args)
{
	return 0;
}
int SGSVirtualMachine::runFunction(SGSFunction function,SGSArguments *args)
{
	return 0;
}