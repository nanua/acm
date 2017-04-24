#include <map>
#include <set>
#include <queue>
#include <cmath>
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

char str[maxn];
int n;
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	scanf("%d\n",&n);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", str);
		int n = strlen(str);
		reverse(str, str+n);
		printf("%s\n", str);
	}
}
 
