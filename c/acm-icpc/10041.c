/*
Program:    Vito's family
Author:		Saúl Martínez Vidals
Date:		30-03-2007
*/

/* @JUDGE_ID: 63787VV 10041 C "Easy algorithm" */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int comparar(const void*, const void*);

int main()
{
	short i, n, r, j, k;
	int s[30000];
	long  suma, res;
	scanf("%hd", &n);
	for(i = 0; i < n; i++)
	{
        res = 15000000;
		scanf("%hd", &r);
		for(j = 0; j < r; j++)
			scanf("%d", &s[j]);
		qsort(s, r, sizeof(int), comparar);
		for(j = 0; j < r; j++)
		{
			suma = 0;
			for(k = 0; k < r; k++)
				suma += abs(s[j] - s[k]);
			if(suma < res)
			    res = suma;
		}
		printf("%ld\n", res);
	}
	return 0;
}

int comparar(const void *a, const void *b)
{
	if(*(int *)a < *(int *)b)	return -1;
	if(*(int *)a == *(int *)b)  return 0;
	return 1;
}
