#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cctype>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 2e5+50, maxm = 1e5+50;
const int inf = 0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f, base = 23456789;;

typedef int arrn[maxn];
typedef ll arrm[maxn];


template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar())
{
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}


int n, T;
string s[20];
ll h[20][200];
ll e[200];

void calc_hash(ll h[], string &s)
{
	for (int i = 1; i <= 60; ++i)
		h[i] = (h[i-1] * base + s[i-1]) % mod;
}

ll get(ll x[], int j, int i)
{
	return ((x[i+j-1] - x[j-1] * e[i]) % mod + mod) % mod;
}

bool check(ll v, int l)
{
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j+l-1 <= 60; ++j)
			if (get(h[i], j, l) == v) goto pass;
		
		return 0;
	  pass:
		continue;
	}
	return 1;
}
int main()
{
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	
	e[0] = 1;
	for (int i = 1; i <= 100; ++i) e[i] = (e[i-1] * base) % mod;
										 
	for (scanf("%d\n", &T); T; T--)
	{
		gint(n);
		for (int i = 1; i <= n; ++i)
			cin >> s[i], calc_hash(h[i], s[i]);
		
		for (int i = 60; i >= 3; --i)
		{
			string Min = "Z";
			for (int j = 1; i+j-1 <= 60; ++j)
			{
				ll h_val = get(h[1], j, i);
				if (check(h_val, i))
				{
					string tmp = s[1].substr(j-1, i);
					if (tmp < Min) Min = tmp;						
				}
			}	
			if (Min != "Z")
			{
				printf("%s\n", Min.c_str());
				goto succ;
			}
		}
		
		puts("no significant commonalities");
	  succ:
		continue;
	}	
}
