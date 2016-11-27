#include <stdio.h>

int main()
{
	unsigned short s;
	for(s = 0; s <= 255; s++)
		printf("\t%i: %c\n", s, s);
	return 0;
}
