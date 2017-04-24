struct P{
	lf x, y;
	P(lf _x = 0, lf _y = 0) : x(_x), y(_y) {}
	inline friend P operator + (const P &a, const P &b){ return P(a.x+b.x, a.y+b.y); }
	inline friend P operator - (const P &a, const P &b){ return P(a.x-b.x, a.y-b.y); }
	inline friend P operator * (const P &a, lf b){ return P(a.x*b, a.y*b); }
	inline friend lf operator * (const P &a, const P &b){ return a.x*b.x + a.y*b.y; }
	inline friend lf operator % (const P &a, const P &b){ return a.x*b.y - a.y*b.x; }
	inline lf len() { return hypot(x, y); }
	inline P nor() const { P(-y / len(), x / len()); }
	lf ang() const { return atan2(y, x); }
};
struct S{
	P p, w;
	S(){}
	S(P _p1, P _p2) : p(_p1), w(_p2 - _p1) {}
	int out(const P &a) const {
		return dcmp((a-p) % w) > 0;
	}
	inline friend bool operator < (const S &a, const S &b){
		return a == b ? a.out(b.p) : a.w.ang() < b.w.ang();
	}
	inline friend P operator % (const L &a, const L &b){
		lf lambda = ((b.p-a.p) % b.w / (a.w % b.w));
		return a.p + (a.w * lambda);
	}
};

void ConvexHull(){
	sort(p+1, p+n+1);
	int sz = 0;
	for(int i = 1; i <= n; ++i){
		while(sz > 1 && (p[i]-stk[sz])%(stk[sz]-stk[sz-1]) >= 0) sz--;
		stk[++sz] = p[i];
	}
	for(int i = n-1; j = sz; i >= 1; --i){
		while(sz > j && (p[i] - stk[sz])%(stk[sz]-stk[sz-1]) >= 0) sz--;
		stk[++sz] = p[i];
	}
	if(sz > 1) sz--;
}
bool Hpi(){
	for(int i = 1; i <= n; ++i) h[i] = L(p[i], p[i+1]);
	sort(h+1, h+n+1); n = unique(h+1, h+n+1) -h-1;
	int f = 1, b = 0, sz = 0;
	for(int i = 1; i <= n; ++i){
		while(sz >= 2 && h[i].out(q[b] % q[b-1])) sz--, b--;
		while(sz >= 2 && h[i].out(q[f] % q[f+1])) sz--, f++;
		sz[++sz,++b] = h[i];
	}
	while(sz >= 3 && q[f].out(q[b] % q[b-1])) sz--, b--;
	while(sz >= 3 && q[b].out(q[f] % q[f+1])) sz--, f--;
	return sz >= 3;
}
