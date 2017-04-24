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

int n, m;
struct M {
	bitset<510> mps[510];

	const M flip() {
		M ret;
		for (int i = 1; i <= n; ++i)
			ret.mps[i] = this->mps[i].flip();
		return ret;
	}
	friend M operator * (const M &x, const M &y) {
		M ret;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if (x.mps[i][j] == 1)
					ret.mps[i] |= y.mps[j];
		return ret;
	}
}d[2], tmp[2][65];

void prepare() {
	tmp[0][0] = d[0], tmp[1][0] = d[1];
	for (int i = 1; i <= 62; ++i) {
		tmp[0][i] = tmp[0][i-1] * tmp[1][i-1];
		tmp[1][i] = tmp[1][i-1] * tmp[0][i-1];
	}
}
ll calc() {
	M rd;
	for (int i = 1; i <= n; ++i) rd.mps[i].set();

	ll ret = 0, tp = 0;
	for (int i = 62; i >= 0; --i) {
		M t = rd * tmp[tp][i];
		for (int j = 1; j <= n; ++j)
			if (t.mps[1][j] == 1) goto success;

		continue;
	success:
		rd = t, tp ^= 1, ret |= 1LL<<i;
	}
	return ret;
}
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	gint(n), gint(m);
	for (int i = 1, u, v, t; i <= m; ++i)
		gint(u), gint(v), gint(t), d[t].mps[u][v] = 1;

	prepare();
	ll ans = calc();

	cout << (ans >= 1e18 + 1 ? -1 : ans);
}

