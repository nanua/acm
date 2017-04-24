#include <stdio.h>
#include <stdlib.h>

int main()
{
	freopen("a.in","r",stdin);
	freopen("c.out","w",stdout);
	int a=0,b=0,c;
	char x;
	while (scanf("%c",&x)==1)
		{
			//printf("%c",x);
			//printf("%d",a);
			if (a==0)
				{
					if (x == ' ');
					else if (x == ',');
					else if (x == '\n')
						a=0;
					else
						{
							//printf("shabi\n");
							a=1, b=0;
							printf("%c",x);

						}
				}
			else if (a==1)
				{
					if (x == ',')
						{
							a=0;
							b=0;
							puts("");
						}
					else if (x == '\n')
						{
							a=0;
							puts("");
						}
					else if (x==' ')
						b++;
					else
						{
							for (c=0;c<b;c++)
								{
									printf(" ");
								}
							printf("%c",x);
							b=0;
						}
				}
		}
	if (a == 1) puts("");
	return 0;
} 
