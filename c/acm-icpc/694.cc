/**********************************************************
	Program:	The Collatz Sequence
	Author:		Saúl Martínez Vidals
	Date:		06/30/07	
***********************************************************
		@JUDGE_ID: 63787VV 694 C++ "Easy Algorithm"
**********************************************************/

#include <iostream>

using namespace std;

/* función principal */
int main()
{	
	long long a, b, s, caso = 0, pasos;
	
	cin >> a >> b;
	while((a > -1) || (b > -1))
	{
		if(a > b)
		{
			cout << "a es mayor que b\n";
			s = a;
			a = b;
			b = s;
		}	
		caso ++;
		s = a;
		pasos = 0;
		do {
			pasos ++;
			if(s % 2)
				s = 3*s + 1;
			else
				s /= 2;
		} while((s != 1) && (s <= b));
		if(s == 1)
			pasos ++;
		cout << "Case " << caso <<": A = " << a << ", limit = " << b <<
		", number of terms = " << pasos << endl;
		cin >> a >> b;
	}
	
	return 0;
}
