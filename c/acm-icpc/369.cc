/**********************************************************
	Program:	Combinations
	Author:		Saúl Martínez Vidals
	Date:		06/24/07
***********************************************************
		@JUDGE_ID: 63787VV 369 C++ "Combination"
**********************************************************/

#include <iostream>

using namespace std;

int main()
{
	short aux, i, k, n, m, m2, numeros[100];
	unsigned long long combinaciones;
	
	cin >> n >> m;
	while((n != 0) || (m != 0))
	{
		m2 = m;
		if(n == m)
			combinaciones = 1;
		else
		{
			if((n -m) > m)
				m = n-m+1;
			else
				m++;
			for(i = m, k = 0; i <= n; i++, k++)
				numeros[k] = i;
			m = k;
			i = 0;
			aux = 1;
			while(m > 1)
			{
				if(i >= k)
				{
					aux *= m;
				 	i = 0;
					m--;
				}
				else if(!(numeros[i] % m))
				{
					numeros[i] /= m;
					i = 0;
					m--;
				}
				else
					i++;
			}
			combinaciones = 1;
			for(i = 0; i < k; i++)
				combinaciones *= numeros[i];
 			combinaciones /= aux;
		}
		cout << n << " things taken " << m2 << " at a time is " << combinaciones <<
			" exactly.\n";
		cin >> n >> m;
	}
	return 0;
}

