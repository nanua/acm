int Add(int x, int y, int p){
	return ((x + y) % p + p) % p;
}
int Mul(int x, int y, int p){
	return Add(x*y, -(int)((double)x*y/p) * p, p);
}
int Pow(int x, int p, int e){
	int r = 1;
	for(; e; e >>= 1, x = x * x % p) if(e & 1) r = r * x % p;
	return r;
}
