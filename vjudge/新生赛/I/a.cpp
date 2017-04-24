#include<bits/stdc++.h>
using namespace std;

long double eps = 1e-25, pi = acos(-1);
long double p[10][3], q[10][3], a, b, c, d, angp[10], angq[10];

bool check() {
	if (p[1][0] * p[3][0] < 0 && p[3][1] * p[4][1] < 0) return 1;
	if (q[1][0] * q[3][0] < 0 && q[3][1] * q[4][1] < 0) return 1;

	for (int i = 1; i <= 4; ++i) angp[i] = atan2(p[i][1], p[i][0]);
	for (int i = 1; i <= 4; ++i) angq[i] = atan2(q[i][1], q[i][0]);

	sort(angp+1, angp+5), sort(angq+1, angq+5);

	for (int i = 5; i <= 8; ++i) angp[i] = angp[i-4] + pi*2;
	for (int i = 5; i <= 8; ++i) angq[i] = angq[i-4] + pi*2;

	for (int i = 1; i < 8; ++i)
		for (int j = 1; j < 8; ++j)
			if (angp[i+1] - angp[i] <= pi && angq[j+1] - angq[j] <= pi)
				if ((angp[i]-angq[j] >= -eps && angq[j+1] - angp[i] >= -eps) ||
				    (angq[j]-angp[i] >= -eps && angp[i+1] - angq[j] >= -eps)) return 1;

	return 0;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> a >> b >> c >> d;

	long double l = 0, r = 1e10, mid, ans;
	for (int i = 1; i <= 10000; ++i){
		mid = (l + r) / 2;
		p[1][0] = p[2][0] = a-mid;
		p[1][1] = p[3][1] = b-mid;
		p[3][0] = p[4][0] = a+mid;
		p[2][1] = p[4][1] = b+mid;

		q[1][0] = q[2][0] = c-mid;
		q[1][1] = q[3][1] = d-mid;
		q[3][0] = q[4][0] = c+mid;
		q[2][1] = q[4][1] = d+mid;

		bool ch = check();

		q[1][0] *= -1, q[1][1] *= -1;
		q[2][0] *= -1, q[2][1] *= -1;
		q[3][0] *= -1, q[3][1] *= -1;
		q[4][0] *= -1, q[4][1] *= -1;

		ch |= check();
		if (ch)
			ans = mid, r = mid;
		else
			l = mid;
		//cerr << l << " " << r << endl;
	}
	cout << fixed << setprecision(10) << ans;
}
