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

char str[maxn], grd;
int cnt;
ld gpa;

int idx(char g) {
	switch(g) {
	case 'A': return 4;
	case 'B': return 3;
	case 'C': return 2;
	case 'D': return 1;
	case 'F': return 0;
	default: return -1;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (gets(str)) {
		cnt = gpa = 0;
		for (int i = 0; str[i]; ++i)
			if (isalpha(str[i])) {
				if (idx(str[i]) == -1)
					{ puts("Unknown letter grade in input"); goto gt; }
				gpa += idx(str[i]);
				cnt++;
			}
		cout << fixed << setprecision(2) << gpa / cnt << endl;
	gt:;
	}
}
