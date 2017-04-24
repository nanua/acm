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

template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar()) {
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

char op[20];
int T, n, d, kase;
deque<int> dq;
int q[600000], l = 300001, r = 300000;

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for (scanf("%d\n", &T); T; T--) {
		gint(n);
		d = 1,l = 300001, r = 300000, dq.clear();
		printf("Case #%d:\n",++kase);
		
		for (int i = 1, a; i <= n; ++i) {
			scanf("%s", op);
			switch(op[2]) {
			case 'S':
				scanf("%d",&a);
				if (d == 1) {
					q[++r] = a;
					if (a == 0) dq.push_back(r);
				}
				else {
					q[--l] =a;
					if (a == 0) dq.push_front(l);
				}				
				break;
			case 'P':
				if (d == 1) {
					if (dq.size() && dq.back() == r) dq.pop_back();
					r--;
				}
				else {
					if (dq.size() && dq.front() == l) dq.pop_front();
					l++;
				}
				break;
			case 'V':
				d *= -1;
				break;
			case 'E':
				if (r-l+1 == 0) puts("Invalid.");
				else {
					int tot = 0;
					if (d == -1) {
						if (dq.size()) tot = r - dq.back() + 1 - (dq.back() == l);
						else tot = r - l + 1;
					}
					else {
						if (dq.size()) tot = dq.front() - l + 1 - (dq.front() == r);
						else tot  = r - l + 1;
					}
					printf("%d\n",tot&1);
				}
				break;
			}
		}
	}
}

