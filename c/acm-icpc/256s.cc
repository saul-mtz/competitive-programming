/**********************************************************
    Program:    Quirksome Squares 
    Author:     Saúl Martínez Vidals
    Date:       06/26/07	
***********************************************************
	@JUDGE_ID: 63787VV 264 C++ "Mathematic Formula"
**********************************************************/

#include <iostream>
#include <string>

using namespace std;

/* función principal */
int main()
{
    short n, i, l;
    string *numeros;
    string numeros2[] = {"00", "01", "81"};
    string numeros4[] = {"0000", "0001", "2025", "3025", "9801"};
    string numeros6[] = {"000000", "000001", "088209", "494209", "998001"};
    string numeros8[] = {"00000000", "00000001", "04941729", "07441984", "24502500",
                         "25502500", "52881984", "60481729", "99980001"};
    
    while(cin >> n)
    {
        switch(n)
        {
            case 2: numeros = numeros2;
                    l = 3;
                    break;
            case 4: numeros = numeros4;
                    l = 5;
                    break;
            case 6: numeros = numeros6;
                    l = 5;
                    break;
            case 8: numeros = numeros8;
                    l = 9;
                    break;
        }
        i = 0;
        while(i < l)
            cout << numeros[i ++] << endl;
    }
    
    return 0;
}

