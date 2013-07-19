/*
Program:	Ones
Author:		Saúl Martínez Vidals
Date:		26-03-2007
*/

/* @JUDGE_ID: 63787VV 10127 C "Easy algorithm" */

#include <stdio.h>

int main()
{
	short n, numero;
	unsigned int count;
	while(scanf("%hd", &n) != EOF)
	{
		count = 3;
		numero = 111;
		while(numero % n)
		{
			numero = (numero*10 + 1) % n;
			count ++;
		}
		printf("%d\n", count);
	}
	return 0;
}
