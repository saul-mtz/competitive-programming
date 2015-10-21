/*
Program:	Automated Judge Script
Author:		Saúl Martínez Vidals
*/

/* @JUDGE_ID: 63787VV 10188 C "Easy algorithm" */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_L	125
#define MAX_P   105

/* * * * * *  P R O T O T I P O S    D E    F U N C I O N E S  * * * * */
int compara(char [], char []);
void judge(char correctas[MAX_P][MAX_L], char usuario[MAX_P][MAX_L], short, short *);

/*función principal*/
int main()
{
	short i, j, n, m, contador = 1;
	char correctas[MAX_P][MAX_L], usuario[MAX_P][MAX_L];
	scanf("%hd", &n);
	while(n != 0)
	{
        getc(stdin);
		for(i = 0; i < n; i++)
		{
			j = 0;
			while((correctas[i][j++] = getc(stdin)) != '\n');
			correctas[i][j-1] = '\0';
		}
		scanf("%hd", &m);
		getc(stdin);
		for(i = 0; i < m; i++)
		{
			j = 0;
			while((usuario[i][j++] = getc(stdin)) != '\n');
			usuario[i][j-1] = '\0';
		}
		if( n != m)
           	printf("Run #%d: Wrong Answer\n", contador++);
		else
		    judge(correctas, usuario, n, &contador);
		scanf("%hd", &n);
	}
	return 0;
}

/*juez que evalua las respuestas*/
void judge(char correctas[MAX_P][MAX_L], char usuario[MAX_P][MAX_L], short n, short *count)
{
	short i, j, r;
	char temp[MAX_L], temp2[MAX_L];
	for(i = 0; i < n; i++)
	{
		j = 0;
		while((temp[j] = correctas[i][j++]) != '\0');
		j = 0;
		while((temp2[j] = usuario[i][j++]) != '\0');
		r = compara(temp, temp2);
		if(r == 0)
		{
           	printf("Run #%d: Wrong Answer\n", (*count)++);
           	return;
		}
	}
	printf("Run #%d: ", (*count)++);
	switch(r)
	{
		case 0:		puts("Wrong Answer");
					break;
		case 1:		puts("Presentation Error");
					break;
		default:    puts("Accepted");
	}
}

/*hace la comparación de las dos cadenas recibidas como parámetros, hay tres posibles --
valores de retorno, 0 la respuesta es incorrecta, 1 error de presentacion y 2 las cade -
nas son iguales*/
int compara(char c1[], char c2[])
{
	int j=0, k=0;
	if(strcmp(c1, c2) == 0)								/*si son iguales se regresa 2  */
		return 2;
	else
	{
		while((c1[j] != '\0') && (c2[k] != '\0'))
		{
			while(c1[j] == ' ') j++;			/*ignora los espacios en ambas cadenas */
			while(c2[k] == ' ') k++;
			if((c1[j++] != c2[k++]) && (isdigit(c1[j-1]) || isdigit(c2[k-1])))
   				return 0;
		}
		if(abs(k-j) > 1)
			return 0;
		return 1;							/*si se llega a esta instrucción, la única --
									/*posibilidad es que exista error de presentación  */
	}
}
