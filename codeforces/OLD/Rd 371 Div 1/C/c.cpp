#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
const ll maxn = 1e5 + 10, inf = 1LL<<40, mod = 1e9 + 7;

int n, a[maxn];
pii f[maxn];
ll sum_min, sum_max;
multiset<int> set_max;
multiset<int, greater<int> > set_min;

inline void swap_top() {
	int x = *set_min.begin(), y = *set_max.begin();
	sum_min -= x - y, sum_max -= y - x;
	set_min.erase(set_min.begin());
	set_max.erase(set_max.begin());
	set_min.insert(y);
	set_max.insert(x);
}
inline void push_top() {
	int x = *set_min.begin();
	sum_min -= x, sum_max += x;
	set_max.insert(x);
	set_min.erase(set_min.begin());
}
inline void adjust(int x) {
	set_min.insert(x), sum_min += x;
	while (set_min.size() - set_max.size() >= 2) push_top();
	if (set_max.size())
		while (*set_min.begin() > *set_max.begin()) swap_top();
}
inline ll calc_cost() {
	if (set_max.size() == 0)
		return abs(sum_min - (ll)*set_min.begin() * (ll)set_min.size());
	return abs(sum_min - (ll)*set_min.begin() * (ll)set_min.size()) +
		abs(sum_max - (ll)*set_min.begin() * (ll)set_max.size());
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i], f[i] = pii(inf, inf);
	f[0] = pii(0, -inf);
	
	for (int i = 0; i < n; ++i) {
		set_min.clear(), set_max.clear();
		sum_min = sum_max = 0;
		for (int j = i+1, t = 1; j <= n; ++j, ++t) {
			adjust(a[j] - t + 1);
			if (f[i].se <= *set_min.begin() + t/2 - t)
				f[j] = min(f[j], pii(f[i].fi+calc_cost(), *set_min.begin() + t/2));
			continue;
		}
	}
	
	cout << f[n].fi << endl;
}
