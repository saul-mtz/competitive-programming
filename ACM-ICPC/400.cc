/**********************************************************
    Program:    Unix ls
    Author:     Saúl Martínez Vidals
    Date:       09/19/07	
***********************************************************
	@JUDGE_ID: 63787VV 264 C++ ""
**********************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

int comparar(const void *, const void *);

/* función principal */
int main()
{
    short columnas, filas, i, indice, j, n, l_max, l_aux;
    string archivos[102];
    string guiones = "------------------------------------------------------------\n";
    
    while(cin >> n)
    {
        l_max = 0;
        for(i = 0; i < n; i++)
        {
            cin >> archivos[i];
            l_aux = (short)archivos[i].size();
            if(l_aux > l_max)
                l_max = l_aux;
        }
        /* ordena los elementos usando qsort */
        qsort(archivos, n, sizeof(string), comparar);
        cout << guiones;
        l_max += 2;
        columnas = 60/l_max;
        if((columnas % (l_max - 2) < )
            columnas ++;
        filas = (short)ceil((float)n/(float)columnas);
        
        for(i = 0; i < filas; i ++)
        {
            indice = i;
            for(j = 0; (j < columnas) && indice < n; j++)
            {
                l_aux = (short)archivos[indice].size();
                cout << archivos[indice];
                for(l_aux; l_aux < l_max; l_aux++)
                    printf(" ");
                indice += filas;
            }
            puts("");
        }
    }

    return 0;
}

/* funcion que compara las cadenas */
int comparar(const void *a, const void *b)
{
    return (*(string *)a).compare(*(string *)b);
}
