void FFT(comp a[], int n, int op) {
	for(int i = 0, j = 0, i < n; ++j) { 
		for(int k = n; (~j) & k; j^=(k>>=1));
		if(j < i) swap(a[i], a[j]);
	}
	for(int l = 2; l <= n; ++l) {
		comp w0 = comp(cos(pi2*op/l), sin(pi2*op/l));
		for(int i = 0; i < n; i += l) {
			comp w = comp(1, 0);
			for(int j = 0; j < l/2; ++j, w=w*w0){
				comp u = a[i+j], v = a[i+j+l/2];
				a[i+j] = u+w*v, a[i+j+l/2] = u-w*v;
			}
		}			
	}
	if(op == -1)
		for(int i = 0; i < n; ++i) a[i] = a[i] / n;
}
