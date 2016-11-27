/**********************************************************
	Program:	Soundex
	Author:		Saúl Martínez Vidals
	Date:		15-06-2007
***********************************************************
        @JUDGE_ID: 63787VV 10260 C "Easy Algorithm"
**********************************************************/

#include <stdio.h>
#include <string.h>

char codificacion(char);

int main()
{
	char palabra[21], salida[21], i, j, k, l, n, s;
	
	while(gets(palabra) != NULL)
	{
		l = 0;
		n = (char)strlen(palabra);
		for(i = 0; i < n; i++)
		{
			k = codificacion(palabra[i]);
			if(k)
			{
				s = 1;
				for(j = 0; (j < l) && s; j++)
				{
					if(k == salida[j])
						s = 0;
				}
				if(s)
					salida[l++] = k;
			}
		}
		salida[l] = '\0';
		puts(salida);
	}
	return 0;
}

char codificacion(char c)
{
	switch(c)
	{
		case 'B':	return '1';
		case 'F':	return '1';
		case 'P':	return '1';
		case 'V':	return '1';
		case 'C':	return '2';
		case 'G':	return '2';
		case 'J':	return '2';
		case 'K':	return '2';
		case 'Q':	return '2';
		case 'S':	return '2';
		case 'X':	return '2';
		case 'Z':	return '2';
		case 'D':	return '3';
		case 'T':	return '3';
		case 'L':	return '4';
		case 'M':	return '5';
		case 'N':	return '5';
		case 'R':	return '6';
		default:	return 0;
	}
}

