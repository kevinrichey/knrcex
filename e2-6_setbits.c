#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	unsigned n_bits = ~(~0 << n);
	printf("n_bits = %o\n", n_bits);
	unsigned n_bits_of_y = y & n_bits;
	printf("n_bits_of_y = %o\n", n_bits_of_y);
	unsigned prep_x = x & ~(n_bits << (p-n+1));
	printf("prep_x = %o\n", prep_x);
	return prep_x | n_bits_of_y << (p-n+1);
}

int main(int argc, char *argv[])
{
	//  876 543 210
	//  000 101 100
	printf("%o\n", setbits(054, 5, 3, 03));
    return 0;
}


