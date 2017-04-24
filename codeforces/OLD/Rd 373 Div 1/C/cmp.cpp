#include <bits/stdc++.h>

typedef long long LLONG;
typedef std::pair<int, int>PII;
typedef std::pair<LLONG, LLONG>PLL;
typedef std::pair<int, PLL>PIPLL;
typedef std::map<int, int>MII;
typedef std::vector<PII>VPII;
#define TDEBUG
#ifdef TDEBUG
#define tout(x) std::cerr << #x << " = " << x << std::endl;
#define tdebug(args...) { std::cerr << "(" << #args << ") => "; dbg, args; std::cerr << std::endl; }
#else
#define tout(x)	//skip all
#define tdebug(args...)
#endif
struct Debuger {
	template<typename T>
	Debuger& operator, (const T& v) {
		std::cerr << v << " ";
		return *this;
	}
} dbg;
template<typename T>inline void scaf(T&v) {
	char ch = getchar();
	int sgn = 1;
	for (; '-' != ch && (ch < '0' || ch > '9'); ch = getchar());
	if ('-' == ch) sgn = -1, v = 0;
	else v = ch - '0';
	for (ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar()) v = (v << 1) + (v << 3) + ch - '0';
	v *= sgn;
}

const int N = 1e5 + 10;
const LLONG MOD = 1e9 + 7;
const int K = 50;

inline void add(LLONG& a, LLONG b, LLONG mod) {
	a += b;
	if(a >= mod && ~mod) { a %= mod; }
}
inline void times(LLONG& a, LLONG b, LLONG mod) {
	a *= b;
	if(a >= mod && ~mod) { a %= mod; }
}

template < int N, int MOD = -1 > struct Matrix {
	Matrix(bool identify = false) {
		memset(m, 0, sizeof(m));
		if(identify) { for(int i = 0; i < N; ++i) { m[i][i] = 1; } }
	}
	const LLONG* operator[](int i)const { return m[i]; }
	LLONG* operator[](int i) { return m[i]; }

	friend Matrix operator+(const Matrix& a, const Matrix& b) {
		Matrix c;
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < N; ++j) {
				add(c[i][j], a[i][j] + b[i][j], MOD);
				//c[i][j] = a[i][j] + b[i][j];
			}
		}
		return c;
	}

	friend Matrix operator*(const Matrix& a, const Matrix& b) {
		Matrix c;
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < N; ++j) {
				for(int k = 0; k < N; ++k) {
					add(c[i][j], a[i][k]*b[k][j], MOD);
					//c[i][j] += a[i][k] * b[k][j];
				}
			}
		}
		return c;
	}
	Matrix& operator*=(const Matrix& o) { *this = *this * o; return *this;}
	Matrix& operator+=(const Matrix& o) { *this = *this + o; return *this;}

	friend std::ostream& operator<<(std::ostream& o, const Matrix& mat) {
		putchar(10);
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < N; ++j) {
				printf("%lld ", mat[i][j]);
			}
			putchar(10);
		}
		return o;
	}
private:
	LLONG m[N][N];
};
typedef Matrix<2, MOD> FibMatrix;

FibMatrix power(FibMatrix a, int p) {
	FibMatrix rlt(true);
	for(; p; p >>= 1) {
		if(p & 1) { rlt *= a; }
		a *= a;
	}
	return rlt;
}

FibMatrix U, T, sum[N << 1], delta[N << 1];

#define TMID int mid = l + r >> 1;
#define LSON getId(l, mid)
#define RSON getId(mid + 1, r)
#define SELF getId(l, r)

int a[N];
inline int getId(int l, int r) { return l + r | l != r; }
inline void pushUp(int l, int r) {
	TMID;
	sum[SELF] = (sum[LSON] + sum[RSON]) * delta[SELF];
}

inline void build(int l, int r) {
	delta[getId(l, r)] = FibMatrix(true);
	if(l >= r) {
		sum[getId(l, r)] = U * power(T, a[l]);
	} else {
		int mid = l + r >> 1;
		build(l, mid);
		build(mid + 1, r);
		pushUp(l, r);
	}
}

inline void update(int l, int r, int ul, int ur, const FibMatrix& m) {
	if(l > ur || r < ul) { return;}
	if(l >= ul && r <= ur) {
		delta[SELF] *= m;
		sum[SELF] *= m;
	} else {
		TMID;
		update(l, mid, ul, ur, m);
		update(mid + 1, r, ul, ur, m);
		pushUp(l, r);
	}
}

inline FibMatrix query(int l, int r, int ql, int qr) {
	if(l > qr || r < ql) { return FibMatrix();}
	if(l >= ql && r <= qr) {
		return sum[SELF];
	} else {
		TMID;
		return (query(l, mid, ql, qr) + query(mid + 1, r, ql, qr)) * delta[SELF];
	}
}

int main() {	
	freopen("a.in","r",stdin);
	freopen("c.out","w",stdout);
	int n, m;
	U[0][1] = T[0][1] = T[1][0] = T[1][1] = 1;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	build(0, n - 1);
	for(; m--;) {
		int oper, l, r;
		scanf("%d%d%d", &oper, &l, &r);
		--l; --r;
		if(1 == oper) {
			int x;
			scanf("%d", &x);
			FibMatrix m = power(T, x);
			update(0, n - 1, l, r, m);
		} else {
			printf("%d\n", query(0, n - 1, l, r)[0][0]);
		}
	}
	return 0;
}
