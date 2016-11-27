/**********************************************************
	Program:	Mischievous Children
	Author:		Saúl Martínez Vidals
	Date:		06/30/07
***********************************************************
		@JUDGE_ID: 63787 10338 C++ "técnica de programación"
**********************************************************/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

unsigned long long factorial(short);

/* función principal */
int main()
{
	char cadena[21];
	short i, n, m, s;
	unsigned long long formas, aux;

	cin >> m;
	for(short k = 1; k <= m; k++)			/* ejecuta el bucle k-veces */
	{
		cin >> cadena;
		n = strlen(cadena);
		i = 0;
		aux = 1;
		sort(cadena, cadena + n);			/* ordena la cadena en orden léxico */
		while(i < n-1)						/* cuenta el número de apariciones de cada*/
		{									/* letra de la palabra, en caso de estar -*/
			s = 1;							/* más de una ves, se calcula el factorial*/
			while((i < n-1) && (cadena[i] == cadena[++i])) s++;	/* del número de apari*/
			if(s > 1)						/* ciones, y se va almacentando el resulta*/
				aux *= factorial(s);		/* do en la variable aux */
		}
		formas = factorial(n) / aux;		/* calcula el número de formas de ordenar */
											/* la cadena */
		cout << "Data set " << k << ": " << formas << endl;
	}

	return 0;
}

/* calcula el factorial de n*/
unsigned long long factorial(short n)
{
	if((n == 1) || (n == 0))
		return 1;
	return (n * factorial(n-1));
}

