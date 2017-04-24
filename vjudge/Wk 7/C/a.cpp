#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;
ll n, T;
int a[maxn], cnt[2];
ld AnsA, AnsB, AnsC;
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		AnsA = AnsB = AnsC = 0;
		
		for (int d = 0; d <= 30; ++d) {
			ll A = 0, B = 0, C = 0;
			
			for (ll i = 1, j = 1; j <= n && i <= n; i = j+1, j = i) {
				while (j <= n && (a[j] & (1<<d)) != 0) ++j;
				A += (j-i+1)*(j-i) / 2;
			}
			
			for (ll i = 1, j = 1; j <= n && i <= n; i = j+1, j = i) {
				while (j <= n && (a[j] & (1<<d)) == 0) ++j;
				B += (j-i+1)*(j-i) / 2;
			}
			B = n*(n+1)/2 - B;
			
			cnt[0] = 1, cnt[1] = 0;
			for (int i = 1, tag=0; i <= n; ++i){
				tag ^= (a[i]>>d)&1;
				C += cnt[tag^1];
				cnt[tag]++;
			}
			
			AnsA += A * (1<<d), AnsB += B*(1<<d), AnsC += C*(1<<d);			
		}
		AnsA /= n*(n+1)/2.0, AnsB /= n*(n+1)/2.0, AnsC /= n*(n+1)/2.0;
		cout << fixed << setprecision(6)
		     << "Case #" << t << ": " << AnsA << " " << AnsB << " " << AnsC << endl;
	}
} 
