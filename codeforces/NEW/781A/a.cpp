#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pk pop_back
#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 4e5+50, maxm = 1e5+50, inf = (int)0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = (ll)1e17;

typedef int arrn[maxn];
typedef ll arrm[maxn];


template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar()) {
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

int n, m, edg;
arrn la, nxt, to, f, col;
set<int> s;
set<int>::iterator itr;

void add_edge(int x, int y) {
	to[++edg] = y, nxt[edg] = la[x], la[x] = edg;
	to[++edg] = x, nxt[edg] = la[y], la[y] = edg;
}

void dfs(int x, int fa) {
	f[x] = fa;
	if ((itr = s.find(col[x])) != s.end()) s.erase(itr);
	if ((itr = s.find(col[f[x]])) != s.end()) s.erase(itr);

	for (int i = la[x]; i; i = nxt[i])
		if (to[i] != f[x]) {
			if (!s.size()) s.insert(++m);
			col[to[i]] = *s.begin();
			s.erase(s.begin());
		}
	for (int i = la[x]; i; i = nxt[i])
		if (to[i] != f[x])
			s.insert(col[to[i]]);	
	s.insert(col[x]);
	if (f[x] != 0) s.insert(col[f[x]]);
	
	for (int i = la[x]; i; i = nxt[i])
		if (to[i] != f[x])
			dfs(to[i], x);
}

int main() {
#ifdef LOCAL
    freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1, u, v; i < n; ++i)
		cin >> u >> v, add_edge(u, v);

	col[1] = ++m, s.insert(1);
	dfs(1, 0);

	cout << m << endl;
	for (int i = 1; i <= n; ++i)
		cout << col[i] << " ";
}

