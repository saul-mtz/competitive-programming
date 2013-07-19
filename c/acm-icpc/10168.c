/**********************************************************
	Program:	Summation of Four Primes
	Author:		Saúl Martínez Vidals
	Date:		12-05-2007
***********************************************************
		@JUDGE_ID: 63787VV 10168 C "Number Theory"
**********************************************************/

#include <stdio.h>
#include <math.h>

int ip = 1;
long primos[450] = {2};

void genera_primos(long, long);
short es_primo(long);

int main()
{
	long n, aux, s[4];
	char a;
	int i0, i1, i2;
	
	genera_primos(3, 3163);	
	
	for(n = 0; n < ip; n++)
		printf("%ld: %ld\n", n+1, primos[n]);
	
	printf("%ld\n", primos[ip-1]);
	while(scanf("%ld", &n) != EOF)
	{
		if(n < 8)
			puts("\"Impossible.\"");
		else
		{
			aux = 0;
			i0 = 0;
			a = 1;
			while(a && (i0 < ip))
			{
				aux += primos[i0];
				i1 = i0;
				while(a && (i1 < ip))
				{
					aux += primos[i1];
					i2 = i1;
					while(a && (i2 < ip))
					{
						aux += primos[i2];
						if((n > aux) && es_primo(n-aux))
						{
							s[0] = primos[i0];
							s[1] = primos[i1];
							s[2] = primos[i2];
							s[3] = n-aux;
							a = 0;
							break;
						}
						aux -= primos[i2++];
					}
					aux -= primos[i1++];
				}
				aux -= primos[i0++];
			}
			printf("%ld %ld %ld %ld\n", s[0], s[1], s[2], s[3]);
		}
	}
	return 0;
}

/*genera los números primos que se encuentran en el intervalo [a, b]*/
void genera_primos(long a, long b)
{
	long i;
	long k, p, aux;

	for(k = a; k <= b; k += 2)
	{
		aux = sqrt(k)+1;
		i = 0; p = 0;
		while((primos[i] <= aux) && (i < ip))
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

short es_primo(long n)
{
	char p = 1;
	int aux = sqrt(n) + 1;
	int i = 0;
	
	while((primos[i] <= aux) && (i < ip))
	{
		if (!(n % primos[i++]))
		{
			p = 0;
			break;
		}
	}
	if(p)
		return 1;
	return 0;
}

