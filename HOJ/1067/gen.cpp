#include <bits/stdc++.h>
#define gen(nd) (rand() % (nd) + 1)
using namespace std;

typedef pair<int, int> pii;
const int n = 1e5+10, m = 1e5 + 10,mod = 1e9+7, maxn = 1e6+10;

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
	int a[1001];
	int n = gen(4);
	for (int i = 1; i <= n; ++i) {
		int t = gen(20);
		int q = gen(10);
		cout << q << endl;
		for (int j = 1; j <= q; ++j) a[j] = j;
		for (int i = 1 ; i <= t; ++i, puts("")) {
			random_shuffle(a+1, a+q+1);
			for (int j = 1; j <= q; ++j) cout << a[j] << " ";
 		}
		cout << "0\n";
	}
	cout << "0\n";
}
