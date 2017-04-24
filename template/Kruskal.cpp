int find(int x){
	return x == ufs[x] ? x : ufs[x] = find(ufs[x]);
}
void Kruskal(){
	for(int i = 1; i <= n; ++i) ufs[i] = i;
	for(int i = 1, u, v; i <= m; ++i)
		if((u = find(e[i].a) != (v = find(e[i].b))))
			ufs[u] = ufs[v];
}
