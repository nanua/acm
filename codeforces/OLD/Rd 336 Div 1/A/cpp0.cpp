#include<bits/stdc++.h>
#define fi first
#define se second

using namespace std;

const int maxn = 1e5+10, inf = 0x3f3f3f3f;

typedef pair<int, int> pii;

pii p[maxn];
int ans, n, f[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin >> n, ans = n;
    for (int i = 1; i <= n; ++i) cin >> p[i].fi >> p[i].se;
    sort(p+1, p+n+1);

    for (int i = 1; i <= n; ++i) {
        int j = lower_bound(p+1, p+n+1, pii(p[i].fi-p[i].se, -inf)) - p;
        ans = min(ans, n - i + (f[i] = f[j-1] + i - j));
    }

    cout << ans;
}
