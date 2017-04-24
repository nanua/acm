#include <bits/stdc++.h>
#define sqr(x) ((x)*(x))
using namespace std;

typedef long double ld;
typedef long long ll;
const int maxn = 1e5 + 10;
const ld eps = 1e-15, pi = acos(-1);;

int n;
ld a[maxn], b[maxn], c[maxn], v[maxn], x[maxn], y[maxn];
ll ans;

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i] >> c[i];
	for (int i = 1; i <= n; ++i)
		x[i] = -c[i]*a[i]/(sqr(a[i])+sqr(b[i])), y[i] = -c[i]*b[i]/(sqr(a[i])+sqr(b[i]));

	for (int i = 1; i <= n; ++i) {
		int sz = 0, cnt = 0;
		for (int j = 1; j <= n; ++j)
			if (i != j) {
				if (fabs(y[j]-y[i]) > eps || fabs(x[j]-x[i]) > eps) {
					v[++sz] = atan2(y[j]-y[i], x[j]-x[i]);
					if (v[sz] <= eps) v[sz] += pi + pi*(fabs(v[sz]+pi)<=eps);
				}
				else cnt++;
			}

		sort(v+1, v+sz+1);

		for (int j = 1, k; j <= sz; j = k) {
			for (k = j; k <= sz && fabs(v[k]-v[j]) <= eps; ++k);
			ans += (k-j+cnt)*(k-j-1+cnt)/2;
		}			
	}

	cout << ans / 3 << endl;
}
