/**********************************************************
    Program:    Selfdescribing Sequence
    Author:     Saúl Martínez Vidals
    Date:       10/08/07
**********************************************************/

#include <iostream>
#define MAX 673367

using namespace std;

struct saul
{
    unsigned long lim_inferior;
    unsigned long lim_superior;
};

unsigned long buscar_incremento(unsigned long n, saul f[MAX])
{
    unsigned long i;
    
    i = 1;
    while(f[i ++].lim_inferior <= n);
    return (i - 2);
}

int main()
{
    saul f[MAX];
    unsigned long mayor, n, incremento;
    
    f[1].lim_inferior = 1;
    f[1].lim_superior = 1;    
    f[2].lim_inferior = 2;
    f[2].lim_superior = 3;
    f[3].lim_inferior = 4;
    f[3].lim_superior = 5;
    f[4].lim_inferior = 6;
    f[4].lim_superior = 8;
    
    mayor = 1;
    n = 2;
    while(n < MAX)
    {
        incremento = buscar_incremento(n, f);
        f[n].lim_inferior = mayor + 1;
        mayor += incremento;
        f[n].lim_superior = mayor;
        n ++;
    }
    
    cin >> n;
    while(n != 0)
    {
        cout << buscar_incremento(n, f) << endl;
        cin >> n;
    }
    
    return 0;
}

