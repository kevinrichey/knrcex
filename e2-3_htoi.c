#include <stdio.h>
#include <ctype.h>

#define MAX  100

int htoi(char s[])
{
	int d = 0;

	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
		for (int i = 2; s[i]; ++i)
			if (isdigit(s[i]))
				d = 16 * d + (s[i] - '0');
			else if (s[i] >= 'a' && s[i] <= 'f')
				d = 16 * d + (s[i] - 'a' + 10);
			else if (s[i] >= 'A' && s[i] <= 'F')
				d = 16 * d + (s[i] - 'A' + 10);
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
			printf("%s = %d\n", line, htoi(line));
			i = -1;
		}
		else
			line[i] = c;

	return 0;
}

