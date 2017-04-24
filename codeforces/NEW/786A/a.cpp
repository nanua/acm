#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 7000+50, maxm = 1e5+50;
const int inf = 0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;

typedef int arrn[maxn];
typedef ll arrm[maxn];


template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar())
{
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

int n;
int k[3];
int s[3][maxn];
bool vis[3][maxn];
int f[3][maxn];

int dfs(int x, int p)
{
	if (vis[x][p] == 1 || f[x][p] == 1 || f[x][p] == 2)
		return f[x][p];
	vis[x][p] = 1, f[x][p] = 3;
	if (p == 1) return (f[x][p] = 1); // 1 lose, 2 win, 3 infty
	
	int cnt[5] = {};
	for (int i = 1; i <= k[x]; ++i)
	{
		cnt[dfs(3-x, (p + s[x][i]-1) % n + 1)]++;
		if (cnt[1] != 0) f[x][p] = 2;
	}

	if (cnt[1] != 0) f[x][p] = 2;
	else if (cnt[2] == k[x]) f[x][p] = 1;
	else f[x][p] = 3;
	
	return f[x][p];
}
int main()
{
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n;
	cin >> k[1];
	for (int i = 1; i <= k[1]; ++i) cin >> s[1][i];
	cin >> k[2];
	for (int i = 1; i <= k[2]; ++i) cin >> s[2][i];

	for (int i = 1; i <= n; ++i)
	{
		memset(vis, 0, sizeof(vis));
		dfs(1, i);
		memset(vis, 0, sizeof(vis));
		dfs(2, i);
	}

	for (int i = 1; i <= 2; ++i, puts(""))
		for (int j = 2; j <= n; ++j)
			switch(f[i][j])
			{
				case 1: printf("Lose "); break;
				case 2: printf("Win "); break;
				case 3: printf("Loop "); break;
			}
		
}
 
