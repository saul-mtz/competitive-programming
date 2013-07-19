/* ********************************************************
	Program:	Light, more light
	Author:		Saúl Martínez Vidals
	Date:		03-05-2007
***********************************************************
		@JUDGE_ID: 63787VV 10110 C "Number Theory"
**********************************************************/

#include <stdio.h>
#include <math.h>

/* primos es el arreglo que contiene los números primos que se necesitan en el problema,
ip es el índice que nos ayuda a escribir en el arreglo, cuando se han generado los primos
necesarios ip nos informa de cuantos numeros se encontraron */
unsigned int ip = 1, primos[6550] = {2};

/* prototipos de funciones */
void genera_primos(unsigned int, unsigned int);

int main()
{
	short p, cont, mult;
	unsigned int raiz;
	unsigned long n, i;

	/* genera los primos en el rango [3, 65521] y los almacena en el arreglo 'primos' y-
	actualiza la variable 'ip' que contiene el número de primos encontrados */
	genera_primos(3, 65521);		
	scanf("%lu", &n);		
	while(n != 0)
	{
		p = 0;
		i = 0;
		cont = 1;
		raiz = sqrt(n)+1;
		while((n != 1) && (primos[i] <= raiz) && (i < ip))
		{
			if(!(n % primos[i]))
			{
				p = 1;
				mult = 0;
				while(!(n % primos[i]))
				{
					n /= primos[i];			/*cont cuenta el número de factores primos*/
					mult ++;
				}
				cont *= (mult + 1);
				if(mult % 2)
				{
					p = 0;
					break;
				}
			}
			i++;
		}
		if(p == 0)							/*si no cambia de valor en el bucle while-*/
			puts("no");						/*entonces no hay factores primos de n, esto
											quiere decir que n es un primo */
		else
		{
			if(n > 1)						/*si n es mayor que 1, hay otro factor ---*/
				cont ++;					/*primo de n, que no estaba en el arreglo, -
											sin importar, por lo tanto se incrementa el-
											contador de los factores */
			if(cont % 2)
				puts("yes");
			else
				puts("no");
		}		
		scanf("%lu", &n);
	}
	return 0;
}

/* genera los números primos que se encuentran en el intervalo [a, b]*/
void genera_primos(unsigned int a, unsigned int b)
{
	int i;
	unsigned int k, p, raiz;

	for(k = a; k <= b; k += 2)
	{
		i = 0;
		p = 0;
		raiz = sqrt(k)+1;
		while((primos[i] <= raiz) && (i < ip))
		{
			if (!(k % primos[i++]))
			{
				p = 1;
				break;
			}
		}
		if(!p)
			primos[ip++] = k;
	}
}
