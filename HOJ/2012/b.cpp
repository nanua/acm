#include <map>
#include <set>
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

int n, a[maxn], ans;
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (cin >> n) {
		for (int i = 1; i <= n; ++i) cin >> a[i];
		sort(a+1, a+n+1);
		for (int i = 2; i <= n; ++i) {
			a[i] += a[i-1] - 1;
			for (int j = i; j < n && a[j] > a[j+1]; ++j) swap(a[j], a[j+1]);
		}
		cin >> ans;
		puts(ans == a[n] ? "GREAT!" : "POOR!");
	}
}
 
