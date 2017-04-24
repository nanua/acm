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
int r, c, a[maxn], b[maxn];

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (~scanf("%d %d\n", &r, &c)) {
		ll sumr = 0, sumc = 0;
		
		for (int i = 1; i <= r; ++i) scanf("%d", a+i), sumr += a[i];
		for (int i = 1; i <= c; ++i) scanf("%d", b+i), sumc += b[i];
		sort(a+1, a+r+1), sort(b+1, b+c+1);
		
		int x = upper_bound(a+1, a+r+1, 0)-a, y = upper_bound(b+1, b+c+1, 0)-b;
		
		if (sumr == sumc && ll(r-x+1) * ll(c-y+1) >= sumr)
			puts("YES");
		else
			puts("NO");				
	}
}
