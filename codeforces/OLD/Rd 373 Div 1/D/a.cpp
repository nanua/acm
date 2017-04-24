#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int maxn = 1e5 + 10;
typedef long long ull;
typedef int arr[maxn<<2];
typedef ull prr[maxn<<2][2];
typedef pair<ull, ull> pii;
const ull base = 4000037, mod[2] = {(ull)1e9 + 7, 100001053};

int edg, vsz, n;
prr hsh, pmd = {{1,1}};
arr vedg, frm, to, nxt, last, deg, sz;
pii vec[maxn<<2];

inline void add_mod(ull &x, ull y, ull z, ull mod) {
	x += (y * z) % mod;
	if (x > mod) x -= mod;
}
void add_edge(int u, int v) {
	frm[++edg] = u, to[edg] = v, nxt[edg] = last[u], last[u] = edg;
	frm[++edg] = v, to[edg] = u, nxt[edg] = last[v], last[v] = edg;
	deg[u]++, deg[v]++;
}

void dfs(int x) {
	vedg[x] = 1;
	pii px[2][6] = {};
	int psz[2] = {};
	for (int i = last[to[x]]; i; i = nxt[i])
		if (to[i] != frm[x]) {
			if (!vedg[i]) dfs(i);
			for (int j = 0; j <= 1; ++j)
				px[j][++psz[j]] = pii(hsh[i][j], (ull)sz[i]);
			sz[x] += sz[i];
		}
	for (int j = 0; j <= 1; ++j)
		sort(px[j]+1, px[j]+psz[j]+1);
	
	for (int j = 0; j <= 1; ++j)
		for (int i = 1; i <= psz[j]; ++i)
			add_mod(hsh[x][j], px[j][i].fi, pmd[px[j][i].se+1][j], mod[j]);
	hsh[x][0]++, hsh[x][1]++;
	sz[x]++;	
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n+1; ++i)
		for (int j = 0; j <= 1; ++j)
			add_mod(pmd[i][j], pmd[i-1][j], base, mod[j]);
	
	for (int i = 1, u, v; i < n; ++i)
		cin >> u >> v, add_edge(u, v);

	for (int i = 1; i <= edg; ++i)
		if (!vedg[i])
			dfs(i);
	
	for (int x = 1; x <= n; ++x)
		if (deg[x] <= 3) {
			pii px[2][6];
			int psz[2] = {0,0};
			ull phsh[2] = {0,0};
			for (int i = last[x]; i; i = nxt[i])
				for (int j = 0; j <= 1; ++j)
					px[j][++psz[j]] = pii(hsh[i][j], sz[i]);
			for (int j = 0; j <= 1; ++j)
				sort(px[j]+1, px[j]+psz[j]+1);
			for (int j = 0; j <= 1; ++j)
				for (int i = 1; i <= psz[j]; ++i)
					add_mod(phsh[j], px[j][i].fi, pmd[px[j][i].se][j], mod[j]);
			vec[++vsz] = pii(phsh[0], phsh[1]);
		}
	
	sort(vec+1, vec+vsz+1);
	cout << (unique(vec+1, vec+vsz+1) - vec - 1);
}
