#include <stdio.h>
#include <string.h>

char *strnchr(const char *s, int c, size_t n)
{
	for ( ; *s != '\0'  &&  n > 0;  ++s, --n)
		if (*s == c)
			return (char*)s;

	return NULL;
}

void squeeze(char s1[], size_t s1_n, char s2[], size_t s2_n)
{
	int i, j;
	char *s;

	for (s = s1; *s1 != '\0'  &&  s1_n > 0; ++s1, --s1_n)
		if (strnchr(s2, *s1, s2_n) == NULL)
			*s++ = *s1;

	*s = '\0';
}

#define arrlen(A_)  (sizeof(A_) / sizeof(A_[0]))

int main(int argc, char *argv[])
{
	char hello[] = "Hello, world!";
	char vowels[] = "aeiou";

	printf("original: %s\n", hello);
	squeeze(hello, arrlen(hello), vowels, arrlen(vowels));
	printf("squeezed: %s\n", hello);

    return 0;
}

