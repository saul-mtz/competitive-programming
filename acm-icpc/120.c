/* @JUDGE_ID: 110402 120 B "Easy algorithm" */

/*
Autor: Saúl Martínez Vidals
Problema: Stacks of Flapjacks
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_L 31

int llena_arreglo(char [], int[]);
void ordena_pila(int, int, int []);
void cambio(int, int []);

int main()
{
	int i, n;
	int pila[MAX_L];
	char cadena[2*MAX_L], *c;
	c = gets(cadena);
	do{
		n = llena_arreglo(cadena, pila);
        for(i = 0; i < n; i++)
			printf("%i ", pila[i]);
		puts("");
		ordena_pila(n-1, n, pila);
		c = gets(cadena);
	} while(c != NULL);
	return 0;
}

int llena_arreglo(char cadena[], int pila[])
{
	int i, n=0;
	char *c;
	c = strtok(cadena, " ");
	pila[n++] = atoi(c);
	while((c = strtok(NULL, " ")) != NULL)
		pila[n++] = atoi(c);
	return n;
}

void ordena_pila(int fin, int n, int pila[])
{
	int i, k = -1;
	for(i = 0; i < fin; i++)
	{
		if(pila[i] < pila[i+1])
		{
			if(k == -1)
			    k =i+1;
			else if(pila[i+1] > pila[k])
			    k = i+1;
		}
		else
		{
			if(k == -1)
			    k =i;
			else if(pila[i] > pila[k])
			    k = i;
		}
	}
	if(k == -1)
		printf("0\n");
	else if(k == 0)
	{
		printf("%d ", n-fin+k);
		cambio(fin-k, pila);
		ordena_pila(--fin, n, pila);
	}
	else
	{
        if(k == fin)
		    fin--;
		else
		{
			printf("%d ", n-k);
			cambio(k, pila);
		}
		ordena_pila(fin, n, pila);
	}
}

void cambio(int n, int pila[])
{
	int aux, m;
	int i;
	for(i = 0, m = n; i <= n/2; i++, m--)
	{
		aux = pila[i];
		pila[i] = pila[m];
		pila[m] = aux;
	}
}
