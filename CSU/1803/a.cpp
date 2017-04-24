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


template<class Q> void gint(Q &ret, char ch = getchar()) {
	while (!isdigit(ch)) ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
}
int n, m;
ll calc(int x) {
	int d[3] = {1,1,1}, ret = 0;
	if (x % 32 == 0) d[0] = 0;
	if (x % 9 == 0) d[1] = 0;
	if (x % 7 == 0) d[2] = 0;
	for (int i = 0; i <= 1; ++i)
		if (!i || d[0])
			for (int j = 0; j <= 1; ++j)
				if (!j || d[1])
					for (int k = 0; k <= 1; ++k)
						if (!k || d[2]) {
							int q = (i?2:1)*(j?3:1)*(k?7:1);
							ret += ((i+j+k)%2?-1:1)*(n/x/q);
						}
	return ret;
}
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
		
	while (cin >> n >> m) {
		ll ans = 0;
		for (int i = 1; i <= 2016 && i <= n; ++i)
			if (2016 % i == 0)
				ans += calc(i) * ll(m / (2016 / i));
		cout << ans << endl;
	}
}
 
