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

int T;
string str[5];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for (cin >> T; T; T--) {
		for (int i = 0; i <= 3; ++i) cin >> str[i];
		
		for (int i = 0; i <= 2; ++i)
			for (int j = 0; j <= 2; ++j) {
				int k = str[i][j] + str[i][j+1] + str[i+1][j] + str[i+1][j+1];
				if (k == '#'*3 + '.' || k == '.'*3+'#' || k == '.'*4 || k == '#'*4)
					{ puts("YES"); goto gt; }
			}
		puts("NO");
	gt:;
	}
}
