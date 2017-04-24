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

#define pb push_back
#define pk pop_back
#define fi first
#define se second

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

const int maxn = 2e5+50, maxm = 1e5+50, inf = (int)0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = (ll)1e17;

typedef int arrn[maxn];
typedef int arrm[maxm];


template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar()) {
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

int t, s, n, a, b, c, d, edg, Ans;
arrn st, ed, vis, dis, to, wgt, la, nxt;

void add_edge(int x, int y, int w) {
	to[++edg] = y, wgt[edg] = w, nxt[edg] = la[x], la[x] = edg;
	to[++edg] = x, wgt[edg] = w, nxt[edg] = la[y], la[y] = edg;
}

void dijk(int bg) {
	for (int i = 1; i <= n; ++i) 
		dis[i] = inf, vis[i] = 0;
	dis[bg] = 0;

	for (int t = 1; t <= n; ++t) {
		int min_id = 0, min_val = inf;

		for (int i = 1; i <= n; ++i) 
			if (!vis[i] && dis[i] < min_val)
				min_id = i, min_val = dis[i];

		vis[min_id] = 1;
		for (int i = la[min_id]; i; i = nxt[i]) 
			dis[to[i]] = min(dis[to[i]], dis[min_id] + wgt[i]);
	}
}

int main() {
#ifdef LOCAL
    freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

	n = 1000;
	while (~scanf("%d%d%d", &t, &s, &d)) {
		for (int i = 1; i <= n; ++i) 
			la[i] = 0;
		Ans = inf, edg = 0;

		for (int i = 1; i <= t; ++i) {
			cin >> a >> b >> c;
			add_edge(a, b, c);
		}

		for (int i = 1; i <= s; ++i) 
			gint(st[i]);

		for (int i = 1; i <= d; ++i)
			gint(ed[i]);

		for (int i = 1; i <= s; ++i) {
			dijk(st[i]);
			for (int j = 1; j <= d; ++j)
				Ans = min(Ans, dis[ed[j]]);
		}

		cout << Ans << endl;
	}
}
