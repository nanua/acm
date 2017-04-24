#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pk pop_back
#define fi first
#define se second

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

const int maxn = 2e5+50, maxm = 1e5+50, inf = (int)0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = (ll)1e17;

typedef int arrn[maxn];
typedef int arrm[maxm];


template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar()) {
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

int n, m;
int f[110][110];

int main() {
#ifdef LOCAL
    freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

	while (cin >> n >> m, n) {
		for (int i = 1; i <= n; ++i) 
			for (int j = 1; j <= n; ++j) 
				f[i][j] = inf * (i != j);

		for (int a, b, c, i = 1; i <= m; ++i) {
			cin >> a >> b >> c;
			f[a][b] = min(f[a][b], c);
			f[b][a] = min(f[b][a], c);
		}	

		for (int k = 1; k <= n; ++k)
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					f[i][j] = min(f[i][j], f[i][k] + f[k][j]);

		cout << f[1][n] << endl;
	}
}
