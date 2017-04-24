#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 2e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int n, t, p, pos, stp, bsz, fsz;;
string score;
int fwd[maxn], bwd[maxn];
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n >> t;
	cin >> score;
	p = score.find('.');
	for (int i = p-1; i >= 0; --i) fwd[++fsz] = score[i] - '0';
	for (int i = n-1; i > p; --i) bwd[++bsz] = score[i] - '0';

	for (pos = bsz; pos > 1 && bwd[pos] <= 4; --pos);
	for (stp = pos; stp <= bsz && bwd[stp] >= 5 && t > 0; ++stp, --t) bwd[stp+1]++;
	fwd[1] += bwd[bsz+1];
	for (int i = 1; fwd[i] > 9; ++i) fwd[i+1]++, fwd[i] -= 10, fsz = max(fsz, i+1);
	for (int i = fsz; i >= 1; --i) cout << fwd[i];
	if (stp <= bsz)cout << ".";
	for (int i = bsz; i >= stp; --i) cout << bwd[i];
}
