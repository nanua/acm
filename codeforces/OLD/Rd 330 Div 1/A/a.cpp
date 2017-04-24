#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

set<int> s;
int n, sz, p[maxn], v[maxn];

bool check(int ps, int l) {
	int rb = lower_bound(p+ps, p+n+1, l+p[ps]) - p;
	int lb = upper_bound(p+1, p+ps+1, p[ps]-l) - p;
	return n-rb+lb <= n/2-1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> p[i];
	sort(p + 1, p + n + 1);

	for (int i = 1, tmp; i <= n; ++i) {
		for (int l = 0, r = inf, mid; l <= r; )
			check(i, mid = (l + r) >> 1) ? r = (tmp = mid) - 1 : l = mid + 1;
		v[++sz] = tmp;					     
	}
	sort(v+1, v+sz+1);
	cout << v[n-n/2+1]-1;

}


