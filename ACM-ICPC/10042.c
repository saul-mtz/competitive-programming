/* ********************************************************
    Program:    Smith Numbers
    Author:     Saúl Martínez Vidals
    Date:       09-05-2007
***********************************************************
        @JUDGE_ID: 63787VV 10042 C "Number Theory"
***********************************************************
                     RESUELTO !!!
**********************************************************/

#include <stdio.h>
#include <math.h>

int ip = 1;
/* arreglo para almacenar los numeros primos menores que 31607 ~= sqrt(1000000000) */
long primos[3410] = {2};

/* prototipos de funciones */
void genera_primos(long, long);
int factoriza(long);
int suma_digitos(long);

int main()
{
    int i, n, f;
    long m;

    genera_primos(3, 31607);                /*genera sólo los numeros primos necesarios-
                                            para este problema */
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%ld", &m);
        do {                                /*factoriza m en factores primos y regresa*/
            m++;                            /*la suma de ellos, si m es primo la fun -*/
            f = factoriza(m);               /*cion factoriza regresa 0, si m no sea un -
                                            smith number, intantamos con el numero m+1,-
                                            m+2, m+3, ... hasta encontrar uno */
        } while(!f || (suma_digitos(m) != f));
        printf("%ld\n", m);
    }
    return 0;
}

/*genera los números primos que se encuentran en el intervalo [a, b]*/
void genera_primos(long a, long b)
{
    int i;
    long k, p, aux;

    for(k = a; k <= b; k += 2)
    {
        aux = sqrt(k); i = 0; p = 0;
        while((primos[i] <= aux) && (i < ip))
        {
            if (!(k % primos[i++]))
            {
                p = 1;
                break;
            }
        }
        if(!p)
            primos[ip++] = k;
    }
}

/*factoriza en numeros primos y regresa la suma de ellos, si m es un numero primo el ---
valor regresado por la función es 0*/
int factoriza(long m)
{
    int suma = 0, i = 0;
    long m2 = m, aux = sqrt(m);

    while((m != 1) && (primos[i] <= aux) && (i < ip))
    {
        while(!(m % primos[i]))
        {
            m /= primos[i];
            suma += suma_digitos(primos[i]);
        }
        i++;
    }
    if(m == m2)
        return 0;
    else if(m > 1)
        suma += suma_digitos(m);
    return suma;
}

/*suma los dígitos de un numero */
int suma_digitos(long numero)
{
    int suma = 0;

    while(numero)
    {
        suma += (numero % 10);
        numero /= 10;
    }
    return suma;
}

