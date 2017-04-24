//Scc
void Tarjan(int x){
	dfn[x] = low[x] = ++idx;
	vis[stk[++top] = x] = 1;
	for(int i = last[x]; i; i = e[i].last)
		if(!vis[e[i].t]){
			Tarjan(e[i].t);
			low[x] = min(low[x], low[e[i].t]);			
		}
		else if(vis[e[i].t] == 1)
			low[x] = min(low[x], dfn[e[i].t]);
	if(dfn[x] == low[x]){
		scc++;
		for(; stk[top+1] != x; top--) vis[stk[top]] = 2;
	}
}
//Bscc
void Tarjan(int x, int fa){
	dfn[x] = low[x] = ++idx;
	vis[stk[++top] = x] = 1;
	for(int i = last[x]; i; i = e[i].last)
		if(i != fa){
			if(!vis[e[i].t]){
				Tarjan(e[i].t, i);
				low[x] = min(low[x], low[e[i].t]);			
			}
			else if(vis[e[i].t] == 1)
				low[x] = min(low[x], dfn[e[i].t]);
		}
	if(dfn[x] == low[x]){
		scc++;
		for(; stk[top+1] != x; top--) vis[stk[top]] = 2;
	}
}
//Bridge
void Tarjan(int x, int fa){
	dfn[x] = low[x] = ++idx;
	vis[stk[++top] = x] = 1;
	for(int i = last[x]; i; i = e[i].last)
		if(i != fa){
			if(!vis[e[i].t]){
				Tarjan(e[i].t, i);
				low[x] = min(low[x], low[e[i].t]);
			}
			else if(vis[e[i].t] == 1)
				low[x] = min(low[x], dfn[e[i].t]);
			if(low[e[i].t] > dfn[x]) bridge[i] = 1;
		}
	if(dfn[x] == low[x]){
		scc++;
		for(; stk[top+1] != x; top--) vis[stk[top]] = 2;
	}
}

//Cut

void Tarjan(int x, int fa){
	dfn[x] = low[x] = ++idx;
	vis[stk[++top] = x] = 1;
	int ch = 0;
	for(int i = last[x]; i; i = e[i].last)
		if(e[i].t != fa){
			if(!vis[e[i].t]){
				Tarjan(e[i].t, x);
				low[x] = min(low[x], low[e[i].t]);
			}
			else if(vis[e[i].t] == 1)
				low[x] = min(low[x], low[e[i].t]);
			if(low[e[i].t] >= dfn[x]) cut[x] = 1;
		}
	if(dfn[x] == low[x]){
		scc++;
		for(; stk[top+1] != x; top--) vis[stk[top]] = 2;
	}			
}
