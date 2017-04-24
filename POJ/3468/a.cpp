#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cctype>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define clr(x, y) memset(x, y, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(y))
#define all(x) x.begin(), x.end()
#define sqr(x) ((x) * (x))
#define sz(x) ((ll)x.size())

#define mk make_pair
#define pb push_back
#define pk pop_back
#define fi first
#define se second

#define add_edge(x, y) (to[++edg] = y, nt[edg] = la[x], la[x] = edg)
#define add_wedge(x, y, w) (to[++edg] = y, wgt[edg] = w, nt[edg] = la[x], la[x] = edg)
#define lowbit(x) ((x) & (-x))

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

const ld eps = 1e-12, pi = acos(-1);
const int maxn = 8e5+50, maxm = 1e5+50, inf = (int)0x3f3f3f3f, mod = (int)1e9 + 7, sigma = 129;
const ll INF = (ll)1e17;

typedef ll arrn[maxn];
typedef int arrm[maxm];


template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar()) {
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

arrn sum, tag, a;
ll v;
int n, T, q, l, r;
char op[20];

void build(int x, int l, int r) {
	if (l == r) {
		sum[x] = a[l], tag[x] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(x<<1, l, mid), build(x<<1|1, mid+1, r);
	sum[x] = sum[x<<1] + sum[x<<1|1], tag[x] = 0;
}
void push_down(int x, int L, int R) {
	int mid = (L+R) >> 1;
	if (L != R)
		tag[x<<1] += tag[x], tag[x<<1|1] += tag[x],
			sum[x<<1] += tag[x] * (mid-L+1), sum[x<<1|1] += tag[x] * (R-mid);
	tag[x] = 0;
}
void chg(int x, int L, int R, int l, int r, ll v) {
	if (l > r) return;
	push_down(x, L, R);

	if (L == l && r == R) {
		sum[x] += (R-L+1) * v, tag[x] += v;
		return;
	}
	int mid = (L + R) >> 1;
	chg(x<<1, L, mid, l, min(mid, r), v);
	chg(x<<1|1, mid+1, R, max(l, mid+1), r, v);
	sum[x] = sum[x<<1] + sum[x<<1|1];
}
ll ask(int x, int L, int R, int l, int r) {
	if (l > r) return 0;
	push_down(x, L, R);
	if (L == l && r == R)
		return sum[x];

	int mid = (L + R) >> 1;
	return ask(x<<1, L, mid, l, min(mid, r)) + ask(x<<1|1, mid+1, R, max(l, mid+1), r);
}
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	
	while (~scanf("%d %d", &n, &q)) {		
		for (int i = 1;  i <= n; ++i) gint(a[i]);

		build(1, 1, n);
		for (; q; q--) {
			scanf("%s", op);
			switch(op[0]) {
			case 'Q':
				scanf("%d %d", &l, &r);
				printf("%lld\n", ask(1, 1, n, l, r)); 
				break;
			case 'C':
				scanf("%d %d %lld", &l, &r, &v);
				chg(1, 1, n, l, r, v);
				break;
			}
		}
	}

}
 
