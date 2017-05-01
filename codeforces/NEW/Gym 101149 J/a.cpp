#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 2e5 + 15;
typedef long long ll;
ll n, a[maxn];

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	ll ans = a[1];
	for(int i = 2; i <= n; i++) if(a[i] > a[i - 1]) ans += (a[i] - a[i - 1]);
	cout << ans;
	return 0;
}
