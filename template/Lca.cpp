void init_lca(){
	for(int i = 1; i <= n; ++i) g[i][0] = f[i];
	for(int j = 1; j <= 20; ++j)
		for(int i = 1; i <= n; ++i) g[i][j] = g[g[i][j-1]][j-1];							 
}
int lca(int x, int y){
	if(d[x] < d[y]) swap(x, y);
	for(int i = 20, j = d[x]-d[y]; i >= 0; --i)
		if(j & (1 << i)) x = g[x][i];
	if(x == y) return x;
	for(int i = 20; i >= 0; --i)
		if(g[x][i] != g[y][i])
			x = g[x][i], y = g[y][i];
	return g[x][0];
}
