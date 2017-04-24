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

int d[210][410], sz[210], n;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	sz[1] = sz[2] = d[1][1] = d[2][1] = 1;
	for (int i = 3; i <= 200; ++i) {
		for (int j = 1; j <= sz[i-1]; ++j) d[i][j] = d[i-1][j] * (i-2);
		for (int j = 1; j <= sz[i-1] + 5; ++j) d[i][j+1] += d[i][j] / 10, d[i][j] %= 10;
		for (sz[i] = sz[i-1] + 5; d[i][sz[i]] == 0; sz[i]--);
	}

	while (cin >> n, n) {
		for (int i = sz[n]; i >= 1; --i) cout << d[n][i];
		cout << endl;
	}
}
