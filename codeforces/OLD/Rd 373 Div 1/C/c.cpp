#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int n, m, a[maxn];

#define Add(x, y) ((x) + (y) > mod ? (x)+(y)-mod:(x)+(y))
#define Sum(x, y, z) ({(x) = (y) + (z); if (x > mod) x %= mod;})
#define Mul(x, y) (x*y)
struct Matrix
{
	ll a[2][2];
	Matrix(int a00 = 0, int a01 = 0, int a10 = 0, int a11 = 0)
	{
		a[0][0] = a00, a[0][1] = a01, a[1][0] = a10, a[1][1] = a11;
	}
	inline friend Matrix operator *(const Matrix &a, const Matrix &b)
	{
		Matrix ret;
		Sum(ret.a[0][0], Mul(a.a[0][0], b.a[0][0]),Mul(a.a[0][1], b.a[1][0]));
		Sum(ret.a[0][1], Mul(a.a[0][0], b.a[0][1]),Mul(a.a[0][1], b.a[1][1]));
		Sum(ret.a[1][0], Mul(a.a[1][0], b.a[0][0]),Mul(a.a[1][1], b.a[1][0]));
		Sum(ret.a[1][1], Mul(a.a[1][0], b.a[0][1]),Mul(a.a[1][1], b.a[1][1]));
		return ret;
	}
} Mat, Trs = Matrix(0, 1, 1, 1), trs[70], Id = Matrix(1,0,0,1);


inline Matrix operator ^(const Matrix &a, ll E)
{
	Matrix ret = Matrix(1,0,0,1);
	for (int i = 0; E; E >>= 1, ++i)
		if (E & 1) ret = ret * trs[i];
	return ret;
}

namespace Segment_Tree
{
	Matrix Nd[maxn<<3], Lazy[maxn<<3];

	inline void Inc(Matrix &Mt, const Matrix &Lz)
	{
		Mt = Mt * Lz;
	}
	void push_down(int x)
	{
		if (memcmp(Lazy[x].a, Id.a, sizeof(Id.a)) == 0) return;
		Inc(Nd[x<<1], Lazy[x]), Inc(Nd[x<<1|1], Lazy[x]);
		Inc(Lazy[x<<1], Lazy[x]), Inc(Lazy[x<<1|1], Lazy[x]);
		Lazy[x] = Id;
	}
	void push_up(int x)
	{
		Sum(Nd[x].a[0][0], Nd[x<<1].a[0][0], Nd[x<<1|1].a[0][0]);
		Sum(Nd[x].a[0][1], Nd[x<<1].a[0][1], Nd[x<<1|1].a[0][1]);
	}
	void Build(int x, int l, int r)
	{
		Lazy[x] = Id;
		if (l == r)
			return void(Nd[x] = Matrix(0,1,0,0) * (Trs^(a[l]-1)));
		int mid = (l + r) >> 1;
		Build(x<<1, l, mid);
		Build(x<<1|1, mid+1, r);
		push_up(x);
	}
	void Modify(int x, int l, int r, int nl, int nr, int val)
	{
		if (nl > nr) return;
		push_down(x);
		if (l == nl && r == nr) {
			Inc(Lazy[x], Trs^val);
			Inc(Nd[x], Trs^val);
			return;
		}
		int mid = (l + r) >> 1, Lx = min(nr, mid), Rx = max(nl, mid+1);
		Modify(x<<1, l, mid, nl, Lx, val);
		Modify(x<<1|1, mid+1, r, Rx, nr, val);
		push_up(x);
	}
	int Query(int x, int l, int r, int nl, int nr)
	{
		if (nl > nr) return 0;
		push_down(x);
		if (l == nl && r == nr) return Nd[x].a[0][1];
		int mid = (l + r) >> 1, Lx = min(nr, mid), Rx = max(nl, mid+1);
		int Lret = Query(x<<1, l, mid, nl, Lx);
		int Rret = Query(x<<1|1, mid+1, r, Rx, nr);
		return Add(Lret, Rret);
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	trs[0] = Trs;
	for (int i = 1; i <= 68; ++i) trs[i] = trs[i-1] * trs[i-1];

	Segment_Tree::Build(1, 1, n);
	for (int x, l, r, tp; m; m--) {
		cin >> tp >> l >> r;
		if (tp == 1) {
			cin >> x;
			Segment_Tree::Modify(1, 1, n, l, r, x);
		} else {
			int Ret = Segment_Tree::Query(1, 1, n, l, r);
			cout << Ret << endl;
		}
	}
}
