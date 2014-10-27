#include "StdAfx.h"

#include <algorithm>

#include "SGSAnalyzer.h"
#include "SGSExpression.h"
#include "SGSStatement.h"

class IdMatcher
{
public:
	IdMatcher(int i):identifierId(i){}
	bool operator ()(const std::map<std::string,int>::value_type &pair)
	{
		return pair.second == identifierId;
	}
private:
	const int identifierId;
};


SGSAnalyzer::SGSAnalyzer(void)
	: lineNumber(1)
{
}
SGSAnalyzer::~SGSAnalyzer(void)
{
	for(std::map<int,SGSFunction*>::iterator function=m_functions.begin();function != m_functions.end();++function)
		delete function->second;
	for(std::list<SGSStatement*>::iterator statement=m_statements.begin();statement != m_statements.end();++statement)
		delete *statement;
}
void SGSAnalyzer::clearStringLiteralCache()
{
	stringLiteralCache="";
}
void SGSAnalyzer::addStringLiteralCharacter(char c)
{
	stringLiteralCache+=c;
}
const char* SGSAnalyzer::getStringLiteralCache()
{
	return stringLiteralCache.c_str();
}
void SGSAnalyzer::lineNumberUp()
{
	++lineNumber;
}
int SGSAnalyzer::getIdentifierId(char* identifierName)
{
	std::map<std::string,int>::iterator it=m_identifierTable.find(identifierName);
	if (m_identifierTable.end()==it)//Not found.
	{
		int id=m_identifierTable.size();
		m_identifierTable.insert(make_pair(std::string(identifierName),id));
		return id;
	}
	return it->second;
}
std::string SGSAnalyzer::getIdentifierName(int identifierId)
{
	std::map<std::string,int>::iterator it=std::find_if(m_identifierTable.begin(), m_identifierTable.end(), IdMatcher(identifierId));
	if (m_identifierTable.end()==it)//Not found.
		throw(std::string("Bad Identifier"));
	return it->first;
}
void SGSAnalyzer::addStatement(SGSStatement* p)
{
	m_statements.push_back(p);
}
void SGSAnalyzer::addFunction(SGSFunction* p)
{
	//m_functions.insert(std::make_pair(p->getIdentifierId(),p));
}
