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

int n, m, vsz;
int a[101010];
int v[3010*3010/2];

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

	while (~scanf("%d %d",&n,&m)) {
		for (int i = 1; i <= n; ++i)
			gint(a[i]);
		vsz = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = i+1; j <= n; ++j)
				v[++vsz] = a[i] + a[j];
		sort(v+1, v+vsz+1, greater<int>());
		for (int i = 1; i <= m; ++i)
			printf("%d%c", v[i], i==m?'\n':' ');
	}
}
