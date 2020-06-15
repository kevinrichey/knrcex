#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *fill_range(char b, char e, char *s, size_t s_size)
{
	int d = (b < e)? 1: -1;

	for (char stop = e + d; b != stop && s_size --> 1; b += d)
		*s++ = b;

	*s = '\0';
	return s;
}

void expand(const char *s1, char *s2, size_t s2_size)
{
	char *end = s2 + s2_size;
	for (int i = 0;  s1[i] != '\0' && s2 != end; ) {
		if (isalnum(s1[i]) && s1[i+1] == '-' && isalnum(s1[i+2])) {
			s2 = fill_range(s1[i], s1[i+2], s2, end - s2);
			i += 3;
		}
		else
			*s2++ = s1[i++];
	}
	*s2 = '\0';
}

int main(int argc, char *argv[])
{
	char s[100];

	expand("a-z", s, 27);
	printf("%s\n", s);

	expand("9-0A-Z", s, 37);
	printf("%s\n", s);

	expand("-0-9xA-F%^&Z-", s, 100);
	printf("%s\n", s);

	expand("a-aa-ba-b-c", s, 100);
	printf("%s\n", s);

    return 0;
}


