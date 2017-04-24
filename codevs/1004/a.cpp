#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

struct D{
	char p[6][6];
	pii a[2];
}
void bfs() {
	queue<D> q;
	q.push_back(st);
	while (q.size()) {
		D x = q.front(); q.pop();
		
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j <= 1; ++j) {
				D y = x.nxt(i, j);
				if ()
			}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

	for (int i = 1, t = 0; i <= sz; ++i)
		for (int j = 1; j <= sz; ++j) {
			cin >> st.p[i][j];
			if (st.p[i][j] == 'O') st.a[t++] = pii(i, j);
		}
	bfs();

	cout << ans;
}
