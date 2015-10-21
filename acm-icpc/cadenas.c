#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 100
#define MAXL 1000

void subcadena3(short [], int);

int main()
{
	short numeros[MAXN];
	int i;
	for(i = 0; i < MAXN; i++)
		numeros[i] = rand() % MAXL;
	for(i = 0; i < MAXN; i++)
		printf("%hd  ", numeros[i]);
	puts("");
	subcadena3(numeros, MAXN-1);
	return 0;
}

void subcadena3(short numeros[], int n)
{
	int i, j, k, lim_i, lim_s;
	unsigned int suma, suma_mayor = 0;
	for(i = 0; i <= n; i++)
	{
		for(j = i; j <= n; j++)
		{
			suma = 0;
			for(k = i; k <= j; k++)
				suma += numeros[k];
			suma = abs(suma);
			if(suma > suma_mayor)
			{
				suma_mayor = suma;
				lim_i = i;
				lim_s = j;
			}
		}
	}
	printf("i = %hd, j = %hd:\t%d\n", lim_i, lim_s, suma_mayor);
}
