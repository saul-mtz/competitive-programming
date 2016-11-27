/**********************************************************
	Program:	Editing a book
	Author:		Saúl Martínez Vidals
	Date:		03-06-2007
***********************************************************
		A Big Contest of Brute Force: 168008
**********************************************************/

#include <stdio.h>
#include <string.h>

short busca_numeros(short n, short *in, char s, char numeros[])
{
	short i, k, l;
	
	for(i = 0, k = 0; i < n; i++)
	{
		if(numeros[i] == s)
		{
			*in = i;
			while(numeros[i++] == s)
			{
				k ++;
				s ++;
			}
			break;
		}
	}
	
	return k;
}

void quita_elementos(char numeros[], short i, short m, short n)
{
	short j;

	for(j = 0; j < n; j++, i++)
		numeros[i] = numeros[i+m];
}

int main()
{
	char e, numeros[15];
	short count, i, l, m, n;
	
	scanf("%hd", &n);
	while(n != 0)
	{
		count = 0;
		for(i = 0; i < n; i++)
			scanf("%hd", &numeros[i]);
		for(i = 0; i < n; i++)
			numeros[i] += 48;
		numeros[i] = '\0';
		m = n;
		e = '1';
		while(numeros[0] != '\0')
		{
			if(numeros[0] != e)
			{
				l = busca_numeros(m, &i, e, numeros);
				quita_elementos(numeros, i, l, m);
				m -= l;
				e += l;
				count ++;
			}
			else
			{
				quita_elementos(numeros, 0, 1, m);
				e ++;
				m --;
			}
			numeros[m] = '\0';
		}
		printf("%hd\n", count);
		for(i = 0; i < 10; i++)
			numeros[i] = 0;
		numeros[10] = '\0';
		scanf("%hd", &n);
	}
	return 0;
}

