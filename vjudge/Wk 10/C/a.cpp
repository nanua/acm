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
int n;
char str[20][20], res[20][20];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while(scanf("%d\n", &n) != EOF) {
		memset(str, 0, sizeof(str));
		memset(res, 0, sizeof(res));
		for (int i = 1; i <= n; ++i) scanf("%s\n", str[i] + 1);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) {
				int cnt = 0;
				for (int k = -1; k <= 1; k++)
					for (int l = -1; l <= 1; l++)
						if (k != 0 || l != 0)
							cnt += (str[i+k][j+l] == '+');
				if (str[i][j] == '+')
					res[i][j] = ((cnt <= 1 || cnt > 3) ? '-' : '+');
				else
					res[i][j] = ((cnt == 3) ? '+' : '-'); 
			}
		for (int i = 1; i <= n; ++i) puts(res[i]+1);
	}
}
 
