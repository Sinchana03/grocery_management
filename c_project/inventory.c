#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"

#define INVENTORY_FILE_PATH "C:\\Users\\sinch\\c_grocery_management\\inventory.csv"

Item* createItem(const char *name, float price, int quantity) {
    Item *item = (Item*)malloc(sizeof(Item));
    if (item != NULL) {
        strncpy(item->name, name, MAX_ITEM_NAME_LENGTH);
        item->price = price;
        item->quantity = quantity;
    }
    return item;
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

Item *findItemByName(LinkedList *inventoryList, const char *name) {
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

void loadInventoryFromFile(LinkedList *inventoryList) {
    FILE *file = fopen(INVENTORY_FILE_PATH, "r");
    if (file == NULL) {
        perror("Error opening inventory file");
        printf("Please check file permissions or directory existence: %s\n", INVENTORY_FILE_PATH);
        exit(EXIT_FAILURE);
    }

    char *line = NULL;
    size_t len = 0;
    size_t read;

    while ((read = getline(&line, &len, file)) != -1) {
    
        char *name = strtok(line, ",");
        float price = atof(strtok(NULL, ","));
        int quantity = atoi(strtok(NULL, ","));
        Item *item = createItem(name, price, quantity);
        if (item == NULL) {
            fprintf(stderr, "Failed to allocate memory for item. Exiting.\n");
            exit(EXIT_FAILURE);
        }
        append(inventoryList, item);
    }

    if (line) {
        free(line);
    }
    fclose(file);
}

void saveInventoryToFile(LinkedList *inventoryList) {
    FILE *file = fopen(INVENTORY_FILE_PATH, "w");
    if (file == NULL) {
        perror("Error opening inventory file");
        printf("Please check file permissions or directory existence: %s\n", INVENTORY_FILE_PATH);
        exit(EXIT_FAILURE);
    }

    Node *current = inventoryList->head;
    while (current != NULL) {
        Item *item = (Item *)current->data;
        fprintf(file, "%s,%.2f,%d\n", item->name, item->price, item->quantity);
        current = current->next;
    }

    fclose(file);
}
