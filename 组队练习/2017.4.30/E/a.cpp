#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 2e6+50, maxm = 1e5+50;
const int inf = 0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int T, n, sz;
int phi[maxn], p[maxn], vis[maxn];
ll sum[maxn];;

void get(int mx){
	for(int i = 2; i <= mx; ++i){
		if(!vis[i])
			p[++sz] = i, phi[i] = i-1;
		for(int j = 1, k = p[j]*i; j <= sz && k <= mx; ++j, k = p[j]*i){
			vis[k] = 1;
			phi[k] = phi[i] * (i % p[j] ? p[j] - 1 : p[j]);
		}
	}
}

int main() {
	get(int(1e6+10));
	for (int i = 1; i <= 1e6+10; ++i) sum[i] = (sum[i-1] + phi[i]) % mod;
	
	for (scanf("%d\n", &T); T; T--)
	{
		scanf("%d",&n);
		if (n < 0) cout << 0 << endl;
		else cout << sum[n] << endl;
	}

}
