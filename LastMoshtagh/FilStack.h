#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
typedef long long ll;
typedef long double ld;
#define read freopen("a.in","r",stdin)
#define For(I,N) for(ll I=0;I<N;++I)
#define MAXN 100000+99
#define inf 1ll<<62
using namespace std;
#pragma once
//har khune vector b surate structure hast
struct expression {
	//asl = string daryafty , output = ebarate moshtagh gerefte shode
	string asl, output;
	//ebarat daraye operator ast ya kheir
	char oper;
	//func = aya ebarat tabe hast ya na , si = alamte ebarat , operi = mahale operator (dar surate vojud)
	ll func, si, operi;
	//mosh = aya moshtaghe ebarat gerefte shode ya kheir , funcmosh = aya moshtaghe func gerefte shode ya kheir , split func = function split shode ya kheir
	bool mosh, funcmosh, splitfunc;
	expression(string a) {
		asl = a;
		oper = 0;
		operi = 0;
		func = -1;
		si = 1;
		mosh = false;
		funcmosh = false;
		splitfunc = false;
	}
};

//kare in tabe tashkile saf az hame ebarat hast
ll Fill(string, vector<expression*>& v);
ll GetOpi(const char * x, char * op[]);
ll recfunc(const char * eop);
char * closest(char *p);

class FilStack {
public:
	FilStack(string, vector<expression*>& v);
	~FilStack();
};

