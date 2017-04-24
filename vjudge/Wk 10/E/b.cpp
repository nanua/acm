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
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int n, ans;
map<int, int> m;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (scanf("%d\n",&n), n) {
		m.clear(), ans = 0;
		for (int i = 1, t; i <= n; ++i) scanf("%d\n",&t), m[t-i]++;
		for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
			ans = max(ans, it->second);
		cout << n - ans << endl;
	}
}
