#include <map>
#include <set>
#include <queue>
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

int f[10010], n, m;
int F(int x) {
	if (x <= 3) return f[x] = x;
	if (f[x]) return f[x];
	return f[x] = (F(x-1) + F(x-3)) % m;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (cin >> n >> m, m) {
		f[1] = 1 % m, f[2] = 2 % m, f[3] = 3 % m;
		for (int i = 4; i <= n; ++i) f[i] = (f[i-1] + f[i-3]) % m;
		cout << (n <= 0 ? (n % m + m) % m : f[n]) << endl;
	}
}
 
