#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

ull n, x = 2, p;
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin >> n;
	for (ull i = 1; i <= n; ++i) {
		p = i*(i+1)*(i+1) - x;
		x = max(1ULL, i);
		cout << p << endl;
	}
}
 
