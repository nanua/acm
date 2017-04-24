#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int p, a, b;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for (cin >> p; p; p--)
		cin >> a >> b, puts(a < b ? "NO BRAINS" : "MMM BRAINS");
}
