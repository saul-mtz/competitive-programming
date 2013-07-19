/**********************************************************
	Program:	Twin Primes
	Author:		Saúl Martínez Vidals
	Date:		13-06-2007
***********************************************************
        @JUDGE_ID: 63787VV 10394 C ""
**********************************************************/

#include <stdio.h>
#include <math.h>

#define MAX_P 1175780


long primos[MAX_P] = {2};
long ip = 1, itw = 0;
long twin_primes[100001];

/* prototipo de función */
void genera_primos(unsigned long, unsigned long);

/* función principal */
int main()
{
	long n;
	
	genera_primos(3, 18409201);

	/*while(scanf("%ld", &n) != EOF)
		printf("(%ld, %ld)\n", twin_primes[n-1].a, twin_primes[n-1].b);*/

	return 0;
}
/* genera los números primos que se encuentran en el longervalo [a, b]*/
void genera_primos(unsigned long a, unsigned long b)
{
	unsigned long i, k, p, raiz;
	
	for(k = a; k <= b; k += 2)
	{
		i = 0;
		p = 1;
		raiz = sqrt(k)+1;
		while((primos[i] <= raiz) && (i < ip))
		{
			if (!(k % primos[i++]))
			{
				p = 0;
				break;
			}
		}
		if(p)
		{
			if(primos[ip-1] == k-2)
			{
				printf("(%ld, %ld)\n", k-2, k);
				twin_primes[itw] =  k;
			}
			primos[ip++] = k;
		}
	}
}

