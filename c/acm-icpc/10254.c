/*
Program:	The Priest Mathematician
Author:		Saúl Martínez Vidals
Date:		02-05-2007
*/

/* @JUDGE_ID: 63787VV 10254 C "Recurrence Relations" */

#include <stdio.h>

unsigned long hanoi(int n)
{
	if(n == 1)
		return 1;
	else
		return (2*hanoi(n-1) + 1);
}
int main()
{
	int n;
	int i;
	for(i = 1; i < 100; i++)
		printf("%d:\t%ld\n", i, hanoi(i));
	/*while(scanf("%d", &n) != EOF)
	{
	}*/
	return 0;
}
