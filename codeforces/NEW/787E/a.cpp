#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 2e5+50, maxm = 1e5+50;
const int inf = 0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;

typedef int arrn[maxn];
typedef ll arrm[maxn];


template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar()) {
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

struct P
{
	int l, r;
	map<int, int> m;
};

list<P> ls;

int n;
int a[maxn];

int main()
{
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	gint(n);
	for (int i = 1; i <= n; ++i)
	{
		gint(a[i]);
		ls.push_back((P){i, i});
		ls.back().m[a[i]]++;
	}

	for (int i = 1; i <= n; ++i)
	{
		for (list<P>::iterator nt = ls.begin(), cr; ; )
		{
			cr = nt++;
			if (nt == ls.end()) break;
			while (nt->l <= nt->r && (cr->m.size() < i || (cr->m.size() == i && cr->m.count(a[nt->l]))))
			{
				cr->m[a[nt->l]]++;
				cr->r++;
				if (--(nt->m[a[nt->l]]) == 0)
					nt->m.erase(a[nt->l]);
				if (++(nt->l) > nt->r)
				{
					ls.erase(nt), nt = cr;
					break;
				}
			}
		}

		cout << ls.size() << " ";
		cerr << i << endl;
	}
}
 
