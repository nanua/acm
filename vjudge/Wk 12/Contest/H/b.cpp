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

const int maxn = 3e5 + 10, inf = 0x3f3f3f3f, mod = 4000037;

int nxt[maxn], las[mod+10];
vector<int> tmp[maxn], t, q;
int flag, edg, T, n;

int calc_hash() {
	int ret = 0;
	for (int i = 0; i < 6; ++i) ret ^= t[i];
	return ret % mod;
}
bool find(vector<int>&x, vector<int>&y) {
	return search(x.begin(), x.end(), y.begin(), y.end()) != x.end();
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
	tmp[++edg] = q;
	nxt[edg] = las[h_val];
	las[h_val] = edg;
}
void init() {
	flag = edg = 0;
	memset(las, 0, sizeof(las));
}
int main() {
	freopen("a.in","r",stdin), freopen("a.out","w",stdout);

	for (scanf("%d\n",&T); T; T--) {
		init();
		scanf("%d\n", &n);
		for (int i = 1; i <= n; ++i) {
			t.clear();
			for (int j = 1, tmp; j <= 6; ++j) scanf("%d", &tmp), t.push_back(tmp);
			if (flag) continue;
			try_find();
			q = t;
			for (int j = 0; j < 6; ++j) q.push_back(t[j]);
			insert();
			reverse(q.begin(), q.end());
			insert();
		}
		puts(flag ? "Twin snowflakes found." : "No two snowflakes are alike.");
	}
}
 
