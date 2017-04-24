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
int y[3][maxn], x[3][maxn];

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> x[1][i] >> y[1][i];
	cin >> m;
	for (int i = 1; i <= m; ++i)
		cin >> x[2][i] >> y[2][i];


	int t1 = *max_element(x[1]+1, x[1]+n+1) - *min_element(y[2]+1, y[2]+m+1);
	int t2 = *max_element(x[2]+1, x[2]+m+1) - *min_element(y[1]+1, y[1]+n+1);

	cout << max(max(t1, t2), 0);
}

