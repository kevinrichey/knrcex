#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
	bool in_word = false;
	for (int c = 0; (c = getchar()) != EOF; )
		if (c == ' ' || c == '\t' || c == '\n') {
			if (in_word)
				putchar('\n');
			in_word = false;
		}
		else {
			putchar(c);
			in_word = true;
		}

	return 0;
}

