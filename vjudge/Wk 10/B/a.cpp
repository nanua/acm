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
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;
int n, a[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	int flag = 1;
	while (scanf("%d",&n) != EOF) {
		// if (!flag) puts("");
		// flag = 0;
		for (int i = 1, t; i <= n; ++i) scanf("%d",&t), a[t] = i;
		for (int i = 1; i <= n; ++i) {
			printf("%d", a[i]);
			if (i != n) printf(" ");
		}
		puts("");
	}
}
 
