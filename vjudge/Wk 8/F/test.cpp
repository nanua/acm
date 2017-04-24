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

typedef long long ll;
typedef long double ld;
const int maxn = 1e6 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int isnprime[maxn], cnt[maxn];
int n = 1e6;
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for (ll i = 2; i <= n; ++i)
		if (!isnprime[i])
			for (ll j = i*i; j <= n; j += i) isnprime[j] = i;
	
	for (int i = 2; i <= n; cnt[i++]++)
		for (int j = i; isnprime[j]; j /= isnprime[j]) cnt[i]++;


	for (int i =  1; i <= )
}
