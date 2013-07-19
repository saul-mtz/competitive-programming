/**********************************************************
    Program:    Sumas de números consecutivos
    Author:     Saúl Martínez Vidals
    Date:       10/14/07
**********************************************************/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    bool primero;
    long i, formas, n, p, suma;
    long lim_inferior, lim_superior;
    
    while(cin >> n)
    {
        formas = 1;
        lim_inferior = 1;
        lim_superior = (long)(sqrt(2*n)) - 1;
        primero = false;
        suma = lim_superior*(lim_superior + 1) / 2;
        
        while(suma != 0)
        {
            while(suma < n)
            {
                lim_superior ++;
                suma += lim_superior;
            }
            if(suma == n)
            {
                if(!primero)
                {
                    p = lim_inferior;
                    primero = true;
                }
                formas ++;
            }
            suma -= lim_superior;
            suma -= lim_inferior;
            lim_superior --;
            lim_inferior ++;
        }
        cout << formas << " " << p << endl;
    }
    
    return 0;
}
