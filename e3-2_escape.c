#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "klib.h"



string *string_escape(string *s1, string *s2)
{
	int i = 0;
	for (char *c = s1->str; *c != '\0'; ++c)
		switch(*c) {
			case '\t':
				s2 = string_cat_cstr(s2, i, "\\t");
				i += 2;
				break;
			case '\\':
				s2 = string_cat_cstr(s2, i, "\\\\");
				i += 2;
				break;
			case '\b':
				s2 = string_cat_cstr(s2, i, "\\b");
				i += 2;
				break;
			case '\n':
				s2 = string_cat_cstr(s2, i, "\\n");
				i += 2;
				break;
			default:
				s2 = string_insert(s2, i++, *c);
				break;
		}

	s2->str[i] = '\0';

	return s2;
}

int main(int argc, char *argv[])
{
	string *s = string_create_n(80);
	string *e = string_create_n(80);
	
	while (readline(&s, '\n') > 0) {
		e = string_escape(s, e);
		printf("%s", e->str);
	}

	return 0;
}
