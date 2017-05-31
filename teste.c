#include <stdio.h>

int main()
{
	unsigned int x=255;
	unsigned int b;
	b = 0x0000FF00 & x;


	printf("x%d ",b );

	return 0;
}