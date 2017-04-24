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
	int h = gen(100), t = gen(500), flag = 1;
	cout << h << " " << t << endl;
	for (int i = 1; i <= h; ++i){
		for (int j = 1; j <= h-i; ++j) putchar(' ');
		for (int j = 1; j <= i; ++j) {
		gt:;
			int k = gen(50);
			if (k <= 1)
				if (flag)
					flag = 0, putchar('S'), putchar(' ');
				else
					goto gt;
			else
				if (k == 6)
					putchar('*'), putchar(' ');
				else
					if (k == 20)
						putchar('D'), putchar(' ');
					else 
						if (k <= 50)
							putchar('@'), putchar(' ');
		}
		puts("");
	}
	h = gen(100), t = gen(500), flag = 1;
	cout << h << " " << t << endl;
	for (int i = 1; i <= h; ++i){
		for (int j = 1; j <= h-i; ++j) putchar(' ');
		for (int j = 1; j <= i; ++j) {
		gt1:;
			int k = gen(50);
			if (k <= 1)
				if (flag)
					flag = 0, putchar('S'), putchar(' ');
				else
					goto gt1;
			else
				if (k < 20)
					putchar('*'), putchar(' ');
				else
					if (k == 20)
						putchar('D'), putchar(' ');
					else 
						if (k <= 50)
							putchar('@'), putchar(' ');
		}
		puts("");
	}
}
