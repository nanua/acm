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

int n, k;
arrn lg, rmq[21], sum;

void rmq_init() {
	for (register int i = 1; i <= 20; ++i)
		for (register int j = 1; j + (1<<i) - 1 <= n; ++j)
			rmq[i][j] = max(rmq[i-1][j], rmq[i-1][j+(1<<(i-1))]);
}
inline int rmq_qer(int l, int r) {
	register int k = lg[r-l+1];
	return max(rmq[k][l], rmq[k][r-(1<<k)+1]);
}

int main() {
#ifdef LOCAL
    freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for (int i = 2; i < maxn; ++i) lg[i] = lg[i>>1] + 1;

	while (gint(n), gint(k), n != -1) {
		for (int i = 1; i <= n; ++i)
			gint(rmq[0][i]), sum[i] = sum[i-1] + rmq[0][i];

		rmq_init();

		int ans = -1, lim = max(1,k / max(*max_element(rmq[0]+1, rmq[0]+n+1), 1));
		for (register int i = lim; i <= (n>>1); ++i) {

			register int tot  = 0, t = n/i;
			for (register int j = 1; j <= i && tot <= k; ++j)
				tot += rmq_qer((j-1)*t+1, j*t);
			if (tot > k) {
				ans = i; break;
			}
		}
		if (ans == -1)
			for (int i = (n>>1)+1; i <= n; ++i)
				if (sum[i] > k)
					{ ans = i; break; }

		printf("%d\n", ans);
	}
}
