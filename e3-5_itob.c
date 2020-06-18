#include <stdio.h>
#include <string.h>

void swap_c(char *a, char *b)
{
	char t = *a;
	*a = *b;
	*b = t;
}

char *str_reverse_n(char s[], int len)
{
	char *r = s;
	char *e = s + len - 1;
	while (s < e)  swap_c(s++, e--);
	return r;
}

char *str_reverse(char s[])
{
	char *r = s;
	for (char *e = s + strlen(s) - 1; s < e; )  swap_c(s++, e--);
	//return str_reverse_n(s, strlen(s));
	return r;
}

char *itob(int n, char s[], int b)
{
	int sign;

	if ((sign = n) < 0)
		n = -n;

	int i = 0;
	do {
		s[i++] = "0123456789ABCDEF"[n % b];
	}
	while ((n /= b) > 0);

	if (sign < 0)
		s[i++] = '-';

	s[i] = '\0';
	return str_reverse(s);
}

int main(int argc, char *argv[])
{
	int  n = 500;
	char s[100];

	printf("base 2  = %s\n", itob(n, s,  2));
	printf("base 8  = %s\n", itob(n, s,  8));
	printf("base 10 = %s\n", itob(n, s, 10));
	printf("base 16 = %s\n", itob(n, s, 16));

    return 0;
}

