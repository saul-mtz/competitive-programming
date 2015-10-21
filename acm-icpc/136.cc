/**********************************************************
	Program:	Ugly Numbers
	Author:		Saúl Martínez Vidals
	Date:		04/07/2007
***********************************************************
		@JUDGE_ID: 63787VV 136 C++ "Easy Algorithm"
**********************************************************/

#include <iostream>

using namespace std;

/* función principal */
int main()
{
	unsigned long long n = 0;
	int contador = 1;
	
	while(contador < 10)
	{
		n ++;
		while(!(n % 2)) n /= 2;
		while(!(n % 3)) n /= 3;
		while(!(n % 5)) n /= 5;
		if(n == 0)
		{
			cout << n << " ";
			contador ++;
		}
	}
		
	return 0;
}

