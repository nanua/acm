#include <bits/stdc++.h>
using namespace std;

#define clr(x, y) memset(x, y, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(y))
#define all(x) x.begin(), x.end()
#define sqr(x) ((x) * (x))
#define sz(x) ((ll)x.size())

#define mk make_pair
#define pb push_back
#define pk pop_back
#define fi first
#define se second

#define add_edge(x, y) (to[++edg] = y, nt[edg] = la[x], la[x] = edg)
#define add_wedge(x, y, w) (to[++edg] = y, wgt[edg] = w, nt[edg] = la[x], la[x] = edg)
#define lowbit(x) ((x) & (-x))

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

const ld eps = 1e-12, pi = acos(-1);
const int maxn = 2e5+50, maxm = 1e5+50, inf = (int)0x3f3f3f3f, mod = (int)1e9 + 7, sigma = 129;
const ll INF = (ll)1e17;

typedef int arrn[maxn];
typedef int arrm[maxm];


template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar()) {
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

list<char> lst;
list<char>::iterator itr, tmp;
char str[1001000];
int T;

string D() {
	string ret = "";
	for (list<char>::iterator itr = lst.begin(); itr != lst.end(); ++itr)
		ret += *itr;
	return ret;
}
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

	for (scanf("%d\n", &T); T; T--) {
	 	scanf("%s",str);
		
	 	lst.clear();
		lst.pb('*'), lst.pb('*');
		itr = --lst.end();
		
	 	for (int i = 0, l = strlen(str); i < l; ++i) {
			//cerr << D() << endl;
	 		switch(str[i]) {
	 		case '-':
	 			if (itr != ++lst.begin())
					tmp = itr, lst.erase(--tmp);
				break;
			case '<':
				if (itr != ++lst.begin()) itr--;
				break;
	 		case '>':
				if (itr != --lst.end()) itr++;
				break;
	 		default :
				lst.insert(itr, str[i]);
				break;
	 		}
		}
		for (itr = ++lst.begin(); itr != --lst.end(); ++itr)
			printf("%c",*itr);
		puts("");		
	}
}
 
