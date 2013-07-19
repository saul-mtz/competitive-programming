/**********************************************************
	Program:	Super long sums
	Author:		Saúl Martínez Vidals
	Date:		21-05-2007
***********************************************************
        @JUDGE_ID: 63787VV 10013 C ""
***********************************************************
					RESUELTO !!
**********************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000005

typedef long longitud;


char *suma(char[], char[]);
void voltea(char[], int);

int main()
{
	long i, j, n, m;
	short s1, s2;
	char a[MAX], b[MAX];
	
	scanf("%ld", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%ld", &m);
		for(j = 0; j < m; j++)
		{
			scanf("%hd %hd", &s1, &s2);
			a[j] = s1+48;
			b[j] = s2+48;
		}
		a[j] = '\0';
		b[j] = '\0';
		printf("%s\n", suma(a, b));
		if(i < n-1)
			puts("");
		
	}
	return 0;
}

/*suma dos numeros enteros*/
char *suma(char a[], char b[])
{
	longitud la = strlen(a)-1, lb = strlen(b)-1;
	longitud i = 0, acarreo = 0, temp;
	static char t1[MAX], t2[MAX], *suma;

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

