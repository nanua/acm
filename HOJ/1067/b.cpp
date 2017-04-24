#include <cstdio>
#include <cstdlib>
#include <cstring>

int stack[1005], top;
int put(int num)
{
	stack[top++] = num;
	return 0;
}
int get(int index)
{
	return(top >= index && index > 0 ? stack[index-1] : -1);
}
int del()
{
	if (top)
	{
		top--;
		return stack[top];
	}
	else
	{
		return -1;
	}
}
int clear()
{
	top = 0;
	return 0;
}
int main()
{	
	freopen("a.in","r",stdin);
	freopen("b.out","w",stdout);
	int a, b, d, fail;
	char c[5000];
	scanf("%d", &a);
	while (a)
	{
		gets(c);
		gets(c);
		while (c[0]!='0')
		{
			d = 1,fail=0;
			clear();
			for (b = 0; b < a; b++)
			{
				while (get(top) != c[2 * b]-'0')
				{
					put(d++);
					if (top > a){fail = 1;break;}
				}
				del();
			}
			printf(fail ? "No\n" : "Yes\n");
			gets(c);
		}
		printf("\n");
		scanf("%d", &a);
	}
	// printf("\n");
	return 0;
}
