#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 15;
struct po{
	int a, b, c;
	bool operator > (const po &x) const {
		return (a > x.a&& b > x.b)|| (b > x.b&& c > x.c)|| (a > x.a&& c > x.c);
	}
} pos[maxn];
int n;

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d %d %d", &pos[i].a, &pos[i].b, &pos[i].c);
	int Low = 1;
	for(int i = 2; i <= n; i++) if(pos[Low] > pos[i]) Low = i;
	bool isLow = true;
	for(int i = 1; i <= n; i++){
		if(Low == i) continue;
		if(pos[Low] > pos[i]){
			isLow = false;
			break;
		}
	}
	if(isLow) printf("1\n%d\n", Low);
	else printf("0\n");
	return 0;
}
