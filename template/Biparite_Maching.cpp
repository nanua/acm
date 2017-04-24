//Hungary
int find(int x){
	for(int i = last[x]; i; i = e[i].last)
		if(!vis[e[i].t]){
			vis[e[i].t] = 1;
			if(!mt[e[i].t] || find(mt[e[i].t]))
				return mt[e[i].t] = x, 1;
		}
	return 0;
}

//KM
int find(int x){
	vx[x] = 1;
	for(int y = 1; y <= n; ++y)
		if(!vy[y]){
			int d = lx[x] + ly[y] - w[x][y];
			if(!d){
				vy[y] = 1;
				if(!mt[y] || find(mt[y]))
					return mt[y] = x, 1;
			}
			else slk[y] = min(slk[y], d);
		}
	return 0;
}

void adjust(){
	int d = inf;
	for(int i = 1; i <= n; ++i) if(!vy[i]) d = min(d, slk[i]);
	for(int i = 1; i <= n; ++i) if(!vx[i]) lx[i] -= d;
	for(int i = 1; i <= n; ++i) vy[i] ? ly[i] += d : slk[i] -= d;
}
void KM(){
	memset(mt, 0, sizeof(mt)), memset(lx, -0x3f, sizeof(lx)), memset(ly, 0, sizeof(ly));
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j) lx[i] = max(lx[i], w[i][j]);
	for(int i = 1; i <= n; ++i){
		memset(slk, 0x3f, sizeof(slk));
		for(;;){
			for(int j = 1; j <= n; ++j) vx[i] = vy[i] = 0;
			if(find(i)) break;
			ajdust();
		}
	}
}
