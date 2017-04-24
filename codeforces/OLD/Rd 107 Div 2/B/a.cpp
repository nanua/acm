#include <bits/stdc++.h>
using namespace std;

#define clr(x, y) memset(x, y, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(y))
#define all(x) x.begin(), x.end()
#define sqr(x) ((x) * (x))
#define sz(x) ((ll)x.size())

#define mk make_pair
#define pb push_back
#define pk pop_back
#define fi first
#define se second

#define add_edge(x, y) (to[++edg] = y, nt[edg] = la[x], la[x] = edg)
#define add_wedge(x, y, w) (to[++edg] = y, wgt[edg] = w, nt[edg] = la[x], la[x] = edg)
#define lowbit(x) ((x) & (-x))

typedef int lint;
typedef long long ll;
typedef long double ld;

typedef map <lint, lint> mii;
typedef pair <lint, lint> pii;
typedef set <lint> sint;
typedef vector <lint> vint;

const ld eps = 1e-12, pi = acos(-1);
const lint maxn = 2e5+50, maxm = 1e5+50, inf = (lint)0x3f3f3f3f, mod = (lint)1e9 + 7, sigma = 129;
const ll INF = (ll)1e17;

typedef lint arrn[maxn];
typedef lint arrm[maxm];


template<class Q> void gint(Q &ret, char ch = getchar()) {
	while (!isdigit(ch)) ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
}

int typ(string s) {
	if (s[0] == s[1] && s[1] == s[3] && s[3] == s[4]
	    && s[4] == s[6] && s[6] == s[7]) return 1;
	
	if (s[0] > s[1] && s[1] > s[3] && s[3] > s[4]
	    && s[4] > s[6] && s[6] > s[7]) return 2;
	return 3;
}
int n;
string s[maxn];
int p[4][maxn];
vector<string> v[4];
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1, t; i <= n; ++i) {
		cin >> t >> s[i];
		string cell;
		for (int j = 1; j <= t; ++j)
			cin >> cell, p[typ(cell)][i]++;
	}

	int Max[3];
	for (int i = 1; i <= 3; ++i) Max[i] = *max_element(p[i]+1, p[i]+n+1);

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= 3; ++j)
			if (p[j][i] == Max[j]) v[j].pb(s[i]);

	cout << "If you want to call a taxi, you should call: ";
	for (int i = 0; i < sz(v[1]); ++i) cout << v[1][i] << (i == sz(v[1])-1 ? ".\n" : ", ");
	cout << "If you want to order a pizza, you should call: ";
	for (int i = 0; i < sz(v[2]); ++i) cout << v[2][i] << (i == sz(v[2])-1 ? ".\n" : ", ");
	cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
	for (int i = 0; i < sz(v[3]); ++i) cout << v[3][i] << (i == sz(v[3])-1 ? ".\n" : ", ");
}
 
