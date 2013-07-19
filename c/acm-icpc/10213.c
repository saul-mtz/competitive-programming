/*
Program:
Author:		Saúl Martínez Vidals
Date:		26-03-2007
*/

/* @JUDGE_ID: 63787VV 10213 C "Easy algorithm" */

#include <stdio.h>
#include <math.h>

int main()
{
	short i;
	double num = 1;
	for( i = 1; i <= 82; i++)
	{
        num *= 10;
		printf("2^%hd = %.0lf\n", i, num);
	};
	system("pause");
	return 0;
}
