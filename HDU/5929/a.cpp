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

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

const ld eps = 1e-12, pi = acos(-1);
const int maxn = 2e5+50, maxm = 1e5+50, inf = (int)0x3f3f3f3f, mod = (int)1e9 + 7, sigma = 129;
const ll INF = (ll)1e17;

typedef int arrn[maxn];
typedef int arrm[maxm];


template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar()) {
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

int n, T, d, a, kase;
char op[20];

struct node {
	int v, _fwd, _bwd;

	node(int _v, int __fwd, int __bwd) {
		v = _v;
		if (d == 1) _fwd = __fwd, _bwd = __bwd;
		else _fwd = __bwd, _bwd = __fwd;
	}

	int &fwd() { return (d == 1) ? _fwd : _bwd; }
	int &bwd() { return (d == 1) ? _bwd : _fwd; }
};
struct Que {
	deque<node> q;
	deque<node>::iterator itr;

	Que() { itr = q.end(); }
	node &front() { return d == 1 ? q.front() : q.back(); }
	node &back() { return d == 1 ? q.back() : q.front(); }
	
	void push_back(int v) {
		node tmp = node(v, (v ? (sz(q) ? back().fwd()+1 : 1) : 1), 1);
		bool flag = (!sz(q) || back().v == 0);

		if (d == 1) q.push_back(tmp); else q.push_front(tmp);
		if (flag && tmp.v == 1) itr = (d == 1) ? (--q.end()) : q.begin();
		if (tmp.v == 1) itr->bwd()++; 
		else if (itr != q.end()) itr->bwd()++, itr = q.end();
		
	}
	void pop_back() {
		node tmp = back();
		if (d == 1) q.pop_back(); else q.pop_front();
		if (sz(q) && back().v == 1) back().bwd() = tmp.bwd() - 1;
	}

	int nand() {
		int t = back().fwd();
		if (t == sz(q) && front().v == 0) t--;
		return t & 1;
	}
}Qu;

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	
	for (scanf("%d\n", &T); T; T--) {
		gint(n);
		d = 1;
		printf("Case #%d:\n",++kase);
		
		for (int i = 1; i <= n; ++i) {
			scanf("%s", op);
			switch(op[2]) {
			case 'S':
				scanf("%d",&a);
				Qu.push_back(a);
				break;
			case 'P':
				Qu.pop_back();
				break;
			case 'V':
				d *= -1;
				break;
			case 'E':
				if (sz(Qu.q) == 0) puts("Invalid.");
				else printf("%d\n", Qu.nand());
				break;
			}
		}
	}

}

