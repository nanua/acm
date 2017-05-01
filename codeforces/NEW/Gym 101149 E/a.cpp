
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 5e5+50, maxm = 1e5+50;
const int inf = 0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int n, sz, ans;
int v[maxn];
int l[maxn], r[maxn], cnt[maxn], vis[maxn];
map<int, int> m;

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> l[i] >> r[i], v[++sz] = l[i]-1, v[++sz] = r[i];
	sort(v+1, v+sz+1), sz = unique(v+1, v+sz+1) - v - 1;
	for (int i = 1; i <= sz; ++i) m[v[i]] = i;
	for (int i = 1; i <= n; ++i)
		cnt[m[l[i]-1]]--, cnt[m[r[i]]]++, vis[m[l[i]-1]] = 1;
	for (int i = sz; i >= 1 && vis[i] == 0; --i)
		ans = max(ans, cnt[i] += cnt[i+1]);
	cout << ans << endl;
}
