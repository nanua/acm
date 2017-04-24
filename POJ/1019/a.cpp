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

typedef int lint;
typedef long long ll;
typedef long double ld;
typedef pair <lint, lint> pii;

const ld eps = 1e-12, pi = acos(-1);
const lint maxn = 2e5+50, maxm = 1e5+50, inf = (lint)0x3f3f3f3f, mod = (lint)1e9 + 7, sigma = 129;
const ll INF = (ll)1e17;

typedef lint arrn[maxn];
typedef lint arrm[maxm];


template<class Q> void gint(Q &ret, char ch = getchar()) {
	while (!isdigit(ch)) ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
}

int len(int x, int ret = 0) {
	while (x) ret++, x /= 10;
	return ret;
}

int T, n;
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

	for (scanf("%d\n", &T); T; T--) {
		gint(n);
		ll i, j, tot = 0, cur = 0;
		for (i = 0; cur < n; ++i) {
			tot += len(i+1);
			cur += tot;
		}
		cur -= tot;
		for (j = 0; j < n; ++j)
			if (cur + len(j+1) < n) cur += len(j+1);
			else break;
		j++, ++cur;
		char s[25] = "";
		int sz = 0;
		for (; j; j /= 10) s[sz++] = j % 10 + '0';
		
		for (i = sz-1; i >= 0 && cur != n; --i, ++cur);
		cout << s[i] << endl;
	}
}
 
