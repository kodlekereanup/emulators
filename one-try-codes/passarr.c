#include <stdio.h>

#define SIZE 2

void show(int arr[]) { 
	printf("\n");
	for(int i = 0; i < SIZE; i++) 
		printf("%d ", arr[i]);
	printf("\n");
}  

void value(int arr[]) {
	for(int i = 0; i < SIZE; i++)
		arr[i] *= 2;
}

void pointer(int ar[]) {
	for(int i = 0; i < SIZE; i++)
		ar[i] *=3;
}

void main(void) {
	int arr[] = { 1, 2 };
	value(arr);
	show(arr); // 2 4
	pointer(&arr);
	show(arr); // 6 12
	printf("%p %p %p", arr, &arr, &arr[0]);
// do the same with structs and pass the aos as &a and receive **
// arrays, pointers, array of pointers, pointer to array, structures, aos, soa, pointer to aos, returns, passing ...
// pass aos by reference, pass array by refernce
}