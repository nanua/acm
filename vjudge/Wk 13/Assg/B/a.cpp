#include <bits/stdc++.h>
using namespace std;

string mps[120];
int T, h, w;

void dfs(int x, int y) {
	if (x < 0 || y < 0 || x >= h || y >= w || mps[x][y] == '.') return;
	
	mps[x][y] = '.';
	dfs(x+1, y);
	dfs(x-1, y);
	dfs(x, y+1);
	dfs(x, y-1);
}
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for (cin >> T; T; T--) {
		cin >> h >> w;
		for (int i = 0; i < h; ++i) cin >> mps[i];

		int cnt = 0;
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < mps[i].size(); ++j)
				if (mps[i][j] == '#')
					cnt++, dfs(i, j);
		cout << cnt << endl;
	} 
}
