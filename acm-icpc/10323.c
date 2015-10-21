/**********************************************************
	Program:	Factorial! You Must be Kidding!!!
	Author:		Saúl Martínez Vidals
	Date:		13-06-2007
***********************************************************
        @JUDGE_ID: 63787VV 10323 C "Easy Algorithm"
**********************************************************/

#include <stdio.h>

int main()
{
	long n;
	char *numeros[] = {"40320", "362880", "3628800", "39916800", "479001600",
						"6227020800"};
						
	while(scanf("%ld", &n) != EOF)
	{
		if(n < 0)
		{
			if(n % 2)
				puts("Overflow!");
			else
				puts("Underflow!");
		}
		else if(n < 8)
			puts("Underflow!");
		else if(n > 13)
			puts("Overflow!");
		else
			puts(numeros[n-8]);
	}
	return 0;
}

