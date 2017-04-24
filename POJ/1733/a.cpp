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
#define sz(x) ((LL)x.size())

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

typedef map <lint, lint> mii;
typedef pair <lint, lint> pii;
typedef set <lint> sint;
typedef vector <lint> vint;

const ld eps = 1e-12, pi = acos(-1);
const lint maxn = 2e5+50, maxm = 1e5+50, inf = (lint)0x3f3f3f3f, mod = (lint)1e9 + 7, sigma = 129;
const ll INF = (ll)1e17;

typedef lint arrn[maxn];
typedef lint arrm[maxm];


template<class Q> void gint(Q &ret, char ch = getchar()) {
	while (!isdigit(ch)) ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
}

arrn l, r, f, t, dsc;
int n, m, tl, tr, dsz;
char s[1010];

inline int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

inline void _union(int x, int y) {
	f[find(x)] = f[find(y)];
}
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	
	while (~scanf("%d %d", &n, &m)) {
		dsz = 0;
		for (int i = 1; i <= m; ++i) {
			gint(tl), gint(tr), scanf("%s\n", s);
			dsc[++dsz] = l[i] = tl-1, dsc[++dsz] = r[i] = tr, t[i] = (s[0] == 'o');		
		}

		sort(dsc+1, dsc+dsz+1);
		dsz = unique(dsc+1, dsc+dsz+1) - dsc - 1;

		for (int i = 1; i <= m; ++i) {
			l[i] = (lower_bound(dsc+1, dsc+dsz+1, l[i]) - dsc) * 2;
			r[i] = (lower_bound(dsc+1, dsc+dsz+1, r[i]) - dsc) * 2;
		}

		for (int i = 2; i <= dsz*2+1; ++i) f[i] = i;

		for (int i = 1; i <= m; ++i) {
			_union(l[i], r[i]^t[i]);
			_union(l[i]^1, r[i]^1^t[i]);

			if (find(l[i]) == find(l[i]^1) || find(r[i]) == find(r[i]^1))
				{ printf("%d\n", i-1); goto fail; }
		}

		printf("%d\n",m);
	fail:;		
	}
}

