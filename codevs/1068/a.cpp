#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;
int n, m;
pii a[maxn];
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n >> m;
	m = (ld)m*1.5;
	for_each(a+1, a+n+1, [](pii &x){cin >> x.fi >> x.se;});
	sort(a+1, a+n+1, [](pii &x, pii &y) -> bool{ return x.se == y.se ? x.fi < y.fi : x.se > y.se;});
	cout << a[m].se << " " << count_if(a+1, a+n+1, [&](pii &x)->bool{return x.se >= a[m].se;}) << endl;;
	for_each(a+1, a+n+1, [&](pii &x){ if(x.se >= a[m].se)cout << x.fi << " " << x.se << endl;});
}
