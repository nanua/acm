#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int T, n, m, p;

struct node{
	int n;
	struct node *nxt;
}*head, *ptr;

void Create(node *head, int x) {
	node *p = head,*q;
	while (p->nxt != NULL) p = p->nxt;
	q = (node*) malloc(sizeof(node));
	q->n = x, q->nxt = NULL;
	p->nxt = q;
}
void Delete(node *ptr) {
	node *p = ptr->nxt;
	ptr->nxt = ptr->nxt->nxt;
	cout << p->n << ",";
	free(p);
}
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (cin >> n >> p >> m, n) {				
		head = (node*) malloc(sizeof(node));
		head->n = 1, head->nxt = NULL;
		
		for (int i = 2; i <= n; ++i) Create(head, i);
		for (ptr = head; ptr->nxt != NULL; ptr = ptr->nxt);
		ptr->nxt = head;

		for (int i = 1; i < (p-2+n)%n+1; ++i) head = head->nxt;
		
		for (int j, i = 1; i < n; ++i) {
			for (j = 1; j < m; ++j)
				head = head->nxt;
			Delete(head);
		}
		cout << head->n;
		puts("");
	}
}
