#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct {
    int x;
} test[SIZE];

test* ret() {
    test local = { 1, 2 };
    test* ptr = &local;
    //for(int i = 0; i < SIZE; i++) (*ptr + i)->x = i;
    for(int i = 0; i < SIZE; i++) printf("Inside: %d ", ptr[i]->x);
    return ptr;
}

int* arr() {
    int arr[SIZE];
    int* a = arr;
    for(int i = 0; i < SIZE; i++) a[i] = i;
    return a;
}

void aos(test t) {
    for(int i = 0; i < SIZE; i++) t[i].x = i;    
}

void main(void) {
    // test* ans = ret();
    // for(int i = 0; i < SIZE; i++) printf("%d ", ans[i]->x);
    
    int* p = arr();
    for(int i = 0; i < SIZE; i++) printf("%d ", p[i]);
    
    test t; // AOS 
    aos(t);
    for(int i = 0; i < SIZE; i++) printf("\n\n%d ", t[i]);
}

