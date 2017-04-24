#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pk pop_back
#define fi first
#define se second

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <int, pii> tpi;

const int maxn = 1010, maxm = 1e5+50, inf = (int)0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = (ll)1e17;

typedef int arrn[maxn];
typedef int arrm[maxm];


template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar()) 
{
	while (!isdigit(ch) && ch != '-') ch = getchar();
 	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

int T, n, m, edg, kase;
int f[maxn][maxn];
int ufs[maxn*maxn];
tpi e[maxn*maxn*2];

int find(int x) 
{
	return ufs[x] == x ? x : ufs[x] = find(ufs[x]);
}
inline int idx(int i, int j) 
{
	return (i-1) * m + j;
}

int main() 
{
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

	for (gint(T); T--; ) 
	{
		edg = 0;
		gint(n), gint(m);

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				gint(f[i][j]);

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j < m; ++j)
				e[++edg] = tpi(abs(f[i][j] - f[i][j+1]), pii(idx(i, j), idx(i, j+1)));		 	
		
		for (int i = 1; i < n; ++i)
			for (int j = 1; j <= m; ++j)
				e[++edg] = tpi(abs(f[i][j] - f[i+1][j]), pii(idx(i, j), idx(i+1, j)));

		sort(e+1, e+edg+1);

		for (int i = 1; i <= n*m; ++i) 
			ufs[i] = i;

		int ans = 0;
		for (int i = 1; i <= edg; ++i)
		{
			int u = find(e[i].se.fi), v = find(e[i].se.se);

			if (u != v) 
			{
				ufs[u] = ufs[v];
				ans += e[i].fi;
			}
		}

		printf("Case #%d:\n%d\n", ++kase, ans);
 	}	
} 
