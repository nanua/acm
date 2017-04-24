#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

int n, a[maxn];
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		while (a[i] % 3 == 0) a[i] /= 3;
		while (a[i] % 2 == 0) a[i] /= 2;
	}
	puts(unique(a+1, a+n+1)-a-1 == 1 ? "YES" : "NO");
}
