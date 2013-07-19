/*
Program:	Anagram
Author:		Saúl Martínez Vidals
Date:       08-03-200
*/

/* @JUDGE_ID: 63787VV 195 C "Easy algorithm" */

#include <stdio.h>
#include <string.h>

#define LONG_W	20							/*máxima longitud de las palabras*/

/* * * * * *  P R O T O T I P O S    D E    F U N C I O N E S  * * * * */
int comparar(const void*, const void*);
void permutaciones(char [], char [], short, short);
short esta(short [], short, short);
void nueva(char [], char [], short, short);

/*función principal*/
int main()
{
	char cadena[LONG_W], aux[LONG_W];
	short i, n, l;
	scanf("%hd", &n);						/*se leeran n palabras del teclado     ---*/
	for(i = 0; i < n; i++)
	{
		scanf("%s", cadena);				/*lee la i-ésima palabra e invoca a la    */
		l = (short)strlen(cadena);
		aux[l] = '\0';
		qsort(cadena, l, sizeof(char), comparar);
		permutaciones(cadena, aux, l, 0);
	}
	return 0;
}

/*funcion usada por qsort para ordenal los elemtos del arreglo*/
int comparar(const void *a, const void *b)
{
	if(*(char *)a < *(char *)b)	return -1;
	if(*(char *)a == *(char *)b)  return 0;
	return 1;
}

/*genera las permutaciones de los elementos de 'cadena', la palabra actual es almacena -
da en aux, , l es la longitud de 'cadena' y 'lp' es un entero que contien un ídice para-
escribir en aux*/
void permutaciones(char cadena[], char aux[], short l, short lp)
{
	short i, j, k, tomados[l], it=0;
	char temp[l-1];
	if(l == 1)									/*cuando l==1, 'cadena' solo consta de*/
	{											/*de un elemento, entonces se genero -*/
		aux[lp] = cadena[0];					/*una permutacion*/
		aux[lp+1] = '\0';
		puts(aux);
	}
	else
	{											/*cuando 'cadena' tiene longitud > 1 -*/
		for(i = 0; i < l; i++)					/*se agarra como lp-ésimo elemento de */
		{										/*la permutación actual algún elemento*/
			if(!esta(tomados, it, cadena[i]))   /*que no se ha tomado antes, y se in- */
			{                                   /*voca recursivamente a la misma fun -*/
				tomados[it++] = cadena[i];      /*ción */
				aux[lp] = cadena[i];
				nueva(cadena, temp, i, l);
				permutaciones(temp, aux, l-1, lp+1);
			}
		}
	}
}

/*función que ordena los elemento de la cadena de longitud 'n' recibida como parámetro,
usa el algoritmo de la burbuja */
void ordena(char cadena[], short n)
{
	short i, j, k=n-1;
	char aux;
	for(i = 0; i < k; i++, n--)
	{
		for(j = 0; j < n-1; j++)
		{
			if(cadena[j] > cadena[j+1])
			{
				aux = cadena[j];
				cadena[j] = cadena[j+1];
				cadena[j+1] = aux;
			}
		}
	}
}

/*busca si 'c' esta en 'cadena', desde cero al n-ésimo elemento del arreglo si no esta
regresa cero, si esta regresa un número mayor que cero*/
short esta(short cadena[], short n, short c)
{
	short i;
	for(i = 0; i < n; i++)
	{
    	if(cadena[i] == c)
			return 1;
	}
	return 0;
}

/*crea la cadena c2 a partir c1, copia todos los elementos a excepcion del n-ésimo*/
void nueva(char c1[], char c2[], short n, short l)
{
	short i;
	for(i = 0; i < n; i++)
	    c2[i] = c1[i];
	for(++i; i < l; i++)
	    c2[i-1] = c1[i];
	c2[i-1] = '\0';
}
