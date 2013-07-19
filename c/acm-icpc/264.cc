/**********************************************************
	Program:	Count on Cantor 
	Author:		Saúl Martínez Vidals
	Date:		06/26/07	
***********************************************************
	@JUDGE_ID: 63787VV 264 C++ "Mathematic Formula"
**********************************************************/

#include <iostream>

using namespace std;

/* función principal */
int main()
{
	int i, n, a, b, sumatoria[4474];
	
	/* almacen a en el arreglo sumatoria, una serie de números que nos ayudan a saber en
	que parte del arreglo de Cantor debémos buscar el número deseado */
	for(i = 0, n = 0; i < 4473; i++)
	{
		n += i;
		sumatoria[i] = n;
	}	
	/* ejecuta el siglo mientras no se encuentre el fin de archivo */
	while(cin >> n)
	{
		i = 0;
		/* se mueve a través de los datos del arrehlo previamente calculado */
		while(sumatoria[i] < n)
			i++;
		a = sumatoria[i--] - n + 1;
		b = n - sumatoria[i];
		/* imprime el resultado de acuerdo a la diagonal en la que esta, si la diagobal-
		es un número impar, la dirección en la que se lee el arreglo de cantor es hacia
		arriba, en caso contrario se va leyendo hacia abajo */
		if(i % 2)
			cout << "TERM " << n << " IS " << b << "/" << a << "\n";
		else
			cout << "TERM " << n << " IS " << a << "/" << b << "\n";
	}
	
	return 0;
}

