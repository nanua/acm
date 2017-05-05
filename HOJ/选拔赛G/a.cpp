 #include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 2e5+50, maxm = 1e5+50;
const int inf = 0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;

typedef int arrn[maxn];
typedef ll arrm[maxn];


template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar()){
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}


ll pmod(ll x, ll e, ll ret = 1) {
	for (; e; e >>= 1, x = x * x % mod)
		if (e & 1) ret = ret * x % mod;
	return ret;
}

int T;
ll a, b;

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
   
	for (scanf("%d\n", &T); T; T--) {
		gint(a), gint(b);
		ll x = pmod(2, a)-1, y = pmod(2, b)-1;
		ll z = pmod(pmod(2, __gcd(a, b)) - 1, mod-2);

		cout << (x * y % mod * z % mod + mod) % mod << endl;
	}

}
