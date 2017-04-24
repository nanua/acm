#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 2e6+50, maxm = 1e5+50;
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

int n, edg;
int to[maxn];
int nt[maxn];
int la[maxn];
int d[maxn];
int q[maxn];

void add_edge(int x, int y)
{
	to[++edg]= y, nt[edg] = la[x], la[x] = edg;
}
void bfs()
{
	int hd = 0, tl = 0;
	memset(d, 0x3f, sizeof(d));
	d[q[++tl] = 1] = 0;
	while (hd < tl)
	{
		int x = q[++hd];
		for (int i = la[x]; i; i = nt[i])
			if (d[to[i]] == inf)
				d[q[++tl] = to[i]] = d[x] + 1;
	}

	for (int i = 1; i <= n; ++i) printf("%d ", d[i]);
}
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	gint(n);
	for (int i = 1, t; i <= n; ++i)
		gint(t), add_edge(i, t);
	for (int i = 1; i < n; ++i)
		add_edge(i, i+1), add_edge(i+1, i);
	bfs();
}
