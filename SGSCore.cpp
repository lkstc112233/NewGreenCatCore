// SGSCore.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SGSAnalyzer.h"
#include "SGSStatement.h"
#include "SGSFunction.h"
#include <map>
#include <iostream>
extern "C" int yyparse();

extern SGSAnalyzer *s_analyzerVector;


int _tmain(int argc, _TCHAR* argv[])
{
	s_analyzerVector=new SGSAnalyzer();
	yyparse();
	for (SGSAnalyzer::DEBUG_OutputListType::iterator i=s_analyzerVector->m_statements.begin();i!=s_analyzerVector->m_statements.end();++i)
		std::cout<<(*i)->getDebugString();
	for (std::map<int,SGSFunction*>::iterator i=s_analyzerVector->m_functions.begin();i!=s_analyzerVector->m_functions.end();++i)
		std::cout<<i->second->getDebugString();
	return 0;
}

