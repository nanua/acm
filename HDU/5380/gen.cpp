#include <bits/stdc++.h>
#define gen(nd) (rand() % (nd) + 1)
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
const int n = 1e5, m = 1e5,mod = 1e9+7, maxn = 1e6+10;

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

	int n = 10, c = 100000;
	int d[201010] = {};
	
	cout << 2 << endl;
	cout << n << " " << c << endl;

	for (int i = 1; i <= n; ++i) cout << (d[i] = gen(c) + d[i-1]) << " ";
	cout << endl;

	for (int i = 1; i <= n+1; ++i) {
		int x = gen(50000), y = x + gen(50000);

		cout << y << " " << x << endl;
	}
	cout << n << " " << c << endl;

	for (int i = 1; i <= n; ++i) cout << (d[i] = gen(c) + d[i-1]) << " ";
	cout << endl;

	for (int i = 1; i <= n+1; ++i) {
		int x = gen(50), y = x + gen(50);

		cout << y << " " << x << endl;
	}	
}
 
