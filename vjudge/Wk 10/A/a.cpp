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

int t = 1, n, T;
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for(cin >> T; t <= T; ++t) {
		cin >> n;
		ll ans = 0;
		for (int i = 1; i <= n; ++i)
			ans += i * (i+1) * (i+2) / 2;
		cout << t << " " << n << " " << ans << endl;
	}
}
 
