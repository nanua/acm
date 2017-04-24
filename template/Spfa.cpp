void Spfa(int S){
	for(int i = 1; i <= n; ++i) d[i] = inf, vis[i] = 0;	
	int h = 0, t = 0;
	d[S] = 0, q[++t] = S;
	while(h < t){
		int x = q[++h]; vis[x] = 0;
		for(int i = last[x]; i; i = e[i].last)
			if(d[e[i].t] > d[x] + e[i].w){
				d[e[i].t] = d[x] + e[i].w;
				if(!vis[e[i].t])
					vis[q[++t] = e[i].t] = 1;
			}
	}	
}
