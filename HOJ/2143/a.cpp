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
#define id first
#define len second .first
#define feq second.second
using namespace std;

typedef pair<int, pair<double, double> > tpi;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int n, pos;
tpi sg[maxn];

inline int cmp(const tpi &x, const tpi &y) {
	return x.len / x.feq < y.len / y.feq;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (cin >> n) {
		for (int i = 1; i <= n; ++i)
			cin >> sg[i].id >> sg[i].len >> sg[i].feq;
		sort(sg+1, sg+n+1, cmp);

		cin >> pos;
		cout << sg[pos].id << endl;
	}
}
