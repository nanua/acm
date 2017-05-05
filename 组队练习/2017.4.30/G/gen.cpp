#include <bits/stdc++.h>
#define gen(nd) (rand() % int(nd) + 1)
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
const int n = 100000, m = 200000, N = 2e5, M = 5e5, mod = 1e9+7, maxn = 1e6+10;

int seq[maxn], fa[maxn];
pii Pair[maxn];

void gen_sequence(int len, int rng) {
	for(int i = 1; i <= len; ++i) seq[i] = gen(rng);
}
void gen_tree(int len) {
	for (int i = 2; i <= len; ++i) fa[i] = gen(i-1);
}
void gen_rng(int rep, int len) {
	for (int i = 1; i <= rep; ++i) {
		int l = gen(len), r = gen(len);
		if (l > r) swap(l, r);
		Pair[i] = make_pair(l, r);
	}
}
void output(int seq[], int len) {
    for (int i = 1; i <= len; ++i) cout << seq[i] << " ";
    cout << endl;
}
int main() {
	freopen("a.in","w",stdout);
	srand(time(0));
	cout << 2 << endl;

	cout << n << endl;
	for (int i = 1; i <= n; ++i) cout << rand() % (1 << 25) << " ";
	cout << endl;

	cout << m << endl;
	for (int i = 1; i <= m; ++i) {
		int tp = rand() % 2 + 1;
		if (tp == 1)
			cout << 1 << " " << rand() % n + 1 << " " << rand() % n + 1 << endl;
		else
			cout << 2 << " " << rand() % n + 1 << endl;
	}

	cout << n << endl;
	for (int i = 1; i <= n; ++i) cout << rand() % 100 << " ";
	cout << endl;

	cout << m << endl;
	for (int i = 1; i <= m; ++i) {
		int tp = rand() % 2 + 1;
		if (tp == 1)
			cout << 1 << " " << rand() % n + 1 << " " << rand() % n + 1 << endl;
		else
			cout << 2 << " " << rand() % n + 1 << endl;
	}
}

