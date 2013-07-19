/**********************************************************
	Program:	Palindromes
	Author:		Saúl Martínez Vidals
	Date:		01-06-2007
***********************************************************
        @JUDGE_ID: 63787VV 401 C "Easy algorithm"
**********************************************************/

#include <stdio.h>
#include <string.h>

short es_palindroma(char[], short);
short es_espejo(char[], short);
short tiene_reverso(char);

char reversos[][2]= {
					'1', '1',
					'2', 'S',
					'3', 'E',
					'5', 'Z',
					'8', '8',
					'A', 'A',
					'E', '3',
					'H', 'H',
					'I', 'I',
					'J', 'L',
					'L', 'J',
					'M', 'M',
					'O', 'O',
					'S', '2',
					'T', 'T',
					'U', 'U',
					'V', 'V',
					'W', 'W',
					'X', 'X',
					'Y', 'Y',
					'Z', '5',
					};

int main()
{
	char cadena[100];
	short k;
	
	while(scanf("%s", cadena) != EOF)
	{
		k = 0;
		if(es_palindroma(cadena, (short)strlen(cadena) - 1))
			k ++;
		if(es_espejo(cadena, (short)strlen(cadena) - 1))
			k += 2;
		printf("%s ", cadena);
		switch(k)
		{
			case 0:	puts("-- is not a palindrome.\n");
					break;
			case 1:	puts("-- is a regular palindrome.\n");
					break;
			case 2: puts("-- is a mirrored string.\n");
					break;
			case 3:	puts("-- is a mirrored palindrome.\n");
		}
	}
	return 0;
}

/* verifica si cadena es palindroma */
short es_palindroma(char cadena[], short n)
{
	short i, j;
	for(i = 0, j = n; i <= n/2; i++, j--)
		if(cadena[i] != cadena[j]) return 0;
	return 1;
}

/* verifica si cadena es espejo */
short es_espejo(char cadena[], short n)
{
	short i, j, k;
	
	for(i = 0, j = n; i <= n/2; i++, j--)
	{
		if(k = tiene_reverso(cadena[i]))
		{
			if(reversos[k][1] != cadena[j])
				return 0;
		}
		else
			return 0;
	}
	return 1;
}

/* verifica si el caractér c tiene un reverso */
short tiene_reverso(char c)
{
	short i = 0, j = 20, m;
	
	while(i < j)
	{
		m = (i + j)/2;
		if(c > reversos[m][0])
			i = m + 1;
		else
			j = m;
	}
	if(c == reversos[i][0])
		return i;
	return 0;
}

