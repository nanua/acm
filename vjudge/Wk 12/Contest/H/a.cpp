#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cctype>
#include <vector>
#include <iomanip>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 2e5 + 10, inf = 0x3f3f3f3f;

int nxt[maxn], las[maxn], tmp[maxn][13], to[maxn], q[13], t[13];
int flag, edg, T, n;

int calc_hash() {
	int ret = 0;
	for (int i = 1; i <= 6; ++i) ret ^= t[i];
	return ret;
}
bool find(int *x, int *y) {
	for (int i = 1; i <= 6; ++i) {
		for (int j = 1, k = i; j <= 6; ++j, ++k)
			if (x[k] != y[j]) goto gt;
		return 1;
	gt:;
	}
	return 0;
}
void try_find() {
	int h_val = calc_hash();
	for (int i = las[h_val]; i; i = nxt[i])
		if (find(tmp[i], t))
			return void(flag = 1);
}
void insert() {
	if (flag) return;
	int h_val = calc_hash();
	for (int i = las[h_val]; i; i = nxt[i])
		if (memcmp(tmp[i], q, sizeof(q)) == 0) return;
	
	memcpy(tmp[++edg], q, sizeof(q));
	nxt[edg] = las[h_val];
	las[h_val] = edg;
}
void init() {
	flag = edg = 0;
	memset(las, 0, sizeof(las));
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for (scanf("%d\n",&T); T; T--) {
		init();
		scanf("%d\n", &n);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= 6; ++j)
				scanf("%d\n", &t[j]), q[j] = t[j];
			if (flag) continue;
			try_find();
			for (int j = 7; j <= 12; ++j) q[j] = t[j-6];
			insert();
			reverse(q+1, q+13);
			insert();
		}
		puts(flag ? "Twin snowfalkes found." : "No two snowflakes are alike.");
	}
}
