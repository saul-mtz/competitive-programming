#include <iostream>
#include <cstring>

using namespace std;

/* función principal */
int main()
{
    short i, k, c, n, r;
    short tmp1, tmp2, tmp3, tmp4;
    short copia_c, copia_tmp1, copia_tmp2, copia_tmp3, copia_tmp4;
    char cadena[401], mensaje[401];

    cin >> r >> c;
    while(r || c)
    {
        /* r es el número de filas */
        /* c es el número de columnas */
        cin >> cadena;
        
        /* longitud del mensaje leído */
        n = (short)strlen(cadena);
        
        /* inicialización de variables */
        i = tmp1 = 0;
        tmp2 = -1;
        tmp3 = n - 1;
        tmp4 = n;
        copia_c = c;

        /* lee una fila de izquierda a derecha */
        while(i < n)
        {
            for(k = 1, copia_tmp1 = tmp1; k < c; k ++)
                mensaje[i ++] = cadena[tmp1 ++]-7;
            tmp1 = copia_tmp1 + copia_c + 1;

            /* lee una columna de arriba hacia abajo */
            if(i < n)
            {
                for(k = 1, copia_tmp2 = tmp2; k < r; k ++)
                {
                    tmp2 += copia_c;
                    mensaje[i ++] = cadena[tmp2]-7;
                }
                tmp2 = copia_tmp2 + copia_c - 1;

                /* lee una fila de izquierda a derecha */
                if(i < n)
                {
                    for(k = 1, copia_tmp3 = tmp3; k < c; k ++)
                        mensaje[i ++] = cadena[tmp3 --]-7;
                    tmp3 = copia_tmp3 - copia_c - 1;

                    /* lee una columna de abajo hacia arriba */
                    if(i < n)
                    {
                        for(k = 1, copia_tmp4 = tmp4; k < r; k ++)
                        {
                            tmp4 -= copia_c;
                            mensaje[i ++] = cadena[tmp4]-7;
                        }
                        tmp4 = copia_tmp4 - copia_c + 1;
                    }
                }
            }
            
            /* decrementa el número de filas y columnas */
            r -= 2;
            c -= 2;
        }
        mensaje[n] = '\0';
        cout << mensaje << endl;
        cin >> r >> c;
    }

    return 0;
}
