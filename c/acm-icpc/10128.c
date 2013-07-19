3/*
Program:	Queue
Author:		Saúl Martínez Vidals
Date:		07-03-2007
*/

/* @JUDGE_ID: 63787VV 10128 C "Backtracking" */

#include <stdio.h>

#define MAX     14							/*longitud máxima de personas*/
#define TRUE	1
#define FALSE	0

/* * * * * *  P R O T O T I P O S    D E    F U N C I O N E S  * * * * */
void queue(short [], short, short, short, short, short, short, long long *);
void candidatos(short [], short, short, short [], short *);
short mayor(short [], short, short, short);

/*función principal*/
int main()
{
	short n, i, solucion[MAX];
	short a, b, c, d=0, e=0, f=0;
	long long soluciones;

	scanf("%hd", &n);
	for(i = 0; i < n; i++)
	{
		soluciones = 0;
		scanf("%hd %hd %hd", &a, &b, &c);
		queue(solucion, a, b, c, d, e, f, &soluciones);
		printf("%ld\n", soluciones);
	}

	return 0;
}


/*función recusiva que busca las soluciones del problema usando backtracking*/
void queue(	short solucion[], short n, short p, short r, short np,
			short ind, short i_p_mayor, long long *s)
{
	short c[n-ind+1];
	short i, j, n_candidatos=0, may=0;

	if(ind > (n-p+np))
	    return;

	else if(ind == n)
	{
		for(i = i_p_mayor+1, j = 0; i < n; i++)
		{
			if(mayor(solucion, i+1, n, solucion[i]))
			    j++;
		}
	    if(j+1 == r)
			(*s)++;
	}
	else if(np == p)
	{
        candidatos(solucion, ind, n, c, &n_candidatos);
        for(i = 0; i < n_candidatos; i++)
        {
			if(c[i] < solucion[i_p_mayor])
			{
       			solucion[ind] = c[i];

				/*se invoca la función recursivamente*/
				queue(solucion, n, p, r, np, ind+1, i_p_mayor, s);

			}
		}
	}
	else
	{
		candidatos(solucion, ind, n, c, &n_candidatos);
        for(i = 0; i < n_candidatos; i++)
        {
			solucion[ind] = c[i];
			if(mayor(solucion, 0, ind, c[i]))
			{
				np++;
				may = 1;
			}
			if(np == p)
				i_p_mayor = ind;

			/*se invoca la función recursivamente*/
			queue(solucion, n, p, r, np, ind+1, i_p_mayor, s);

			if(may == 1)
			{
				may = 0;
				np--;
			}
		}
	}
}

/*genera los candidatos para la función recursiva que hace backtrack*/
void candidatos(short solucion[], short longitud, short n, short c[], short *nc)
{
	short i, j, esta;
	*nc = 0;
	for(i = 0; i < n; i++)
	{
        esta = FALSE;
		for(j = 0; j < longitud; j++)
		{
		    if(solucion[j] == i)
			    esta = TRUE;
		}
		if(esta == FALSE)
		   	c[(*nc)++] = i;
	}
}

/*verifica si 'num' es mayor que todos los elementos del arreglo 'solucion' en el inter-
valo [a, b), si lo es regresa TRUE, si no retornará FALSE*/
short mayor(short solucion[], short a, short b, short num)
{
	short i;
	for(i = a; i < b; i++)
	{
    	if(solucion[i] > num)
			return FALSE;
	}
	return TRUE;
}
