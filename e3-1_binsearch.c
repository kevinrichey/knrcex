#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "klib.h"


/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;

	while (low <= high) {
		mid = (low+high)/2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else /* found match */
			return mid;
	}
	return -1; /* no match */
}

int binsearch2(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;

	while (low < high) {
		mid = (low+high)/2;
		if (x <= v[mid])
			high = mid;
		else 
			low = mid + 1;
	}
	return (x == v[low])? low: -1;
}

#include "numbers.c"


int main(int argc, char *argv[])
{
	printf("length of numbers: %llu\n", arrlen(numbers));
	int max = numbers[arrlen(numbers)-1];

	clock_t start = clock();
	for (int n = 0, i = 9000000; i--; n = randint(max))
		binsearch(n, numbers, arrlen(numbers));
		//printf("find %d: %d\n", n, binsearch(n, numbers, arrlen(numbers)));
	clock_t duration = clock() - start;
	printf("binsearch time: %ld\n", duration);

	start = clock();
	for (int n = 0, i =  9000000; i--; n = randint(max))
		binsearch(n, numbers, arrlen(numbers));
		//printf("find %d: %d\n", n, binsearch2(n, numbers, arrlen(numbers)));
	duration = clock() - start;
	printf("binsearch2 time: %ld\n", duration);

	return 0;
}


