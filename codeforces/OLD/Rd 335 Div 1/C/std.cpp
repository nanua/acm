#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
#define N 100100
#define rep(x, a, b) for(int x=a; x<=b; x++)
int n, tx, m, ty, h[N], U, R;
struct point{
	double x, y;
	point(){}
	point(double _, double __):x(_),y(__){}
	void read(){ scanf("%lf%lf", &x, &y); }
	point operator + (point b) { return point(x+b.x, y+b.y); }
	point operator - (point b) { return point(x-b.x, y-b.y); }
	point operator * (double b) { return point(x*b, y*b); }
	double operator * (point b) { return 1ll*x*b.y-1ll*y*b.x; }
	bool operator < (const point &rhs) const { return x<rhs.x || (x==rhs.x && y<rhs.y); }
}p[N], u[N];
int main(){
	freopen("in.in","r",stdin);
	freopen("std.out","w",stdout);
	
	scanf("%d%d%d", &n, &tx, &ty);
	rep(i, 1, n) p[i].read();
	sort(p+1, p+n+1);
	h[m=1]=1;
	rep(i, 2, n)
	{
		while(m>1 && (p[h[m]]-p[h[m-1]])*(p[i]-p[h[m]])>=0) m--;
		h[++m]=i;
	}
	int mx;
	mx=0; rep(i, 1, m) if(p[h[i]].y>mx) mx=p[h[i]].y, U=i;
	mx=0; rep(i, 1, m) if(p[h[i]].x>mx) mx=p[h[i]].x, R=i;
	u[1]=point(0, p[h[U]].y);
	rep(i, U, R) u[i-U+2]=p[h[i]];
	u[R-U+3]=point(p[h[R]].x, 0);
	double ang=atan2(ty, tx);
	rep(i, 2, R-U+3)
		if(ang>=atan2(u[i].y, u[i].x) && ang<=atan2(u[i-1].y, u[i-1].x))
		{
			point p1=point(0,0), v1=point(tx, ty);
			point p2=u[i-1], v2=u[i]-u[i-1];
			double k2=(p1-p2)*v1/(v2*v1);
			point isc=p2+v2*k2;
			printf("%.15lf\n", sqrt(1.*tx*tx+1.*ty*ty)/sqrt(isc.x*isc.x+isc.y*isc.y));
			break;
		}
}
