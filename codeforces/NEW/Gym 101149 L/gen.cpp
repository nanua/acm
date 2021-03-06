#include <bits/stdc++.h>
 #define gen(nd) (rand() % int(nd) + 1)
 using namespace std;

 typedef pair<int, int> pii;
 typedef long long ll;
 const int n = 1e5, m = 1.7e5, N = 2e5, M = 5e5, mod = 1e9+7, maxn = 1e6+10;

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

int f[1010100];
 int main() {
 	freopen("a.in","w",stdout);
 	srand(time(0));

 	int a = rand() % n + 1, b = rand() % n + 1;
 	while (a == b)
 		a = rand() % n + 1, b = rand() % n + 1;

 	printf("%d %d %d %d\n", n, m, a, b);
 	f[1] = 0;
 	for (int i = 2; i <= n; ++i) f[i] = rand() % (i-1);
 	for (int i = 1; i <= n; ++i) printf("%d %d\n", f[i], i);
 	for (int i = 1; i <= m-n; ++i) {
 		int x = rand() % (n+1), y = rand() % (n+1);
 		while (x == y)
 			x = rand() % (n+1), y = rand() % (n+1);
 		printf("%d %d\n",x, y);
 	}
 }

