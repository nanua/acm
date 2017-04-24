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

const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int a[maxn], n, T;
char typ(int l, int r) {
	int B = 0, I = 0;
	for (int i = l; i <= r; ++i)
		a[i] == 1 ? I++ : B++;
	return min(I, B) == 0 ? (I == 0 ? 'B' : 'I') : 'F';
}
void build(int l, int r) {
	int mid = (l + r) >> 1;
	if (l != r)
		build(l, mid), build(mid+1, r);
	putchar(typ(l, r));
}
int main() {
	for (cin >> T; T; T--) {
		cin >> n;
		for (int i = 1; i <= (1 << n); ++i) scanf("%1d",&a[i]);
		build(1, 1<<n);
		puts("");
	}
}
