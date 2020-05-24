#include <stdio.h>


int main(int argc, char *argv[])
{
	int tabstop = 8;
	int leading = tabstop;

	for (int c = 0; (c = getchar()) != EOF; --leading) {
		if (leading <= 0)
			leading = tabstop;
		if (c == '\n')
			leading = tabstop + 1;  // count the new-line
		if (c == '\t')
			while (leading--) 
				putchar(' ');
		else 
			putchar(c);
	}

	return 0;
}

