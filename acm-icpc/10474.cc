/**********************************************************
	Program:	Where is the Marble?
	Author:		Saúl Martínez Vidals
	Date:		07/02/07	
***********************************************************
		@JUDGE_ID: 63787VV 10474 C++ "Binary Search"
**********************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

int busqueda_binaria(int a, int n, int datos[]);

int main()
{
	int i, k= 0, l, m, n, p, q, numeros[10000];
	
	cin >> n >> q;
	while((n != 0) || (q != 0))
	{
		for(i = 0; i < n; i ++)
			cin >> numeros[i];
		sort(numeros, numeros + n);
		cout << "CASE# " << ++k <<":\n";
		for(i = 0; i < q; i ++)
		{
			cin >> m;
			if(n == 1)
			{
				if(numeros[0] == m)
					cout << m << " found at 1\n";
				else
					cout << m << " not found\n";
			}
			else if ((p = busqueda_binaria(m, n, numeros)) != -1)
				cout << m << " found at " << p << endl;
			else
				cout << m << " not found\n";
		}
		cin >> n >> q;
	}
	
	return 0;
}


/* busqueda binaria */
int busqueda_binaria(int a, int n, int datos[])
{
	int i = 0, j = n, m;
	
	while(i < j)
	{
		m = (i + j)/2;
		if(a > datos[m])
			i = m+1;
		else
			j = m;
	}
	if(a == datos[i])
		return i+1;
	else
		return -1;
}
