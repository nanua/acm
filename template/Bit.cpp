void ins(int p, int v){
	for(int i = p; i <= n; i += i&-i) bit[i] += v;
}
void qer(int p){
	int r = 0;
	for(int i = p; i; i -= i&-i) r += bit[i];
	return r;
}
