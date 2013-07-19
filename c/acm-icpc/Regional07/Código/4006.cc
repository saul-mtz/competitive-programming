/**********************************************************
    Program: Remedial Forecast
    Author:  Saúl Martínez Vidals
    Date:    mié feb 27 04:17:20 CST 2008
    Number:  4006
**********************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

/* definición de tipos de dato */
typedef unsigned short entero;      /* tipo entero */

typedef struct                      /* datos de cada alumno */
{
    entero id;                      /* identificador */
    entero p;                       /* promedio */
    entero he;                      /* horas de estudio */
    entero hc;                      /* horas de clase */
    bool r;                         /* resultado */
} alumno;

typedef struct                      /* distancias manhattan */
{
    entero n;
    bool r;
} dist;

/* lista con la informaciónd de los alumnos */
alumno h[100];
dist respuestas[5000];

/* para uso del buffer */
string cadena;
istringstream buffer;
entero contador = 0;

/* llena el historial de alumnos */
void llena_historial(entero *hr)
{
    static string cadena;
    static alumno a;

    buffer >> a.id >> a.p >> a.he >> a.hc >> a.r;
    do {
        /* inserta los datos en la lista, hr es el número de alumnos */
        h[(*hr) ++] = a;

        /* usa un flujo de cadena */
        getline(cin, cadena);
        buffer.str(cadena);
    } while(buffer >> a.id >> a.p >> a.he >> a.hc >> a.r);
}

/* lee los datos de los alumnos nuevos y resuelve el problema para cada uno de ellos */
bool llena_resuelve(entero *hr)
{
    static entero k, i, d, menor;
    static alumno a, b;
    bool s;

    /* lee k */
    cin >> k;
    getline(cin, cadena);
    while(k)
    {
        buffer.clear();
        getline(cin, cadena);
        buffer.str(cadena);
        
        if(buffer >> b.id >> b.p >> b.he >> b.hc)
        {
            if(buffer >> b.r)
            {
                a.id = b.id;
                a.p = b.p;
                a.he = b.he;
                a.hc = b.hc;
                a.r = b.r;
                return true;
            }

            /* distancias manhattan */
            menor = *hr/2 + 1;
            for(i = 0; i < *hr; i ++)
            {
                d = abs(h[i].p-b.p) + abs(h[i].he-b.he) + abs(h[i].hc-b.hc);
                if(d >= k)
                {
                    if(d == k)
                    {
                        s = h[i].r;
                        break;
                    }
                    else if((d < menor) && (d % 2))
                        s = h[i].r;
                }
            }
            
            /* almacena las respuestas para imprimirlas posteriormente */
            respuestas[contador].n = b.id;
            respuestas[contador ++].r = s;
        }
        else
        {
            if(!(cin >> k))
                return false;
            getline(cin, cadena);
            buffer.str(cadena);
        }
    }
}

/* función principal */
int main()
{
    bool s;
    entero hr, i;

    do {
        hr = 0;
        getline(cin, cadena);
        buffer.str(cadena);

        /* llena el historial de alumnos */
        llena_historial(&hr);

        /* lee los datos de los alumnos nuevos y resuelve el problema para cada */
        s = llena_resuelve(&hr);

        /* imprime las respuestas */
        for(i = 0; i < contador-1; i ++)
            cout << respuestas[i].n << " " << respuestas[i].r << endl;
        cout << respuestas[i].n << " " << respuestas[i].r;
    } while(s);

    return 0;
}

