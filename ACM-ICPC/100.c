/**********************************************************
	Program:	The 3n + 1 problem 
	Author:		Saúl Martínez Vidals
	Date:		18-05-2007
***********************************************************
        @JUDGE_ID: 63787VV 100 C "Easy algorithm"
**********************************************************/

#include <stdio.h>

int algoritmo(unsigned long);

int main()
{
	short c;
	int s, mayor;
	unsigned long i, j, k;
	
	while(scanf("%lu %lu", &i, &j) != EOF)
	{
		c = 0;
		if(i > j)
		{
			c = 1;
			k = i;
			i = j;
			j = k;
		}
		mayor = 0;
		for(k = i; k <= j; k++)
		{
			s = algoritmo(k);
			if(mayor < s)
				mayor = s;
		}
		if(c)
		{
			k = i;
			i = j;
			j = k;
		}
		printf("%lu %lu %d\n", i, j, mayor);
	}
	return 0;
}

int algoritmo(unsigned long x)
{
	int cont = 0;
	
	while(1)
	{
		cont ++;
		if(x == 1)
			break;
		else if(x % 2)
			x = 3*x + 1;
		else
			x /= 2;
	}
	return cont;
}
