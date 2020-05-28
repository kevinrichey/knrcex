#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[])
{
	printf("type\tsizeof\t%12s\t%12s\n", "min", "max");
	printf("-----------------------------------------------------\n");
	printf("char\t%3llu\t%12d\t%12d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
	printf("short\t%3llu\t%12d\t%12d\n", sizeof(short), SHRT_MIN, SHRT_MAX);
	printf("int\t%3llu\t%12d\t%12d\n", sizeof(int), INT_MIN, INT_MAX);
	printf("long\t%3llu\t%12ld\t%12ld\n", sizeof(long), LONG_MIN, LONG_MAX);
	printf("uchar\t%3llu\t%12u\t%12u\n", sizeof(unsigned char), 0, UCHAR_MAX);
	printf("ushort\t%3llu\t%12u\t%12u\n", sizeof(unsigned short), 0, USHRT_MAX);
	printf("uint\t%3llu\t%12u\t%12u\n", sizeof(unsigned int), 0, UINT_MAX);
	printf("ulong\t%3llu\t%12d\t%12lu\n", sizeof(unsigned long), 0, ULONG_MAX);

    return 0;
}


