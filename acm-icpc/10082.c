/*
Program:	Wertyu
Author:		Saúl Martínez Vidals
*/

/* @JUDGE_ID: 63787VV 10082 C "Easy algorithm" */

#include <stdio.h>
#include <stdlib.h>

#define MAX_W    100                            /*mÃ¡xima longitud de la cadena laÃ­da*/

/* * * * * *  P R O T O T I P O S    D E    F U N C I O N E S  * * * * */
char sustituye(char c);

int main()
{
    FILE *arch_in, *arch_out;
    char c[MAX_W];
    int i=0;
	while((c[i] = getc(stdin)) != EOF)		/*mientras el caracter leÃ¬do es distinto */
		printf("%c", sustituye(c[i++]));	/*del fin de archivo, se invoca a la función
											sustituye que es la encargada de reemplazar-
											la letra leída por la correcta, al mismo ti-
											empo que se imprime en pantalla*/
    return 0;
}

/*función que sustituye la letra recibída como parámetro, por el caracter correcto según
el QWERTY keyboard, devuelve el caracter buscado*/
char sustituye(char c)
{
    switch(c)
    {
        case ' ':    return ' ';
        case '\n':   return '\n';
        case 'B':    return 'V';
        case 'C':    return 'X';
        case 'D':    return 'S';
        case 'E':    return 'W';
        case 'F':    return 'D';
        case 'G':    return 'F';
        case 'H':    return 'G';
        case 'I':    return 'U';
        case 'J':    return 'H';
        case 'K':    return 'J';
        case 'L':    return 'K';
        case 'M':    return 'N';
        case 'N':    return 'B';
        case 'O':    return 'I';
        case 'P':    return 'O';
        case 'R':    return 'E';
        case 'S':    return 'A';
        case 'T':    return 'R';
        case 'U':    return 'Y';
        case 'V':    return 'C';
        case 'W':    return 'Q';
        case 'X':    return 'Z';
        case 'Y':    return 'T';
        
        case '1':    return '`';
        case '2':    return '1';
        case '3':    return '2';
        case '4':    return '3';
        case '5':    return '4';
        case '6':    return '5';
        case '7':    return '6';
        case '8':    return '7';
        case '9':    return '8';
        case '0':    return '9';
        
        case '-':    return '0';
        case '=':    return '-';
        case '[':    return 'P';
        case ']':	 return '[';
        case '\\':   return ']';
        case ';':    return 'L';
        case '\'':   return ';';
        case ',':    return 'M';
        case '.':    return ',';
        case '/':    return '.';
    }
}
