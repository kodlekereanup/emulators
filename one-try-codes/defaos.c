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
    insert.key = value;
    insert.value = value;
    
    table->entry = insert;
    
    table->next = NULL;
    
    if(!table[hash].cellFull) table[hash].entry = insert;
    else {
        int old = table[hash].entry.value;
        table[hash]->entry.value = value;
        return old;
    }
    
}

int get(const HashTable* table, int key) {
     unsigned int index = hashCode(key);
     if(table[index]->value == key) return index;
     else return -1;
}

void display(const HashTable* table) { 
    printf("\n");
    for(int i = 0; i < SIZE; i++) 
        printf("%d ", table[i]->entry.value);
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


// BASIC GENERIC HASH TABLE WITH WARNINGS
#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

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
    hash = (key << 4) ^ 0xFFFF;
    return hash % SIZE;
}

void displayEntry(const Entry* e) {
    printf("%d -> %d", e->key, e->value);
}

// TODO: Implement variadic argfuments for the default argument feature //

void put(HashTable table[], int value) {
    unsigned int hashIndex = hashCode(value);
    table->hash = hashIndex;
    printf("\n%d\n", hashIndex);
    Entry insert;
    insert.key = value;
    insert.value = value;
    
    //displayEntry(&insert);
    
    table->entry = insert;
    
    table->next = NULL;
    
    if(!table[hashIndex].cellFull) table[hashIndex].entry = insert;
    // else {
    //     int old = table[hash].entry.value;
    //     table[hash].entry.value = value;
    //   // return old;
    // }
    
}

int get(const HashTable* table, int key) {
     unsigned int index = hashCode(key);
     if(table[index].entry.value == key) return index;
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
     display(table);
    put(table, 'a');
     display(table);
    put(table, 'b');
     display(table);
    put(table, 'g');
    //put(table, 7);
    //put(table, 9);
    
    display(table);
    
    int key = 'g';
    int index = get(table, key);
    if(index != -1) printf("\n Value found at %d", index);
    else printf("\n Value doesn't exist in array\n");
}

#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>

/*
	Write a generic data structure for the following operations:
		- O(1) Insert.
		- O(1) Delete.
		- O(1) Lookup.
		
	Assume static size data structure. 

	Disadvantages:
		- No insertion order will be maintained.
		- Elements once inserted may not be present at the time of last insertion
		  due to the collisions, and so collision resolution methods need to be applied
		  here to solve the problem.
		- No idea what to do if the array needs resizing, do we change the whole array setup? 
		  Make a new table, re-hash the old elements and place them in the new table? No body knows...
		- Can't hold duplicates

*/

#define SIZE 5
static unsigned int collisions = 0;

/*
This is the correct implementation, bu for time time being we will simplify a little bit //

#define THRESHOLD, CAPACITY, INITIAL CAPACITY, SIZE, LOAD_FACTOR ...

typedef struct {
	void* key;
	void* value;
} Entry;

typedef struct {
	int hash;
	Entry entry;
	HashTable* next;
} HashTable;

*/

unsigned int hashCode(const int key) {
	unsigned int hash = 0;
	hash = (key << 2) ^ 0xABCD;
	return hash % SIZE;
}

bool put(int* arr, int value) {
	printf("\n Inserting %d\n", value);
	unsigned int index = hashCode(value);
	bool flag = true;
	if (arr[index] == 0) arr[index] = value;
	else {
		printf("\n Collision occured at %d. Finding next possible index \n", index);
		collisions++;
		int round = index;
		while (arr[index] != 0) {
			index++;
			if (round == index) {
				flag = false; // some failure occured //
				printf("\n Couldn't find a suitable index for %d, insertion failed.\n", value);
				break;
			}
			if (index == SIZE) index = 0;
		}
		arr[index] = value;
	}
	return flag; // succesfully inserted
}

int get(const int* arr, const int key) {
	unsigned int index = hashCode(key);
	bool flag = true;
	if (arr[index] == key) return index;
	else {
		// handle collision resolution
		int round = index;
		while (arr[index] != key) {
			index++;
			if (round == index) {
				flag = false; // some failure occured //
				printf("\n Key doesn't exist in array");
				break;
			}
			if (index == SIZE) index = 0;
		}
		return index;
	}
}

void display(const int* arr) {
	printf("\n");
	for (int i = 0; i < SIZE; i++) printf(" %d", arr[i]);
	printf("\n");
}

void main(void) {

	int arr[SIZE] = { 0 };
	//srand(time(NULL));

	//TODO: Implement put(arr, otherArray); 

	put(arr, 2);
	put(arr, 5);
	put(arr, 1);

	display(arr);
	printf("\n No of collisons: %d", collisions);

	int key = 5;
	// linear search: O(N), binary search: O(logn) 
	// the below call to get() takes constant time to return (on average)
	// cause we use open addressing, incase of collisions, get() may take O(N).
	int index = get(arr, key); 	
	if(index != -1) printf("\n %d found at index %d", key, index);
	else printf("\n Element doesn't exist in array\n");

	_getch();
}


