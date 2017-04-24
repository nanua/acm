#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mid ((l+r)>>1)
#define Ls (x<<1)
#define Rs (x<<1|1)

typedef long long ll;
typedef double ld;
typedef pair <ll, int> pii;

const int maxn = 1e6+50, maxm = 5e6+50;
const int inf = 0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;

template<class Q> void gi(Q &ret, int sig = 1, char ch = getchar())
{
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}


int n, q, s, t, nsz;
int nd[maxn][2];
int edg;
int to[maxm];
ll wt[maxm];
int nt[maxm];
int la[maxn];

void add_edge(int x, int y, int w)
{
	to[++edg] = y, wt[edg] = w, nt[edg] = la[x], la[x] = edg;
}

void build(int x, int l, int r)
{
	nd[x][0] = ++nsz, nd[x][1] = ++nsz;
	if (l == r)
	{
		add_edge(l, nd[x][0], 0), add_edge(l, nd[x][1], 0);
		add_edge(nd[x][0], l, 0), add_edge(nd[x][1], l, 0);
		return;
	}

	build(Ls, l, mid), build(Rs, mid+1, r);
	add_edge(nd[x][0], nd[Ls][0], 0), add_edge(nd[x][0], nd[Rs][0], 0);
	add_edge(nd[Ls][1], nd[x][1], 0), add_edge(nd[Rs][1], nd[x][1], 0);
}

void link_edge(int x, int l, int r, int u, int L, int R, int w, int t)
{
	if (R < l || L > r) return;
	if (L <= l && r <= R)
	{
		if (t == 1) add_edge(u, nd[x][0], w);
		if (t == 2) add_edge(nd[x][1], u, w);
		return;
	}

	link_edge(Ls, l, mid, u, L, R, w, t);
	link_edge(Rs, mid+1, r, u, L, R, w, t);
}


ll d[maxn];
bool vis[maxn];

void dijk()
{
	static int sz;
	static pii qu[maxm];

	for (int i = 1; i <= nsz; ++i) d[i] = INF;
	d[s] = 0;
	qu[++sz] = pii(0, s);

	while (1)
	{
		while (sz && vis[qu[1].se])
			pop_heap(qu+1, qu+(sz--)+1, greater<pii>());
		
		if (!sz) break;
		int x = qu[1].se;
		vis[x] = 1;
		pop_heap(qu+1, qu+(sz--)+1, greater<pii>());

		for (int i = la[x]; i; i = nt[i])
			if (d[to[i]] > d[x] + wt[i])
			{
				d[to[i]] = d[x] + wt[i];
				qu[++sz] = pii(d[to[i]], to[i]);
				push_heap(qu+1, qu+sz+1, greater<pii>());
			}
	}
}

int main()
{
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	gi(n), gi(q), gi(s);

	nsz = n;
	build(1, 1, n);

	for (int i = 1; i <= q; ++i)
	{
		int t, u, v, l, r, w;
		gi(t);
		switch(t)
		{
			case 1:
				gi(u), gi(v), gi(w);
				link_edge(1, 1, n, u, v, v, w, 1); break;
			case 2:
				gi(u), gi(l), gi(r), gi(w);
				link_edge(1, 1, n, u, l, r, w, 1); break;
			case 3:
				gi(u), gi(l), gi(r), gi(w);
				link_edge(1, 1, n, u, l, r, w, 2); break;
		}
	}

	dijk();

	for (int i = 1; i <= n; ++i)
		cout << (d[i] == INF ? -1 : d[i]) << " ";
}
