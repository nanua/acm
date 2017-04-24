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
const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2}, dy[] = {1, -1, 2, -2, 2, -2, 1, -1};

string s1, s2;
int f[10][10], X1, X2, Y1, Y2;

void dfs(int x, int y, int d) {
	if (f[x][y] <= d || min(x, y) < 1 || max(x, y) > 8) return;
	f[x][y] = d;
	for (int i = 0; i < 8; ++i)
		dfs(x+dx[i], y+dy[i], d+1);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (cin >> s1 >> s2) {
		X1 = s1[0]-'a'+1, Y1 = s1[1]-'0';
		X2 = s2[0]-'a'+1, Y2 = s2[1]-'0';
		memset(f,0x3f,sizeof(f));
		dfs(X1,Y1,0);
		printf("To get from %s to %s takes %d knight moves.\n",s1.c_str(), s2.c_str(), f[X2][Y2]);
	}
}
