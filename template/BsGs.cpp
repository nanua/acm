void Bs_Gs(int a, int b, int p){
	map<int,int>M;
	int t = b;
	for(int i = 0, j = sqrt(p)+1; i <= j; ++i, t = t * a % p)
		M[t] = min(M[t], i);
	int q = Pow(a, sqrt(p)+1, p);
	for(int i = 0, j = sqrt(p)+1; i <= j; ++i, a = a * t % p)
		if(M[a]) return i*j - M[a];
	return -1;
}
