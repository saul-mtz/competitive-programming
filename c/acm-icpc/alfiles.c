#include <stdio.h>
#include <string.h>

#define TRUE    1
#define FALSE	0
#define N   10

void alfiles(int[], int, int, int, long long*);
void construye_candidatos(int[], int, int, int[], int*);

/*función principal*/
int main()
{
	int i, n, k, solucion[N*N];
	long long soluciones=0;
	scanf("%d %d", &n, &k);
	while((n != 0) || (k != 0))
	{
        for(i = 0; i < n*n; i++)
			solucion[i] = -1;
		alfiles(solucion, n, k, 0, &soluciones);
		printf("%ld\n", soluciones);
		scanf("%d %d", &n, &k);
	}
	return 0;
}

void alfiles(int solucion[], int n, int k, int i_sol, long long *sol)
{
	int i, n_candidatos, candidatos[n*n];
	if(i_sol == k)
	{
		(*sol)++;
/*		printf("solucion %ld:   \n", *sol);*/
		for(i = 0; i < k; i++)
		    printf("%d ", solucion[i]);
		puts("");
	}
	else
	{
/*		printf("n=%d\ti=%d\t", n, i_sol);*/
		construye_candidatos(solucion, n, i_sol, candidatos, &n_candidatos);
/*		printf("no. candidatos = %d\n", n_candidatos);-*/
		for(i = 0; i < n_candidatos; i++)
		{
			solucion[i_sol] = candidatos[i];
			alfiles(solucion, n, k, i_sol+1, sol);
		}
	}
}

void construye_candidatos(int solucion[], int n, int k, int c[], int *nc)
{
	int i, j, l, esta;
	*nc = 0;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			esta = FALSE;
			for(l = 0; l < k; l++)
			{
                if(solucion[l] = i+j)
				{
					esta = TRUE;
					break;
				}
			}
			if(esta == FALSE)
				c[(*nc)++] = i+j;
		}
	}
}
