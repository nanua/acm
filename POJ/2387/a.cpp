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

int T, n, a, b, c, edg;
arrn vis, d, to, wgt, la, nxt;

void add_edge(int x, int y, int w) {
	to[++edg] = y, wgt[edg] = w, nxt[edg] = la[x], la[x] = edg;
	to[++edg] = x, wgt[edg] = w, nxt[edg] = la[y], la[y] = edg;
}

void dijk() {
	for (int i = 1; i <= n; ++i) 
		d[i] = inf, vis[i] = 0;
	d[1] = 0;

	for (int t = 1; t <= n; ++t) {
		int min_id = 0, min_val = inf;

		for (int i = 1; i <= n; ++i) 
			if (!vis[i] && d[i] < min_val)
				min_id = i, min_val = d[i];

		vis[min_id] = 1;
		for (int i = la[min_id]; i; i = nxt[i]) 
			d[to[i]] = min(d[to[i]], d[min_id] + wgt[i]);
	}
}

int main() {
#ifdef LOCAL
    freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

	cin >> T >> n;
	for (int i = 1; i <= T; ++i) {
		cin >> a >> b >> c;
		add_edge(a, b, c);
	}

	dijk();

	cout << d[n];
}
