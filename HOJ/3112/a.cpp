#include <map>
#include <set>
#include <queue>
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
const int maxn = 1e6 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int ls, pl, rs, pr, sz, n;
ll q[maxn], l[maxn], r[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	
	q[++sz] = 1;
	l[++ls=pl] = 3, r[++rs=pr] = 4;
	for (int i = 2; i <= int(1e6); ++i) {
		if (l[pl] < r[pr]) q[++sz] = l[pl++];
		else q[++sz] = r[pr++];
		if (q[sz] == q[sz-1]) sz--;
		l[++ls] = q[sz] * 2 + 1;
		r[++rs] = q[sz] * 3 + 1;
	}

	while (cin >> n) cout << q[n] << endl;
}

