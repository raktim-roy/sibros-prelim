#include <stdio.h>
#include <stdlib.h>


typedef struct linked_list {
void * data;
struct linked_list * next;
} linked_list_s;

// 1. Add a node at the beginning of the list
/* Given a reference (pointer to pointer)
to the head of a list and a data,
inserts a new node on the front of the list. */
void InsertatBeginning(linked_list_s** head_ref, void* new_data);

// 2. Add a node at the end of the list
// Given a reference (pointer to pointer) to the head 
// of a list and a data, appends a new node at the end
void InsertatEnd(linked_list_s** head_ref, void* new_data);

// 3. Remove a node
// Given a reference (pointer to pointer)
// to the head of a list and a position, deletes
// the node at the given position
void deleteNode(linked_list_s** head_ref, int position);

// 4. Return the count of nodes
// Given a reference 
// to the head of a list, iterate through the list and return count
int getCount(linked_list_s* head_ref);