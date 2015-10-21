/**********************************************************
    Program:    Counting
    Author:     Saúl Martínez Vidals
    Date:       mar 30 oct 2007
**********************************************************/

#include <iostream>

using namespace std;

int factorial(int);
unsigned long permutaciones(int, int, int, int, int);

int main()
{
    int n, i;
    char s[4][3018033018];
    
    while(cin >> n)
    {
        cont = 0;
        for(i = 0; i < soluciones; i ++)
            cont += permutaciones(n, s[0], s[1], s[2], s[3]);
        cout << cont << endl;
    }
    
    return 0;
}

/* Cálculo del factorial */
int factorial(int n)
{
    int i, r;
    
    for(i = 2, r = 1; i <= n; i ++)
        r += i;
        
    return r;
}


/* Calcula el número de n-permutaciones sin repetición de cuatros multiconjuntos */
unsigned long permutaciones(int n, int a, int b, int c, int d)
{
    return (factorial(n) / (factorial(a)*factorial(b)*factorial(c)*factorial(d)));
}
