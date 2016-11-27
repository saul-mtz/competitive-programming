/**********************************************************
    Program:    Quirksome Squares 
    Author:     Saúl Martínez Vidals
    Date:       06/26/07	
***********************************************************
	@JUDGE_ID: 63787VV 264 C++ "Mathematic Formula"
**********************************************************/

#include <iostream>
#include <cmath>

using namespace std;

/* función principal */
int main()
{
    short n;
    unsigned long s, mitad1, mitad2, i, limite, cuadrado;
    
    while(cin >> n)
    {
        switch(n)
        {
            case 2: limite = 99;
                    s = 10;
                    break;
            case 4: limite = 9999;
                    s = 100;
                    break;
            case 6: limite = 999999;
                    s = 1000;
                    break;
            case 8: limite = 99999999;
                    s = 10000;
                    break;
        }
        for(i = 0; i <= limite; i++)
        {
            mitad1 = i/s;
            mitad2 = i%s;
            cuadrado = (unsigned long)pow((double)(mitad1 + mitad2), 2);
            if(cuadrado == i)
                cout << i << endl;
        }
    }
    
    return 0;
}
