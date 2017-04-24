#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int maxn = 2e6, inf = 0x3f3f3f3f;

bool seive[maxn+10];
int fwd[maxn+10], prime[maxn+10], factor[maxn+10];
int k, sz;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	memset(seive, 1, sizeof(seive));
	for (int i = 2; i <= maxn; ++i) {
		if (seive[i]) fwd[i] = prime[++sz] = i;
		for (int j = 1; j <= maxn && (long long)i * prime[j] <= maxn; ++j) {
			seive[i*prime[j]] = 0; fwd[i*prime[j]] = prime[j];
			if (i % prime[j] == 0) break;
		}
	}
	for (int i = 1; i <= maxn; ++i) {
		factor[i] = 1;
		for (int j = i, cnt, cur; j != 1; ) {
			for (cnt = 1, cur = fwd[j]; fwd[j] == cur; cnt++, j /= cur);
			factor[i] *= cnt;
		}
		factor[i] = (factor[i]&1) + factor[i-1];
	}
	while (cin >> k, k) cout << factor[k] << endl;		
}
