#include <bits/stdc++.h>>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 2e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;
typedef int arr[maxn*2];

arr to, val, nxt, las, cnt, wei;
int T, n, q, s, edg;

void add_edge(int a, int b ,int c) {
	to[++edg] = b, val[edg] = c, nxt[edg] = las[a], las[a] = edg;
	to[++edg] = a, val[edg] = c, nxt[edg] = las[b], las[b] = edg;
}
void dfs(int x, int f) {
	cnt[wei[x]]++;
	for (int i = las[x]; i; i = nxt[i])
		if (to[i] != f)
			wei[to[i]] = wei[x] ^ val[i], dfs(to[i], x);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
#endif

	ios::sync_with_stdio(0);
	for (cin >> T; T; T--) {
		cin >> n;
		edg = 0;
		for (int i = 0; i < maxn; ++i) las[i] = cnt[i] = 0;
		for (int i = 1, a,b,c; i < n; ++i)
			cin >> a >> b >> c, add_edge(a, b, c);
		dfs(1, 0);		
		for (cin >> q; q; q--) {
			cin >> s;
			ll ans = 0;
			for (int j = 1; j <= n; ++j) ans += cnt[s^wei[j]];
			ans += (s == 0) * n;
			cout << ans / 2 << endl;
		}
	}
} 
