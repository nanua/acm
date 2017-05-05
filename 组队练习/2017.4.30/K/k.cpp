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


int vis[maxn], pre[maxn], pri[maxn], m[maxn];
int psz;

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for (int i = 2; i <= 100000; ++i)
		if (!vis[i]) {
			pre[i] = i, pri[++psz] = i;
			for (int j = i+i; j <= 100000; j += i)
				vis[j] = 1, pre[j] = i;
		}

	int n, t;

	for (scanf("%d",&t); t--; ) {
		scanf("%d",&n);
		memset(m, 0, sizeof(m));

		int cnt = 0, a, ans = 0, flag = 0;

		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a);
			if (a == 0) continue;
			else {
				while (a != 1) {
					if (pre[a] != 0) m[pre[a]]++;
					for (int p = pre[a]; a % p == 0; a /= p);
				}
			}
		}


		for (int i = 1; i <= psz; ++i) ans = max(ans, cnt + m[pri[i]]);
		cout << ans << endl;
	}
}
