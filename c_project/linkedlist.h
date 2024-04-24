#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} LinkedList;

LinkedList* createLinkedList();
void append(LinkedList *list, void *data);
void freeLinkedList(LinkedList *list);

#endif // LINKEDLIST_H
