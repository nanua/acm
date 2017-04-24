#include <cctype>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

string str;
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (cin >> str) {
		bool flag = 1;
		for (int i = 1; i < str.size(); ++i)
		if (flag)
		     for (int i = 0; i < str.size(); ++i)
			    if (isupper(str[i])) str[i] = tolower(str[i]);
			    else str[i] = toupper(str[i]);
		
		cout << str << endl;
	}
}
