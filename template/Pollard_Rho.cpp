int Rho(int n){
	int x = rand() % n + 1, y = rand() % n + 1, g;
	for(int i = 1, j = 1; ; ++i){
		x = Add(Mul(x, x, n), rand() % n);
		if((g = __gcd(x-y+n, n)) != 1) return g;
		if(x == y) return n;
		if(i == j) y = x, j <<= 1;
	}
}
void Factor(int x){
	if(x == 1) return;
	if(Miller_Rabin(x)) return;
	int p = x;
	while(p >= x) p = Rho(x);
	Factor(p), Factor(x / p);
}
