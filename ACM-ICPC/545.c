/**********************************************************
	Program:	Heads 
	Author:		Saúl Martínez Vidals
	Date:		00-00-2007
***********************************************************
        @JUDGE_ID: 63787VV 545 C ""
**********************************************************/

#include <stdio.h>
#include <math.h>

int main()
{
	int i, n, r;
	double num, decimal, log2_10 = log10(2);
	
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &r);
		num = (double)(-r) * log2_10;
		num --;
		decimal = modf(num, &num);
		decimal ++;		
		printf("2^-%d = %1.3lfE%.0lf\n", r, pow(10, decimal), num);
	}
	return 0;
}

