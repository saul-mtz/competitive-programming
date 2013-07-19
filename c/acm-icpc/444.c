/**********************************************************
	Program:	Encoder and Decoder
	Author:		Saúl Martínez Vidals
	Date:		03-06-2007
***********************************************************
	@JUDGE_ID: 63787VV 444 C "Very very easy algorithm"
***********************************************************
					RESUELTO !!!
**********************************************************/

#include <stdio.h>
#include <string.h>

char *decodifica(char[], int);
char *codifica(char[], int);
void voltea(char[], int);

int main()
{
	int l;
	char cadena[245];

	while(gets(cadena) != NULL)
	{
		l = strlen(cadena);
		if((cadena[0] >= 48) && (cadena[0] <= 57))
			puts(decodifica(cadena, l));
		else
			puts(codifica(cadena, l));
	}
	return 0;
}


/* invierte el orden de los caracteres en 'cadena' */
void voltea(char cadena[], int n)
{
	int i, m;
	char aux;
	
	for(i = 0, m = n; i <= n/2; i++, m--)
	{
		aux = cadena[i];
		cadena[i] = cadena[m];
		cadena[m] = aux;
	}
}


/* decodifica el mensaje encriptado en cadena */
char *decodifica(char cadena[], int n)
{
	int i, j;
	static char mensaje[245], num[5];
	
	voltea(cadena, n-1);
	mensaje[0] = '\0';
	for(i = 0, j = 0; i < n; i += 2)
	{
		num[0] = cadena[i];
		num[1] = cadena[i+1];
		if(num[0] == '1')
		{
			num[2] = cadena[i+2];
			num[3] = '\0';
			i++;
		}
		else
			num[2] = '\0';
		mensaje[j++] = (char)atoi(num);
	}
	mensaje[j] = '\0';
	
	return mensaje;
}

/* codifica la cadena recibida como parametro */
char *codifica(char cadena[], int n)
{
	int i;
	static char cifrado[245], num[5];
	
	cifrado[0] = '\0';
	for(i = 0; i < n; i ++)
	{
		sprintf(num, "%i", cadena[i]);
		strcat(cifrado, num);
	}
	voltea(cifrado, strlen(cifrado)-1);
		
	return cifrado;
}

