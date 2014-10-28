#include "stdafx.h"
#include <iostream>

#include "SGSNativeFunctions.h"
#include "SGSValue.h"

namespace NativeFunctions
{
	using std::cout;
	using std::endl;
	SGSFunctionType(myOutput)
	{
		cout<<arg.operator std::string()<<endl;
		return SGSValue();
	}
}
