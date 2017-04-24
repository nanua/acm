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
int T;
char str[maxn], oup[maxn];
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for (scanf("%d\n", &T); T; T--) {
		scanf("%s", str);
		int l = strlen(str), sz = 0;
		for (int i = 0, j, k; i < l; ++i)
			if (isdigit(str[i])) {
				for (j = i-1; j >= 0 && !isalpha(str[j]); --j);
				for (k = 0; k < str[i] - '0'; ++k) oup[sz++] = str[j];
			}
			else oup[sz++] = str[i];
		for (int i = 0; i < sz; ++i) putchar(oup[i]);
		puts("");					
	}
}
