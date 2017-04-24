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
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

pair<ld, ld> p[5];
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (cin >> p[1].x >> p[1].y >> p[2].x >> p[2].y >> p[3].x >> p[3].y >> p[4].x >> p[4].y) {
		if (p[1] == p[3] || p[1] == p[4]) swap(p[1], p[2]);
		if (p[1] == p[4] || p[2] == p[4]) swap(p[3], p[4]);
		cout << fixed << setprecision(3) << p[2].x+(p[1].x-p[2].x)+(p[4].x-p[3].x) << " " << p[2].y+(p[1].y-p[2].y)+(p[4].y-p[3].y) << endl;
	}
}
