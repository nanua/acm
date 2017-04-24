#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pk pop_back
#define fi first
#define se second

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

const int maxn = 2e5+50, maxm = 1e5+50, inf = (int)0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = (ll)1e17;

typedef int arrn[maxn];
typedef int arrm[maxm];


template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar()) {
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

int n, stp, k, kase;
char op[10], id1[10], id2[10];
vector<stack<pii> > v;
set<pii, greater<pii> > Top[2];

void push_stack(char c, int x) {
	set<pii, greater<pii> > &st = Top[c-'A'];
	if (st.size() == 0)
		v.push_back(stack<pii>()), st.insert(pii(++stp, v.size()-1));
	pii ele = pii(x, ++stp), ctop = *st.begin();
	v[ctop.se].push(ele);
	st.erase(st.begin());
	ctop.fi = stp;
	st.insert(ctop);
}
void pop_stack(char c) {
	set<pii, greater<pii>> &st = Top[c-'A'];
	pii ctop = *st.begin();
	st.erase(st.begin());
	printf("%d\n", v[ctop.se].top().fi);
	v[ctop.se].pop();
	if (v[ctop.se].size())
		ctop.fi = v[ctop.se].top().se, st.insert(ctop);
}
void merge_stack(char x, char y) {
	set<pii, greater<pii>> &A = Top[x-'A'], &B = Top[y-'A'];
	int flag = 0;
	if (A.size() > B.size()) swap(A, B), flag = 1;
	for (set<pii, greater<pii>>::iterator itr = B.begin(); itr != B.end(); ++itr)
		A.insert(*itr);
	if (flag) swap(A, B);
}
int main() {
#ifdef LOCAL
    freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (gint(n), n) {
		v.clear(), Top[0].clear(), Top[1].clear(), stp = 0;

		printf("Case #%d:\n", ++kase);
		while (n--) {
			scanf("%s", op);
			switch(op[1]) {
				case 'u':
					scanf("%s %d", id1, &k), push_stack(id1[0], k); break;
				case 'o':
					scanf("%s", id1), pop_stack(id1[0]); break;
				case 'e':
					scanf("%s %s", id1, id2), merge_stack(id1[0], id2[0]); break;
			}
			cerr << n << " " << Top[0].size() << " " << Top[1].size() << endl;
		}
	}
}
