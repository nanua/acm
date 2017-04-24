#include <vector>
#include <iostream>
#include <algorithm>
#define fi first
#define se second
using namespace std;

typedef pair<string, pair<int, int> > tip;

vector<tip> v;
string oper, site;
int cur;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	v.push_back(tip("http://www.acm.org/", make_pair(-1, -1))), cur = 0;

	while (cin >> oper, oper[0] != 'Q') {
		switch(oper[0]) {
		case 'V':
			cin >> site;
			v.push_back(tip(site, make_pair(cur, -1)));
			v[cur].se.se = v.size()-1;
			puts(v[cur = v.size()-1].fi.c_str());
			break;
		case 'B':
			puts(v[cur].se.fi == -1 ? "Ignored" : v[cur=v[cur].se.fi].fi.c_str());
			break;
		case 'F':
			puts(v[cur].se.se == -1 ? "Ignored" : v[cur=v[cur].se.se].fi.c_str());
			break;
		}
	}
}
