/*
Program:	The Archeologists' Dilemma
Author:		Saúl Martínez Vidals
Date:		20-03-2007
*/

/* @JUDGE_ID: 63787VV 701 C "Easy algorithm" */

#include <stdio.h>
#include <string.h>

unsigned long busca_potencia(char [], short);
short solucion(char[], char[], short);

int main()
{
	short l;
	char numero[11];
	while(scanf("%s", numero) != EOF)
	{
        l = strlen(numero);
   		printf("%ld\n", busca_potencia(numero, l));
	}
	return 0;
}

unsigned long busca_potencia(char numero[], short n)
{
	short l;
	double aux2 = 64;
	unsigned long i=7;
	char aux[309];
	do {
		aux2 *= 2;
		l = sprintf(aux, "%.0f", aux2);
		if((aux[0] == numero[0])&&(aux[n/2] == numero[n/2])&&(aux[n-1] == numero[n-1])&&(l > 2*n))
		{
			if(solucion(numero, aux, n))
			    return i;
		}
		if(l > 307)
		{
			aux[21] = '\0';
			sscanf(aux, "%lf", &aux2);
		}
		i++;
	} while(l > 0);
	return 0;
}

short solucion(char c1[], char c2[], short n)
{
	short i;
	for(i = 0; i < n; i++)
	    if(c1[i] != c2[i])  return 0;
	return 1;
}
