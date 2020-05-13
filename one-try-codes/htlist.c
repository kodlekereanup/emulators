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
    bool cellFull;
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
    table->hash = hash;
    
    Entry insert;
    insert->key = value;
    insert->value = value;
    
    table->entry = insert;
    
    table->next = NULL;
    
    if(!table[hash]->cellFull) table[hash]->entry = insert;
    else {
        int old = table[hash]->entry.value;
        table[hash]->entry.value = value;
        return old;
    }
    
}

int get(const HashTable* table, int key) {
     unsigned int index = hashCode(key);
     if(table[index].value == key) return index;
     else return -1;
}

void display(const HashTable* table) { 
    printf("\n");
    for(int i = 0; i < SIZE; i++) 
        printf("%d ", table[i].entry.value);
    printf("\n");
}

void main(void) {
    HashTable table[SIZE] = {0};
    
    // for(int i = 0; i < SIZE; i++) {
        
    //     printf("%d --- %d --- %d --- %d --- %d", 
    //     table[i].hash,
    //     table[i].entry.key,
    //     table[i].entry.value, 
    //     table[i].next,
    //     table[i].cellEmpty)
    // }
    
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