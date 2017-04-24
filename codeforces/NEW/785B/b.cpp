#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 2e5+50, maxm = 1e5+50;
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

bool cmp1(pii x, pii y) { return x.se < y.se; }
bool cmp2(pii x, pii y) { return x.fi > y.fi; }

int n, m, ans;
pii p[3][maxn];

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> p[1][i].fi >> p[1][i].se;
	cin >> m;
	for (int i = 1; i <= m; ++i)
		cin >> p[2][i].fi >> p[2][i].se;

	sort(p[1]+1, p[1]+n+1, cmp1);
	sort(p[2]+1, p[2]+m+1, cmp2);
	ans = p[2][1].fi - p[1][1].se;

	sort(p[1]+1, p[1]+n+1, cmp2);
	sort(p[2]+1, p[2]+m+1, cmp1);
	ans = max(ans, p[1][1].fi - p[2][1].se);

	cout << max(ans, 0);
}
