/*
Program:	Word Crosses
Author:		Saúl Martínez Vidals
*/

/* @JUDGE_ID: 63787VV 159 C "Easy algorithm" */

#include <stdio.h>
#include <string.h>

#define mayor(a, b) (a>b)?a:b			/*macro que regresa el mayor de dos numeros   */
#define MAX_W 12						/*longitud máxima de las cadenas leídas leídas*/

/* * * * * *  P R O T O T I P O S    D E    F U N C I O N E S  * * * * */
int coinciden(char [], char []);
void parte_cadena(char [], char [], char);
void imprime(char [], char [], char [], char [], int, int);

/*función principal*/
int main()
{
	int i1, i2;								/*guardan el índice de la primer y tercer-*/
											/*cadena*/
	char c, c1[MAX_W], c2[MAX_W], c3[MAX_W], c4[MAX_W];
	c = getc(stdin);
	while(c != '#')							/*se realiza mientras no se encuentre el--*/
	{										/*caracter '#'*/
	    ungetc(c, stdin);
		scanf("%s %s %s %s", c1, c2, c3, c4);
		/*si i1 e i2 son mayores que 0 hay caracteres en común, en este caso se imprimen
		las palabras en el archivo*/
		if((i1 = coinciden(c1, c2))>=0 && (i2 = coinciden(c3, c4))>=0)
		    imprime(c1, c2, c3, c4, i1, i2);
		/*si son < 0 entonces no hay coincidencias y se escribe un mensaje*/
		else
			puts("Unable to make two crosses");
		getc(stdin);
		c = getc(stdin);
		if(c != '#')
     		puts("");
	}
	return 0;
}

/*esta funcion verifica si hay algun caracter en comun en las dos palabras pasadas como
argumentos, si esto ocurre retorna el valor del indice de la primer cadena en el cual
aparece el caracter, si no pasa esto retorna -1*/
int coinciden(char c1[], char c2[])
{
	int i, j;
	for(i = 0; i < strlen(c1); i++)
	{
		for(j = 0; j < strlen(c2); j++)
			if(c1[i] == c2[j]) return i;
	}
	return -1;
}

/*función que se encarga de escribir las palabras en el archivo de salida*/
void imprime(char a[], char b[], char c[], char d[], int i1, int i2)
{
	char cruces[MAX_W*2-3][MAX_W*2 + 3], b2[MAX_W-1], d2[MAX_W-1];
	int i, j, l1, l2, l3, m, n;
	short count;
	for(i = 0; i < MAX_W*2 - 3; i++)		/*inicalizacion del arreglo con espacios  */
	{
		for(j = 0; j < MAX_W*2 + 3; j++)
		    cruces[i][j] = ' ';
	}
	parte_cadena(b, b2, a[i1]);             /*parte en dos las cadenas que se escriben*/
	parte_cadena(d, d2, c[i2]);             /*verticalmente*/
	l1 = strlen(a);                         /*se almacena la longitud de la primera y-*/
	l2 = strlen(c);                         /*tercer palabra, ya que se usaran despues*/
	m = mayor(strlen(b), strlen(d));        /*m es el renglon donde se escribiran las -
	                                        palabras horizontales*/
	for(i = 0; i < l1; i++)
	    cruces[m][i] = a[i];                /*se guardan en el arreglo las dos pala  -*/
	for(i = 0, j = l1+3; i < l2; i++, j++)  /*bras horizontales*/
	    cruces[m][j] = c[i];
	cruces[m][j] = '\0';
	l2 = strlen(d);
	l3 = strlen(d2);
	for(i = strlen(b), n = m-1, count = 0; i > 0; i--, n--, count++)
	{												/*en esta parte se escriben en el-*/
	    cruces[n][i1] = b[i-1];                     /*arreglo las primeras subcadenas-*/
	    if(l2 == 0 || count >= l2)
	        cruces[n][i1+1] = '\0';
	}
	for(i = l2, n = m-1; i > 0; i--, n--)			/*de las palabras verticales de  -*/
	{												/*de abajo hacia arriba, empezando*/
	    cruces[n][l1+i2+3] = d[i-1];                /*un renglon mas arriba de donde -*/
	    cruces[n][l1+i2+4] = '\0';                  /*se escribieron las horizontales*/
	}												/*se escriben las segundas subcade*/
	for(i = 0, n = m+1; i < strlen(b2); i++, n++)
	{												/*nas en el arreglo de las pala - */
	    cruces[n][i1] = b2[i];                      /*bras verticales, pero ahora de -*/
	    if(l3 == 0 || i >= l3)
	        cruces[n][i1+1] = '\0';
	}
	for(i = 0, n = m+1; i < l3; i++, n++)
	{												/*arriba hacia abajo empezando des*/
	    cruces[n][l1+i2+3] = d2[i];                 /*deun renglon mas abajo de donde */
	    cruces[n][l1+i2+4] = '\0';					/*se escribieron las horizontales */
	}
	n = mayor(strlen(b2), strlen(d2));
	for(i = 0; i < m+n+1; i++)                      /*se imprime en el archivo el con-*/
	{                                               /*tenido del arreglo*/
		for(j = 0; cruces[i][j] != '\0'; j++)
			printf("%c", cruces[i][j]);
		puts("");
	}
}

/*parte cadena1 en dos subcadenas, toma como punto de particion el caracter c, cadena1 -
contendra los caracteres antes de c, y cadena2 los caracteres despues de c, ninguna ca -
dena contiene a c*/
void parte_cadena(char cadena1[], char cadena2[], char c)
{
	int i=0, j, l = strlen(cadena1);
	while(cadena1[i++] != c);
	cadena1[i-1] = '\0';
	for(i, j=0; i < l; i++, j++)
	    cadena2[j] = cadena1[i];
	cadena2[j] = '\0';
}
