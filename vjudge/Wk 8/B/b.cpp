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

int T, n, a[maxn], premax[maxn], sucmax[maxn], ansmax[maxn];
ll ans;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
	for (scanf("%d",&T); T; ans = 0, T--) {
		scanf("%d",&n);
		for (int i = 1; i <= n; ++i) scanf("%d",&a[i]);
		for (int i = 0; i <= n+1; ++i) premax[i] = sucmax[i] = ansmax[i] = -inf;
		
		for (int i = 2; i < n; ++i) ansmax[i] = max(ansmax[i], abs(a[i-1]-a[i+1]));

		for (int i = 2; i <= n; ++i) premax[i] = max(premax[i-1], abs(a[i-1] - a[i]));
		for (int i = n-1; i >= 1; --i) sucmax[i] = max(sucmax[i+1], abs(a[i+1] - a[i]));

		for (int i = 3; i <= n-2; ++i) ansmax[i] = max(ansmax[i], max(premax[i-1], sucmax[i+1]));
		ansmax[1] = max(ansmax[1], sucmax[2]);
		ansmax[2] = max(ansmax[2], sucmax[3]);
		ansmax[n] = max(ansmax[n], premax[n-1]);
		ansmax[n-1] = max(ansmax[n-1], premax[n-2]);

		for (int i = 1; i <= n; ++i) ans += ansmax[i];
		cout << ans << endl;
	}
} 
