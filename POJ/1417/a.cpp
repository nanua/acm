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

int f[610][610], cnt[610][2], pre[610][610], used[610], vis[610];
arrn to, la, nt, _self, __self;
int n, p1, p2, x, y, sz, edg;
char s[10];

int dfs(int id, int x) {
	vis[x-(p1+p2)*(x>p1+p2)] = id*2-(x>p1+p2);
	cnt[id][x>p1+p2]++;

	int ret = -1;
	for (int t, i = la[x]; i; i = nt[i])
		if (!vis[to[i]>p1+p2?to[i]-p1-p2:to[i]])
			if ((t = dfs(id, to[i])) != -1) ret = t;
	if (_self[x]) return x <= p1+p2;
	return ret;
}
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	
	while (~scanf("%d %d %d",&n,&p1,&p2), n) {
		for (int i = 1; i <= (p1+p2)<<1; ++i) _self[i] = la[i] = vis[i] = 0;
		for (int i = 1; i <= sz; ++i) cnt[i][0] = cnt[i][1] = 0;
		for (int i = 1; i <= sz<<1; ++i) used[i] = 0;
		edg = sz = 0;
		
		for (int i = 1; i <= n; ++i) {
			gint(x), gint(y), scanf("%s", s);
			if (x == y) _self[x] = 1;
			else {
				add_edge(x, y+(p1+p2)*(s[0]=='n')), add_edge(x+(p1+p2), y+(p1+p2)*((s[0]=='n')^1));
				add_edge(y+(p1+p2)*(s[0]=='n'), x), add_edge(y+(p1+p2)*((s[0]=='n')^1), x+(p1+p2));
			}
		}

		for (int i = 1, t; i <= p1+p2; ++i)
			if (!vis[i])
				if ((t = dfs(++sz, i)) != -1) cnt[sz][t] = 0, __self[sz] = 1;
		
		for (int i = 1; i <= sz; ++i)
			for (int j = 0; j <= p1+p2; ++j) f[i][j] = pre[i][j] = 0;

		f[0][0] = 1;

		for (int i = 1; i <= sz; ++i)
			for (int j = 0; j <= 1; ++j)
				for (int k = cnt[i][j]; k <= p1+p2; ++k)
					if (!__self[i]){
						int x = f[i-1][k], y = f[i-1][k-cnt[i][j]], z = f[i][k];
						if (z == 0 && x + y == 1) f[i][k] = 1, pre[i][k] = j;
						else f[i][k] = min(2, x+y+z);					
					}
					else if (cnt[i][j]) {
						int x = f[i-1][k-cnt[i][j]];
						if (x == 1) f[i][k] = 1, pre[i][k] = j;
						else f[i][k] = x;
					}

		if (f[sz][p1] != 1) puts("no");
		else {
			for (int i = sz, k = p1, j = pre[sz][p1]; i >= 1; )
				used[i*2-j] = 1, k -= cnt[i][j], j = pre[--i][k];

			for (int i = 1; i <= p1+p2; ++i)
				if (used[vis[i]]) printf("%d\n", i);

			puts("end");
		}			
	}
}

