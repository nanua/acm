#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> set_t;
map<int, int> map_t;
int T, k, n, b[maxn], dsz;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	for (cin >> T; T; T--) {
		cin >> k >> n;
		dsz = 0, set_t.clear(), map_t.clear();;
		
		for (int i = 1, t; i <= n; ++i) {
			cin >> t;
			set_t.insert(((ll)t<<30) + (++map_t[t]));
			if (i & 1) b[++dsz] = (*set_t.find_by_order(i/2) >> 30);
		}
		
		cout << k << " " << dsz << endl;
		for (int i = 1; i <= dsz; ++i)
			cout << b[i] << ((i % 10 && i != dsz) ? " " : "\n");
	}
}
