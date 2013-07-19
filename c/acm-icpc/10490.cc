/**********************************************************
	Program:	Mr. Azad and His Son!!!!!
	Author:		Saúl Martínez Vidals
	Date:		07/03/07	
***********************************************************
		@JUDGE_ID: 63787VV 10490 C++ "Prime numbers"
**********************************************************/

#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long entero;

/* clase generadora de número primos */
class Primo
{
	public:
	entero primos[4792];					/* arreglo que contiene todos los números --
											primos del intervalo deseado */
	entero num_primos;						/* numero de primos hay en el arreglo */
	entero k, raiz;

	/* constructor de la clase, se encarga de generar los números */
	Primo(entero a, entero b)
	{
		entero i;
		bool p;
		
		primos[0] = 2;
		num_primos = 1;

		for(k = a; k <= b; k += 2)
		{
			i = 0;
			p = true;
			raiz = (entero)sqrt(k) + 1;
			while((primos[i] <= raiz) && (i < num_primos))
			{
				if (!(k % primos[i++]))
				{
					p = false;
					break;
				}
			}
			if(p)
				primos[num_primos ++] = k;
		}
	}

	/* verifica si n es primo */
	bool es_primo(entero n)
	{
		k = 0;
		raiz = (entero)sqrt(n) + 1;
		
		if(n == 2)
			return true;

		while((k < num_primos) && (primos[k] <= raiz))
		{
			if(!(n % primos[k]))
				return false;
			k ++;
		}

		return true;
	}
};


/* función principal */
int main()
{
	Primo p(3, 46337);
	entero k;
	int n;
	
	cin >> n;
	while(n != 0)
	{
		if((n > 1) && (p.es_primo(n)))
		{
			k = (entero)pow(2.0, n) - 1;
		
			if(p.es_primo(k))
				cout << "Perfect: " << (entero)pow(2.0, n-1)*k << "!\n";
			else
				cout << "Given number is prime. But, NO perfect number is available.\n";
		}
		else
			cout << "Given number is NOT prime! NO perfect number is available.\n";
		cin >> n;
	}
		
	return 0;
}

