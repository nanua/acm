#include <bits/stdc++.h>
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

int n, m, a[101][101], b[101][101], ans = inf;
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> m >> n;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> a[i][j];

	cpy(b, a);
	for (int r = 1; r <= m; ++r)
		for (int c = 1; c <= n; ++c) {
			int cnt = 0;
			cpy(a, b);
			for (int i = 1; i <= m; ++i)
				for (int j = 1, Min; j <= n; ++j)
					if ((Min = a[i][j]) != 0) {
						if (i+r-1 > m || j+c-1 > n) goto fail;
						for (int x = i; x < i+r; ++x)
							for (int y = j; y < j+c; ++y)
								if (a[x][y] < a[i][j]) goto fail;
								else a[x][y] -= Min;
						cnt += Min;
					}
			ans = min(ans, cnt);
		fail:;
		}

	cout << ans;			
}
 
