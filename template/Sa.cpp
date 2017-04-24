#define rep(i,a,b) for(int i = a; i <= b; ++i)
#define rev(i,a,b) for(int i = a; i >= b; --i)

int cmp(int y[], int a, int b, int c){
	return y[a] == y[b] && y[a+c] == y[b+c];
}
void build(char *s, int n, int m){
	int *x = t1, *y = t2;
	rep(i, 0, m) c[i] = 0;
	rep(i, 1, n) c[x[i] = s[i]]++;
	rep(i, 1, m) c[i] += c[i-1];
	rev(i, n, 1) sa[c[x[i]]--] = i;
	for(int j = 1, p = 0; p < n; j <<= 1, m = p, p = 0){
		rep(i, n-j+1, n) y[++p] = i;
		rep(i, 1, n) if(sa[i] > j) y[++p] = sa[i] - j;
		rep(i, 0, m) c[i] = 0;
		rep(i, 1, n) c[x[y[i]]]++;
		rep(i, 1, m) c[i] += c[i-1];
		rev(i, n, 1) sa[c[x[y[i]]]--] = x[i];
		for(swap(x, y), x[sa[1]] = 1, p = 1, i = 2; i <= n; ++i)
			x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p : ++p;
	}
}
void calc_height(char *s){
	rep(i, 1, n) rank[sa[i]] = i;
	for(int i = 1, k = 0, j; i <= n; height[++i] = k)
		for(k ? 0 : --k, j = sa[rank[i]-1]; s[i+k] == s[j+k]; ++k);
}
