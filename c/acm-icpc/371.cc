/**********************************************************
	Program:	Ackermann Functions
	Author:		Saúl Martínez Vidals
	Date:		06/29/07
***********************************************************
		@JUDGE_ID: 63787VV 371 C++ ""
**********************************************************/

#include <iostream>

using namespace std;

/* función principal */
int main()
{
	int cont;
	unsigned long i_ack, m, n, s, i, mayor;

	cin >> m >> n;
	while((n != 0) || (m != 0))				/* ejecuta el bucle hasta que se lea lea -*/
	{										/* la entrada 0 0 */
		if(m > n)							/* si el valor leído de m es mayor que el-*/
		{									/* de n, se hace un intercambio de datos  */
			s = n;
			n = m;
			m = s;
		}
		mayor = 0;							/* la longitus mayor inicial es 0 */
		for(i = m; i <= n; i++)				/* calcula la longitud de la serie, para -*/
		{									/* cada elemento en el intervalo */
			s = i;
			cont = 0;
			do {
				cont ++;
				if(s % 2)
					s = 3*s + 1;
				else
					s /= 2;
			} while(s != 1);
			if(cont > mayor)				/* si la longitud de la serie calculada es*/
			{								/* mayor que la máxima que se tenía, se ac*/
				i_ack = i;					//tualiza el valor, por el nuevo encontrado
				mayor = cont;
			}
		}
		cout << "Between " << m <<" and " << n << ", " << i_ack <<
		" generates the longest sequence of " << mayor << " values.\n";
		
		cin >> m >> n;
	}

	return 0;
}

