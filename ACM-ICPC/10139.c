/* ********************************************************
	Program:	Factovisors
	Author:		Saúl Martínez Vidals
	Date:		24-04-2007
***********************************************************
	@JUDGE_ID: 63787VV 10139 C "Easy algorithm"
***********************************************************
					RESUELTO !!!
******************************************************** */

#include <stdio.h>
#include <math.h>
typedef struct p
{
	unsigned long numero;
	short multiplicidad;
} primo;

unsigned int ip = 1, primos[4975] = {2};

/* prototipos de funciones */
void genera_primos(unsigned int, unsigned int);
short factoriza(unsigned long, primo[]);

int main()
{
	short lm, i, s;
	unsigned long a, n, m, aux;
	primo fact_m[14];

	genera_primos(3, 46337);		
	while(scanf("%lu %lu", &n, &m) != EOF)
	{
		if(m <= n)
			printf("%lu divides %lu!\n", m, n);
		else
		{
			for(i = 0; i < 14; i++)
				fact_m[i].multiplicidad = 0;
			lm = factoriza(m, fact_m);			
			if(fact_m[lm].numero > n)
				printf("%lu does not divide %lu!\n", m, n);
			else
			{
				s = 1;
				for(i = 0; i <= lm; i++)
				{
					a = 0;
					aux = fact_m[i].numero;
					while(aux <= n)
					{
						a += (n/aux);
						aux *= fact_m[i].numero;
					}
					if(a < fact_m[i].multiplicidad)
					{
						s = 0;
						break;
					}
				}				
				if(s)
					printf("%lu divides %lu!\n", m, n);
				else
					printf("%lu does not divide %lu!\n", m, n);
			}
		}
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


/*factoriza m en sus factores primos*/
short factoriza(unsigned long m, primo factorizacion[])
{
	short i_fact = -1;
	int i = 0, aux = sqrt(m)+1;
	
	while((m != 1) && (primos[i] <= aux) && (i < ip))
	{
		if(!(m % primos[i]))
		{
			factorizacion[++i_fact].numero = primos[i];
			while(!(m % primos[i]))
			{
				m /= primos[i];
				factorizacion[i_fact].multiplicidad ++;
			}
		}
		i++;
	}
	if(m > 1)
	{
		factorizacion[++i_fact].numero = m;
		factorizacion[i_fact].multiplicidad ++;
	}
	return i_fact;
}

