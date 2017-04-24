#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

int n, a[maxn], pos[maxn], len[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i], pos[a[i]] = i;
		len[a[i]] = len[a[i]-1] * (pos[a[i]-1] != 0)  + 1;
	}
	cout << n - *max_element(len+1, len+n+1);
}
