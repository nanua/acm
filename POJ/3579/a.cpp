#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cctype>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define clr(x, y) memset(x, y, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(y))
#define all(x) x.begin(), x.end()
#define sqr(x) ((x) * (x))
#define sz(x) ((ll)x.size())

#define mk make_pair
#define pb push_back
#define pk pop_back
#define fi first
#define se second

#define add_edge(x, y) (to[++edg] = y, nt[edg] = la[x], la[x] = edg)
#define add_wedge(x, y, w) (to[++edg] = y, wgt[edg] = w, nt[edg] = la[x], la[x] = edg)
#define lowbit(x) ((x) & (-x))

typedef int lint;
typedef long long ll;
typedef long double ld;
typedef pair <lint, lint> pii;

const ld eps = 1e-12, pi = acos(-1);
const lint maxn = 2e5+50, maxm = 1e5+50, inf = (lint)0x3f3f3f3f, mod = (lint)1e9 + 7, sigma = 129;
const ll INF = (ll)1e17;

typedef lint arrn[maxn];
typedef lint arrm[maxm];


template<class Q> void gint(Q &ret, char ch = getchar()) {
	while (!isdigit(ch)) ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
}

int n;
arrn a;
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	
	while (~scanf("%d",&n)) {
		for (int i = 1; i <= n; ++i) gint(a[i]);

		sort(a+1, a+n+1);
		
		int L = 0, R = inf << 1, mid, res;
		ll cmp = ((ll)n*(n-1)/2+1)/2;
		
		while (L <= R) {
			mid = (L + R) >> 1;
			ll cnt = 0;
			for (int i = 1, j = 1; i <= n; ++i) {
				while (j <= n && (j < i || a[j] - a[i] < mid)) ++j;
				cnt += j-i-1;
			}
			if (cnt <= cmp - 1) L = (res = mid) + 1;
			if (cnt > cmp - 1) R = mid - 1;
		}

		cout << res << endl;
	}
}
 
