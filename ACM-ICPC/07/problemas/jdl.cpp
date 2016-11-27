/**********************************************************
    Program:    Juego de letras
    Author:     Saúl Martínez Vidals
    Date:       10/12/07
**********************************************************/

#include <iostream>

using namespace std;

int main()
{
    string palabra;
    short alfabeto[] = {1,    // A
                        5,    // B
                        3,    // C
                        3,    // D
                        3,    // E
                        4,    // F
                        5,    // G
                        6,    // H
                        8,    // I
                        7,    // J
                        8,    // K
                        9,    // L
                        7,    // M
                        6,    // N
                        9,    // O
                        0,    // P
                        1,    // Q
                        4,    // R
                        2,    // S
                        5,    // T
                        7,    // U
                        4,    // V
                        2,    // W
                        2,    // X
                        6,    // Y
                        1     // Z
                        };
    char c;
    int i, l, valor;
    
    /* lee las palabras */
    while(cin >> palabra)
    {
        valor = 0;
        l = palabra.size();
        
        /* calcula la suma de los valores */
        for(i = 0; i < l; i ++)
            valor += alfabeto[palabra.at(i) - 65];
        cout << valor << endl;
    }
    
    return 0;
}

