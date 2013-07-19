/*
Program:	Euclid Problem
Author:		Saúl Martínez Vidals
Date:		12-05-2007
*/

/* @JUDGE_ID: 63787VV 10104 C "Easy algorithm" */

#include <stdio.h>

long mcd(long, long);

int main()
{
	long a, b;
	while(scanf("%ld %ld", &a, &b) != EOF)
	{
		printf("mcd(%ld, %ld) = %ld\n", a, b, mcd(a, b));
	}
	return 0;
}

long mcd(long a, long b)
{
	long r;
	while(b)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
