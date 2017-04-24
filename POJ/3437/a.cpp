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
char str[maxn];
int n, edg, pred, aftd, l, sz = 1, ks;
arrn stk, la, to, nt, deg;

void dfs(int x, int d1, int d2) {
	pred = max(pred, d1);
	aftd = max(aftd, d2);
	for (int i = la[x], j = deg[x]; i; i = nt[i], --j)
		dfs(to[i], d1+1, d2+j);
}
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	
	while (scanf("%s",str), str[0] != '#') {
		for (int i = 1; i <= n; ++i) la[i] = 0, deg[i] = 0;
		pred = aftd = edg = 0, l = strlen(str);

		stk[sz] = n = 1;
		for (int i = 0; i < l; ++i)
			if (str[i] == 'd') {
				stk[++sz] = ++n;
				add_edge(stk[sz-1], stk[sz]), deg[stk[sz-1]]++;
			}
			else
				sz--;

		dfs(1, 0, 0);

		printf("Tree %d: %d => %d\n", ++ks, pred, aftd);
	}
}
 
