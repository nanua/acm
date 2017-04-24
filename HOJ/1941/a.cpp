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

int n, a[maxn], Time, d[3], wait[maxn];
double tot;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (cin >> n) {
		for (int i = 1; i <= n; ++i) cin >> a[i];
		sort(a+1, a+n+1);
		
		tot = Time = d[1] = d[2] = 0;
		
		for (int i = 1; i <= n; ) {
			if (Time >= d[1] && i <= n)
				d[1] = Time + a[i], wait[i] = Time, i++;
			if (Time >= d[2] && i <= n)
				d[2] = Time + a[i], wait[i] = Time, i++;
			Time = min(d[1], d[2]);
		}

		for (int i = 1; i <= n; ++i) tot += wait[i];

		cout << fixed << setprecision(3) << tot / n << endl;
	}
}
 
