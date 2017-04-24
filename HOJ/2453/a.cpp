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

int n, r, e, c;
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> r >> e >> c, e -= c;
		if (r == e) puts("does not matter");
		else puts(r > e ? "do not advertise" : "advertise");
	}
	
}
 
