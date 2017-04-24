#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pk pop_back
#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 2e5+50, maxm = 1e5+50, inf = (int)0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = (ll)1e17;

typedef int arrn[maxn];
typedef ld arrm[maxn];


template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar()) {
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

int n;
arrm x, v;

ld calc(ld p) {
	ld ret = fabs(x[1] - p) / v[1];
	for (int i = 2; i <= n; ++i)
		ret = max(ret, fabs(x[i] - p) / v[i]);
	return ret;
}
int main() {
#ifdef LOCAL
    freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> x[i];
	for (int i = 1; i <= n; ++i) cin >> v[i];

	ld l = 1, r = 1e9;
	for (int j = 100; j >= 1; --j) {
		ld p1 = l + (r-l) / 3, p2 = r - (r-l) / 3;
		if (calc(p1) > calc(p2))
			l = p1;
		else
			r = p2;
	}

	cout << fixed << setprecision(10) << calc((l + r) / 2);
}

