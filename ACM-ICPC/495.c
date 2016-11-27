/*
Program:	Fibonacci Freeze
Author:		Saúl Martínez Vidals
Date:		30-04-2007
*/

/* @JUDGE_ID: 63787VV 495 C "trampa"*/

#include <stdio.h>
#include <string.h>

#define MAX 1050

typedef struct cad
{
	char cadena[MAX];
} string;

string sucesion[5001] = {"0", "1"};

void voltea(char [], int);
char *suma(char [], char []);

int main()
{
	int i;
	char a[MAX] = "0", b[MAX] = "1", *sum;

	for(i = 2; i <= 5000; i++)
	{
		sum = suma(a, b);
		strcpy(a, b);
		strcpy(b, sum);
		strcpy(sucesion[i].cadena, sum);
	}

	while(scanf("%d", &i) != EOF)
		printf("The Fibonacci number for %d is %s\n", i, sucesion[i].cadena);

	return 0;
}

/*invierte una cadena de caracteres de longitud n*/
void voltea(char cadena[], int n)
{
	int i, j;
	char aux;
	for(i = 0, j = n; i <= n/2; i++, j--)
	{
		aux = cadena[i];
		cadena[i] = cadena[j];
		cadena[j] = aux;
	}	
}

/*suma dos numeros enteros*/
char *suma(char a[], char b[])
{
	int la = strlen(a)-1, lb = strlen(b)-1;
	int i = 0, acarreo = 0, temp;
	char t1[MAX], t2[MAX], *suma;

	while((la >= 0) && (lb >= 0))
	{
		temp = a[la--] + b[lb--] + acarreo - 96;
		if(temp > 9)
		{
			acarreo = 1;
			temp %= 10;
		}
		else
			acarreo = 0;
		t1[i++] = temp + 48;
	}
	t1[i] = '\0';
	if(la == lb)
	{
		if(acarreo == 1)
		{
			t1[i++] = '1';
			t1[i] = '\0';
		}
		voltea(t1, i-1);
		suma = t1;
	}
	else
	{
		if(acarreo == 0)
		{
			voltea(t1, i-1);
			if(la > lb)
			{
				strncpy(t2, a, la+1);
				t2[la+1] = '\0';
			}
			else
			{
				strncpy(t2, b, lb+1);
				t2[lb+1] = '\0';
			}
			suma = strcat(t2, t1);
		}
		else
		{
			if(la > lb)
			{
				lb = la;
				strcpy(t2, a);
			}
			else
				strcpy(t2, b);
			while((lb >= 0) && (acarreo == 1))
			{
				temp = t2[lb--] + acarreo - 48;
				if(temp > 9)
				{
					acarreo = 1;
					temp %= 10;
				}
				else
					acarreo = 0;
				t1[i++] = temp + 48;
			}
			if(acarreo == 1)
				t1[i++] = '1';
			t1[i] = '\0';
			voltea(t1, i-1);
			suma = t1;
			if(lb >= 0)
			{
				strncpy(t1, b, lb+1);
				suma = strcat(t2, t1);
			}
		}
	}
	return suma;
}
