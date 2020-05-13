#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

typedef struct ArrayHashTable {
    int key;
    int value;

    unsigned int (*hashCode)(const int);
    int 	 (*put)(struct ArrayHashTable* table, int value);
    int 	 (*get)(struct ArrayHashTable* table, int key);
    void 	 (*display)(const struct ArrayHashTable* table);
} ArrayHashTable;

unsigned int hashCode(const int key) {
    unsigned int hash = 0;
    hash = (key << 4) ^ 0xFFFF;
    return hash % SIZE;
}

int put(ArrayHashTable table[], int value) {
    // if something is already existing at the current location, evict -> insert -> return evicted 
    unsigned int index = hashCode(value);
    
    if(table[index].value == 0) table[index].value = value; // if(arr[index] == 0)
    else {
        int old = table[index].value;
        table[index].value = value;
        return old;
    }
}

int get(ArrayHashTable table[], int key) {
     unsigned int index = hashCode(key);
     if(table[index].value == key) return index;
     else return -1;
}

void display(const ArrayHashTable* table) { 
    printf("\n");
    for(int i = 0; i < SIZE; i++) 
        printf("%d ", table[i].value);
    printf("\n");
}

void main(void) {
    
    ArrayHashTable table[SIZE] = { { 0, 0, hashCode, put, get, display } };
    display(table);
    
    table->put(table, 2);
    table->put(table, 5);
    int old = table->put(table, 8);
    printf("\n Old value: %d", old);
    table->put(table, 1);
    
    table->display(table);
    
    //traditional array: 2 5 1
    int key = 2;
    int find = table->get(table, key);

    if(find == -1) printf("\n Value doesn't exist in array");
    else printf("\n Value found in array at index %d", find);
}	

#include <stdio.h>
#include <stdbool.h>

#define SIZE 10 

typedef struct {
    void* key;
    void* value;
} Entry;

typedef struct HashTable {
    unsigned int hash;
    Entry entry;
    bool cellEmpty;
    struct HashTable* next;
} HashTable;

/*
typedef struct HashTable {
    int hash;
    Entry entry;
    struct HashTable* next;
} HashTable[SIZE];
*/

unsigned int hashCode(int key) {
    unsigned int hash = 0;
    hash = (key << 4) | 0xFFFF;
    return hash % SIZE;
}

// TODO: Implement variadic argfuments for the default argument feature //

void put(HashTable table[], int value) {
    unsigned int hash = hashCode(value);
    table.hash = hash;
    
    Entry insert;
    insert.key = value;
    insert.value = value;
    
    table.entry = insert;
    
    table.next = NULL;
    
    if(table[index].entry.value == 0) table[index].entry = insert;
    else {
        int old = table[index].entry.value;
        table[index].entry.value = value;
        return old;
    }
    
}

int get(const Hashtable* table, int key) {
    unsigned int index = hashCode(key);
    if(table[index])
}

void main(void) {
    HashTable table[SIZE] = {0, };
    
    put(table, 2);
    put(table, 5);
    put(table, 1);
    put(table, 7);
    put(table, 9);
    
    display(table);
    
    int key = 7;
    int index = find(table, key);
    if(table[index] == key) printf("\n Value found at %d", index);
    else printf("\n Value doesn't exist in array\n");
}	