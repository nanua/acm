#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

typedef long long ll;
typedef int arr[maxn];

int n, q, sz;
arr p, dif, lef, rig, stk;

ll calc(int l, int r) {	
	sz = 0;
	for (int i = l; i < r; ++i){
		for (; sz && dif[stk[sz]] < dif[i]; sz--);
		lef[i] = !sz ? l-1 : stk[sz];
		stk[++sz] = i;
	}
	sz = 0;
	for (int i = r-1; i >= l; --i) {
		for (; sz && dif[stk[sz]] <= dif[i]; sz--);
		rig[i] = !sz ? r : stk[sz];
		stk[++sz] = i;
	}
	ll ret = 0;
	for (int i = l; i < r; ++i)
		ret += (ll)dif[i] * (i-lef[i]) * (rig[i]-i);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
#endif

	scanf("%d %d", &n, &q);

	for (int i = 1; i <= n; ++i) scanf("%d",&p[i]);
	for (int i = 1; i < n; ++i) dif[i] = abs(p[i+1] - p[i]);
	
	for (int l, r, i = 1; i <= q; ++i)
		scanf("%d %d", &l, &r), printf("%lld\n",calc(l, r));	
}
