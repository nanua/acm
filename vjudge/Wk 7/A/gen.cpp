#include <bits/stdc++.h>
#define gen(nd) (rand() % (nd) + 1)
using namespace std;

typedef pair<int, int> pii;
const int n = 1e5, m = 1e5 + 10,mod = 1e9+7, maxn = 1e6+10;

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
	printf("10\n");
	for (int i = 1; i <= 10; ++i) {
		printf("%d %d %d\n", n, gen(9), gen(9));
		for (int i = 1; i <= n; ++i) cout << gen(9) << " ";
		puts("");
	}
		
}
 
