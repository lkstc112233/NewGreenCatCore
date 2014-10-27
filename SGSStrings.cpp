#include "StdAfx.h"
#include "SGSStrings.h"

namespace SGSStrings
{
	using std::string;
	const string INVALID_TYPE("");
}

std::string addTab(std::string &strIn)
{
	std::string toReturn="\t";
	for (std::string::iterator tmp=strIn.begin();strIn.end()!=tmp;++tmp)
		if (*tmp=='\n')
			toReturn+="\n\t";
		else
			toReturn+=*tmp;
	if (toReturn.back()=='\t')
		toReturn.pop_back();
	return toReturn;
}
