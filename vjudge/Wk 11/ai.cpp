#include <bits/stdc++.h>
using namespace std;

inline bool inbound(int x, int y) {
	return (1 <= x && x <= 19) && (1 <= y && y <= 19);
}
void extend(int a, int b, int det) {
	for (int i = a-2; i <= a+2; ++i)
		for (int j = b-2; j <= b+2; ++j)
			if (inbound(i, j)) link[i][j] += det;				
}
ld curval() {
	int cnt[3] = {};
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			
}
ld dfs(int d, int x, int y, int t) {

	v[d][0] = 0;
	for (int i = 1; i <= n)
		for (int j = 1; j <= n; ++j)
			if (link[i][j] && !board[i][j]) {
				board[i][j] = t;
				v[d][++v[d][0]] += tpi(curval(), i, j);
				board[i][j] = 0;
			}
	sort(v[d]+1, v[d]+v[d][0]+1, greater<tpi>());
	ld res = 0, t;
	
	for (int i = 1; i <= v[d][0]; ++i) {
		if (fabs(v[d][i]) == inf) return v[d][i];
		int x = v[d][i].se.fi, y = v[d][i].se.se;
		extend(x, y, 1);
		if (fabs(t = dfs(d+1, x, y, -t)) == inf) return extend(x, y, -1), -t;
		extend(x, y, -1);
		res += t;		
	}
	return ld(res) / v[d][0];
}
int main() {
	while (cin >> a >> b, a != -1) {
		board[a][b] = -1;
		
		extend(a, b, 1);
		
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if (maxscore < (t = dfs(0, i, j, 1)))
					maxscore = t, ansI = i, ansJ = j;
		
		cout << ansI << " " << ansJ << endl;
	}				    
}
