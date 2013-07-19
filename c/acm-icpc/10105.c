/*
Program:	Polynomial coefficients
Author:		Saúl Martínez Vidals
Date:		21-03-2007
*/

/* @JUDGE_ID: 63787VV 10105 C "Combinatory algorithm" */

#include <stdio.h>

void coeficiente(short, short, short[]);
unsigned long factorial(short);

int main()
{
	short num[14], n, k, i;
	while(scanf("%hd %hd", &n, &k) != EOF)
	{
		for(i = 0; i < k; i++)
			scanf("%hd", &num[i]);
		coeficiente(n, k, num);
	}
	return 0;
}

void coeficiente(short n, short k, short num[])
{
	short i;
	unsigned long aux = 1;
	for(i = 0; i < k; i++)
		aux *= factorial(num[i]);
	printf("%ld\n", factorial(n)/aux);
}

/*calcula el factorial de n*/
unsigned long factorial(short n)
{
	unsigned long fact = 1;
	short i;
	for(i = 2; i <= n; i++)
		fact *= i;
	return fact;
}
