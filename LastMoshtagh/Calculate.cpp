#include "Calculate.h"

using namespace std;

int expression::GetCalculation(bool bValue) {
	if (func != -1) {
		int nIndex = asl.find('(');
		string str = asl.substr(nIndex + 1);
		str = str.substr(str.rfind(')'));
		double u;
		int nError = Calculate(str.c_str(), u);
		if (nError != 0 && bValue == true)
			return nError;
		if (nError == 0) {
			switch (func) {
			case 25:	// sqrt
			case 26:	// log10
			case 27:	// log
			case 28:	// ln
				if (u <= 0)
					return ERROR_INVALID_ARGUMENT;
				break;
			}
			switch (func) {
			case 0:		outputt = u;			break;
			case 1:		outputt = sin(u);		break;
			case 2:		outputt = cos(u);		break;
			case 3:		outputt = tan(u);		break;
			case 6:		outputt = tan(u);		break;	
			case 7:		outputt = sinh(u);	break;
			case 8:		outputt = cosh(u);	break;
			case 9:		outputt = tanh(u);	break;
			case 13:	outputt = asin(u);	break;
			case 14:	outputt = acos(u);	break;
			case 15:	outputt = atan(u);	break;
			case 25:	outputt = sqrt(u);	break;
			case 26:	outputt = log10(u);	break;
			case 27:	outputt = log(u);		break;
			case 28:	outputt = log(u);		break;
			case 29:	outputt = sign(u);	break;
			case 30:	outputt = abs(u);		break;
			}
			switch (func) {
			case 6:		// cot
				if (outputt == 0)
					return ERROR_INVALID_ARGUMENT;
				outputt = 1 / outputt;
				break;
			case 19:	// asinh
			case 20:	// acosh
			case 21:	// atanh
			case 22:	// asech
			case 23:	// acosech
			case 24:	// acoth
				if ((nError = Calculate(str.c_str(), outputt)) < 0)
					return nError;
				break;
			}
			outputt *= si;
			output = outputt;
		}
		else
		{
			if (func == -1 && bValue == true)
				return ERROR_NOT_NUMERIC;
			switch (func) {
			case 0:		output = c(str.c_str(), m_strStack);			break;
			case 1:		output = c_sin(str.c_str(), m_strStack);		break;
			case 2:		output = c_cos(str.c_str(), m_strStack);		break;
			case 3:		output = c_tan(str.c_str(), m_strStack);		break;
			case 4:		output = c_sec(str.c_str(), m_strStack);		break;
			case 5:		output = c_cosec(str.c_str(), m_strStack);		break;
			case 6:		output = c_cot(str.c_str(), m_strStack);		break;
			case 7:		output = c_sinh(str.c_str(), m_strStack);		break;
			case 8:		output = c_cosh(str.c_str(), m_strStack);		break;
			case 9:		output = c_tanh(str.c_str(), m_strStack);		break;
			case 10:	output = c_sech(str.c_str(), m_strStack);		break;
			case 11:	output = c_cosech(str.c_str(), m_strStack);	break;
			case 12:	output = c_coth(str.c_str(), m_strStack);		break;
			case 13:	output = c_asin(str.c_str(), m_strStack);		break;
			case 14:	output = c_acos(str.c_str(), m_strStack);		break;
			case 15:	output = c_atan(str.c_str(), m_strStack);		break;
			case 16:	output = c_asec(str.c_str(), m_strStack);		break;
			case 17:	output = c_acosec(str.c_str(), m_strStack);	break;
			case 18:	output = c_acot(str.c_str(), m_strStack);		break;
			case 19:	output = c_asinh(str.c_str(), m_strStack);		break;
			case 20:	output = c_acosh(str.c_str(), m_strStack);		break;
			case 21:	output = c_atanh(str.c_str(), m_strStack);		break;
			case 22:	output = c_asech(str.c_str(), m_strStack);		break;
			case 23:	output = c_acosech(str.c_str(), m_strStack);	break;
			case 24:	output = c_acoth(str.c_str(), m_strStack);		break;
			case 25:	output = c_sqrt(str.c_str(), m_strStack);		break;
			case 26:	output = c_log10(str.c_str(), m_strStack);		break;
			case 27:	output = c_log(str.c_str(), m_strStack);		break;
			case 28:	output = c_ln(str.c_str(), m_strStack);		break;
			case 29:	output = c_sign(str.c_str(), m_strStack);		break;
			case 30:	output = c_abs(str.c_str(), m_strStack);		break;
			}
			outputt = si*ATOF(output.c_str());
			output = (si == -1 ? "-" : "") + output;
			if (bValue == true && IsNumeric(output.c_str()) == false)
			{
				m_strStack.empty();
				return ERROR_NOT_NUMERIC;
			}
		}
	}
	else {
		output = asl;
		if (bValue && IsNumeric(output.c_str()) == false)
		{
			m_strStack.empty();
			return ERROR_NOT_NUMERIC;
		}
		outputt = ATOF(output.c_str());
	}

	return 0;
}

