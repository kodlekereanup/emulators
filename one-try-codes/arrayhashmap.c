
/*
#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

typedef struct HashTable {
    int key;
    int value;
    
    unsigned int (*hashCode)(const int key);
    int          (*put)(int arr[], int value);
    int          (*get)(int arr[], int key);
    void         (*display)(int arr[]);
} ArrayHashTable[SIZE];

unsigned int hashCode(const int key) {
    unsigned int hash = 0;
    hash = (key << 4) ^ 0xFFFF;
    return hash % SIZE;
}

int put(int arr[], int value) {
    // if something is already existing at the current location, evict -> insert -> return evicted 
    unsigned int index = hashCode(value);
    
    if(!arr[index]) arr[index] = value; // if(arr[index] == 0)
    else {
        int old = arr[index];
        arr[index] = value;
        return old;
    }
}

int get(int arr[], int key) {
    unsigned int index = hashCode(key);
    if(arr[index] != 0) return index;
    else return -1;
}

void display(int arr[]) { 
    printf("\n");
    for(int i = 0; i < SIZE; i++) 
        printf("%d ", arr[i]);
    printf("\n");
}

void main(void) {
    
    int arr[SIZE] = {0};
    
    ArrayHashTable table;
    
    table->hashCode = hashCode;
    table->put      = put;
    table->get      = get;
    table->display  = display;
    
    table->display(arr);
    
    table->put(arr, 2);
    table->put(arr, 5);
    int old = table->put(arr, 10);
    printf("\n Old value: %d", old);
    table->put(arr, 1);
    
    table->display(arr);
    
    // traditional array: 2 5 1
    int key = 2;
    int find = table->get(arr, key);
    if(arr[find] == key) printf("\n Value found in array at index %d", find);
    else printf("\n Value doesn't exist in array");
    
}




map: (key, value) : key -> value: insertion order is not maintained: keys are automatically sorted 
hashmap: insertion order is not maintained. but keys may /may not be sorted

put(key, value): hash(key) : hash % size : index : array[index] = value 
put(key, key): 




#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

typedef struct HashTable {
    int key;
    int value;
    
    unsigned int (*hashCode)(const int key);
    int          (*put)(int arr[], int value);
    int          (*get)(int arr[], int key);
    void         (*display)(int arr[]);
} ArrayHashTable;

unsigned int hashCode(const int key) {
    unsigned int hash = 0;
    hash = (key << 4) ^ 0xFFFF;
    return hash % SIZE;
}

int put(int arr[], int value) {
    // if something is already existing at the current location, evict -> insert -> return evicted 
    unsigned int index = hashCode(value);
    
    if(!arr[index]) arr[index] = value; // if(arr[index] == 0)
    else {
        int old = arr[index];
        arr[index] = value;
        return old;
    }
}

int get(int arr[], int key) {
    unsigned int index = hashCode(key);
    if(arr[index] != 0) return index;
    else return -1;
}

void display(int arr[]) { 
    printf("\n");
    for(int i = 0; i < SIZE; i++) 
        printf("%d ", arr[i]);
    printf("\n");
}

void main(void) {
    
    int arr[SIZE] = {0};
    
    ArrayHashTable table; // same as ArrayHashTable table[SIZE]
    
    //for(int i = 0; i < SIZE; i++) printf("%d : %d ", i, table[i].key);
    
    table.hashCode = hashCode;
    table.put      = put;
    table.get      = get;
    table.display  = display;
    
    table.display(arr);
    
    table.put(arr, 2);
    table.put(arr, 5);
    int old = table.put(arr, 10);
    printf("\n Old value: %d", old);
    table.put(arr, 1);
    
    table.display(arr);
    
    // traditional array: 2 5 1
    int key = 2;
    int find = table.get(arr, key);
    if(arr[find] == key) printf("\n Value found in array at index %d", find);
    else printf("\n Value doesn't exist in array");
    
}

map: (key, value) : key -> value: insertion order is not maintained: keys are automatically sorted 
hashmap: insertion order is not maintained. but keys may /may not be sorted

put(key, value): hash(key) : hash % size : index : array[index] = value 
put(key, key): 

*/

