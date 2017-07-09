#include "FilStack.h"

//vector asli barname
vector<expression*> qw;
//vector komaki barname
vector<expression*> help;

bool isdig(string a) {
	For(i, a.size()) {
		if (!isdigit(a[i]) && a[i] != '.' && a[i] != '/' && a[i] == 'x') {
			return false;
		}
	}
	return true;
}
//tabe k 0 haye ezafi ashari ro hazf mikone
string improvedstringstoled(string a) {
	ll i = a.size() - 1;
	while ((isdigit(a[i]) && a[i] == '0') || a[i] == '.') {
		a.erase(i, 1);
		i--;
	}
	return a;
}
//moshtghe x ya adad
string d(string u) {
	if (isdig(u)) {
		return "0";
	}
	else if (u == "x") {
		return "1";
	}
	else if (u == "e") {
		return "0";
	}
	else {
		return "y";
	}
}
ll findu(vector<expression*>& v, string a, ll j) {
	for (ll i = j; i < v.size(); i++) {
		if (v[i]->asl == a) {
			return i;
		}
	}
}
//az har tabe ii k vared shavad yek zir reshte az an ba tavajoh b nue tabe an migirad
string substringg(string a,ll b) {
	string shelp;
	switch (b) {
	case 0:
		shelp = a.substr(1, a.rfind(")") - 1);
		break;
	case 1:
		shelp = a.substr(4, a.rfind(")") - 4);
		break;
	case 2:
		shelp = a.substr(4, a.rfind(")") - 4);
		break;
	case 3:
		shelp = a.substr(4, a.rfind(")") - 4);
		break;
	case 4:
		shelp = a.substr(4, a.rfind(")") - 4);
		break;
	case 5:
		shelp = a.substr(5, a.rfind(")") - 5);
		break;
	case 6:
		shelp = a.substr(3, a.rfind(")") - 3);
		break;
	default:
		break;
	}
	return shelp;
}
bool issplitt(vector<expression*>& v) {
	For(i, v.size()) {
		if (!v[i]->splitfunc && v[i]->func != -1) {
			return false;
		}
	}
	return true;
}
ll findnotsplitt(vector<expression*>& v) {
	for (ll i = v.size() - 1; i >= 0;i--) {
		if (!v[i]->splitfunc && v[i]->func != -1) {
			return i;
		}
	}
}
void splitfunc(vector<expression*>& v, ll i) {
	string shelp;
	switch (v[i]->func) {
	case 0:
		if (!v[i]->splitfunc) {
			shelp = substringg(v[i]->asl, 0);
			v[i]->splitfunc = true;
			Fill(shelp, help);
		}
		break;
	case 1:
		if (!v[i]->splitfunc) {
			shelp = substringg(v[i]->asl, 1);
			v[i]->splitfunc = true;
			Fill(shelp, help);
		}
		break;
	case 2:
		if (!v[i]->splitfunc) {
			shelp = substringg(v[i]->asl, 2);
			v[i]->splitfunc = true;
			Fill(shelp, help);
		}
		break;
	case 3:
		if (!v[i]->splitfunc) {
			shelp = substringg(v[i]->asl, 3);
			v[i]->splitfunc = true;
			Fill(shelp, help);
		}
		break;
	case 4:
		if (!v[i]->splitfunc) {
			shelp = substringg(v[i]->asl, 4);
			v[i]->splitfunc = true;
			Fill(shelp, help);
		}
		break;
	case 5:
		if (!v[i]->splitfunc) {
			shelp = substringg(v[i]->asl, 5);
			v[i]->splitfunc = true;
			Fill(shelp, help);
		}
		break;
	case 6:
		if (!v[i]->splitfunc) {
			shelp = substringg(v[i]->asl, 6);
			v[i]->splitfunc = true;
			Fill(shelp, help);
		}
		break;
	default:
		break;
	}
	if (issplitt(help)) {
		return;
	}
	else {
		splitfunc(help, findnotsplitt(help));
	}
}
void moshtaghfunc(vector<expression*>& v, ll sizee) {
	ll i = sizee;
	if (i == -1) {
		return;
	}
	else {
		string t = v[i]->asl;
		string k, p, g;
		string shelp;
		if (v[i]->func != -1) {
			switch (v[i]->func) {
			case 0:
				k = substringg(v[i]->asl, 0);
				v[i]->output = v[findu(v, k, i)]->output;
				break;
			case 1:
				k = substringg(v[i]->asl, 1);
				v[i]->output = "(" + v[findu(v, k, i)]->output + ")*cos(" + v[findu(v, k, i)]->asl + ")";
				break;
			case 2:
				k = substringg(v[i]->asl, 2);
				v[i]->output = "-(" + v[findu(v, k, i)]->output + ")*sin(" + v[findu(v, k, i)]->asl + ")";
				break;
			case 3:
				k = substringg(v[i]->asl, 3);
				v[i]->output = "(" + v[findu(v, k, i)]->output + ")*(1+tan^2(" + v[findu(v, k, i)]->asl + "))";
				break;
			case 4:
				k = substringg(v[i]->asl, 4);
				v[i]->output = "-(" + v[findu(v, k, i)]->output + ")*(1+cot^2(" + v[findu(v, k, i)]->asl + "))";
				break;
			case 5:
				k = substringg(v[i]->asl, 5);
				v[i]->output = "(" + v[findu(v, k, i)]->output + ")/(2*sqrt(" + v[findu(v, k, i)]->asl + "))";
				break;
			case 6:
				k = substringg(v[i]->asl, 6);
				v[i]->output = "(" + v[findu(v, k, i)]->output + ")/(" + v[findu(v, k, i)]->asl + ")";
				break;
			default:
				break;
			}
		}
		else {
			switch (v[i]->oper) {
			case '\0':
				v[i]->output = d(v[i]->asl);
				v[i]->mosh = true;
				break;
			case '+':
				k = v[i]->asl.substr(0, v[i]->operi);
				p = v[i]->asl.substr(v[i]->operi + 1, v[i]->asl.size());
				v[i]->output = "(" + v[findu(v, k, i)]->output + ")+(" + v[findu(v, p, i)]->output + ")";
				v[i]->mosh = true;
				break;
			case '-':
				k = v[i]->asl.substr(0, v[i]->operi);
				p = v[i]->asl.substr(v[i]->operi + 1, v[i]->asl.size());
				if (k == "") {
					v[i]->output = "-(" + v[findu(v, p, i)]->output + ")";
					v[i]->mosh = true;
				}
				else if (p == "") {
					v[i]->output = "-(" + v[findu(v, k, i)]->output + ")";
					v[i]->mosh = true;
				}
				else {
					v[i]->output = "(" + v[findu(v, k, i)]->output + ")-(" + v[findu(v, p, i)]->output + ")";
					v[i]->mosh = true;
				}
				break;
			case '^':
				k = v[i]->asl.substr(0, v[i]->operi);
				p = v[i]->asl.substr(v[i]->operi + 1, v[i]->asl.size());
				if (v[findu(v, k, i)]->asl == "e") {
					if (isdig(v[findu(v, p, i)]->asl)) {
						v[i]->output = "0";
					}
					else {
						v[i]->output = "(" + v[findu(v, p, i)]->output + ")*(e^" + v[findu(v, p, i)]->asl + ")";
						v[i]->mosh = true;
					}
				}
				else if (isdig(v[findu(v, k, i)]->asl)) {
					if (isdig(v[findu(v, p, i)]->asl)) {
						v[i]->output = "0";
					}
					else {
						v[i]->output = "(" + v[findu(v, p, i)]->output + ")*(" + k + "^" + v[findu(v, p, i)]->asl + ")Ln(" + k + ")";
						v[i]->mosh = true;
					}
				}
				else if (isdig(v[findu(v, p, i)]->asl)) {
					if (p != "x") {
						v[i]->output = "(" + v[findu(v, p, i)]->asl + "*" + v[findu(v, k, i)]->output + ")*(" + k + ")^(" + v[findu(v, p, i)]->asl + "-1)";
					}
					else {
						v[i]->output = "(" + v[findu(v, p, i)]->asl + "*" + v[findu(v, k, i)]->output + ")*(" + k + ")^(" + improvedstringstoled(to_string(stold(v[findu(v, p, i)]->asl) - 1)) + ")";
					}
					v[i]->mosh = true;
				}
				else if (!isdig(v[findu(v, k, i)]->asl) && !isdig(v[findu(v, p, i)]->asl)) {
					v[i]->output = "((" + v[findu(v, k, i)]->asl + "^" + v[findu(v, p, i)]->asl + ")*((" + v[findu(v, p, i)]->output + ")*Ln(" + v[findu(v, k, i)]->asl + ")" + "+((" + v[findu(v, k, i)]->output + "/" + v[findu(v, k, i)]->asl + ")*" + v[findu(v, p, i)]->asl + ")))";
				}
				break;
			case '*':
				k = v[i]->asl.substr(0, v[i]->operi);
				p = v[i]->asl.substr(v[i]->operi + 1, v[i]->asl.size());
				if (v[findu(v, k, i)]->output == "0") {
					v[i]->output = "(" + v[findu(v, p, i)]->output + ")*(" + v[findu(v, k, i)]->asl + ")";
				}
				else if (v[findu(v, p, i)]->output == "0") {
					v[i]->output = "(" + v[findu(v, k, i)]->output + ")*(" + v[findu(v, p, i)]->asl + ")";
				}
				else {
					v[i]->output = "(" + v[findu(v, k, i)]->output + ")*(" + v[findu(v, p, i)]->asl + ")+(" + v[findu(v, p, i)]->output + ")*(" + v[findu(v, k, i)]->asl + ")";
				}
				v[i]->mosh = true;
				break;
			case '/':
				k = v[i]->asl.substr(0, v[i]->operi);
				p = v[i]->asl.substr(v[i]->operi + 1, v[i]->asl.size());
				if (v[findu(v, k, i)]->output == "0" || v[findu(v, p, i)]->output == "0") {
					if (v[findu(v, k, i)]->output == "0") {
						v[i]->output = "-(" + v[findu(v, p, i)]->output + "*" + k + ")/(" + p + "^2)";
					}
					else {
						v[i]->output = "(" + v[findu(v, k, i)]->output + "*" + p + ")/(" + p + "^2)";
					}
				}
				else {
					v[i]->output = "((" + v[findu(v, k, i)]->output + "*" + p + ")-(" + v[findu(v, p, i)]->output + "*" + k + "))/(" + p + "^2)";
				}
				v[i]->mosh = true;
				break;
			default:
				break;
			}
		}
		moshtaghfunc(help, i - 1);
	}
}

