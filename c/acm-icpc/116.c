/**********************************************************
	Program:	Undirectional TCP
	Author:		Saúl Martínez Vidals
	Date:		08-06-2007
***********************************************************
        @JUDGE_ID: 63787VV 116 C "Dynamic Programming"
**********************************************************/

#include <stdio.h>

#define MAX_FILAS 11
#define MAX_COLUMNAS 101

int main()
{
	short i, j, n, m;
	int matriz[MAX_FILAS][MAX_COLUMNAS];
	long long max;
	
	while(scanf("%hd %hd", &m, &n) != EOF)
	{
		max = 0;
		for(i = 0; i < m; i++)
		{
			for(j = 0; j < n; j++)
				scanf("%d", &matriz[i][j]);
		}
		busca_solucion(m, &max);
	}
	return 0;
}

void busca_solucion(int matriz[MAX_FILAS][MAX_COLUMNAS], long long *max)
{
	int i;
	
	if(n_s == n)
	{
		for(i = 0; i < k; i++)
		{
			aux = sol + c[i];
			if(aux > *max)
				return;
			else
			{
				if(aux == *max)
				{
					
				}
			}
		}
	}
	for(i = 0; i < 
}

