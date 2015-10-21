/**********************************************************
    Program:    Ordenamiento en zig zag
    Author:     Saúl Martínez Vidals
    Date:       10/14/07
**********************************************************/

#include <iostream>

using namespace std;

/* prototipos de funciones */
void cambio(long *, long *);
int paso_ida(long [], int);
int paso_vuelta(long [], int);
bool paso(long [], int);


void imprime(long num[], int n)
{
    int i;
    cout << "impresion\n";
    for(i = 0; i < n; i ++)
        cout << num[i] << " ";
    cout << endl;
}


/* función principal */
int main()
{
    int i, n, i_i, i_v, pasos;
    long numeros[1001];
    
    while(cin >> n)
    {
        pasos = 1;
        
        /* lee los n numeros */
        for(i = 0; i < n; i ++)
            cin >> numeros[i];
        /* calcula los cambios hechos en el primer paso */
        i_i = paso_ida(numeros, n);
        i_v = paso_vuelta(numeros, n);
        if(i_i != 0)
        {
            /* calcula el número de pasos necesarios */
            while(paso(numeros, n))
                pasos ++;
            pasos ++;
        }
        /* despliega la respuesta en pantalla */
        cout << i_i << " " << i_v << " " << pasos << endl;
    }
    
    return 0;
}

/* hace el cambio de dos elementos del arreglo */
void cambio(long *a, long *b)
{
    long s;
    
    s = *b;
    *b = *a;
    *a = s;
}

/* hace el recorrido hacia adelante */
int paso_ida(long numeros[], int n)
{
    int i, cambios;
    
    for(i = 0, cambios = 0; i < n-1; i ++)
    {
        if(numeros[i] > numeros[i+1])
        {
            cambio(&numeros[i], &numeros[i+1]);
            cambios ++;
        }
    }
    
    return cambios;
}

/* hace el recorrido hacia atras */
int paso_vuelta(long numeros[], int n)
{
    int i, cambios;
    
    for(i = n-1, cambios = 0; i > 0; i --)
    {
        if(numeros[i-1] > numeros[i])
        {
            cambio(&numeros[i-1], &numeros[i]);
            cambios ++;
        }
    }
    
    return cambios;
}

/* realiza un paso de ida y vuelta sobre el arreglo */
bool paso(long numeros[], int n)
{
    if(paso_ida(numeros, n))
    {
        paso_vuelta(numeros, n);
            return true;
    }
    return false;
}

