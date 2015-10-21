/*
Program:	Primary Arithmetic
Author:		Saúl Martínez Vidals
Date:       14-06-2007
*/

/* @JUDGE_ID: 63787VV 10035 C "Easy algorithm" */

#include <stdio.h>
#include <string.h>

#define N_MAX   12

/* * * * * *  P R O T O T I P O S    D E    F U N C I O N E S  * * * * */
void cuenta_acarreos(char[], char[], short, short);

/*función principal*/
int main()
{
	char num1[N_MAX], num2[N_MAX];
	scanf("%s %s", num1, num2);
	while((num1[0] != '0') || (num2[0] != '0'))
	{
		cuenta_acarreos(num1, num2, (short)strlen(num1)-1, (short)strlen(num2)-1);
		scanf("%s %s", num1, num2);
	}
	return 0;
}

/*recibe los numeros como cadenas de caracteres, y las longitudes de ambas*/
void cuenta_acarreos(char num1[N_MAX], char num2[N_MAX], short l1, short l2)
{
	short acarreos = 0, aux = 0;
	for(l1, l2; (l1 >= 0) && (l2 >= 0); l1--, l2--)
	{
		if((num1[l1]-48 + num2[l2]-48 + aux) > 9)
		{
			aux = 1;
		    acarreos++;
		}
		else
		    aux = 0;
	}
	if(l1 >= 0)
	{
		for(l1; l1 >= 0; l1--)
		{
            if((num1[l1]-48 + aux) > 9)
			{
				aux = 1;
				acarreos++;
			}
			else
				break;
		}
	}
	else if(l2 >= 0)
	{
		for(l2; l2 >= 0; l2--)
		{
            if((num2[l2]-48 + aux) > 9)
			{
				aux = 1;
				acarreos++;
			}
			else
				break;
		}
	}
	switch(acarreos)
	{
		case 0:		puts("No carry operation.");
		    		break;
		case 1:		puts("1 carry operation.");
		    		break;
		default:    printf("%hd carry operations.\n", acarreos);
	}
}
