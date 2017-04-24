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
const ld PI = acos(-1.0);

int T, n, f;
ld s[maxn], Min, Max, Mid;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	for (cin >> T; T; T--) {
		cin >> n >> f;
		for (int i = 1, r; i <= n; ++i) cin >> r, s[i] = PI*r*r;
		Min = 0, Max = 1e30;
		while (Max - Min > 1e-10) {
			Mid = (Min + Max) / 2;
			ll cnt = 0;
			for (int i = 1; i <= n; ++i) cnt += ll(s[i] / Mid);
			cnt > f ? (Min = Mid) : (Max = Mid);
		}
		cout << fixed << setprecision(4) << Mid << endl;
	}
}
 
