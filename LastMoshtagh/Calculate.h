#include "FilStack.h"
#pragma once

#define e 2.7182818284590452353602874713527
#define pi 3.1415926535897932384626433832795
#define ATOF(x)	(((x) == "e") ? e : ((x) == "pi" ? pi : atof(x)))
#define sign(x)		((x)>=0 ? 1 : -1)
#define c(u,stack)			Calculate(u,stack)
#define c_sin(u,stack)		"sin("+c(u,stack)+")"						
#define c_cos(u,stack)		"cos("+c(u,stack)+")"
#define c_tan(u,stack)		"tan("+c(u,stack)+")"
#define c_sec(u,stack)		"sec("+c(u,stack)+")"
#define c_cosec(u,stack)	"cosec("+c(u,stack)+")"
#define c_cot(u,stack)		"cot("+c(u,stack)+")"
#define c_sinh(u,stack)		"sinh("+c(u,stack)+")"
#define c_cosh(u,stack)		"cosh("+c(u,stack)+")"
#define c_tanh(u,stack)		"tanh("+c(u,stack)+")"
#define c_sech(u,stack)		"sech("+c(u,stack)+")"
#define c_cosech(u,stack)	"cosech("+c(u,stack)+")"
#define c_coth(u,stack)		"coth("+c(u,stack)+")"
#define c_asin(u,stack)		"asin("+c(u,stack)+")"
#define c_acos(u,stack)		"acos("+c(u,stack)+")"
#define c_atan(u,stack)		"atan("+c(u,stack)+")"
#define c_asec(u,stack)		"asec("+c(u,stack)+")"
#define c_acosec(u,stack)	"acosec("+c(u,stack)+")"
#define c_acot(u,stack)		"acot("+c(u,stack)+")"
#define c_asinh(u,stack)	"asinh("+c(u,stack)+")"
#define c_acosh(u,stack)	"acosh("+c(u,stack)+")"
#define c_atanh(u,stack)	"atanh("+c(u,stack)+")"
#define c_asech(u,stack)	"asech("+c(u,stack)+")"
#define c_acosech(u,stack)	"acosech("+c(u,stack)+")"
#define c_acoth(u,stack)	"acoth("+c(u,stack)+")"
#define c_sqrt(u,stack)		"sqrt("+c(u,stack)+")"
#define c_log10(u,stack)	"log10("+c(u,stack)+")"
#define c_log(u,stack)		"log("+c(u,stack)+")"
#define c_ln(u,stack)		c_log(u,stack)
#define c_sign(u,stack)		"sign("+c(u,stack)+")"
#define c_abs(u,stack)		"abs("+c(u,stack)+")"
#define ERROR_INVALID_ARGUMENT	-1
#define ERROR_DIVIDE_BY_ZERO	-2
#define ERROR_NOT_NUMERIC		-3
int Calculate(const char * lpcsInput, double dOutput);
string Calculate(const char * lpcsInput, string strStack, bool bOptimize = false);

class Calculate {
public:
	Calculate();
	~Calculate();
};

