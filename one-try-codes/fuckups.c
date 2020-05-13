// #include <stdio.h>
// #include <stdlib.h>

// int SIZE = 3;

// typedef struct {
//     int v;
// } one;

// void set(one arr[], int val) {
//   for(int i = 0 ;i < SIZE; i++) arr[i].v = val;
// }

// void main(void) {
//     one arr[SIZE];
//     set(arr, 1);
//     for(int i = 0; i < SIZE; i++) printf("%d ", arr[i].v);
// }


#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

typedef struct point {
    int v;
} Point;

void set(Point** points, int val) {
    *points = malloc(sizeof(Point) * SIZE);
    for(int i = 0; i < SIZE; i++) (*points)[i].v = val; //same as (points + i)->v = val //
}

void main(void) {
    Point* points;
    set(&points, 1); // passing the pointer by value wtf does that mean
    for(int i = 0;  i < SIZE; i++ ) printf("%d ", points[i].v);
    free(points);
    points = NULL;
}

/*
 * What I wanted to do is, have a void function called set, which takes a struct object
 * mallocs it and then "does something" which I thought would directly change the value
 * at the memory cause I was passing a pointer. It was actually passed as a copy not 
 * as a reference, hence the Segmentation Fault. To solve this you have two answers,
 * 
 * Declare a pointer to struct in main, and send it to the setter. 
 * Let the setter do the allocation and then return the pointer. --> value
 
 * The better way to do this is to pass by reference
 
 * Declare a pointer to struct in main, and send the address or the reference of it to the setter.
 * The setter receives it as a double pointer (one to the structure itself which is the type, and one
   being the type of parameter passing). 
 * Here you should use the -> operator since it's a pointer now. No need to return values so the 
 * function can be void.
*/






