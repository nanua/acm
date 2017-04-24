#include <bits/stdc++.h>
using namespace std;

#define clr(x, y) memset(x, y, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(y))
#define all(x) x.begin(), x.end()
#define sqr(x) ((x) * (x))
#define sz(x) ((LL)x.size())

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

int s, x1, x2, t1, t2, p, d;
int calc(int x) {
	int t_ig = abs(x1-x)*t2, t_tr = abs(p-x)*t1, td = d;
	
	if ((x < p && d == 1) || (x > p && d == -1))
		td = -d, t_tr += d == -1 ? p*2*t1 : (s-p)*2*t1;

	while (t_tr < t_ig)
		t_tr += td == -1 ? x*2*t1 : (s-x)*2*t1, td = -td;
	t_tr += abs(x-x2)*t1;
	if ((x2 < x && td == 1) || (x2 > x && td == -1))
		t_tr += td == -1 ? x*2*t1 : (s-x)*2*t1;
	return t_tr;		
}

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> s >> x1 >> x2; //cord from to
	cin >> t1 >> t2; //tram igor
	cin >> p >> d; //pos dir

	int ans = abs(x1-x2)*t2;

	for (int i = 0; i <= s; ++i)
		ans = min(ans, calc(i));

	cout << ans;
}
 
