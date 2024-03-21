#include <stdio.h>

// A
void displayHexadecimalEquivalent (int num) {
    if (num == 0)
        return;
    
    int rem = num % 16;

    displayHexadecimalEquivalent(num / 16); // Recursive call

    if (rem < 10)
        printf ("%i", rem);
    else
        printf ("%c", 'A' + (rem - 10));   
}

// C
#define MAX 10000

// Array List
typedef struct {
    int items[MAX];
    int size;
} ArrayList;

// Doubly-Linked List
typedef struct mynode {
    int item;
    struct mynode *next, *prev;
} Node;

typedef struct {
    int size;
    Node *head, *tail;
} DoublyLinkedList;

// Array List: Function to insert item x in the sorted list l
int insert(ArrayList l, int x) {
    int moveCount = 0, insertIndex = l.size; // Starting position is at the end of the list

    if (l.size >= MAX) {
        printf("Error: Array list is full\n");
        return -1; // Indicate insertion failed due to array list being full
    }
    
    for (; insertIndex > 0; insertIndex--) { // Loop and shift items to the right 
        if (l.items[insertIndex - 1] <= x) { // until correct insert Index is found
            break; 
        }

        l.items[insertIndex] = l.items[insertIndex - 1]; 
        moveCount++;
    }

    l.items[insertIndex] = x;   
    l.size++;

    return moveCount;
}

// Doubly-Linked List: Function to insert item x in the sorted list l
int insert(DoublyLinkedList *l, int x) {
    int traverseCount = 0;
    Node *newNode = malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return -1; // Indicate insertion failed due to memory allocation failure
    }

    newNode->item = x;
    newNode->next = newNode->prev = NULL;

    if (l->size == 0) {
        // Empty list, insert as the only node
        l->head = l->tail = newNode;
    } else {
        Node *current = l->head;

        while (current && current->next->item < x) { // Traverse 
            traverseCount++;
            current = current->next;
        }

        if (current->item < x) { 
            // Insert directly if new head
            newNode->next = l->head;
            l->head->prev = newNode;
            l->head = newNode;
        }
        else if (!current->next) {
            // Insert at the end (as the new tail)
            newNode->prev = l->tail;
            l->tail->next = newNode;
            l->tail = newNode;
        } else {
            // Insert after the current node 
            newNode->next = current->next;
            newNode->prev = current;
            current->next = newNode;
            newNode->next->prev = newNode;
        }
    }

    l->size++;

    return traverseCount;
}

//G #1
void reverseListItems(list *l) {    // Move all elements before the last element to the end  
    int size = getSize(&l);         // of the list using push_back
    for (int i = size - 2; i >= 0; i--) {
        int tmp = getItem(&l, i);   
        erase(l, i);
        push_back(l, tmp);
    }
}

// Example
// 1 2 3 (tmp = 2)
// 1 3  (erase 2)
// 1 3 2 (push_back 2)
// 1 3 2 (tmp = 1)
// 3 2 (erase 1)
// 3 2 1 (push_back 1)