void moshtagh(vector<expression*>& v, ll sizee) {
	ll i = sizee;
	if (i == -1) {
		return;
	}
	else {
		string t = v[i]->asl;
		string k, p;
		string shelp;
		if (v[i]->func != -1) {
			//agar tabe bud miad tike tekash mikone va safe komakie help ro por mikone
			splitfunc(v, i);
			//az safe help moshtagh migire
			moshtaghfunc(help, help.size() - 1);
			switch (v[i]->func) {
			case 0:
				v[i]->output = help[0]->output;
				break;
			case 1:
				v[i]->output = "(" + help[0]->output + ")*cos(" + help[0]->asl + ")";
				break;
			case 2:
				v[i]->output = "-(" + help[0]->output + ")*sin(" + help[0]->asl + ")";
				break;
			case 3:
				v[i]->output = "(" + help[0]->output + ")*(1+tan^2(" + help[0]->asl + "))";
				break;
			case 4:
				v[i]->output = "-(" + help[0]->output + ")*(1+cot^2(" + help[0]->asl + "))";
				break;
			case 5:
				//p = help[0]->asl.substr(help[0]->asl.rfind('^')+1);
				v[i]->output = "(" + help[0]->output + ")/(2sqrt(" + help[0]->asl + "))";
				break;
			case 6:
				v[i]->output = "(" + help[0]->output + ")/(" + help[0]->asl + ")";
				break;
			default:
				break;
			}
			help.clear();
		}
		else {
			switch (v[i]->oper) {
			case '\0':
				v[i]->output = d(v[i]->asl);
				v[i]->mosh = true;
				break;
			case '+':
				k = v[i]->asl.substr(0, v[i]->operi);
				p = v[i]->asl.substr(v[i]->operi + 1, v[i]->asl.size());
				v[i]->output = "(" + v[findu(v, k, i)]->output + ")+(" + v[findu(v, p, i)]->output + ")";
				v[i]->mosh = true;
				break;
			case '-':
				k = v[i]->asl.substr(0, v[i]->operi);
				p = v[i]->asl.substr(v[i]->operi + 1, v[i]->asl.size());
				if (k == "") {
					v[i]->output = "-(" + v[findu(v, p, i)]->output + ")";
					v[i]->mosh = true;
				}
				else if (p == "") {
					v[i]->output = "-(" + v[findu(v, k, i)]->output + ")";
					v[i]->mosh = true;
				}
				else {
					v[i]->output = "(" + v[findu(v, k, i)]->output + ")-(" + v[findu(v, p, i)]->output + ")";
					v[i]->mosh = true;
				}
				break;
			case '^':
				k = v[i]->asl.substr(0, v[i]->operi);
				p = v[i]->asl.substr(v[i]->operi + 1, v[i]->asl.size());
				if (v[findu(v, k, i)]->asl == "e") {
					if (isdig(v[findu(v, p, i)]->asl)) {
						v[i]->output = "0";
					}
					else {
						v[i]->output = "(" + v[findu(v, p, i)]->output + ")*(e^" + v[findu(v, p, i)]->asl + ")";
						v[i]->mosh = true;
					}
				}
				else if (isdig(v[findu(v, k, i)]->asl)) {
					if (isdig(v[findu(v, p, i)]->asl)) {
						v[i]->output = "0";
					}
					else {
						v[i]->output = "(" + v[findu(v, p, i)]->output + ")*(" + k + "^" + v[findu(v, p, i)]->asl + ")Ln(" + k + ")";
						v[i]->mosh = true;
					}
				}
				else if (isdig(v[findu(v, p, i)]->asl)) {
					if (p != "x") {
						v[i]->output = "(" + v[findu(v, p, i)]->asl + "*" + v[findu(v, k, i)]->output + ")*(" + k + ")^(" + v[findu(v, p, i)]->asl + "-1)";
					}
					else {
						v[i]->output = "(" + v[findu(v, p, i)]->asl + "*" + v[findu(v, k, i)]->output + ")*(" + k + ")^(" + improvedstringstoled(to_string(stold(v[findu(v, p, i)]->asl) - 1)) + ")";
					}
					v[i]->mosh = true;
				}
				else if (!isdig(v[findu(v, k, i)]->asl) && !isdig(v[findu(v, p, i)]->asl)) {
					v[i]->output = "((" + v[findu(v, k, i)]->asl + "^" + v[findu(v, p, i)]->asl + ")*((" + v[findu(v, p, i)]->output + ")*Ln(" + v[findu(v, k, i)]->asl + ")" + "+((" + v[findu(v, k, i)]->output + "/" + v[findu(v, k, i)]->asl + ")*" + v[findu(v, p, i)]->asl + ")))";
				}
				break;
			case '*':
				k = v[i]->asl.substr(0, v[i]->operi);
				p = v[i]->asl.substr(v[i]->operi + 1, v[i]->asl.size());
				if (v[findu(v, k, i)]->output == "0") {
					v[i]->output = "(" + v[findu(v, p, i)]->output + ")*(" + v[findu(v, k, i)]->asl + ")";
				}
				else if(v[findu(v, p, i)]->output == "0") {
					v[i]->output = "(" + v[findu(v, k, i)]->output + ")*(" + v[findu(v, p, i)]->asl + ")";
				}
				else {
					v[i]->output = "(" + v[findu(v, k, i)]->output + ")*(" + v[findu(v, p, i)]->asl + ")+(" + v[findu(v, p, i)]->output + ")*(" + v[findu(v, k, i)]->asl + ")";
				}
				v[i]->mosh = true;
				break;
			case '/':
				k = v[i]->asl.substr(0, v[i]->operi);
				p = v[i]->asl.substr(v[i]->operi + 1, v[i]->asl.size());
				if (v[findu(v, k, i)]->output == "0" || v[findu(v, p, i)]->output == "0") {
					if (v[findu(v, k, i)]->output == "0") {
						v[i]->output = "-(" + v[findu(v, p, i)]->output + "*" + k + ")/(" + p + "^2)";
					}
					else {
						v[i]->output = "(" + v[findu(v, k, i)]->output + "*" + p + ")/(" + p + "^2)";
					}
				}
				else {
					v[i]->output = "((" + v[findu(v, k, i)]->output + "*" + p + ")-(" + v[findu(v, p, i)]->output + "*" + k + "))/(" + p + "^2)";
				}
				v[i]->mosh = true;
				break;
			default:
				break;
			}
		}
		moshtagh(qw, i - 1);
	}
}
string a;
int main() {
	read;
	cin >> a;
	FilStack f(a,qw);
	moshtagh(qw, qw.size() - 1);
	cout << qw[0]->output << endl;
	return 0;
}
