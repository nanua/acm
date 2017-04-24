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

int n, sz, k, kase, top[2];
char op[10], id1[10], id2[10];

struct Node{
	int val, pre, dn, up, flag;
}q[maxn];

void push_stack(int id, int k) {
	++sz;
	q[sz] = (Node){k, top[id], max(top[0], top[1]), -1, 0};
	q[max(top[0], top[1])].up = sz;
	top[id] = sz;
}
void pop_stack(int id) {
	printf("%d\n", q[top[id]].val);
	if (q[top[id]].up <= sz)
		q[q[top[id]].up].dn = q[top[id]].dn, q[q[top[id]].dn].up = q[top[id]].up;;
	if (q[top[id]].flag)
		q[top[id] = q[top[id]].dn].flag = 1;
	else
		top[id] = q[top[id]].pre;		
}
void merge_stack(int i1, int i2) {
	top[i1] = max(top[i1], top[i2]);
	top[i2] = 0;
	q[top[i1]].flag = 1;
}
void dsp(int k) {
	int flag = 0;
	cerr << "\n\n\nStack Disp:" << char(k+'A') << "\n";
	for (int i = top[k]; i; )
		if (flag || q[i].flag == 1)
			flag = 1, cerr << q[i].val << " ", i = q[i].dn;
		else
			cerr << q[i].val << " ", i = q[i].pre;
}
int main() {
#ifdef LOCAL
    freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (gint(n), n) {
		sz = 0; top[0] = top[1] = 0;

		printf("Case #%d:\n", ++kase);
		while (n--) {
			scanf("%s", op);
			switch(op[1]) {
				case 'u':
					scanf("%s %d", id1, &k), push_stack(id1[0]-'A', k); break;
				case 'o':
					scanf("%s", id1), pop_stack(id1[0]-'A'); break;
				case 'e':
					scanf("%s %s", id1, id2), merge_stack(id1[0]-'A', id2[0]-'A'); break;
			}
			// dsp(0);
			// dsp(1);
			// cerr << "\n--------------------------------\n"
		}
	}
}
