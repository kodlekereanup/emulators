#include <stdio.h>

#define SIZE 3

typedef struct {
    int x, y;
} Point[SIZE];

void changev(Point p) {
    
     for(int i = 1; i <= SIZE; i++) {
        p[i - 1].x = i;
        p[i - 1].y = i + 1;
    }    

}


void changep(Point* p) {
     for(int i = 1; i <= SIZE; i++) {
        p[i - 1]->x = i;
        p[i - 1]->y = i + 3;
    }    
	 for(int i = 0; i < SIZE; i++) 
        printf("%d -> %d ", p[i]->x, p[i]->y);
    printf("\n");    
}

void main(void) {
    
    Point p;
    for(int i = 1; i <= SIZE; i++) {
        p[i - 1].x = i;
        p[i - 1].y = (i * i);
    }
    
    changev(p);
    
    for(int i = 0; i < SIZE; i++) 
        printf("%d -> %d ", p[i].x, p[i].y);
    printf("\n");    
    changep(&p);
    for(int i = 0; i < SIZE; i++) 
        printf("%d -> %d ", p[i].x, p[i].y);


	Point* ptr; // what data type is this?
	// typedef array struct pointer return 
    
}

#include <stdio.h>

#define SIZE 3

typedef struct {
    int x, y;
} Point[SIZE];

void changev(Point p) {
    
     for(int i = 1; i <= SIZE; i++) {
        p[i - 1].x = i;
        p[i - 1].y = i + 1;
    }    

}


void changep(Point* p) {
     for(int i = 1; i <= SIZE; i++) {
        p[i - 1]->x = i;
        p[i - 1]->y = i  * 2;
    }    

}

void calls(int* a) { *a = 3; }

void main(void) {
    
    Point p;
    for(int i = 1; i <= SIZE; i++) {
        p[i - 1].x = i;
        p[i - 1].y = (i * i);
    }
    
    changev(p);
    
    for(int i = 0; i < SIZE; i++) 
        printf("%d -> %d ", p[i].x, p[i].y);
        
        Point* ab = &p;
    changep(ab);
    for(int i = 0; i < SIZE; i++) 
        printf("%d -> %d ", ab[i]->x, ab[i]->y);
        
    int ans = 2;
    int* a = &ans;
    
    calls(a); // same as calls(&ans);
    printf("\n%d", ans);
    
}



/*
typedef struct {

} some[SIZE]; 

vs 

typedef struct {

} some;

some ar[SIZE];

*/


#include <stdio.h>

#define SIZE 5

typedef struct {
    int x;
} Point;

void setP1(Point p[]) { // same as Point* p //
    for(int i = 0; i < SIZE; i++) p[i].x = (i + 1) * (i + 1);
}

void setP2(Point* p) { // same as Point* p //
    for(int i = 0; i < SIZE; i++) p[i].x = (i + 1) * (i + 1);
}

typedef struct {
    int y;
} array[SIZE];

void setA1(array p) {
     for(int i = 0; i < SIZE; i++) p[i].y = (i + 1) * (i + 1);
}

void setA2(array* p) {
     for(int i = 0; i < SIZE; i++) p[i]->y = (i + 1) * (i + 1);
}

void main(void) {
    
    Point points1[SIZE] = {0};
    Point points2[SIZE] = {0};
    
    setP1(points1);
    printf("\n");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", points1[i].x);
    }
    printf("\n");
    
    setP2(points2);
    printf("\n");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", points2[i].x);
    }
    printf("\n");
    
    
    array a1 = {0};
    array a2 = {0};
    
    setA1(a1);
    printf("\n");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", a1[i].y);
    }
    printf("\n");
    
    setA2(&a2);
    printf("\n");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", a2[i].y);
    }
    printf("\n");
    
}

/*


typedef struct {
int a;
} Array[SIZE];

array a; //array a[size] 
array* a; // array *a[size];
array a[];
array* a[];

array of pointers 
pointer to array

pointer to array of structs
array of struct pointers?

int arr[];
int* a = &arr;

int *b[]; int* c[]

*/


