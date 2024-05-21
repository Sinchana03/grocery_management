#ifndef INVENTORY_H
#define INVENTORY_H

#include "linkedlist.h"

#define MAX_ITEM_NAME_LENGTH 50

typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    float price;
    int quantity;
} Item;

Item* createItem(const char *name, float price, int quantity);
void displayInventory(LinkedList *inventoryList);
Item *findItemByName(LinkedList *inventoryList, const char *name);
void updateItemQuantity(Item *item, int quantity);
void freeInventory(LinkedList *inventoryList);
void loadInventoryFromFile(LinkedList *inventoryList);
void saveInventoryToFile(LinkedList *inventoryList);

#endif /* INVENTORY_H */
