bool bfs(int S, int T){
	for(int i = 1; i <= n; ++i) vis[i] = d[i] = 0;
	int h = 0, t = 0;
	q[++t] = S;
	while(h < t){
		int x = q[++h];
		for(int i = last[x]; i; i = e[i].last)
			if(e[i].c && !vis[e[i].t]){
				d[e[i].t] = d[x] + 1;
				vis[q[++t] = e[i].t] = 1;
			}
	}
	return d[T] != inf;
}
int dfs(int x, int a){
	if(x == T || a == 0) return a;
	int flow = 0, f;
	for(int i = last[x]; i && a; i = e[i].last)
		if(d[e[i].t] == d[x]+1 && (f = dfs(e[i].t, min(a, e[i].c))) > 0)
			e[i].c -= f, e[i^1] += f, a -= f, flow += f;
	return flow;
}
int dinic(int S, int T){
	int flow = 0;
	while(bfs(S, T))
		flow += dfs(S, inf);
	return flow;
}
