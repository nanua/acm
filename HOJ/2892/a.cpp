#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cctype>
#include <vector>
#include <iomanip>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

	string str;
	while (getline(cin, str)) {
		int mark = 0;
		for (int i = 0; i < str.size(); ++i)
			mark += (isupper(str[i])!=0) * (str[i] - 'A' + 1);
		if (mark > 100) cout << "INVALID" << endl;
		else cout << mark << endl;
	}
}
