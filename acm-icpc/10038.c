/**********************************************************
	Program:	Jolly Jumpers
	Author:		Saúl Martínez Vidals
	Date:		15-06-2007
***********************************************************
        @JUDGE_ID: 63787VV 10038 C "Data Structures"
**********************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 3005

int main()
{
	int i, n, numeros[MAX_N], resta;
	char restas[MAX_N], s;
	
	while(scanf("%d", &n) != EOF)
	{
		if(n <= 0)
			s = 0;
		else
		{
			s = 1;
			for(i = 0; i < n; i++)
			{
				restas[i] = 0;
				scanf("%d", &numeros[i]);
			}
			for(i = 1; i < n; i++)
			{
				resta = abs(numeros[i] - numeros[i-1]);
				if((resta >= n) || (resta == 0))
				{
					s = 0;
					break;
				}
				else if(restas[resta] == 1)
				{
					s = 0;
					break;
				}
				else
					restas[resta] = 1;
			}
		}
		if(s)
			puts("Jolly");
		else
			puts("Not jolly");
	}
	return 0;
}

