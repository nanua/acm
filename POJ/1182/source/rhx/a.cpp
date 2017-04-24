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
#define sz(x) ((LL)x.size())

#define mk make_pair
#define pb push_back
#define pk pop_back
#define fi first
#define se second

#define add_edge(x, y) (to[++edg] = y, nt[edg] = la[x], la[x] = edg)
#define add_wedge(x, y, w) (to[++edg] = y, wgt[edg] = w, nt[edg] = la[x], la[x] = edg)
#define lowbit(x) ((x) & (-x))

typedef int lint;
typedef long long ll;
typedef long double ld;

typedef map <lint, lint> mii;
typedef pair <lint, lint> pii;
typedef set <lint> sint;
typedef vector <lint> vint;

const ld eps = 1e-12, pi = acos(-1);
const lint maxn = 2e5+50, maxm = 1e5+50, inf = (lint)0x3f3f3f3f, mod = (lint)1e9 + 7, sigma = 129;
const ll INF = (ll)1e17;

typedef lint arrn[maxn];
typedef lint arrm[maxm];

arrn f;
int n, k, d, x, y, ans;

template<class Q> void gint(Q &ret, char ch = getchar()) {
	while (!isdigit(ch)) ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
}

int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
void _union(int x, int y) {
	f[find(x)] = f[find(y)];
}

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	gint(n), gint(k);

	for (int i = 1; i <= n*3; ++i) f[i] = i;
	
	for (int i = 1; i <= k; ++i) {
		gint(d), gint(x), gint(y);
		
		if (max(x, y) > n) ans++;
		else 	if (d == 1) {
			if (find(x) == find(y+n) || find(x+n) == find(y+n*2) || find(x+n*2) == find(y) ||
			    find(y) == find(x+n) || find(y+n) == find(x+n*2) || find(y+n*2) == find(x))			    
				ans ++;
			else
				_union(x, y), _union(x+n, y+n), _union(x+2*n, y+2*n);
		} else {
			if (find(x) == find(y) || find(x+n) == find(y+n) || find(x+n*2) == find(y+n*2) ||
			    find(y) == find(x+n) || find(y+n) == find(x+n*2) || find(y+n*2) == find(x))			    
				ans ++;
			else
				_union(x, y+n), _union(x+n, y+n*2), _union(x+2*n, y);
		}
	}
	
	cout << ans << endl;
}
 
