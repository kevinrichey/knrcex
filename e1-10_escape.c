#include <stdio.h>

int main(int argc, char *argv[])
{
	for (int c = 0; (c = getchar()) != EOF; )
		if (c == '\t')  
			printf("\\t");
		else if (c == '\b')
			printf("\\b");
		else if (c == '\\')
			printf("\\\\");
		else if (c == '\n')
			printf("\\n\n");
		else 
			putchar(c);

	return 0;
}

