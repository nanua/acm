#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int tests = 105;
const double length = 1e9;
const int maxn = 50000 + 50;
pair<double, double> home[maxn];
int n, cnt;
double ans;
int judge(double dis);

int main()
{
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("c.out","w",stdout);
#endif
	while(scanf("%d", &n), n)
		{
			for(int i = 1; i <= n; i++) 
				scanf("%lf %lf", &home[i].first, &home[i].second);
			//home[i].second = fabs(home[i].second);
			double l = 0, r = length, m;
			cnt = tests;
			while(cnt--)
				{
					m = (l + r) / 2.0;
					if(judge(m)) r = m;
					else l = m;
				}
			printf("%.9lf %.9lf\n", ans, m);
			//memset(home, 0, sizeof(home));
		}
	return 0;
}

int judge(double dis)
{
	double lmax = -length, rmin = length;
	for(int i = 1; i <= n; i++)
		{
			double u = pow(dis, 2) - pow(home[i].second, 2);
			if(u < 0) return 0;
			double q = sqrt(u);
			double l2 = home[i].first - q;
			double r2 = home[i].first + q;
			lmax = max(lmax, l2);
			rmin = min(rmin, r2);
		}
	if(lmax <= rmin)
		{
			ans = (lmax + rmin) / 2.0;
			return 1;
		}
	else return 0;
}
