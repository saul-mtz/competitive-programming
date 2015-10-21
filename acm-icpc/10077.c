/*
Program:    The Stern-Brocot Number System
Author: Saúl Martínez Vidals
Date:   25-03-2007
*/

/* @JUDGE_ID: 63787VV 10077 C "Easy algorithm" */

#include <stdio.h>

void stern_brocot(long, long, long, long, long, long);

int main()
{
	long n, m;
	scanf("%ld %ld", &m, &n);
	while((m != 1) || (n != 1))
	{
		if(m > n)
		{
			printf("R");
			stern_brocot(1, 1, 1, 0, m, n);
		}
		else
		{
			printf("L");
			stern_brocot(0, 1, 1, 1, m, n);
		}
		puts("");
		scanf("%ld %ld", &m, &n);
	}
	return 0;
}

void stern_brocot(long a, long b, long c, long d, long m, long n)
{
	long ac, bd;
	ac = a+c;
	bd = b+d;
	if((ac == m) && (bd == n))
		return;
	else if((double)m/n > (double)ac/bd)
	{
		printf("R");
		stern_brocot(ac, bd, c, d, m, n);
	}
	else
	{
		printf("L");
		stern_brocot(a, b, ac, bd, m, n);
	}
}
