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

int n, k, a[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (scanf("%d %d\n",&n, &k) != EOF) {
		for (int i = 1; i <= n; ++i) scanf("%d\n",&a[i]);
		sort(a+1, a+n+1);
		int ans = 0;
		for (int i = 1, j = n; i <= j; )
			if (i == j) ans++, j--, i++;
			else
				if (a[i] + a[j] > k) ans++, j--;
				else ans++, j--, i++;
		cout << ans << endl;
	}
}
