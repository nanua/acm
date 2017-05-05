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

int t, n, m;
vector<int> v[101091];
int f[101010], a[1010101];

int find(int x) {
	return f[x] == x ? f[x] : f[x] = find(f[x]);
}
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
	for (cin >> t; t--; ) {
		cin >> n;
		for (int i = 1; i <= n; ++i)
			f[i] = i, v[i].clear(), cin >> a[i], v[i].push_back(a[i]);
		for (cin >> m; m--; ) {
			int tp;
			cin >> tp;
			if (tp == 1) {
				int a, b;
				cin >> a >> b;
				int x = find(a), y = find(b);
				if (x != y){
					for (int i = 0; i < v[y].size(); ++i)
						v[x].push_back(v[y][i]);
					f[y] = x;
				}
			}
			else {
				int x, ans = -1;
				cin >> x;
				int y = find(x);
				for (int i = 0; i < v[y].size(); ++i)
					ans = max(ans, a[x]^v[y][i]);
				cout << ans << endl;
			}
		}
	}
}
