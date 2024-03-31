#ifndef INVENTORY_H
#define INVENTORY_H

#define MAX_ITEMS 100 
#define MAX_ITEM_NAME_LENGTH 50

struct Item {
    char name[50];
    float price;
    int quantity;
};

extern struct Item inventory[MAX_ITEMS];

void displayInventory();

#endif // INVENTORY_H
