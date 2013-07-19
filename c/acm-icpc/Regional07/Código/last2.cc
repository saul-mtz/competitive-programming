#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

#define MAX 78500

using namespace std;

typedef unsigned long entero;
typedef long double ld;

/* variables globales */
entero primos[MAX] = {2}, indices[999985], ip = 1;

/* genera los números primos que ese encuentran en el rango (2, b] */
void genera_primos(entero b)
{
    char p = 0;
    entero i = 0;
    entero k, raiz;
    for(k = 3; k <= b; k+=2, i=0, p=0)
    {
        raiz = (entero)(sqrt(k) + 1);
        while((primos[i] <= raiz) && i < ip)
        {
            if(!(k % primos[i ++]))
            {
                p = 1;
                break;
            }
        }
        if(!p)
        {
            primos[ip] = k;
            indices[k] = ip ++;
        }
    }
}

/* calcula las ocurrencias de cada letra en la cadena, almacena el número de ocurrencias-
en el arreglo "arr", regresa el número de caracteres distintos */ 
entero busca_repeticiones(string cadena, entero arr[], entero n)
{
    char k;
    entero i, j, r;

    i = 0; j = 0;
    while(i < n)
    {
        r = 0;
        k = cadena.at(i);
        while((i < n) && (cadena.at(i) == k))
        {
            i ++;
            r ++;
        }
        arr[j ++] = r;
    }

    return j;
}

/* factoriza el número "m", almacena los factores en el arreglo "factores" */
void factoriza(entero m, entero factores[])
{
    entero i = 0, raiz = (entero)(sqrt(m) + 1);

    while((m != 1) && (primos[i] < raiz))
    {
        /* primos[i] divide a m */
        if(!(m % primos[i]))
        {
            m /= primos[i];
            factores[i] ++;
        }
        else
            i ++;
    }

    /* la condición se cumple cuando m es un número primo */
    if(m != 1)
        factores[indices[m]] ++;
}

/* descompone n! en factores primos, los cuales se almacenan en el arreglo "factores"  */
void factoriza_fact(entero n, entero factores[])
{
    entero i, j;

    /* 1! = 1 */
    if(n == 1)
        ;
    else if(n == 2)
    {
        /* 2! = 2, a diferencia de 1, 2 si es un valor que se necesita almacenar para uso
        posterior */
        factores[0] ++;
    }
    else
    {
        for(i = 2; i <= n; i ++)
            factoriza(i, factores);
    }
}

/* quita las parejas de dos y cincos */
void quita_repeticiones(entero a[], entero b[], entero maximo)
{
    entero tmp2, tmp5, k;

    /* ocurrencias de los números dos y cinco en el arreglo a */
    tmp2 = a[0];
    tmp5 = a[2];

    /* quita el numero de parejas posibles */
    if(tmp2 && tmp5)
    {
        if(tmp2 < tmp5)
        {
            a[0] -= tmp2;
            a[2] -= tmp2;
        }
        else
        {
            a[0] -= tmp5;
            a[2] -= tmp5;
        }
    }

    /* ocurrencias de los números dos y cinco en el arreglo b */
    tmp2 = b[0];
    tmp5 = b[2];

    /* quita el numero de parejas posibles */
    if(tmp2 && tmp5)
    {
        if(tmp2 < tmp5)
        {
            b[0] -= tmp2;
            b[2] -= tmp2;
        }
        else
        {
            b[0] -= tmp5;
            b[2] -= tmp5;
        }
    }

    /* elimina factores comúnes */
    for(k = 0; k < maximo; k ++)
    {
        if(a[k] == b[k])
            a[k] = 0;
        else
            a[k] -= b[k];
    }
}

/* función principal */
int main()
{
    string cadena;
    entero n, i, k, longitud, respuesta;

    /* factorización de n! */
    entero factores_n[MAX];
    /* factorización de n1!*n2!*...*nk! */
    entero factores_todos[MAX];
    /* número de veces que se repite cada letra */
    entero repeticiones[1000000];

    genera_primos(1000003);
    while(cin >> cadena)
    {
        respuesta = 1;
        /* tamaño de la cadena */
        n = cadena.size();

        if(n != 1)
        {
            /* ordena la cadena leída */
            sort(cadena.begin(), cadena.end());

            /* "longitud" es el número de caracteres distintos */
            longitud = busca_repeticiones(cadena, repeticiones, n);

            /* inicializa los arreglos */
            for(i = 0; (i < n) && (i < MAX); i ++)
                factores_n[i] = factores_todos[i] = 0;

            /* factoriza n! */
            factoriza_fact(n, factores_n);

            /* factoriza n1!+n2! ... */
            sort(repeticiones, repeticiones+longitud);

            for(i = 0; i < longitud; i ++)
                factoriza_fact(repeticiones[i], factores_todos);

            /* quita las parejas de 2-5's y factores comúmes */
            quita_repeticiones(factores_n, factores_todos, repeticiones[longitud-1]);

            /* calcula el resultado */
            for(i = 0; (i < n) && (i < ip); i ++)
            {
                if(factores_n[i])
                {
                    while(factores_n[i] --)
                    {
                        respuesta *= primos[i];
                        respuesta %= 10;
                    }
                    respuesta %= 10;
                }
            }
        }
        cout << respuesta << endl;
    }
    return 0;
}
