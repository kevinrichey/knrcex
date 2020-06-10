#include <stdio.h>
#include "klib.h"

string *string_unscape(string *e, string *s)
{
	char *c = e->str;
	char *end = e->str + e->size;
	int i = 0;

	while (c != end) {
		if (*c == '\\') {
			switch(*++c) {
				case 't':
					s = string_insert(s, i, '\t');
					break;
				case 'n':
					s = string_insert(s, i, '\n');
					break;
				case 'b':
					s = string_insert(s, i, '\b');
					break;
				case '\\':
					s = string_insert(s, i, '\\');
					break;
			}
		}
		else 
			s = string_insert(s, i, *c);
		++i;
		++c;
	}

	return string_insert(s, i, '\0');
}

int main(int argc, char *argv[])
{
	string *s = string_create_n(80);
	string *e = string_create_n(80);
	
	printf("unscape.exe\n");
	while (readline(&s, '\n') > 0) {
		e = string_unscape(s, e);
		printf("%s", e->str);
	}

	free(s);
	free(e);

    return 0;
}


