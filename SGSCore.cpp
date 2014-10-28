// SGSCore.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <map>
#include <iostream>
#include <algorithm>

#include "SGSAnalyzer.h"
#include "SGSAnalyzerWarper.h"
#include "SGSStatement.h"
#include "SGSFunction.h"
#include "SGSVirtualMachine.h"
#include "SGSNativeFunctions.h"

extern "C" int yyparse();

extern SGSAnalyzer *s_analyzerVector;

int _tmain(int argc, _TCHAR* argv[])
{
	CreateAnalyzerInstance();
	yyparse();
	std::for_each(s_analyzerVector->getStatements().begin(),s_analyzerVector->getStatements().end(),
		[](SGSStatement *statement)
	{
		std::cout<<statement->getDebugString();
	});
	createNewVirtualMachine(s_analyzerVector);
	s_virtualMachine->registerFunction("printf",NativeFunctions::myOutput);
	s_virtualMachine->run();
	return 0;
}

