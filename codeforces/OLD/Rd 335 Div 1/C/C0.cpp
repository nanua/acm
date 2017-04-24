#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10, inf = 0x3f3f3f3f;
const double eps = 1e-8;

int n;
double ans = 1e50, p, q, a[maxn], b[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	cin >> n >> p >> q;
	for (int i = 1; i <= n; ++i)	cin >> a[i] >> b[i];

	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j) {
			double D = a[i]*b[j] - a[j]*b[i], D1 = p*b[j] - q*a[j], D2 = a[i]*q - b[i]*p;
			if (fabs(D) < eps || D1 * D < 0 || D2 * D < 0) 
				ans = min(ans, min(max(p/a[i], q/b[i]), max(p/a[j], q/b[j])));
			else
				ans = min(ans, D1/D + D2/D);
		}
	printf("%.15lf", ans);
}
