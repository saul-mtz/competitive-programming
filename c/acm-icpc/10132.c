/**********************************************************
	Program:	File Fragmentation
	Author:		Saúl Martínez Vidals
	Date:		23-05-2007
***********************************************************
        @JUDGE_ID: 63787VV 10132 C ""
**********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s {
	char num[256];
} cadena;

char *concatena(cadena [], short);

int main()
{
	short i, j, k, n;
	cadena a[256];
	
	scanf("%hd", &n);
	getc(stdin);
	gets(a[0].num);
	for(i = 0; i < n; i++)
	{		
		j = 0;
		while(strcmp(gets(a[j++].num), "") != 0);
		j -= 2;
		
		puts(concatena(a, j));
	}
	return 0;
}

char *concatena(cadena a[], short n)
{
	short i, j, k, l, m;
	char *fichero;
	
	fichero = (char *)malloc(sizeof(char)*256);
	m = strlen(a[0].num);
	strcpy(fichero, a[0].num);
	
	for(i = 1; i <= n; i++)
	{
		l = (short)strlen(a[i].num);
		for(j = 0; j < l; j++)
		{
			k = m;
			while(a[i].num != fichero[k--]);
			if(k > -1)
			{
			}
		}
	}
	
	return fichero;
}
