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
	cout << 1 << endl;
	cout << n << endl;
	int sz = 0;
	for (int i = 1; i <= n;  ++i) {
	gt:
		int p = gen(4);
		switch(p) {
		case 1: cout << "PUSH " << rand() % 2 << endl; ++sz; break;
		case 2: if (sz == 0) goto gt; cout << "POP" << endl; sz--; break;
		case 3: cout << "REVERSE" << endl; break;
		case 4: cout << "QUERY" << endl;
		}
	}
}
