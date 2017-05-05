#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 2e5+50, maxt = 2e6 + 50, maxm = 1e5+50;
const int inf = 0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;

typedef int arrn[maxn];
typedef ll arrm[maxn];


template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar()) {
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

int n, T, vsz, dsz;
int bit[maxn];
int f[maxn];
int x[maxn], y[maxn];
int d[maxn];

struct obj {
	int tp, id;
	friend bool operator < (const obj &a, const obj &b) {
		if (x[a.id] != x[b.id]) return x[a.id] < x[b.id];
		if (y[a.id] != y[b.id]) return y[a.id] < y[b.id];
		return a.tp < b.tp;		
	}
}v[maxn];

void ins(int p, int val) {
	for (; p <= dsz; p += p & -p)
		if (val > 0)
			bit[p] = max(bit[p], val);
		else
			bit[p] = 0;
}
int ask(int p) {
	int ret = -1;
	for (; p; p -= p & -p)
		ret = max(ret, bit[p]);
	return ret;
}
void scanline() {
	sort(v+1, v+vsz+1);
	
	for (int i = 1; i <= vsz; ++i)
		if (v[i].tp == -1)
			ins(y[v[i].id], f[v[i].id]);
		else
			f[v[i].id] = max(f[v[i].id], ask(y[v[i].id])+1);
	
	for (int i = 1; i <= vsz; ++i)
		if (v[i].tp == -1)
			ins(y[v[i].id], -1);		
}
void divide(int l, int r) {
	if (l == r) {
		f[l] = max(f[l], 1);
		return;
	}
	int mid = (l + r) >> 1;

	divide(l, mid);

	vsz = 0;
	for (int i = l; i <= mid; ++i) v[++vsz] = (obj){-1, i};
	for (int i = mid+1; i <= r; ++i) v[++vsz] = (obj){1, i};
	scanline();

	divide(mid+1, r);											 
}

void init() {
	dsz = 0;
	memset(f, 0, sizeof(f));
}
int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
    
	for (scanf("%d\n", &T); T; T--)
	{
		init();
		gint(n);
		for (int i = 1; i <= n; ++i)
			gint(x[i]), gint(y[i]), x[i] -= i, y[i] -= i, d[++dsz] = y[i];
		
		sort(d+1, d+dsz+1), dsz = unique(d+1, d+dsz+1) - d - 1;
		for (int i = 1; i <= n; ++i)
			y[i] = lower_bound(d+1, d+dsz+1, y[i]) - d;

		divide(1, n);
		cout << n - *max_element(f+1, f+n+1) << endl;		
	}
}
