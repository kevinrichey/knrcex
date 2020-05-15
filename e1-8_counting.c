#include <stdio.h>

int main(int argc, char *argv[])
{
	int count_chars  = 0;
	int count_blanks = 0;
	int count_tabs   = 0;
	int count_nls    = 0;

	for (int c = 0; (c = getchar()) != EOF; ++count_chars)
		if (c == ' ')  
			++count_blanks;
		else if (c == '\t')
			++count_tabs;
		else if (c == '\n')
			++count_nls;

	printf("characters:  %6d\n", count_chars);
	printf("blanks:      %6d\n", count_blanks);
	printf("tabs:        %6d\n", count_tabs);
	printf("new lines:   %6d\n", count_nls);

	return 0;
}

