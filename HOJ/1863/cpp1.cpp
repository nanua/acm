#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

const int maxn = 1e5+10, inf = 0x3f3f3f3f;

int t, a[20];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	for (cin >> t; t; t--) {
		for (int i = 1; i <= 10; ++i) cin >> a[i];
		sort(a+1, a+11);
		for (int i = 1; i <= 10; ++i) {
			cout << a[i];
			if (i != 10) putchar(' ');
		}
		puts("");
	}
}
