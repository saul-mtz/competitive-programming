/**********************************************************
    Program:    Mirror, Mirror
    Author:     Saúl Martínez Vidals
    Date:       03/10/07
***********************************************************
	@JUDGE_ID: 63787VV 466 C++ "Array Manipulation"
**********************************************************/

#include <iostream>
#include <string>

using namespace std;

#define MAX 100

void rotacion(short n, char patron[MAX][MAX], char rotado[MAX][MAX])
{
    short i, j, ir, jr;
    
    /* hace la rotaciónn de noventa grados */
    for(jr = i = 0; i < n; i ++, jr ++)
    {
        ir = n-1;
        for(j = 0; j < n; j ++)
            rotado[i][j] = patron[ir --][jr];
    }
}

/* Reflejo */
void refleja( short n, char original[MAX][MAX], char nuevo[MAX][MAX] ) {
	int i, j;
	for( i = 0 ; i < n ; i++ )
		for( j = 0 ; j < n ; j++ )
			nuevo[i][j] = original[n-i-1][j];
}

/* imprime el patron */
void imprime(short n, char patron[MAX][MAX])
{
    short i, j;
    
    for(i = 0; i < n; i ++)
    {
        for(j = 0; j < n; j ++)
            cout << patron[i][j] << " ";
        cout << endl;
    }
}

bool compara(short n, char a[MAX][MAX], char b[MAX][MAX])
{
	short i, j;
	for (i = 0; i < n; i ++)
		for (j = 0; j < n; j ++)
			if(a[i][j] != b[i][j])
				return false;	
	return true;
}

void copia(short n, char fuente[MAX][MAX], char destino[MAX][MAX])
{
	short i, j;
	for (i = 0; i < n; i ++)
		for (j = 0; j < n; j ++)
		    destino[i][j] = fuente[i][j];
}

short solucion(short n, char original[MAX][MAX], char modificado[MAX][MAX])
{
    char aux[MAX][MAX], aux2[MAX][MAX];

    /* verifica si no a habido cambio */
    if(compara(n, original, modificado))
        return 0;
    /* crea una copia del patron modificado */
    copia(n, original, aux);
    
    rotacion(n, aux, aux2);
    if(compara(n, modificado, aux2))
        return 90;
        
    rotacion(n, aux2, aux);
    if(compara(n, modificado, aux))
        return 180;
        
    rotacion(n, aux, aux2);
    if(compara(n, modificado, aux2))
        return 270;

    refleja(n, original, aux);
    if(compara(n, modificado, aux))
        return 1;
    rotacion(n, aux, aux2);
    if(compara(n, modificado, aux2))
        return 2;
        
    rotacion(n, aux2, aux);
    if(compara(n, modificado, aux))
        return 3;
        
    rotacion(n, aux, aux2);
    if(compara(n, modificado, aux2))
        return 4;
    return -1;
}

/* funciÃ³n principal */
int main()
{
    int k = 1;
    short i, j, n;
    char original[MAX][MAX], modificado[MAX][MAX];
    string  c1 = " was rotated 90 degrees.",
            c2 = " was rotated 180 degrees.",
            c3 = " was rotated 270 degrees.",
            c4 = " was reflected vertically.",
            c5 = " was preserved.",
            c6 = " was improperly transformed.",
    	    c7 = " was reflected vertically and rotated 90 degrees.",
    	    c8 = " was reflected vertically and rotated 180 degrees.",
    	    c9 = " was reflected vertically and rotated 270 degrees.";
	    
    while(cin >> n)
    {
        for(i = 0; i < n; i ++)
        {
            for(j = 0; j < n; j ++)
                cin >> original[i][j];
            for(j = 0; j < n; j ++)
                cin >> modificado[i][j];
        }
        cout << "Pattern " << k;
        switch(solucion(n, original, modificado))
        {
            case -1:    cout << c6;
                        break;
            case 0:     cout << c5;
                        break;
            case 1:     cout << c4;
                        break;
            case 2:     cout << c7;
                        break;
            case 3:     cout << c8;
                        break;
            case 4:     cout << c9;
                        break;
            case 90:    cout << c1;
                        break;
            case 180:   cout << c2;
                        break;
            case 270:   cout << c3;
        }

        cout << endl;
        k ++;
    }
    
    return 0;
}

