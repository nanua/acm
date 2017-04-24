#include <bits/stdc++.h>
using namespace std;

#define lowbit(x) (x&(-x))
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

int n;
arrn a, id, bit, lef_les, lef_gre, rig_les, rig_gre;

bool cmp(int x, int y) {
	return a[x] < a[y];
}
void bit_ins(int p) {
	for (; p <= n; p += lowbit(p)) bit[p]++;
}
int bit_ask(int p, int ret = 0) {
	for (; p; p -= lowbit(p)) ret += bit[p];
	return ret;
}
int main() {
#ifdef LOCAL
    freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (~scanf("%d",&n)) {
		for (int i = 1; i <= n; ++i)
			gint(a[i]), id[i] = i;
		a[n+1] = inf;

		sort(id+1, id+n+1, cmp);

		memset(bit, 0, sizeof(bit));
		for (int i = 1, j; i <= n; i = j) {
			for (j = i+1; a[id[i]] == a[id[j]]; ++j);
			for (int k = i; k < j; ++k) {
				lef_les[id[k]] = bit_ask(id[k]);
				rig_les[id[k]] = i-1 - lef_les[id[k]];
			}
			for (int k = i; k < j; ++k)
				bit_ins(id[k]);
		}
		memset(bit, 0, sizeof(bit));
		reverse(id+1, id+n+1);
		for (int i = 1, j; i <= n; i = j) {
			for (j = i+1; a[id[i]] == a[id[j]]; ++j);
			for (int k = i; k < j; ++k) {
				lef_gre[id[k]] = bit_ask(id[k]);
				rig_gre[id[k]] = i-1 - lef_gre[id[k]];
			}
			for (int k = i; k < j; ++k)
				bit_ins(id[k]);
		}

		ll tot_les = 0, tot_gre = 0, cse1 = 0, cse2 = 0, cse3 = 0, cse4 = 0, ans = 0;
		for (int i = 1; i <= n; ++i) {
			tot_les += rig_les[i], tot_gre += rig_gre[i];
			cse1 += rig_les[i] * rig_gre[i];
			cse2 += lef_gre[i] * rig_gre[i];
			cse3 += lef_les[i] * rig_les[i];
			cse4 += lef_les[i] * lef_gre[i];
		}

		ans = tot_les * tot_gre - cse1 - cse2 - cse3 - cse4;

		cout << ans << endl;
	}
}
