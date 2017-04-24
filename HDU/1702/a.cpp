#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <cctype>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
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

stack<int> stk;
queue<int> que;
int n, T;
char op[10];

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	
	for (scanf("%d\n", &T); T; T--) {
		gint(n), scanf("%s", op);
		if (op[2] == 'L') {
			while (stk.size()) stk.pop();
			
			for (int i = 1, x; i <= n; ++i) {
				scanf("%s", op);
				if (op[0] == 'I')
					gint(x), stk.push(x);
				else
					if (stk.size())
						printf("%d\n", stk.top()), stk.pop();
					else puts("None");
			}
		}
		else {
			while (que.size()) que.pop();
			
			for (int i = 1, x; i <= n; ++i) {
				scanf("%s", op);
				if (op[0] == 'I')
					gint(x), que.push(x);
				else
					if (que.size())
						printf("%d\n", que.front()), que.pop();
					else puts("None");
			}			
		}
	}
}
 
