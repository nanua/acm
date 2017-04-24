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
vector<int> v;
int main() {
	freopen("a.in","w",stdout);
	srand(time(0));
	int t, tmp;
	for (int i = 1; i <= 10; ++i) {
		cout << (t = gen(300)) << endl;
		for (int i = 1; i <= t; ++i) {
		gt :;
			int r = gen(3);
			if (r == 1)
				printf("I %d\n", tmp = gen(500)), v.push_back(tmp);
			if (r == 2 && v.size() == 0) goto gt;
			if (r == 2)
				printf("D %d\n", v[tmp = gen(v.size())-1]), v.erase(v.begin()+tmp);
			if (r == 3)
				printf("Q %d\n", gen(500));
		}
	}
	puts("0");
}
