#include <bits/stdc++.h>
using namespace std;

typedef double dbl;

const int maxn = 1e5 + 10;
const dbl eps = 1e-8;

struct ptr {
	dbl x, y;
	ptr(dbl _x = 0, dbl _y = 0) { x = _x, y = _y; }
	friend ptr operator + (ptr a, ptr b) { return ptr(a.x + b.x, a.y + b.y); }
	friend ptr operator - (ptr a, ptr b) { return ptr(a.x - b.x, a.y - b.y); }
	friend dbl operator * (ptr a, ptr b) { return a.x*b.y - a.y*b.x; }
	friend bool operator < (ptr a, ptr b) { return a.x < b.x || (fabs(a.x - b.x) <= eps && a.y < b.y); }	
}tar, p[maxn], stk[maxn*3];

int n, ma, mb, sz, nsz;
dbl ans = 1e50;

void convex_hull() {
	sort(p+1, p+n+1);

	for (int i = 1; i <= n; ++i) {
		while (sz > 2 && (p[i]-stk[sz-1]) * (stk[sz]-stk[sz-1]) >= 0) sz--;
		stk[++sz] = p[i];
	}
	nsz = sz;
	for (int i = n-1; i >= 1; --i) {
		while (sz > nsz && (p[i]-stk[sz-1]) * (stk[sz]-stk[sz-1]) >= 0) sz--;
		stk[++sz] = p[i];
	}
}
ptr itsct(ptr dir, ptr pa, ptr pb) {
	if ((dir * pa) * (dir * pb) > eps) return ptr(eps, eps);
	dbl k = (pa * pb) / (dir*pa - dir*pb);
	return ptr(dir.x*k, dir.y*k);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	cin >> n >> tar.x >> tar.y;
	for (int i = 1, a, b; i <= n; ++i)
		cin >> a >> b, p[i] = ptr(a, b), ma = max(ma, a), mb = max(mb, b);
	p[++n] = ptr(ma, 0), p[++n] = ptr(0, mb);
	
	convex_hull();

	for (int i = 1; i < sz; ++i) {
		ptr itsc = itsct(tar, stk[i], stk[i+1]);
		ans = min(ans, hypot(tar.x, tar.y) / hypot(itsc.x, itsc.y));
	}

	cout << fixed << setprecision(15) << ans;
}
