#include <stdio.h>
#include <string.h>
#include "customer.h" 
#include "inventory.h"

void displayInventory() {
    printf("\nAvailable Items:\n");
    printf("-----------------------------------\n");
    printf("Name\t\tPrice\tQuantity\n");
    printf("-----------------------------------\n");
    
    int itemCount = 0;

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (inventory[i].quantity > 0) {
            printf("%s\t\t%.2f\t%d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
            itemCount++;
        }
    }

    if (itemCount == 0) {
        printf("No items available.\n");
    }

    printf("-----------------------------------\n");
}

struct Item inventory[MAX_ITEMS] = {
    {"Apples", 28.0, 100},
    {"Oranges", 32.0, 80},
    {"Bananas", 3.0, 120},
    {"Potato", 7.0, 200},
    {"Tomato", 8.2, 150},
    {"Bread", 40.0, 50},
    {"Milk", 25.0, 75}
};

void startBilling(struct Customer *customer) {
    char itemName[MAX_ITEM_NAME_LENGTH];
    int quantity;
    float totalAmount = 0;

    printf("\nEnter items to purchase (enter 'done' to finish):\n");
    printf("Item Name: ");
    scanf("%s", itemName);

    while (strcmp(itemName, "done") != 0) {
        printf("Quantity: ");
        scanf("%d", &quantity);

        int found = 0;
        for (int i = 0; i < MAX_ITEMS; i++) {
            if (strcmp(itemName, inventory[i].name) == 0) {
                if (inventory[i].quantity >= quantity) {
                    totalAmount += inventory[i].price * quantity;
                    inventory[i].quantity -= quantity;
                    found = 1;
                    break;
                } else {
                    printf("Insufficient quantity available for %s\n", itemName);
                    found = 1;
                    break;
                }
            }
        }

        if (!found) {
            printf("Item not found in inventory.\n");
        }

        printf("Item Name: ");
        scanf("%s", itemName);
    }

    printf("\nBilling Details:\n");
    printf("Customer Name: %s\n", customer->name);
    printf("Phone Number: %s\n", customer->phoneNumber);
    printf("Email: %s\n", customer->email);
    printf("Total Amount: %.2f rupees\n", totalAmount);
}
