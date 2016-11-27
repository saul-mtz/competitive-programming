/**********************************************************
	Program:	Factors and Factorials
	Author:		Saúl Martínez Vidals
	Date:		06/28/07
***********************************************************
		@JUDGE_ID: 63787VV 160 C++ "Easy Algorithm"
**********************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

typedef short entero;
const entero MAX = 25;
static entero ip = MAX, primos[MAX] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
									43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
									
typedef unsigned int entero;

/* clase que genera números primos */

/* clase generadora de número primos */
class Primos
{
	public:
	entero primos[4792];
	entero num_primos;
	entero k;

	Primos(entero a, entero b)
	{
		entero i, raiz;
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
	
	void imprime()
	{
		for(k = 0; k < num_primos; k++)
			cout << primos[k] << "\t";
		cout << endl;
	}
};

/* declaración de la clase Numero */
class Numero
{
	entero i, n, factores_p[MAX], primo_mayor;
	
public:
	/* constructor de la clase Numero */
	Numero(entero);
	void factores();
	short factoriza(entero, entero[]);
	void imprime_factorizacion();
};

/* función principal */
int main()
{

}


/* implementación del constructor de la clase Numero */
Numero :: Numero(entero numero)
{
	n = numero;
	for(i = 0; i < MAX; i++)
		factores_p[i] = 0;
}


/* I M P L E M E N T A C I Ó N    D E    L O S    M E T O D O S */
/* factoriza m en sus factores primos */
void Numero :: factores()
{
	entero k;

	for(i = 2; i <= n; i ++)
	{
		if(k = factoriza(i, factores_p))
			primo_mayor = k;
	}
}

/* factoriza un numero entero como producto de primos */
short Numero :: factoriza(entero m, entero factores_p[])
{
	entero k = 0, l = m;

	while((m > 1) && (k < ip))
	{
		if(!(m % primos[k]))
		{
			if(primos[k] == l)
			{
				factores_p[k]++;
				return k;
			}
			while(!(m % primos[k]))
			{
				m /= primos[k];
				factores_p[k] ++;
			}
		}
		else
			k ++;
	}

	return 0;
}

/* imrpime la factorización del número */
void Numero :: imprime_factorizacion()
{
	cout << setw(3) << n << "! =";
	for(i = 0; i <= primo_mayor; i++)
	{
		if(!(i % 15) && (i != 0))
			cout << "\n      ";
		cout<< setw(3) << factores_p[i];
	}
	cout << "\n";
}

