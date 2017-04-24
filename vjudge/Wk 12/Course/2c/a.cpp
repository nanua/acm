#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

stack<int> s;
queue<int> q;
int T, n;
string str, typ;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	ios::sync_with_stdio(0);

	for (cin >> T; T; T--) {
		cin >> n >> str;
		if (str == "FIFO") {
			while(q.size()) q.pop();
			for (int i = 1, x; i <= n; ++i) {
				cin >> typ;
				if (typ == "IN")
					cin >> x, q.push(x);
				else
					if (q.size())
						cout << q.front() << endl, q.pop();
					else
						cout << "None\n";
			}
		}
		else {
			while(s.size()) s.pop();
			for (int i = 1, x; i <= n; ++i) {
				cin >> typ;
				if (typ == "IN")
					cin >> x, s.push(x);
				else
					if (s.size())
						cout << s.top() << endl, s.pop();
					else
						cout << "None\n";			
			}
		}
	}
}
 
