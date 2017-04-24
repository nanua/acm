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

int T, n, a[maxn];
multiset<int> mset;
ll ans;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for (scanf("%d",&T); T; ans = 0, T--) {
		scanf("%d",&n);
		for (int i = 1; i <= n; ++i) scanf("%d",&a[i]);
		mset.clear();
		for (int i = 2; i <= n; ++i) mset.insert(abs(a[i-1] - a[i]));

		for (int i = 1; i <= n; ++i) {
			if (i+1 <= n) mset.erase(mset.find(abs(a[i] - a[i+1])));
			if (i-2 >= 1) mset.insert(abs(a[i-2] - a[i-1]));
			if (i-2 >= 1) mset.erase(mset.find(abs(a[i-2] - a[i])));
			ans += *mset.rbegin();			
			if (i+2 <= n) mset.insert(abs(a[i] - a[i+2]));
		}

		cout << ans << endl;
	}
}
