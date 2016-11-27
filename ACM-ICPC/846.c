/**********************************************************
	Program:	Steps
	Author:		Saúl Martínez Vidals
	Date:		24-05-2007
***********************************************************
        @JUDGE_ID: 63787VV 846 C ""
**********************************************************/

#include <stdio.h>

int main()
{
	short i, n;
	int pasos, inc;
	unsigned long x, y;
	long long s;
	
	scanf("%hd", &n);
	for(i = 0; i < n ; i++)
	{
		scanf("%lu %lu", &x, &y);
		pasos = 0;
		if(x != y)
		{
			y--;
			s = x;
			inc = 1;
			while(s != y)
			{
				if(s > y)
				{
					s -= (inc-1);
					inc -= 2;
					pasos --;
				}
				s += inc++;
				pasos ++;
			}
		}
		printf("%d\n", pasos+1);
	}
	return 0;
}

