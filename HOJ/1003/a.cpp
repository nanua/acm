#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cctype>
#include <vector>
#include <iomanip>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int n, m, ans;
pair<int, int> frm[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) cin >> frm[i].fi >> frm[i].se;

	sort(frm+1, frm+m+1);

	for (int i = 1; n > 0 && i <= m; n -= frm[i++].se)
		ans += min(n, frm[i].se) * frm[i].fi;

	cout << ans << endl;
}

