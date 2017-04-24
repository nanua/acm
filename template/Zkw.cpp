bool Spfa(int S, int T){
	for(int i = 1; i <= n; ++i) d[i] = inf, vis[i] = 0;
	int h = 0, t = 0;
	d[q[++t] = S] = 0;
	while(h < t){
		int x = q[++h]; vis[x] = 0;
		for(int i = last[x]; i; i = e[i].last)
			if(e[i].c && d[e[i].t] > d[x] + e[i].w){
				d[e[i].t] = d[x] + e[i].w;
				if(!vis[e[i].t])
					vis[q[++t] = e[i].t] = 1;
			}
	}
	return d[T] != inf;
}
int Aug(int x, int a, int &cost){
	vis[x] = 1;	
	if(x == t || a == 0) return a;
	int flow = 0, f;
	for(int i = last[x]; i && a; i = e[i].last)
		if(e[i].c && d[e[i].t] == d[x] + e[i].w)
			if((f = Aug(e[i].t, min(a, e[i].c), cost)) > 0)
				e[i].c -= f, e[i^1] += f, flow += f, a -= f, cost += f * e[i].w;
	return flow;
}
int Zkw(int S, int T){
	int flow = 0, cost = 0;
	while(Spfa(S, T))
		for(vis[T] = 1; vis[T]; )
			memset(vis, 0, sizeof(vis)), flow += Aug(S, inf, cost);
	return cost;
}
