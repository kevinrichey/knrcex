#include <stdio.h>
#include <stdbool.h>

#define MAX_LEN  30

int main(int argc, char *argv[])
{
	int histogram[MAX_LEN];

	for (int i = 0; i < MAX_LEN; ++i)
		histogram[i] = 0;

	bool in_word = false;
	int length = 0;
	for (int c = 0; (c = getchar()) != EOF; )
		if (c == ' ' || c == '\t' || c == '\n') {
			if (in_word && length < MAX_LEN)
				++histogram[length-1];
			in_word = false;
			length = 0;
		}
		else {
			++length;
			in_word = true;
		}

	for (int l = 0; l < MAX_LEN; ++l) {
		printf("%4d\t", l+1);
		for (int i = 0; i < histogram[l]; ++i)
			putchar('x');
		putchar('\n');
	}

	return 0;
}

