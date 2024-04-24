#ifndef INVENTORY_H
#define INVENTORY_H
#include "linkedlist.h"
#define MAX_ITEM_NAME_LENGTH 50

typedef struct Item {
    char name[MAX_ITEM_NAME_LENGTH];
    float price;
    int quantity;
} Item;

Item *findItem(LinkedList *list, const char *itemName);

Item* createItem(const char *name, float price, int quantity);
void displayInventory(LinkedList *inventoryList);

#endif // INVENTORY_H