char* GetErrorMessage(int nError) {
	switch (nError) {
	case ERROR_INVALID_ARGUMENT:
		return "Invalid argument";
	case ERROR_NOT_NUMERIC:
		return "Not numeric";
	case ERROR_DIVIDE_BY_ZERO:
		return "Divide by zero";
	}
	return "Unknow error";
} 
int CalculateStack(vector<expression*>& vStack, int nExpression, string strOutput)
{
	expression *pQI = vStack[nExpression++];
	int nError;
	if (pQI->oper) {
		string cu, cv;
		// get left operand calculation
		if ((nError = CalculateStack(vStack, nExpression, cu)) < 0)
			return nError;
		// get right operand calculation
		if ((nError = CalculateStack(vStack, nExpression, cv)) < 0)
			return nError;

		if (IsNumeric(cu.c_str()) == false || IsNumeric(cv.c_str()) == false) {
			switch (pQI->oper) {
			case '-':	// c(u-v) = cu-cv
			case '+':	// c(u+v) = cu+cv
				pQI->output = cu + to_string(pQI->outputt) + cv;
				break;
			case '*':	// c(u*v) = cu*cv
				pQI->output = cu + '*' + cv;
				break;
			case '/':	// c(u/v) = cu/cv
				pQI->output = cu + '/' + cv;
				break;
			case '^':	// c(u^v) = cu^cv
				pQI->output = cu + '^' + cv;
				break;
			case '%':	// c(u%v) = cu%cv
				pQI->output = cu + '%' + cv;
				break;
			}
			pQI->output = '(' + pQI->output + ')';
		}
		else
			switch (pQI->oper) {
			case '-':	// c(u-v) = cu-cv
				pQI->output=ATOF(cu.c_str()) - ATOF(cv.c_str());
				break;
			case '+':	// c(u+v) = cu+cv
				pQI->output=ATOF(cu.c_str()) + ATOF(cv.c_str());
				break;
			case '*':	// c(u*v) = cu*cv
				pQI->output=ATOF(cu.c_str())*ATOF(cv.c_str());
				break;
			case '/':	// c(u/v) = cu/cv
				if (ATOF(cv.c_str()) == 0)
					return ERROR_DIVIDE_BY_ZERO;
				pQI->output=ATOF(cu.c_str()) / ATOF(cv.c_str());
				break;
			case '^':	// c(u^v) = cu^cv
				pQI->output=pow(ATOF(cu.c_str()), ATOF(cv.c_str()));
				break;
			case '%':	// c(u%v) = cu%cv
				pQI->output=(int)ATOF(cu.c_str()) % (int)ATOF(cv.c_str());
				break;
			}
	}
	else
		if ((nError = pQI->GetCalculation(false)) < 0) {
			strOutput = GetErrorMessage(nError);
			return nError;
		}
	strOutput = pQI->output;

	return 0;
}

int CalculateStack(vector<expression*>& vStack, int& nExpression, double& dOutput) {
	expression *pQI = vStack[nExpression++];
	int nError;
	if (pQI->oper) {
		double cu, cv;
		if ((nError = CalculateStack(vStack, nExpression, cu)) < 0)
			return nError;
		if ((nError = CalculateStack(vStack, nExpression, cv)) < 0)
			return nError;

		switch (pQI->oper)
		{
		case '-':	// c(u-v) = cu-cv
			pQI->outputt = cu - cv;
			break;
		case '+':	// c(u+v) = cu+cv
			pQI->outputt = cu + cv;
			break;
		case '*':	// c(u*v) = cu*cv
			pQI->outputt = cu*cv;
			break;
		case '/':	// c(u/v) = cu/cv
			if (cv == 0)
				return ERROR_DIVIDE_BY_ZERO;
			pQI->outputt = cu / cv;
			break;
		case '^':	// d(u^v) = cu^cv
			if (cu < 0 && (int)cv != (double)cv)
				return ERROR_INVALID_ARGUMENT;
			pQI->outputt = pow(cu, cv);
			break;
		case '%':	// d(u%v) = cu%cv
			pQI->outputt = (int)cu % (int)cv;
			break;
		}
	}
	else
		// get Expression calculation
		if ((nError = pQI->GetCalculation(true)) < 0)
			return nError;
	// return resultant calculation
	dOutput = pQI->outputt;

	return 0;
}

int Calculate(const char * lpcsInput, double dOutput) {
	string strInput = lpcsInput;
	OptimizeSign(strInput);
	int nError;
	vector<expression*> vStack;
	// parse input equation and fill stack with operators and operands
	if ((nError = Fill(strInput, vStack)) < 0)
		return nError;

	int nExpression = 0;
	// apply operators to operands
	nError = CalculateStack(vStack, nExpression, dOutput);
	for (vector<expression*>::iterator pQI = vStack.begin(); pQI != vStack.end(); pQI++)
		delete *pQI;
	return nError;
}

string Calculate(const char * lpcsInput, string strStack, bool bOptimize) {
	string strInput = lpcsInput;
	OptimizeSign(strInput);
	int nError;
	vector<expression*> vStack;
	if ((nError = Fill(strInput, vStack)) < 0)
		return GetErrorMessage(nError);
	string strOutput;
	double nOutput;
	int nExpression = 0;
	if (CalculateStack(vStack, nExpression, nOutput) < 0) {
		nExpression = 0;
		CalculateStack(vStack, nExpression, strOutput);
	}
	else
		strOutput = nOutput;
	for (vector<expression*>::iterator pQI = vStack.begin(); pQI != vStack.end(); pQI++) {
		if ((*pQI)->oper)
			strStack += (*pQI)->oper + ("\r\n");
		else
			strStack += "c(" + (*pQI)->asl + ") = " + (*pQI)->output + "\r\n";
		InsertTabs((*pQI)->m_strStack);
		strStack += (*pQI)->m_strStack;
		delete *pQI;
	}

	if (bOptimize == true)
		Optimize(strOutput);
	return strOutput;
}

Calculate::Calculate() {

}


Calculate::~Calculate() {

}
