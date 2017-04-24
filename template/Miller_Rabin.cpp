bool Test(int x, int b, int n){
	if(x == 2 || x == b) return 1;
	if(x <= 1 || x % 2 == 0) return 0;
	while(n % 2) n >>= 1;
	int t = Pow(b, n, x);
	while(n != x-1 && t != x-1 && t != 1) t = Mul(t, t, x), n <<= 1;
	return n % 2 || t == x-1;
}
bool Miller_Rabin(int x){
	int Base[] = {2, 3, 5, 7, 29, 61};
	for(int i = 0; i < 6; ++i) if(!Test(x, Base[i], x-1)) return 0;
	return 1;
}
