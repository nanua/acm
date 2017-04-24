#include <bits/stdc++.h>
#define gen(nd) (rand() % int(nd) + 1)
using namespace std;

typedef pair<int, int> pii;
// const int c = 1e5, n = 1e4, m = 1e4,mod = 1e9+7, maxn = 1e6+10;
const int c = 3, n = 7, m = 10,mod = 1e9+7, maxn = 1e6+10;
set<int> s;

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

	printf("%d %d %d\n", n, m, c);

	for (int i = 1; i <= m; ++i) {
		int u = gen(n), v = gen(n), w = gen(10);
		while (s.count(w)) w = gen(10);		
		// int u = gen(n), v = gen(n), w = gen(10);
		// while (s.count(w)) w = gen(1e6);		
		s.insert(w);
		printf("%d %d %d\n", u, v, w);
	}

	for (int i = 1; i <= c; ++i) {
		int u = gen(n), v = gen(n);
		printf("%d %d\n", u, v);
	}		
}
