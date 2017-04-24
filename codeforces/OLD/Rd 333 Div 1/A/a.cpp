#include<bits/stdc++.h>
using namespace std;

const int maxn = 450, inf = 0x3f3f3f3f;

int n, m, g[maxn][maxn], f[maxn][maxn];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
#endif
	ios::sync_with_stdio(0);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			f[i][j] = inf, g[i][j] = i == j ? inf : 1;
		
	
	for (int u, v, i = 1; i <= m; ++i)
		cin >> u >> v, f[v][u] = f[u][v] = 1, g[v][u] = g[u][v] = inf;
	
	for (int k = 1; k <= n; ++k) 
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j){
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}

	cout << (max(f[1][n], g[1][n]) == inf ? -1 : max(f[1][n], g[1][n]));
}
