#include <stdio.h>
#include <ctype.h>

#define MAX  100

unsigned int htoi(char s[])
{
	int d = 0;

	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
		int c;
		for (s += 2; c = *s, c != '\0'; ++s)
			if (isdigit(c))
				d = 16 * d + (c - '0');
			else if (c >= 'a' && c <= 'f')
				d = 16 * d + (c - 'a' + 10);
			else if (c >= 'A' && c <= 'F')
				d = 16 * d + (c - 'A' + 10);
			else 
				break;
	}

	return d;
}

int main(int argc, char *argv[])
{
	char line[MAX];

	int i = 0;
	for (int c = 0; i < MAX-1 && (c = getchar()) != EOF && c != 'q'; ++i)
		if (c == '\n') {
			printf("%s = %u\n", line, htoi(line));
			i = -1;
		}
		else
			line[i] = c;

	return 0;
}

