#include <stdio.h>
#include <stdlib.h>

#define SCOPE_SIZE  1000

void mismatch(int line, int c)
{
	printf("%d: unmatched %c\n", line, c);
	exit(1);
}

typedef enum {
	CX_NONE,
	CX_STRING1,
	CX_STRING2
} context;

int line = 1;

void eatstr(int endc)
{
	int c = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\\')
			getchar();  // skip escape sequence
		else if (c == '\n')
			mismatch(line, endc);
		else if (c == endc)
			break;
	}
}

int main(int argc, char *argv[]) 
{
	context state = CX_NONE;

	char scope_stack[SCOPE_SIZE];
	char *top = scope_stack;
	*top++ = ' ';

	int c = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			*top = '\0';
			printf("%d: %s\n", line, scope_stack);
			++line;
		}
		else if (c == '\"' || c == '\'')
			eatstr(c);
		else if (c == '{' || c == '(')
			*top++ = c;
		else if (c == '}' && *--top != '{')
			mismatch(line, c);
		else if (c == ')' && *--top != '(')
			mismatch(line, c);
	}

	if (*top == ' ' || *top == '\0')
		printf("All good!\n");
	else
		mismatch(line, *top);

	return 0;
}

