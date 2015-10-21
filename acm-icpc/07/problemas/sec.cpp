/**********************************************************
    Program:    Soluciones enteras de una ecuación cuadrática
    Author:     Saúl Martínez Vidals
    Date:       10/13/07
**********************************************************/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long a, b, c, discriminante, soluciones;
    double p, p_entera, p_decimal;
    
    while(cin >> a >> b >> c)
    {
        soluciones = 0;
        if(a == 0)                          /* cuando b = 0 */
        {
            if(b == 0)                      /* ecuación de la forma c = 0 */
            {
                if(c == 0)                  /* a, b y c son 0 */
                    soluciones = -1;
            }
            else if (c == 0)                /* ecuación de la forma bx = 0 */
                soluciones = 1;
            else if(!(-c % b))              /* ecuación de la forma bx + c = 0*/
                soluciones = 1;
        }
        else                                /* ecuación de la forma ax^2 + bx + c = 0 */
        {
            discriminante = b*b - 4*a*c;
            if(discriminante >= 0)          /* si la condición se cumple, significa - */
            {                               /* que no hay raíces complejas */
                p = sqrt(discriminante);
                p_decimal = modf(p, &p_entera);
                if(p_decimal == 0)          /* verifica que el discriminante sea un --*/
                {                           /* número entero */
                    discriminante = (long)p_entera;
                    
                    /* si las soluciones de la ecuación son múltiplos de 2*a, las raíces
                    son enteras y se incrementa el número de soluciones */
                    if(!((-b + discriminante) % (2*a)))
                        soluciones ++;
                    if(!((-b - discriminante) % (2*a)))
                        soluciones ++;
                }
            }
        }
        
        /* imprime el número de soluciones */
        cout << soluciones << endl;
    }
    
    return 0;
}
