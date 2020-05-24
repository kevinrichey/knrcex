#include <stdio.h>


int main(int argc, char *argv[])
{
	int tabstop = 8;

	int space_count = 0;
	int column = 1;
	int c = 0; 
	for ( ; (c = getchar()) != EOF; ++column) {
		if (c == '\n')
			column = 0;
		else if (c == ' ')
			++space_count;
		else {
			for ( ; space_count > tabstop-1; space_count -= 8)
				putchar('\t');
			for ( ; space_count > 0; --space_count)
				putchar(' ');
			putchar(c);
		}
	}

	return 0;
}

