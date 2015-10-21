/*
Autor:		Saúl Martínez Vidals
Problema:	Bridge
*/

/* @JUDGE_ID: 110403 10037 B "Easy algorithm" */

#include <stdlib.h>
#include <stdio.h>

#define MAX_L	1005					/*longitud máxima de las cadenas leídas leídas*/

void bridge(int, int []);
int comparar(const void*, const void*);

/*función principal*/
int main()
{
	int i, j, n, m, velocidades[MAX_L];
	scanf("%d", &n);                    /*número de casos a analizar*/
	for(i = 0; i < n; i++)              /*lectura de los n conjuntos de valores*/
	{
		getc(stdin);
		scanf("%d", &m);				/*número de personas para cruzar el puente    */
		for(j = 0; j < m; j++)		/*lee los m valores que corresponden a las ve-*/
			scanf("%d", &velocidades[j]);			/*locidades de las personas   */
		bridge(m-1, velocidades);
	}
	return 0;
}

/*función que hace todo el trabajo, incluyendo la impresion de los datos en pantalla*/
void bridge(int n, int v[])
{
	int i, k=0, m;
	long suma = 0;
	int s[3*n];
	qsort(v, n+1, sizeof(int), comparar);  /*ordena los valores del arreglo v*/
	if(n < 2)                           /*caso especial, cuando el número de elemntos--*/
	{                                   /*del arreglo es 1 o 2*/
		printf("%d\n", v[n]);
		if(n == 0)
		    printf("%d", v[0]);
		else
			printf("%d %d", v[0], v[1]);
	}
	else                                /*cuando los datos son 3 o más, se ejecuta  --*/
	{                                   /*esta sección de código*/
        while((m < n) && (m != 2))
		for(m=n; m >= 0 && m != 2; m=m-2)
		{                               /*en esta parte del programa, se colocan en el*/
			s[k++] = v[0];              /*arreglo s, los valores de las velocidades en*/
			s[k++] = v[1];              /*el orden en que se quiere que se impriman*/
			suma += v[1];
			if(m > 1)
			{
    			s[k++] = v[0];
				s[k++] = v[m-1];
				s[k++] = v[m];
				s[k++] = v[1];
				suma += v[0] + v[1] + v[m];
			}
		}
		if(m == 2)                      /*cuando los elementos del arreglo son exacta-*/
		{                               /*mente 3, el índice m tiene el valor 2, en --*/
			s[k++] = v[0];              /*este caso se hacen asignaciones especiales--*/
			s[k++] = v[1];
			s[k++] = v[0];
			s[k++] = v[0];
			s[k++] = v[2];
			suma += v[0] + v[1] + v[2];
		}
		printf("%ld\n", suma);
		for(i = 0; i < k-2; i=i+3)     /*imprime los datos en pantalla, de acuerdo al */
			printf("%d %d\n%d\n", s[i], s[i+1], s[i+2]);	/*formato requerido   */
    	printf("%d %d", s[i], s[i+1]);
	}
	puts("\n");
}

/*funcion que se implemeta para el correcto funcionamiento de qsort*/
int comparar(const void *a, const void *b)
{
	if(*(int *)a < *(int *)b)	return -1;
	if(*(int *)a == *(int *)b)  return 0;
	return 1;
}

