#include <map>
#include <set>
#include <cmath>
#include <queue>
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

ld n;
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (cin >> n, fabs(n) > 1e-10) {
		int x = 1;
		for (ld l = 0; l < n; l += 1.0 / (++x));
		cout << x - 1 << " card(s)\n";
	}
}
 
