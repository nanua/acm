#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 4e5+50, maxm = 1e5+50;
const int inf = 0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;

typedef int arrn[maxn];
typedef ll arrm[maxn];


template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar()){
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

int edg;
int to[maxn], wt[maxn], nt[maxn], la[maxn];
int T, n;
int x[maxn], y[maxn], id[maxn];

void add_edge(int x, int y, int w) {
	to[++edg] = y, wt[edg] = w, nt[edg] = la[x], la[x] = edg;
	to[++edg] = x, wt[edg] = w, nt[edg] = la[y], la[y] = edg;
}

int spfa(int s, int t) {
	static int q[maxn*5], d[maxn], vis[maxn];
	int hr = 0, tl = 0;
	
	memset(d, 0x3f, sizeof(d));
	memset(vis, 0, sizeof(vis));
	
	d[q[++tl] = s] = 0;
	
	while (hr < tl) {
		int x = q[++hr];
		vis[x] = 0;
		for (int i = la[x]; i; i = nt[i])
			if (d[to[i]] > d[x] + wt[i]) {
				d[to[i]] = d[x] + wt[i];
				if (vis[to[i]] == 0) vis[q[++tl] = to[i]] = 1;
			}
	}

	return d[t];	
}

bool cmp1(int l, int r) {
	return x[l] < x[r];
}
bool cmp2(int l, int r) {
	return y[l] < y[r];
}

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

	for (scanf("%d\n", &T); T; T--)	{
		gint(n);
		edg = 0;
		
		for (int i = 1; i <= n; ++i)
			gint(x[i]), gint(y[i]), id[i] = i, la[i] = 0;

		sort(id+1, id+n+1, cmp1);
		for (int i = 2; i <= n; ++i) add_edge(id[i], id[i-1], x[id[i]] - x[id[i-1]]);
		sort(id+1, id+n+1, cmp2);
		for (int i = 2; i <= n; ++i) add_edge(id[i], id[i-1], y[id[i]] - y[id[i-1]]);

		printf("%d\n",spfa(1, n));
	}

}
 
