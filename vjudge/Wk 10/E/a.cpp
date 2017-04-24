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

int n, a[maxn];
ll ans;
set<int> set_max;
set<int, greater<int> > set_min;

void adjust(int num) {
	set_min.insert(num);
	while (set_min.size() - set_max.size() >= 2)
		set_max.insert(*set_min.begin()), set_min.erase(set_min.begin());
	int x, y;
	if (set_max.size())
		while ((x = *set_min.begin()) > (y = *set_max.begin())) {
			set_min.erase(set_min.begin()), set_max.erase(set_max.begin());
			set_min.insert(y), set_max.insert(x);
		}		
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (scanf("%d\n",&n), n) {
		set_min.clear(), set_max.clear(), ans = 0;
		for (int i = 1; i <= n; ++i) scanf("%d\n",&a[i]);
		for (int i = 1; i <= n; ++i) adjust(a[i] - i);
		for (int i = 1; i <= n; ++i) ans += abs(a[i] - *set_min.begin());
		cout << ans << endl;
	}
}
 
