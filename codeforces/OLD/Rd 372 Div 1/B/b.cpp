#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
const ll maxn = 1e5 + 10, inf = 1LL<<40, mod = 1e9 + 7;

ll era[maxn], wgt[maxn], fin[maxn], beg[maxn];
int to[maxn], nxt[maxn], lst[maxn], tra[maxn];
pli q[maxn];
int edg=1, n, m, L, s, t;

void add_edge(int u, int v, int w) {
	era[++edg] = w, wgt[edg] = w, to[edg] = v, nxt[edg] = lst[u], lst[u] = edg;
	era[++edg] = w, wgt[edg] = w, to[edg] = u, nxt[edg] = lst[v], lst[v] = edg;
}

void dijk(int st, ll *dis) {
	int qsz = 0, x;
	for (int i = 1; i <= n; ++i) dis[i] = inf, tra[i] = 0;
	dis[st] = 0;
	q[++qsz] = pli(0, st);
	while (qsz) {
		while (qsz && q[1].fi != dis[x = q[1].se])
			pop_heap(q+1, q+qsz+1, greater<pli>()), qsz--;
		if (!qsz) break;
		pop_heap(q+1, q+qsz+1, greater<pli>()), qsz--;
		for (int i = lst[x]; i; i = nxt[i])
			if (dis[to[i]] > dis[x] + wgt[i]) {
				tra[to[i]] = i;
				dis[to[i]] = dis[x] + wgt[i];
				q[++qsz] = pli(dis[to[i]], to[i]);
				push_heap(q+1, q+qsz+1, greater<pli>());
			}
		
	}
}
void modify(ll val) {
	for (int i = 2; i <= edg; ++i)
		if (era[i] == 0) wgt[i] = val;
}
	
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin >> n >> m >> L >> s >> t;
	s++, t++;
	
	for (int i = 1, u, v, w; i <= m; ++i)
		cin >> u >> v >> w, add_edge(u+1, v+1, w);

	modify(inf);
	dijk(s, fin);
	modify(1);
	dijk(s, beg);
	
	if (beg[t] <= L && L <= fin[t])
		cout << "Yes\n";
	else
		cout << "No\n", exit(0);

	while (fin[t] != L) {		
		dijk(s, fin);
		for (int i = t; i != s; i = to[tra[i]^1])
			if (era[tra[i]] == 0)
				era[tra[i]] = era[tra[i]^1] = -1;
		for (int i = 2; i <= edg; i+=2) {
			if (era[i] == 0) wgt[i] = wgt[i+1] = inf;
			if (era[i] == -1) {
				wgt[i] = wgt[i+1] = L+wgt[i]-fin[t], era[i] = era[i+1] = 1;
				break;
			}
		}
	}

	for (int i = 2;i <= edg; i += 2)
		cout << to[i+1]-1 << " " << to[i]-1 << " " << wgt[i] << endl;
}
