#include <stdio.h>
#include <string.h>
#include "klib.h"

string *string_create_n(size_t size)
{
	string *s = malloc(sizeof(string) + sizeof(char) * size);
	s->size = size;
	if (size)  s->str[0] = '\0';
	return s;
}

string *string_create()
{
	return string_create_n(STRING_CREATE_SIZE);
}

string *string_reserve(string *s, size_t size)
{
	if (s->size < size) {
		s->size *= (size / s->size) + 1;
		s = realloc(s, sizeof(string) + sizeof(char) * s->size);
	}
	return s;
}

string *string_insert(string *s, int i, int c)
{
	s = string_reserve(s, i+1);
	s->str[i] = c;
	return s;
}

string *string_cat_cstr(string *s1, int i, const char *s2)
{
	size_t s2_len = strlen(s2);
	s1 = string_reserve(s1, i + s2_len + 1);
	strncpy(s1->str+i, s2, s2_len);
	return s1;
}

int readline(string **out_s, int term)
{
	string *s = *out_s;

	int c, i;
	for (i = 0; (c = getchar()) != EOF && c != term; ++i) {
		s = string_insert(s, i, c);
	}

	if (c == term) {
		s = string_insert(s, i, c);
		++i;
	}
	s = string_insert(s, i, '\0');

	*out_s = s;

	return i;
}


