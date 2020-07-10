#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

#define MAXOP  100
#define NUMBER '0'
#define MAXVAL 100
#define BUFFSIZE 100

_Noreturn void error(char msg[])
{
	printf("ERROR: %s\n", msg);
	abort();
}

char buff[BUFFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0)? buff[--bufp]: getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFFSIZE) 
		printf("ERROR: ungetch buffer fill\n");
	else
		buff[bufp++] = c;
}

int sp = 0;
double val[MAXVAL];

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		error("stack full");
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else
		error("pop: stack empy");
	return 0.0;
}

double peek(void)
{
	if (sp > 0)
		return val[sp-1];
	else
		error("peek: stack empy");
}

int getop(char s[])
{
	int c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;

	s[1] = '\0';

	if (!isdigit(c) && c != '.' && c != '-')
		return c;

	if (c == '-') {
		int p = peek();
		if (!isdigit(p) && p != '.')
			return c;
	}

	int i = 0;
	if (isdigit(c) || c == '-')
		while (isdigit(s[++i] = c = getch()))
			;

	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;

	s[i] = '\0';

	if (c != EOF)
		ungetch(c);

	return NUMBER;
}

int main(int argc, char *argv[])
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					error("divide by zero!");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push(fmod(pop(),op2));
				else
					error("modulo divide by zero!");
				break;
			case '\n':
				printf("\t%.8g\n", peek());
				break;
			default:
				printf("ERROR: unknown command: %s\n", s);
				break;
		}
	}

    return 0;
}

