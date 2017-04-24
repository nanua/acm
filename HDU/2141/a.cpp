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
const lint maxn = 1010, maxm = 1e5+50, inf = (lint)0x3f3f3f3f, mod = (lint)1e9 + 7, sigma = 129;
const ll INF = (ll)1e17;

typedef lint arrn[maxn];
typedef lint arrm[maxm];


template<class Q> void gint(Q &ret, char ch = getchar()) {
	while (!isdigit(ch)) ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
}

set<ll> st;

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	static int l, n, m, s, ks;
	static arrn a, b, c, x;
	
	while (~scanf("%d %d %d",&l,&n,&m)) {
		for (int i = 1; i <= l; ++i) scanf("%d", a+i);
		for (int i = 1; i <= n; ++i) scanf("%d", b+i);
		for (int i = 1; i <= m; ++i) scanf("%d", c+i);

		st.clear();
		for (int i = 1; i <= l; ++i)
			for (int j = 1; j <= n; ++j) st.insert(ll(a[i]) + ll(b[j]));

		scanf("%d", &s);
		printf("Case %d:\n", ++ks);
		
		for (int i = 1; i <= s; ++i) {
			scanf("%d", x+i);
			for (int j = 1; j <= m; ++j)
				if (st.find(ll(x[i]) - ll(c[j])) != st.end()) goto succ;
			
			puts("NO");
			continue;
		succ:
			puts("YES");
		}
	}
}

 
