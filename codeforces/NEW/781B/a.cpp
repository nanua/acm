#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pk pop_back
#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 4e6+50, maxm = 1e5+50, inf = (int)0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = (ll)1e17;

typedef int arrn[maxn];
typedef ll arrm[maxn];


template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar()) {
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

int n, cnt, edg;
string nm, hm, name[maxn][2];
int node[1010][2], def[1010], tmp[1010];;
arrn la, nt, to;

void add_edge(int x, int y) {
	to[++edg] = y, nt[edg] = la[x], la[x] = edg;
}

bool dfs(int x) {
	if (def[(x+1)/2] != -1)
		return def[(x+1)/2] == ((x-1)&1);

	def[(x+1)/2] = (x-1)&1;

	for (int i = la[x], ret; i; i = nt[i])
		if ((ret = dfs(to[i])) == false)
			return 0;

	return 1;
}
bool DFS(int x) {
	memcpy(tmp, def, sizeof(def));
	int ret = dfs(x);
	if (!ret)
		memcpy(def, tmp, sizeof(def));
	return ret;
}
int main() {
#ifdef LOCAL
    freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> nm >> hm;
		name[i][0] = nm.substr(0, 3);
		name[i][1] = nm.substr(0, 2) + hm.substr(0, 1);
		node[i][0] = ++cnt, node[i][1] = ++cnt;
	}

	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			for (int x = 0; x <= 1; ++x)
				for (int y = 0; y <= 1; ++y)
					if (name[i][x] == name[j][y]) {
						if (x == 0 && y == 0) {
							add_edge(node[i][x^1], node[j][y^1]);
							add_edge(node[j][y^1], node[i][x^1]);
							add_edge(node[i][x], node[i][x^1]);
							add_edge(node[j][y], node[j][y^1]);
						}
						else {
							add_edge(node[i][x], node[j][y^1]);
							add_edge(node[j][y], node[i][x^1]);
						}
					}

	fill(def+1, def+n+1, -1);
	for (int i = 1; i <= n; ++i)
		if (def[i] == -1)
			if (DFS(node[i][0]) == false && DFS(node[i][1]) == false)
				puts("NO"), exit(0);

	puts("YES");
	for (int i = 1; i <= n; ++i)
		cout << name[i][def[i]] << endl;
}

