/*
Program:	Reverse and Add
Author:		Saúl Martínez Vidals
*/

/* @JUDGE_ID: 63787VV 10018 C "Easy algorithm"*/

#include <stdio.h>
#include <string.h>

#define L_MAX	11

void reverse(char[], short, short);
void invierte(char[], char[], short);
short palindromo(char numero[], short n);

int main()
{
	char numero[L_MAX];
	short n, i, l;
	scanf("%hd", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%s", numero);
		l = (short)strlen(numero) - 1;
		reverse(numero, l, 1);
	}
	return 0;
}

void reverse(char numero[], short n, short count)
{
	char numr[L_MAX], aux[L_MAX + 1];
	short i, j, carry = 0;
	invierte(numero, numr, n);
	for(i = n, j = 0; i >= 0; i--, j++)
	{
		if((aux[j] = numero[i]-48 + numr[i]-48 + carry) > 9)
		{
			carry = 1;
			aux[j] %= 10;
		}
		else
			carry = 0;
		aux[j] += 48;
	}
	if(carry == 1)
		aux[j++] = '1';
	aux[j] = '\0';
	if(!palindromo(aux, j-1))
		reverse(aux, j-1, ++count);
	else
		printf("%hd %s\n", count, aux);
}

void invierte(char numero[], char numr[], short n)
{
	short i, m;
	for(i = 0, m = n; i <= n/2; i++, m--)
	{
		numr[i] = numero[m];
		numr[m] = numero[i];
	}
	numr[n+1] = '\0';
}

short palindromo(char numero[], short n)
{
	short i, m;
	for(i = 0, m = n; i <= n/2; i++, m--)
	{
		if(numero[i] != numero[m])
			return 0;
	}
	return 1;
}
