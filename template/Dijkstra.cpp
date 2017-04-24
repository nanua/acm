void Dijkstra(int S){
	for(int i = 1; i <= n; ++i) d[i] = inf, vis[i] = 0;
	d[S] = 0;
	q[++sz] = S, push_heap(q+1, q+sz+1);
	for(int i = 1; i <= n; ++i){
		for(; sz && vis[q[1]]; sz--) pop_heap(q+1, q+sz+1);
		if(sz){
			vis[q[1]] = 1;
			for(int x = q[1], j = last[x]; j; j = e[j].last)
				if(d[e[j].t] > d[x] + e[j].w){
					d[e[j].t] = d[x] + e[j].w;
					q[++sz] = e[j].t, push_heap(q+1, q+sz+1);
				}
		}
		else break;
	}
}
