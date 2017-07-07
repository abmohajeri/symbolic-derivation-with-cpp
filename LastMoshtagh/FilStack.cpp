#include "FilStack.h"

//tavabe baraye moshtagh giri
char * exfunc[] = {
	"(",
	"sin(",
	"cos(",
	"tan(",
	"cot(",
	"sqrt(",
	"ln(",
	NULL
};
//list operator ha ba asase olaviat
char * operators[] = { "+-", "*/", "^", NULL };

ll Fill(string a, vector<expression*>& v) {
	v.push_back(new expression(a));
	For(n, v.size()) {
		//age ebarat operator nadasht (0 yani nadarad)
		if (v[n]->oper == 0) {
			const char * cpy = v[n]->asl.c_str();
			//tabe Getopi reshte ra az akhar ebarat migardad va b tartibe olaviat ha makan operator ra bar migardanad
			ll nopi = GetOpi(cpy, operators);
			//baraye behine shodan moshtagh giri in amal anjam mishavad
			v[n]->operi = nopi;
			//age operator peida shod
			if (nopi != -1) {
				//baraye haman ebarat operator ra lahaz mikonad
				v[n]->oper = v[n]->asl[nopi];
				//bar asase operator yaft shode ebarat ra nesf mikona v b saf miafzayad
				v.insert(v.begin() + n + 1, new expression(v[n]->asl.substr(0, nopi)));
				v.insert(v.begin() + n + 2, new expression(v[n]->asl.substr(nopi + 1)));
			}
			//age operator peida nashod
			else {
				if ((v[n]->func = recfunc(cpy)) == 0 && v[n]->si == 0)
					v[n--]->asl = v[n]->asl.substr(1, v[n]->asl.size() - 2);
			}
		}
	}
	return 0;
}

ll GetOpi(const char * x, char * op[]) {
	//char * operators ro migardad
	for (int n = 0; op[n]; n++) {
		ll i = 0;
		//address akharin char ro migire  ->  p=address akharin khune , *p=characteresh
		char * p = (char *)x + strlen(x) - 1;
		//moghyese address ha
		while (p >= x) {
			//age parantez baste peida shod yani ghatan bayad y baz ham dashte bashad
			if (*p == ')')
				i++;
			//age parantez baz peida shod yani y ebarati dakhel parantez bude
			else if (*p == '(')
				i--;
			//agar parantez ha baz va baste tashkhis dade shod va 
			else if (i == 0 && strchr(op[n], *p) != NULL)
				return (ll)(p - x);
			p--;
		}
	}
	return -1;
}

ll recfunc(const char * eop) {
	char * p = (char *)eop;
	//dar dakhel array exfunc migardad
	for (int i = 0; exfunc[i]; i++) {
		//agar khorujie tabe zir 0 bashad yani tabe dakhel exfunc yaft shode ast
		if (memcmp(p, exfunc[i], strlen(exfunc[i])) == 0) {
			//baraye nazdik tarin parantez baste jost va ju mikonad , va b in gune ersal mikonad: sin(x)->(x),(x)->(x)
			if (closest(p + strlen(exfunc[i]) - 1) == NULL)
				return -1;
			return i;
		}
	}
	return -1;
}

char * closest(char *p) {
	//meghdar 1 yani y parantez baz shode
	int eop = 1;
	//yeki yeki dakhel reshte jolo miravad
	while (*(++p))
		//agar b parantez baz resid yeki b tedade parantezaye baz miafzayad
		if (*p == '(')
			eop++;
		//agar b parantez baste resid
		else	if (*p == ')')
			//agar tedade parantez haye baz - 1 barabar sefr shod
			if (--eop == 0)
				//address khune nazdik tarin parantez bar migardad
				return ++p;
	return NULL;
}

FilStack::FilStack(string a, vector<expression*>& v) {
	Fill(a, v);
}

FilStack::~FilStack() {

}
