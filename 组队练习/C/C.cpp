#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 15;
const double pai = acos(-1);
struct po{
	double h, r;
	bool operator < (const po &x) const{
		return r < x.r;
	}
} pos[maxn];
int cnt, n;
double sum[maxn];
double current(){
	double res = pos[1].r * pos[1].r + pos[n].r * pos[n].r;
	for(int i = 1; i <= n - 1; i++){
		res += fabs(pos[i].r * pos[i].r - pos[i + 1].r * pos[i + 1].r);
	}
	return res * pai;
}

int main(){
	scanf("%d", &cnt);
	while(cnt--){
		scanf("%d", &n);
		double ans = 0.00;
		for(int i = 1; i <= n; i++){
			scanf("%lf %lf", &pos[i].r, &pos[i].h);
			ans += pos[i].r * pos[i].h;
		}
		ans *= (2 * pai);
		double ttt = ans + current();
		sort(pos + 1, pos + n + 1);
		int r = (n / 2);
		int l = r + 1;
		if(!(n & 1)) r--;
		double tem = 0.00;
		for(int i = 1; i <= r; i++) tem -= pos[i].r * pos[i].r;
		for(int i = l; i <= n; i++) tem += pos[i].r * pos[i].r;
		ans += 2.0 * pai * tem;
		printf("%.2lf %.2lf\n", ttt, ans);
	}
	return 0;
}
