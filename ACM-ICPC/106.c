/**********************************************************
	Program:	Fermat vs. Pythagoras
	Author:		Saúl Martínez Vidals
	Date:		20-05-2007
***********************************************************
        @JUDGE_ID: 63787VV 106 C "Easy Algorithm"
***********************************************************
					RESUELTO !!!
**********************************************************/

#include <stdio.h>
#include <math.h>

short primos_r(long, long);

int main()
{
	long k, n, x, y, z, a, b, trios, ca, cb;
	char num[1000005];
	
	while(scanf("%ld", &n) != EOF)
	{
		for(a = 0; a <= n; a++)
			num[a] = 0;
		trios = 0;
		a = 1;
		b = 2;
		ca = 1;
		cb = 4;
			
		while((cb + ca) <= n)
		{
			while((cb + ca) <= n)
			{
				if(primos_r(a, b))
				{
					k = 1;
					x = cb - ca;
					y = 2 * a * b;
					z = cb + ca;
					while(z*k <= n)
					{
						num[x*k] = 1;
						num[y*k] = 1;
						num[z*k] = 1;
						k++;
					}
					trios ++;
				}
				b += 2;
				cb = b*b;
			}
			a ++;
			b = a + 1;
			ca = a*a;
			cb = b*b;
		}
		b = 0;
		for(a = 1; a <= n; a++)
			if(!num[a]) b ++;
		printf("%ld %ld\n", trios, b);

	}
	return 0;
}

short primos_r(long a, long b)
{
	long r;
	while(b)
	{
		r = a % b;
		a = b;
		b = r;
	}
	if(a == 1)
		return 1;
	return 0;
}

