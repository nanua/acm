void Ex_Gcd(int &x, int &y, int &d, int a, int b){
	if(!y) x = 1, y = 0, d = a;
	else Ex_Gcd(y, x, d, b, a%b), y -= x * (a/b);
}
int Crt(int a[] ,int m[], int n){
	int M = 1;
	for(int i = 1; i <= n; ++i) M *= m[i];
	int r = 0;
	for(int i = 1, x,y,d; i <= n; ++i){		
		Ex_Gcd(x, y, d, M / m[i], m[i]);
		r = (r + M / m[i] * x * a[i]) % M;
	}
	return r;
}
