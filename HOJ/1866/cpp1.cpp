#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

const int maxn = 2e6, inf = 0x3f3f3f3f;
int k, res[maxn+10];
bool prime[maxn+10];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	for (int i = 1; i*i <= maxn; ++i) res[i*i] = 1;
	for (int i = 1; i <= maxn; ++i) res[i] += res[i-1];
	while (cin >> k, k) cout << res[k] << endl;
}
