#include <bits/stdc++.h>
using namespace std;
int T, n, m, i;
string s, t;
inline void Write(string s)
{
	for (int i = 0; i < s.length(); i++)
		putchar(s[i]);
	puts("");
}
int main()
{
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		if (n < 10)
		{
			s = (char)(n + 48);
			t = "";
			n = 0;
			m = 0;
		}
		else
			if ((n & 1) == 1)
			{
				s = "9";
				t = "";
				n -= 9;
				m = 0;
			}
			else
			{
				s = "";
				t = "8";
				m = n - 8;
			}
		while (n)
		{
			if (n < 19)
			{
				s = (char)(n / 2 + 48) + s + (char)(n / 2 + 48);
				n = 0;
			}
			else
			{
				s = "9" + s + "9";
				n -= 18;
			}
		}
		while (m)
		{
			if (m < 19)
			{
				t = (char)(m / 2 + 48) + t + (char)(m / 2 + 48);
				m = 0;
			}
			else
			{
				t = "9" + t + "9";
				m -= 18;
			}
		}
		if (t == "")
		{
			Write(s);
			continue;
		}
		if (t.length() < s.length())
			Write(t);
		else
			if (t.length() > s.length())
				Write(s);
			else
				Write(min(s, t));
	}
	return 0;
}
