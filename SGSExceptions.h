#pragma once

#include <string>

// Definitions of exceptions.

class SGSException
{
public:
	inline SGSException(){}
	inline SGSException(const char* c):e(c){}
public:
	std::string e;
};

class SGSInvalidTypeException : public SGSException
{
public:
	inline SGSInvalidTypeException(const char* c):SGSException(c){}
};

class SGSWrongStatementException : public SGSException
{
public:
	inline SGSWrongStatementException(const char* c,int e):SGSException(c),errCode(e){}
public:
	int errCode;
};

class SGSMathErrorException : public SGSException
{
public:
	inline SGSMathErrorException(const char* c):SGSException(c){}
};
