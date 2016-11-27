/**********************************************************
	Program:	Marbles
	Author:		Saúl Martínez Vidals
	Date:		14-05-2007
***********************************************************
        @JUDGE_ID: 63787VV 10090 C "Number Theory"
**********************************************************/

#include <stdio.h>

int main()
{
	short s;
	long n, c1, c2, n1, n2, x, y, aux;
	
	scanf("%ld", &n);
	while(n != 0)
	{
		scanf("%ld %ld %ld %ld", &c1, &n1, &c2, &n2);
		if((float)n/n2 < 1)
			puts("failed");
		else
		{
			aux = 1;
			s = 0;
			if((float)c1/n1 < (float)c2/n2)
			{
				y = 0;
				while((aux > 0))
				{
					aux = n - n2*y;
					if(!(aux % n1))
					{
						x = aux/n1;
						s = 1;
						break;
					}
					y++;
				}
			}
			else
			{
				x = 0;
				while(aux > 0)
				{
					aux = n - n1*x;
					if(!(aux % n2))
					{
						y = aux/n2;
						s = 1;
						break;
					}
					x++;
				}
			}
			if(s)
				printf("%ld %ld\n", x, y);
			else
				puts("failed");
		}
		scanf("%ld", &n);
	}
	return 0;
}

