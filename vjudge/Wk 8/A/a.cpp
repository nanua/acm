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

typedef unsigned long long ull;
const int maxn = 30, inf = 0x3f3f3f3f, mod = 1e9 + 7;

ull x[30], vis[30], a[30][30], c[30][30], tot, win;
int T, p, n, m;

ull gcd(ull x, ull y) {
	return !y ? x : gcd(y, x%y);
}

void dfs(int A, int B, int draw, int dam) {
	if (dam >= p) {
		win += c[A][A+B] * a[B][B];
		return;
	}
	if (draw == 0) return;
	if (A >= 1) dfs(A-1, B, draw+1, dam);
	for (int i = 1; i <= m; ++i)
		if (!vis[i]) {
			vis[i] = 1;
			dfs(A, B-1, draw-1, dam+x[i]);
			vis[i] = 0;
		}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for (int i = 0; i <= 20; ++i)
		for (int j = i; j <= 20; ++j) {
			a[i][j] = 1;
			for (int k = j; k > j-i; --k) a[i][j] *= k;
			c[i][j] = a[i][j];
			for (int k = 1; k <= i; ++k) c[i][j] /= k;
		}
	
	for (cin >> T; T; T--) {
		cin >> p >> n >> m;
		for (int i = 1; i <= m; ++i) cin >> x[i];
		tot = c[n][n+m] * a[m][m];
		win = 0;
		dfs(n, m, 1, 0); //depth, Acard, Bcard, draw
		if (win == 0) tot = 1;
		ull g = gcd(win, tot);
		win /= g, tot /= g;
		cout << win << "/" << tot << endl;
	}	
} 
