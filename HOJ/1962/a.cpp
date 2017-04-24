#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;

int t, n, cnt, a[1010];
double sum;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

	for (cin >> t; t; t--) {
		cin >> n, cnt = sum = 0;
		for (int i = 1; i <= n; ++i) cin >> a[i], sum += a[i];
		sum /= n;
		for (int i = 1; i <= n; ++i) cnt += a[i] > sum;
		cout << fixed << setprecision(3) << 100.0 * cnt / n << "%" << endl;
	}	
}
