void init_rmq(){
	lg[0] = -1;
	for(int i = 1; i <= n; ++i) g[i][0] = a[i], lg[i] = lg[i/2] + 1;
	for(int j = 1; j <= 20; ++j)
		for(int i = 1; i+(1<<j) < n; ++i)
			g[i][j] = min(g[i][j-1], g[i+(1<<(j-1))][j-1]);	
}
int rmq(int l, int r){
	int k = lg[r-l+1];
	return min(g[l][k], g[r-(1<<k)+1][r]);
}
