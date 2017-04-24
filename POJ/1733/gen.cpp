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
	int n = 5, m = rand()%20;
	cout << n << endl;
	cout << m << endl;
	for (int i = 1; i <= m; ++i) {
		int l = gen(n), r = gen(n), od = gen(2);
		if (l > r) swap(l, r);
		printf("%d %d %s\n", l, r, od % 2 ? "even" : "odd");
	}

	n = 1e9, m = rand()%600;
	cout << n << endl;
	cout << m << endl;
	for (int i = 1; i <= m; ++i) {
		int l = gen(n), r = gen(n), od = gen(2);
		if (l > r) swap(l, r);
		printf("%d %d %s\n", l, r, od % 2 ? "even" : "odd");
	}
}
 
