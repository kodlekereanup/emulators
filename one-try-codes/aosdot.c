/*
#include <stdio.h>
#define SIZE 2
typedef struct {
int x;
} arr;

typedef struct {
int y;
} sarr[SIZE];

//typedef struct sarr sarr[SIZE];

void pass_arr_by_pointer(arr* nr) { nr[1].x = 3; }
void pass_arr_without_star(arr a[]) { a[1].x = 10; }
// void pass_arr_by_pointer(arr** nr) { nr[1]->x = 3; } // call: pass_arr_by_pointer(&a); 

void pass_sarr_by_pointer(sarr* nr)  { nr[1]->y = 4; }
void pass_sarr_without_star(sarr a) { a[1].y = 20; }

// sarr* pass_sarr_by_pointer(sarr* nr)  { nr[1]->y = 4; return nr; }

void main(void) {
	arr a[SIZE];
	a[1].x = 2;
	printf("%d", a[1].x); //2
	
	pass_arr_without_star(a);
	printf("\n%d", a[1].x); // 10

	pass_arr_by_pointer(a);
	printf("\n%d", a[1].x); // 3


	sarr ar; // sarr ar[SIZE] //
	ar[1].y = 1;
	printf("\n%d", ar[1].y); //1

	pass_sarr_by_pointer(&ar); // why isn't ar getting updated in main? // passing pointer by value? //
	printf("\n%d", ar[1].y); // 1   //4 doesnt match but why //

	pass_sarr_without_star(ar);
	printf("\n%d", ar[1].y); // 20 

	
}

*/
#include <stdio.h>

#define SIZE 3

typedef struct {
    int x, y;
} Point;

void changev(Point p[]) {
     for(int i = 1; i <= SIZE; i++) {
        p[i - 1].x = i;
        p[i - 1].y = i + 1;
    }    

}

void changep(Point* p) {
     for(int i = 1; i <= SIZE; i++) {
        p[i - 1].x = i;
        p[i - 1].y = i  * 2;
    }    
}

void calls(int* a) { *a = 3; }

void main(void) {
    
    Point p[SIZE];
    for(int i = 1; i <= SIZE; i++) {
        p[i - 1].x = i;
        p[i - 1].y = (i * i);
    }
    
    changev(p);
    
    for(int i = 0; i < SIZE; i++) 
        printf("%d -> %d ", p[i].x, p[i].y);
        
    //    Point* ab = &p;
    changep(p); // what is &p ? 
    for(int i = 0; i < SIZE; i++) 
        printf("%d -> %d ", p[i].x, p[i].y);
        
    int ans = 2;
    int* a = &ans;
    
    calls(a); // same as calls(&ans);
    printf("\n%d", ans);
    
}
// to receive double poiner, send ampersand of a pointer 