#include <stdio.h>

int main(int argc, char *argv[])
{
	int t = 0;
	for (int a = 0, b = 1; b < 500000000; t = b, b = a + b, a = t)
		printf("%d,\n", b);

    return 0;
}


