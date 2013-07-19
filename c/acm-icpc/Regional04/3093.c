/**********************************************************
	Program:	IP Address
	Author:		Saúl Martínez Vidals
	Date:		12-06-2007
***********************************************************
        @JUDGE_ID: 9327DA 3093 C "Easy Algorithm"
**********************************************************/

#include <stdio.h>
#include <math.h>

short convierte(char[]);

int main()
{
	char cadena[35], n1[10], n2[10], n3[10], n4[10];
	short i, j, k, n;
	
	scanf("%hd\n", &n);
	for(k = 0; k < n; k++)
	{
		i = 0;
		gets(cadena);		
		for(j = 0; j < 8; j++)
			n1[j] = cadena[i++];
		for(j = 0; j < 8; j++)
			n2[j] = cadena[i++];
		for(j = 0; j < 8; j++)
			n3[j] = cadena[i++];
		for(j = 0; j < 8; j++)
			n4[j] = cadena[i++];
		n1[8] = n2[8] = n3[8] = n4[8] = '\0';
		printf("%hd.%hd.%hd.%hd\n", convierte(n1),
									convierte(n2),
									convierte(n3),
									convierte(n4));
	}
	
	return 0;
}

short convierte(char numero[])
{
	short i, num = 0;
	
	for(i = 0; i < 8; i++)
		num += ((short)pow(2, i) * (numero[7-i]-48));
			
	return num;
}
