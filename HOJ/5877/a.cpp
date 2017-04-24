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
const lint maxn = 2e5+50, maxm = 4e6+50, inf = (lint)0x3f3f3f3f, mod = (lint)1e9 + 7, sigma = 129;
const ll INF = (ll)1e18+10;

typedef lint arrn[maxn];
typedef lint arrm[maxm];


template<class Q> void gint(Q &ret, char ch = getchar()) {
	while (!isdigit(ch)) ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
}

int T, n, tnode, dsz, edg;
ll dsc[maxn], k;
arrn a, la, to, nt, fa, head, deg;
arrm lch, rch, cnt;

void init() {
	edg = tnode = 0;
	for (int i = 1; i <= n; ++i) la[i] = 0;
	dsc[n+1] = INF;
	sort(dsc+1, dsc+n+2);
	dsz = unique(dsc+1, dsc+n+2) - dsc - 1;
}

inline int get_pos(ll x) {
	return lower_bound(dsc+1, dsc+dsz+1, x) - dsc;
}

int insert(int hd, int l, int r, int p) {
	int ret = ++tnode;
	lch[tnode] = lch[hd], rch[tnode] = rch[hd], cnt[tnode] = cnt[hd] + 1;
	
	int mid = (l + r) >> 1;
	if (l != r)
		if (p <= mid) lch[ret] = insert(lch[hd], l, mid, p);
		else rch[ret] = insert(rch[hd], mid+1, r, p);
	
	return ret;
}

int query(int x, int l, int r, int p) {
	if (p < l || p > r) return 0;
	if (r <= p) return cnt[x];
	
	int mid = (l + r) >> 1;
	
	if (p <= mid) return query(lch[x], l, mid, p);
	else return cnt[lch[x]] + query(rch[x], mid+1, r, p);
}

void dfs(int x, int f) {
	fa[x] = f;
	head[x] = insert(head[f], 1, dsz, get_pos(a[x]));
	
	for (int i = la[x]; i; i = nt[i])
		if (to[i] != f) dfs(to[i], x);
}

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	
	for (scanf("%d\n", &T); T; T--) {
		gint(n), gint(k);	   
		for (int i = 1; i <= n; ++i) gint(a[i]), dsc[i] = a[i], deg[i] = 0;
		
		init();
		
		for (int i = 1, u, v; i < n; ++i) {
			gint(u), gint(v);
			add_edge(u, v), add_edge(v, u), deg[v]++;;
		}

		for (int i = 1; i <= n; ++i)
			if (deg[i] == 0) dfs(i, 0);

		ll ans = 0;
		for (int i = 1; i <= n; ++i) {
			ll val = (a[i] == 0 ? INF : k / a[i]);
			ans += query(head[fa[i]], 1, dsz, get_pos(val + 1)-1);
		}

		cout << ans << endl;
	}
}
 
