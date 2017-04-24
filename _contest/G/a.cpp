#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 5e5+50, maxm = 1e5+50;
const int inf = 0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f, base = 23456789;;

typedef int arrn[maxn];
typedef ll arrm[maxn];


template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar()) {
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

int n, m;
char s[maxn], t[maxn];
deque<int> qt[30], qs[30];
ll sumt[30], sums[30], tot[maxn];
int cnt[30];
bool vis[30][30];
vector<int> ans;
vector<pii> v, c;

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	scanf("%d%d\n%s\n%s",&n,&m,s+1, t+1);
	if (n < m) puts("0"), exit(0);
	
	tot[0] = 1;
	for (int i = 1; i <= n; ++i) tot[i] = (tot[i-1] * base) % mod;
	for (int i = 1; i <= n; ++i) (tot[i] += tot[i-1]) %= mod;
		

	for (int i = 1; i <= m; ++i)
	{
		qt[t[i]-'a'+1].push_back(i), sumt[t[i]-'a'+1] = (sumt[t[i]-'a'+1] * base + i) % mod;
		qs[s[i]-'a'+1].push_back(i), sums[s[i]-'a'+1] = (sums[s[i]-'a'+1] * base + i) % mod;
	}

	for (int j = 1; j <= 26; ++j)
		if (qt[j].size())
			c.push_back(pii(*qt[j].begin(), j));
	sort(c.begin(), c.end());
	
	for (int i = m; i <= n; ++i)
	{
		v.clear();
		for (int j = 1; j <= 26; ++j)
			if (qs[j].size())
			{
				v.push_back(pii(*qs[j].begin(), j));
				// for (deque<int>::iterator it = qs[j].begin(); it != qs[j].end(); ++it)
				// 	cerr << *it << " ";
				// cerr << endl;
			}
		// cerr << endl << endl;
		sort(v.begin(), v.end());

		if (v.size() == c.size())
		{
			for (int i = 0; i < v.size(); ++i)
				if (sums[v[i].se] != sumt[c[i].se]) goto fail;
			memset(cnt, 0, sizeof(cnt));
			memset(vis, 0, sizeof(vis));
			for (int i = 0; i < v.size(); ++i)
				if (s[v[i].fi] != t[c[i].fi])
					if (!vis[s[v[i].fi]-'a'+1][t[c[i].fi]-'a'+1])
					{
						vis[s[v[i].fi]-'a'+1][t[c[i].fi]-'a'+1] = vis[t[c[i].fi]-'a'+1][s[v[i].fi]-'a'+1] = 1;
						if (++cnt[s[v[i].fi]-'a'+1] > 1) goto fail;
						if (++cnt[t[c[i].fi]-'a'+1] > 1) goto fail;
					}
			ans.push_back(i-m+1);			
		}
		
	  fail:
		for (int j = 1; j <= 26; ++j)
			if (qs[j].size())
				sums[j] = ((sums[j] - tot[qs[j].size()-1]) % mod + mod) % mod;
		qs[v[0].se].pop_front();
		qs[s[i+1]-'a'+1].push_back(i+1);
		sums[s[i+1]-'a'+1] = (sums[s[i+1]-'a'+1] * base % mod + m) % mod;
	}

	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); ++i)
		printf("%d ", ans[i]);
}
