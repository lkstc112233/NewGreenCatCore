#pragma once

#define SGSFunctionType(funName) SGSValue funName(SGSValue arg)

class SGSValue;

namespace NativeFunctions
{
	SGSFunctionType(myOutput);
}
