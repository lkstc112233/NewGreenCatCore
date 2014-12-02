#pragma once

#include <map>
#include <string>
#include <list>
#include "SGSFunction.h"
#include "SGSValue.h"

class SGSExpression;
class SGSStatement;
class SGSFunction;
class SGSOperateExpression;
enum OperateExpressionType;

class SGSAnalyzer
{
public:
	SGSAnalyzer(void);
	~SGSAnalyzer(void);
private:
public:
	std::map<int,SGSFunction*> m_functions;
	std::list<SGSStatement*> m_statements;
	std::map<std::string,int> m_identifierTable;
	std::map<std::string,SGSValue> m_globalValues;
private:
	std::string stringLiteralCache;
	int lineNumber;
public:
	void clearStringLiteralCache();
	void addStringLiteralCharacter(char);
	const char* getStringLiteralCache();
	void lineNumberUp();
	int getIdentifierId(const char* identifierName);
	std::string getIdentifierName(int identifierId);
	void addStatement(SGSStatement* p);
	inline const std::list<SGSStatement*>& getStatements(){return m_statements;}
	void addFunction(SGSFunction* p);
};
