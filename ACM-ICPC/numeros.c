#include <stdio.h>

#define MIN 0
#define MAX 10000000

int main()
{
	unsigned long long i;
	for(i = MIN; i <= MAX; i++)
		printf("%llu\n", i);
	return 0;
}
