#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 2e5+50, maxm = 1e5+50;
const int inf = 0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;

typedef int arrn[maxn];
typedef ll arrm[maxn];


template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar()) {
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

int n, T, edg;
arrn to, nt, la, sg;

void add_edge(int x, int y) {
	to[++edg] = y, nt[edg] = la[x], la[x] = edg;
	to[++edg] = x, nt[edg] = la[y], la[y] = edg;
}
void dfs(int x, int f) {
	for (int i = la[x]; i; i = nt[i])
		if (to[i] != f)
			dfs(to[i], x), sg[x] ^= (sg[to[i]] +  1);
}
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for (gint(T); T--; ) {
		edg = 1;
		for (int i = 1; i <= n; ++i) la[i] = sg[i] = 0;

		gint(n);
		for (int i = 1, u, v; i < n; ++i)
			gint(u), gint(v), add_edge(u, v);

		dfs(1, 0);

		puts(sg[1] == 0 ? "Bob" : "Alice");
	}
}

