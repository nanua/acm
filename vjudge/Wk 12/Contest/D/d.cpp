#include <cstdlib>
#include <map>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#define re register
using namespace std;

typedef long long ll;
const int maxn = 100000;

ll n,factor[maxn], sel[maxn], cnt[maxn], fsz, csz;

inline ll mul_mod(re ll a,re ll b,re ll p){
	re ll ret = 0;
	for(; b; a = a * 2 % p, b >>= 1) if(b & 1) ret = (ret + a) % p;
	return ret;
}
inline ll pow_mod(re ll a,re ll b,re ll p){
	re ll ret = 1;
	for(; b; a = mul_mod(a,a,p), b >>= 1) if(b & 1) ret = mul_mod(ret,a,p);
	return ret;
}
inline int test(re ll n,re ll a,re ll p){
	if(n == 2 || n == a) return 1;
	if(n % 2 == 0) return 0;
	while(p % 2 == 0) p >>= 1;
	re ll t = pow_mod(a,p,n);
	while(p != n - 1 && t != 1 && t != n - 1) t = mul_mod(t,t,n), p <<= 1;
	return t == n - 1 || p % 2 == 1;
}
inline int miller_rabin(re ll n){
	if(n < 1) return 0;
	re ll a[] = {2, 3, 61};
	for(int i = 0; i <= 2; ++i) if(!test(n,a[i],n-1)) return 0;
	return 1;
}
inline ll gcd(re ll a, re ll b){ return !b ? a : gcd(b, a % b); }
inline ll pollard_rho(re ll n,re ll c){
	re ll x,y,i,k,g;
	x = y = rand() % (n-1) + 1;
	for(i = k = 2; ; ++i){
		x = (mul_mod(x,x,n) + c) % n;
		if((g = gcd(y - x + n, n)) != 1) return g;
		if(x == y) return n;
		if(i == k) k <<= 1, y = x;
	}
}
inline void fact(re ll n,re ll c){
	if(n == 1) return;
	if(miller_rabin(n))
		return void(factor[++fsz] = n);
	re ll p = n;
	while(p >= n) p = pollard_rho(p,c--);
	fact(p, c); fact(n / p, c);
}
ll calc(int d) {
	if (d == csz+1) {
		re ll ret = 1;
		for (re int i = 1; i <= csz; ++i) ret *= sel[i] + 1;
		return ret*ret*ret;
	}
	re ll ret = 0;
	for (int i = 0; i <= cnt[d]; ++i)
		sel[d] = i, ret += calc(d+1);
	return ret;
}
int main() {
	int T; cin >> T;
	while(T--){
		cin >> n;
		csz = fsz = 0;
		fact(n,107);
		sort(factor+1, factor+fsz+1);
		for (int i = 1, las = 0; i <= fsz; ++i)
			if (factor[i] == las) cnt[csz]++;
			else cnt[++csz] = 1, las = factor[i];
		cout << calc(1) << endl;
	}
}
