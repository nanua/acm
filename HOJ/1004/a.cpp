#include <map>
#include <set>
#include <queue>
#include <iomanip>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int v[maxn], d[20];
int vsz, l, r;
inline ll add_mod(ll x, ll y, ll p){
	return (((ll)x + (ll)y) % p + p) % p;
}
inline ll mul_mod(ll x, ll y, ll p){
	return add_mod(x*y, -(int)((double)x*y/p) * p, p);
}
inline ll pow_mod(ll x, ll p, ll e){
	ll r = 1;
	for(; e; e >>= 1, x = x * x % p) if(e & 1) r = r * x % p;
	return r;
}
inline ll test(ll n,ll a,ll p){
	if(n == 2 || n == a) return 1;
	if(n % 2 == 0) return 0;
	while(p % 2 == 0) p >>= 1;
	ll t = pow_mod(a, n, p);
	while(p != n - 1 && t != 1 && t != n - 1)
		t = mul_mod(t, t, n), p <<= 1;
	return t == n - 1 || p % 2 == 1;
}
inline bool Miller_Rabin(int n) {
	if(n <= 1) return 0;
	int a[] = {2, 3, 5, 7, 29, 61};
	for(int i = 0; i <= 5; ++i) if(!test(n,a[i],n-1)) return 0;
	return 1;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for (int i = 1, j, sz; i < int(1e6); ++i) {
		ll x = i, y =i;
		for (sz = 0, j = i; j; j /= 10) d[++sz] = j % 10;
		for (j = 1; j <= sz; ++j) x = x * 10 + d[j];
		for (j = 2; j <= sz; ++j) y = y * 10 + d[j];
			
		if (x <= 1e9 && Miller_Rabin(x)) v[++vsz] = x;
		if (y <= 1e9 && Miller_Rabin(y)) v[++vsz] = y;
	}
	sort(v+1, v+vsz+1);
	cerr << vsz;
	cin >> l >> r;
	for (int i = 1; i <= vsz; ++i)
		if (l <= v[i] && v[i] <= r) cout << v[i] << endl;
	
}

