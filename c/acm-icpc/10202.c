/*
Program:    Pairsumonious Numbers
Author:		Saúl Martíez Vidals
Date:		27-03-2007
*/

/* @JUDGE_ID: 63787VV 10202 C "Easy algorithm" */

#include <stdio.h>

#define N   10

short gauss(long [N*(N-1)/2][N+1], short);
void intercambia(long matriz[N*(N-1)/2][N+1], short x, short y, short n);
void imprime(long matriz[N*(N-1)/2][N+1]);
void sustitucion_atras(long matriz[N*(N-1)/2][N+1], short n);

int main()
{
	long matriz[N*(N-1)/2][N+1] = {
								{1, 1, 0, 0, 0, 79950},
	                            {0, 1, 1, 0, 0, 79936},
	                            {0, 0, 1, 1, 0, 79942},
	                            {0, 0, 0, 1, 1, 79962},
	                            {1, 0, 1, 0, 0, 79954},
	                            {0, 1, 0, 1, 0, 229},
	                            {0, 1, 0, 0, 1, 228},
	                            {0, 0, 1, 1, 0, 226},
	                            {0, 0, 1, 0, 1, 225},
	                            {0, 0, 0, 1, 1, 227},
								};
	short i, j;
	gauss(matriz, 5);
	imprime(matriz);
	sustitucion_atras(matriz, 4);
	system("pause");
	return 0;
}

short gauss(long matriz[N*(N-1)/2][N+1], short n)
{
	short i, j, k, aux;
	for(i = 0; i < n; i++)
	{
		if(matriz[i][i] == 0)
		{
			imprime(matriz);
			for(k = i+1; k <= n; k++)
			{
				if(matriz[k][i] != 0)
				{
				    intercambia(matriz, i, k, n);
				    break;
				}
				return 0;
			}
		}
		for(j = i+1; j <n; j++)
		{
			if(matriz[j][i] != 0)
			{
				aux = matriz[j][i];
				for(k = i; k <= n; k++)
					matriz[j][k] =  (matriz[j][k] / aux * matriz[i][i]) - matriz[i][k];
			}
		}
	}
}

void intercambia(long matriz[N*(N-1)/2][N+1], short x, short y, short n)
{
	int i;
	long aux;
	for(i = 0; i <= n; i++)
	{
		aux = matriz[x][i];
		matriz[x][i] = matriz[y][i];
		matriz[y][i] = aux;
	}
}

void imprime(long matriz[N*(N-1)/2][N+1])
{
	short i, j;
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j <= 5; j++)
			printf("%-5ld", matriz[i][j]);
		puts("");
	}
}

void sustitucion_atras(long matriz[N*(N-1)/2][N+1], short n)
{
	short i, j;
	long solucion[n+1], aux;
	solucion[n] = matriz[n][n+1]/matriz[n][n];
	for(i = n-1; i >= 0; i--)
	{
		aux = 0;
		for(j = i+1; j <= n; j++)
			aux += matriz[i][j] * solucion[j];
		solucion[i] = (matriz[i][n+1] - aux) / matriz[i][i];
	}
	for(i = 0; i <= n; i++)
	    printf("%ld ", solucion[i]);
	puts("");
}
