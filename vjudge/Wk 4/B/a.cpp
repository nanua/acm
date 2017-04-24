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
#define lowbit(x) (x & -x)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int maxn = 2e6 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7, inv4 = 250000002;

int l, r[maxn], m[maxn];
ll lx[maxn], rx[maxn], cntl[maxn], cntr[maxn], ans;
char str[maxn];
void manacher(char s[], int L) {
	memset(r, 0, sizeof(r));
	m[++l] = '#';
	for (int i = 0; i < L; ++i) m[++l] = s[i], m[++l] = '#';
	for (int i = 1, j = 0, k; i < l; i += k) {
		while (i-j-1 >= 1 && i+j+1 <= l && m[i-j-1] == m[i+j+1]) j++;
		r[i] = j;
		for (k = 1; k <= r[i] && r[i] != r[i-k]+k; ++k)
			r[i+k] = min(r[i-k], r[i]-k);
		j = max(j-k, 0);
	}
	for (int i = 1; i <= l; ++i) r[i]++;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while(scanf("%s\n",str) != EOF) {
		l = 0;
		manacher(str, strlen(str));
		for (int i = 0; i <= l+1; ++i) cntl[i] = cntr[i] = lx[i] = rx[i] = 0;
		
		for (int i = 1; i <= l; ++i) {
			cntl[i]++, cntl[i+r[i]-1]--, lx[i] += 2*i, lx[i+r[i]-1] -= 2*i;
			cntr[i-r[i]]++, cntr[i-1]--, rx[i-r[i]] += 2*i-2, rx[i-1] -= 2*i-2;
		}
		for (int i = 1; i <= l; ++i) {			
			(cntl[i] += cntl[i-1]) %= mod, (cntr[i] += cntr[i-1]) %= mod;
			(lx[i] += lx[i-1]) %= mod, (rx[i] += rx[i-1]) %= mod;			
		}		
		ans = 0;
		for (int i = 1; i <= l; ++i)
			if (m[i] != '#')
				ans = (ans + inv4*(lx[i]-cntl[i]*i%mod)%mod*(rx[i]-cntr[i]*i%mod)%mod) % mod;

		cout << (ans%mod+mod)%mod << endl;
	}
}
