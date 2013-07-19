/**********************************************************
	Program:	The ? 1 ? 2 ? ... ? n = k problem
	Author:		Saúl Martínez Vidals
	Date:		21-05-2007
***********************************************************
        @JUDGE_ID: 63787VV 10025 C ""
***********************************************************
					RESUELTO !!!
**********************************************************/

#include <stdio.h>

int main()
{
	short i, n;
	long k, r;
	int j, s;
	
	scanf("%hd", &n);
	for(i = 0; i < n; i++)
	{
		r = 0;
		j = 1;
		scanf("%ld", &k);
		if(k == 0)
			j = 4;
		else if(k > 0)
		{
			while(r < k)
				r += j++;
			if(r > k)
			{
				while((r - k) % 2)
					r += j++;
			}
		}
		else
		{
			while(r > k)
				r -= j++;
			if(r < k)
			{
				while((k - r) % 2)
					r -= j++;
			}
		}
		printf("%d\n", j-1);
		if(i < n-1)
			puts("");
	}
	return 0;
}
