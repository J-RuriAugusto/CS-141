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


//B
typedef struct {
    int red, green, blue;
} color;

void countColors (color image[][1000], int r, int c) {
    int redCount = 0, greenCount = 0, blueCount = 0, whiteCount = 0, blackCount = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            color currentPixel = image[i][j];
            if (currentPixel.red == 255 && currentPixel.green == 0 && currentPixel.blue == 0) {
                redCount++;
            } else if (currentPixel.red == 0 && currentPixel.green == 255 && currentPixel.blue == 0) {
                greenCount++;
            } else if (currentPixel.red == 0 && currentPixel.green == 0 && currentPixel.blue == 255) {
                blueCount++;
            } else if (currentPixel.red == 255 && currentPixel.green == 255 && currentPixel.blue == 255) {
                whiteCount++;
            } else if (currentPixel.red == 0 && currentPixel.green == 0 && currentPixel.blue == 0) {
                blackCount++;
            }
        }
    }

    printf("Red count: %i\n", redCount);
    printf("Green count: %i\n", greenCount);
    printf("Blue count: %i\n", blueCount);
    printf("White count: %i\n", whiteCount);
    printf("Black count: %i\n", blackCount);
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
} node;

typedef struct {
    int size;
    node *head, *tail;
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
    node *newNode = malloc(sizeof(node));
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
        node *current = l->head;

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


//D
typedef struct mynode {
    int item;
    struct mynode *next;
} node;

typedef struct {
    int size;
    node *head, *tail;
} list;

// Function to reverse the singly-linked list in linear time
void reverse(list *l) {
    if (l->size <= 1) {
        // No need to reverse if the list is empty or has only one node
        return;
    }

    node *current = l->head;
    node *prev = NULL;
    node *nextNode = NULL;

    while (current) {
        // Store the next node before modifying the "next" pointer
        nextNode = current->next;
        current->next = prev; // Reverse the pointer

        // Move the "prev" and "current" pointers one step forward
        prev = current;
        current = nextNode;
    }

    // Swap the head and tail pointers to reflect the reversed list
    node *temp = l->head;
    l->head = l->tail;
    l->tail = temp;
}


//E
// Function to erase the item in position pos from the tail of the doubly-linked list
void erase(list *l, int pos) {
    if (l->size == 0 || pos < 1 || pos > l->size) {
        printf("Invalid position to erase\n");
        return;
    }

    // Find the node to be erased by traversing from the tail
    node *current = l->tail;
    for (int i = 1; i < pos; i++) {
        current = current->prev;
    }

    // Handle if the node to be erased is the head or tail
    if (current == l->head) {
        l->head = current->next;
        if (l->head) {
            l->head->prev = NULL;
        }
    } else if (current == l->tail) {
        l->tail = current->prev;
        if (l->tail) {
            l->tail->next = NULL;
        }
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    // Free the memory used by the erased node
    free(current);
    l->size--;
}


//F
// Function to get the size of the doubly-linked list
int getSize(list l) {
    int size = 0;
    node *current = l.head;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
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

//#2
void eraseEvenPositions(list *l) {
    for (int i = l->size - 1; i >= 0; i--) {
        if (i % 2 == 0) {
            erase(l, i);
        }
    }
}