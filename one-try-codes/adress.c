#include <stdio.h>

void main(void) {

	int arr[] = { 1, 2 };
	int* na = arr;
	int** da = &na;
	printf("%p %p %p", &arr, &na, &da);
}