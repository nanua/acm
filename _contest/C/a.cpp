#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 2e6+50, maxm = 1e5+50;
const int inf = 0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f, base = 23456789;

typedef int arrn[maxn];
typedef ll arrm[maxn];


template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar())
{
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

int T, n, m;
int a[maxn];
int b[maxn];
ll ha[maxn];
ll hb[maxn];
ll e[maxn];

void calc_hash(ll h[], int x[], int n)
{
	for (int i = 1; i <= n; ++i)
		h[i] = (h[i-1] * base + x[i]) % mod;
}
int main()
{
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	e[0] = 1;
	for (int i = 1; i <= 10000; ++i) e[i] = (e[i-1] * base) % mod;
										 
	for (gint(T); T; T--)
	{
		gint(n), gint(m);
		for (int i = 1; i <= n; ++i) gint(a[i]), a[i] += 1e6+1;
		for (int i = 1; i <= m; ++i) gint(b[i]), b[i] += 1e6+1;

		calc_hash(ha, a, n);
		calc_hash(hb, b, m);

		for (int i = 1; i <= n-m+1; ++i)
			if (hb[m] == ((ha[i+m-1] - ha[i-1] * e[m]) % mod + mod) % mod)
			{
				printf("%d\n",i);
				goto succ;
			}
		puts("-1");
	  succ:
		continue;
	}

}
