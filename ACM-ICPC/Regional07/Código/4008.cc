/**********************************************************
    Program: Last digit
    Author:  Saúl Martínez Vidals
    Date:    mar feb 26 12:29:40 CST 2008
    Number:  4008
**********************************************************/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

typedef unsigned int entero;

/* constantes */
const entero MAX = 1000000;                 /* número máximo de caracteres */
const entero NUM_PRIMOS = 78500;            /* números primos de 2 a 1000000 */
const entero MAX_PRIMO = 999984;            /* primo mayor en [2, 1000000] más uno */

/* variables globales */
entero primos[NUM_PRIMOS] = {2, 3, 5}, ip = 3;
entero indices[MAX_PRIMO] = {0, 0, 0, 1, 0, 2};
entero primo_actual;
entero mayor_actual;

/* prototipos de función */
void genera_primos(void);
entero busca_repeticiones(string, entero[], entero);
void factoriza(entero, entero[]);
void quita_repeticiones(entero[], entero[], entero);


/* función principal */
int main()
{
    entero repeticiones[27], factores_n[MAX_PRIMO], factores_todos[MAX_PRIMO];
    entero i, j, n, anterior, longitud, respuesta;
    string cadena;
    
    /* llena los arreglos primos[] e indices[] */
    genera_primos();

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
            sort(repeticiones, repeticiones+longitud);

            /* inicializa los arreglos */
            for(i = 0; i < n; i ++)
                factores_n[i] = factores_todos[i] = 0;

            /* factoriza n1!+n2! ... */
            anterior = 0;
            mayor_actual = 1;
            primo_actual = 1;

            for(i = 0; i < longitud; i++)
            {
                if(repeticiones[i] != anterior)
                {
                    factoriza(repeticiones[i], factores_n);
                    mayor_actual = repeticiones[i];
                }
                for(j = 0; j < primo_actual; j ++)
                    factores_todos[j] += factores_n[j];
                anterior = repeticiones[i];
            }
            j = primo_actual;
/*
cout << "tds! =\t";
for(i = 0; i < primo_actual-1; i ++)
    cout << "(" << primos[i] << "^" << factores_todos[i] << ")*";
cout << "(" << primos[i] << "^" << factores_todos[i] << ")\n";
//*/

            /* factoriza n! */
            factoriza(n, factores_n);
/*
cout << n <<"! =\t";
for(i = 0; i < primo_actual-1; i ++)
    cout << "(" << primos[i] << "^" << factores_n[i] << ")*";
cout << "(" << primos[i] << "^" << factores_n[i] << ")\n";
//*/
            /* quita las parejas de 2-5's y factores comúmes */
            quita_repeticiones(factores_n, factores_todos, j);
/*
cout << "sin! =\t";
for(i = 0; i < primo_actual-1; i ++)
    cout << "(" << primos[i] << "^" << factores_n[i] << ")*";
cout << "(" << primos[i] << "^" << factores_n[i] << ")\n";
//*/
            /* calcula el resultado */
            for(i = 0; i < primo_actual; i ++)
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

/* genera los números primos que ese encuentran en el rango (2, b] */
void genera_primos()
{
    bool p = true;
    entero i = 0;
    entero k, raiz;

    for(k = 7; k <= MAX; k += 2, i = 0, p = true)
    {
        /* raíz cuadrada de k */
        raiz = (entero)(sqrt(k) + 1);

        while(primos[i] <= raiz)
        {
            /* primos[i] divide a k, k no es primo */
            if(!(k % primos[i ++]))
            {
                p = false;
                break;
            }
        }
        /* si p es verdadero, k es primo */
        if(p)
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

/* descomposición de los factoriales */
void factoriza(entero m, entero factores[])
{
    entero i, k, n, raiz;

    if(m != 1)
    {
        for(k = mayor_actual+1; k <= m; k ++)
        {
            n = k;
            if(n == primos[primo_actual])
                primo_actual ++;
            else
            {
                i = 0; raiz = (entero)(sqrt(n) + 1);

                while(primos[i] < raiz)
                {
                    /* primos[i] divide a k */
                    if(!(n % primos[i]))
                    {
                        n /= primos[i];
                        factores[i] ++;
                    }
                    else
                        i ++;
                }
            }

            /* la condición se cumple cuando m es un número primo */
            if(n != 1)
                factores[indices[n]] ++;
        }
    }
}

/* quita las parejas de dos y cincos */
void quita_repeticiones(entero a[], entero b[], entero mayor)
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
    k = 0;
    while(k < mayor)
    {
        if(a[k] == b[k])
            a[k] = 0;
        else
            a[k] -= b[k];
        k ++;
    }
}

