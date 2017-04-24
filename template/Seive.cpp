void get(int mx){
	miu[1] = 1;
	for(int i = 2; i <= mx; ++i){
		if(!vis[i])
			p[++sz] = i, phi[i] = i-1, miu[i] = -1;
		for(int j = 1, k = p[j]*i; j <= sz && k <= mx; ++j, k = p[j]*i){
			vis[k] = 1;
			phi[k] = phi[i] * (i % p[j] ? p[j] - 1 : p[j]);
			miu[k] = miu[i] * (i % p[j] ? -1 : 0);
		}
	}
}
