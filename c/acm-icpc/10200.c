/**********************************************************
	Program:	Prime Time
	Author:		Saúl Martínez Vidals
	Date:		01-06-2007
***********************************************************
		@JUDGE_ID: 63787VV 10200 C "Easy Algorithm"
**********************************************************/

#include <stdio.h>
#include <math.h>

short es_primo(int);

int main()
{
	int a, b, i, k, m, numeros[4150];
	
	for(i = 0, k = 0; i <= 9997; i++)
	{
		if(es_primo(i*i + i + 41))
			numeros[k++] = i;
	}	
	while(scanf("%d %d", &a, &b) != EOF)
	{
		i = 0;
		m = 0;
		while((numeros[i] <= b) && (i < k))
		{
			if((numeros[i] >= a) && (numeros[i] <= b))
				m ++;
			i ++;
		}
		printf("%.2f\n", (float)m * 100/(float)(b - a + 1) + .000001);
	}
	return 0;
}

short es_primo(int n)
{
	int k, raiz = sqrt(n) + 1;
	
	if(!(n % 2))
		return 0;
	for(k = 3; k <= raiz; k += 2)
	{
		if(!(n % k))
			return 0;
	}
	return 1;
}

