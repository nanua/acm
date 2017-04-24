#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int maxn = 1e6+10, inf = 0x3f3f3f3f, sig = 233;

int n;
char mov1[maxn], mov2[maxn];
ull Pow[maxn], Hash1[maxn], Hash2[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	scanf("%d\n%s\n%s", &n, mov1+1, mov2+1);
	
	Pow[0] = 1;
	for (int i = 1; i <= n; ++i) {
		Pow[i] = Pow[i-1] * sig;
		if (mov1[i] == 'E' || mov1[i] == 'W') mov1[i] = 'E' + 'W' - mov1[i];
		else mov1[i] = 'N' + 'S' - mov1[i];
	}
	
	for (int i = 1, j = n-1; i < n; ++i, --j)
		Hash1[i] = Hash1[i-1] * sig + mov1[i], Hash2[j] = Hash2[j+1] * sig + mov2[j];
	for (int i = n-1; i >= 1; --i)
		if (Hash2[i] == Hash1[n-1] - Hash1[i-1] * Pow[n-i]) puts("NO"), exit(0);
	puts("YES");	
}
