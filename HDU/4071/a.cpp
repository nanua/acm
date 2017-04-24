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
#define sqr(x) ((x)*(x))
using namespace std;

typedef double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int n;
ld x[maxn], y[maxn], st[maxn], ed[maxn];

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (scanf("%d",&n), n) {
		for (int i = 1; i <= n; ++i) scanf("%lf %lf", &x[i], &y[i]), y[i] = fabs(y[i]);

		ld l = *max_element(y+1, y+n+1), r = 1e9, mid;
		for (int t = 1; t <= 100; ++t) {
			mid = (l + r) / 2;
			for (int i = 1; i <= n; ++i) {
				st[i] = x[i] - sqrt(sqr(mid)-sqr(y[i]));
				ed[i] = x[i] + sqrt(sqr(mid)-sqr(y[i]));
			}
			*max_element(st+1,st+n+1) <= *min_element(ed+1, ed+n+1) ? r = mid : l = mid;
		}

		cout << fixed << setprecision(9) << *max_element(st+1, st+n+1) << " " << mid << endl;
	}
}
 
