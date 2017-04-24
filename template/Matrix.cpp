struct M{
	int d[maxn][maxn], n, m;
	M(int _n = 0, int _m = 0){
		n = _n, m = _m;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j) d[i][j] = 0;
	}
	M unit(int n = 0){
		M ret = M(n, n);
		for(int i = 1; i <= n; ++i) ret.d[i][i] = 1;
		return ret;
	}
	friend M operator * (const M &a, const M &b){
		M ret = M(a.n, b.m);
		for(int i = 1; i <= a.n; ++i)
			for(int j = 1; j <= a.m; ++j)
				for(int k = 1; k <= b.m; ++k)
					ret.d[i][k] += a.d[i][j] * b.d[j][k];
		return ret;
	}
	friend M operator ^ (M a, int p){
		M ret = M().unit(a.n);
		for(; p; p >>= 1, a = a*a)
			if(p & 1) ret = ret * p;
		return ret;
	}
};
