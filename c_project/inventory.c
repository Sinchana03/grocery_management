#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"
#include "linkedlist.h"

Item* createItem(const char *name, float price, int quantity) {
    Item *item = (Item*)malloc(sizeof(Item));
    if (item != NULL) {
        strncpy(item->name, name, MAX_ITEM_NAME_LENGTH);
        item->price = price;
        item->quantity = quantity;
    }
    return item;
}

Item *findItem(LinkedList *list, const char *itemName) {
    Node *current = list->head;
    while (current != NULL) {
        Item *item = (Item *)current->data;
        if (strcmp(item->name, itemName) == 0) {
            return item;
        }
        current = current->next;
    }
    return NULL; 
}


void displayInventory(LinkedList *inventoryList) {
    printf("\nAvailable Items:\n");
    printf("-----------------------------------\n");
    printf("Name\t\tPrice\tQuantity\n");
    printf("-----------------------------------\n");
    
    Node *current = inventoryList->head;
    while (current != NULL) {
        Item *item = (Item*)current->data;
        printf("%s\t\t%.2f\t%d\n", item->name, item->price, item->quantity);
        current = current->next;
    }

    printf("-----------------------------------\n");
}

Item* findItemByName(LinkedList *inventoryList, const char *name) {
    Node *current = inventoryList->head;
    while (current != NULL) {
        Item *item = (Item*)current->data;
        if (strcmp(item->name, name) == 0) {
            return item;
        }
        current = current->next;
    }
    return NULL;
}

void updateItemQuantity(Item *item, int quantity) {
    item->quantity += quantity;
}

void freeInventory(LinkedList *inventoryList) {
    freeLinkedList(inventoryList);
}
