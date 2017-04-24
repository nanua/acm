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
	for (scanf("%d\n",&T); T; T--) {
		scanf("%s", str);		
		int i , j, l = strlen(str);
		for (i = 0, j = 0; i < l; i++)
			switch (str[i]) {
			case '#': j -= min(1, j); break;
			case '@': j = 0; break;
			default : oup[j++] = str[i]; break;
			}
		for (i = 0; i < j; ++i) putchar(oup[i]);
		puts("");
	}
}
