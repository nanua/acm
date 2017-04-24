#include<bits/stdc++.h>
#define fi first
#define se second
#define p pos[i]
using namespace std;

const int maxn = 1e5+10, inf = 0x3f3f3f3f;
typedef pair<int, int> pii;

int v[maxn], in[maxn], pos[maxn];
int n, m, cnt;
pii edg[maxn], tmp[maxn];
priority_queue<pii> q;

int cmp(int x, int y) {
	return v[x] < v[y] || (v[x] == v[y] && in[x] > in[y]);
}
void try_push(pii x) {
	if (x.se > 0) q.push(x);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
		cin >> v[i] >> in[i], pos[i] = i;
	sort(pos+1, pos+m+1, cmp);
	for (int i = 1; i <= m; ++i) {
		if (in[p])
			tmp[i] = pii(n,++cnt), try_push(pii(cnt, cnt-1));
		else if (q.size())
			tmp[i] = q.top(), q.pop(), try_push(pii(tmp[i].fi, tmp[i].se-1));
		else
			puts("-1"), exit(0);
		edg[p] = tmp[i];
	}
	for (int i = 1; i <= m; ++i) cout << edg[i].fi << " " << edg[i].se << endl;
			
}
