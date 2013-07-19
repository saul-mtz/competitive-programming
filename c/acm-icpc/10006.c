/* ********************************************************
	Program:	Carmichael Numbers
	Author:		Saúl Martínez Vidals
	Date:		12-05-2007
***********************************************************
	@JUDGE_ID: 63787VV 10006 C "Number Theory"
	
***********************************************************
					RESUELTO !!!
******************************************************** */

#include <stdio.h>
#include <math.h>

unsigned int ip = 54;
unsigned int primos[4975] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53,
							59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
							127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181,
							191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251};

/* prototipos de funciones */
short factoriza(unsigned int, unsigned int []);

int main()
{
	short l, cn;
	unsigned int n, i, factorizacion[8];
	
	scanf("%d", &n);
	while(n != 0)
	{
		cn = 0;
		l = factoriza(n, factorizacion);
		if(l)
		{
			cn = 1;
			for(i = 0; i <= l; i++)
			{
				if((n-1) % factorizacion[i])
				{
					cn = 0;
					break;
				}
			}
		}
		if(cn)
			printf("The number %d is a Carmichael number.\n", n);
		else
			printf("%d is normal.\n", n);
		scanf("%d", &n);
	}
	return 0;
}

/*factoriza m en sus factores primos*/
short factoriza(unsigned int m, unsigned int factorizacion[])
{
	short i_fact = -1, multiplicidad = 0;
	int i = 0, aux = sqrt(m);
	
	while((m != 1) && (primos[i] <= aux) && (i < ip))
	{
		if(!(m % primos[i]))
		{
			multiplicidad = 0;
			factorizacion[++i_fact] = primos[i]-1;
			while(!(m % primos[i]))
			{
				m /= primos[i];
				multiplicidad ++;
			}
		}
		if(multiplicidad > 1)
			return 0;
		i++;
	}
	if(m > 1)
		factorizacion[++i_fact] = m-1;
	return i_fact;
}

