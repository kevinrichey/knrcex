#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "klib.h"


typedef struct { 
	size_t size; 
	char   str[];
} string;


string *string_renew(string *s, size_t size)
{
	if (s->size < size) {
		s->size *= (size / s->size) + 1;
		watch_i((int)s->size);
		s = realloc(s, sizeof(string) + sizeof(char) * s->size);
	}
	return s;
}


string *readline(string *s, int term)
{
	s = string_renew(s, 16);

	int i = 0;
	for (int c = 0; (c = getchar()) != EOF; ++i) {
		if (i >= s->size)
			s = string_renew(s, s->size * 2);
		s->str[i] = c;
		if (c == term) 
			break;
	}

	s->str[i] = '\0';

	return !feof(stdin)? s: NULL;
}


string *string_cat_cstr(string *s1, int i, const char *s2)
{
	size_t s2_len = strlen(s2);
	s1 = string_renew(s1, i + s2_len + 1);
	strncpy(s1->str+i, s2, s2_len);
	return s1;
}

string *string_insert(string *s, int i, int c)
{
	s = string_renew(s, i+1);
	s->str[i] = c;
	return s;
}

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
			default:
				s2 = string_insert(s2, i++, *c);
				break;
		}

	s2->str[i] = '\0';

		//else if (c == '\b')
			//printf("\\b");
		//else if (c == '\n')
			//printf("\\n\n");

	return s2;
}

#define STRING_CREATE_SIZE   16

string *string_create()
{
	string *s = malloc(sizeof(string) + sizeof(char) * STRING_CREATE_SIZE);
	s->size = STRING_CREATE_SIZE;
	return s;
}

int main(int argc, char *argv[])
{
	string *s = string_create();
	string *e = string_create();
	
	while ((s = readline(s, '\n'))) {
		e = string_escape(s, e);
		printf("%s\n", e->str);
	}

	return 0;
}
