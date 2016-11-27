/*
Program:	A multiplication game
Author:		Saúl Martíez Vidals
Date:		21/03/2007
*/

/* @JUDGE_ID: 63787VV 847 C "Easy algorithm" */

#include <stdio.h>

short stan(unsigned long, unsigned long);
short ollie(unsigned long, unsigned long);

int main()
{
	short ganador;
	unsigned long n;
	
	while(scanf("%ld", &n) != EOF)
	{
		ganador = stan(n, 1);
		if(ganador == 0)
			puts("Stan wins.");
		else
			puts("Ollie wins.");
	}
	return 0;
}


short stan(unsigned long n, unsigned long p)
{
	short i, aux = 9;
	if(p*9 >= n)
		return 0;
	else
	{
		for(i = 9; i >= 2; i--)
		{
			if(p*i*9 < n)
			{
				if(p*i*18 >= n)
				    return ollie(n, p*i);
				if(aux == 9)
					aux = i;
			}
		}
		return ollie(n, p*aux);
	}
}

short ollie(unsigned long n, unsigned long p)
{
	short i, aux = 9;
	if(p*9 >= n)
		return 1;
	else
	{
		for(i = 9; i >= 2; i--)
		{
			if(p*i*9 < n)
			{
				if(p*i*18 >= n)
				    return stan(n, p*i);
				if(aux == 9)
					aux = i;
			}
		}
		return stan(n, p*aux);
	}
}
