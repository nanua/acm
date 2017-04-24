#include <stdio.h>

int main()
{
	
	freopen("a.in","r",stdin);
	freopen("b.out","w",stdout);
	char ch;
	int SPACE , CHAR, COMMA;
	SPACE = CHAR = COMMA = 0;
	int space;
	int n = 0;
	while (scanf("%c", &ch) == 1)
	{
		if (ch == '\n')
		{
			SPACE = CHAR  = COMMA = 0;
			n++;
		}
		else switch (ch)
			{
			case ',':
			{
				COMMA++;
				CHAR = 0;
				break;
			}
			case ' ':
			{
				SPACE++;
				break;
			}
			default:
			{
				if (COMMA == 0 && SPACE == 0)
				{
					CHAR++;
					printf("%c", ch);
					break;
				}
				else if (SPACE && CHAR)
				{
					CHAR++;
					space = SPACE;
					while (space--)
						printf(" ");
					printf("%c", ch);
					SPACE = 0;
					break;
				}
				else if (COMMA && CHAR == 0)
				{
					CHAR++;
					if (n == 0)
					{
						printf("\n");
					}
					else n = 0;
					printf("%c", ch);
					COMMA = SPACE = 0;
					break;
				}
				else if (SPACE && CHAR == 0)
				{
					CHAR++;
					if (n == 0)
					{
						printf("\n");
					}
					else n = 0;
					printf("%c", ch);
					COMMA = SPACE = 0;
					break;
				}
				else if (SPACE == 0 && CHAR)
				{
					CHAR++;
					printf("%c", ch);
					break;
				}

			}
			}
	}
	return 0;
}
