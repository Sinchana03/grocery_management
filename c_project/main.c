#include "customer.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "login.h"
#include "inventory.h"

int main() {
    LinkedList *inventoryList = createLinkedList();

    loadInventoryFromFile(inventoryList);

    displayInventory(inventoryList);

    char username[MAX_USERNAME_LENGTH];
    printf("\nEnter your username: ");
    scanf("%s", username);
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);

    Customer customer;
    getCustomerInfo(&customer);

    char choice;
    float totalPrice = 0.0;
    do {
        char itemName[MAX_ITEM_NAME_LENGTH];
        int quantity;
        printf("\nEnter the name of the item you want to buy: ");
        scanf("%s", itemName);
        printf("Enter the quantity: ");
        scanf("%d", &quantity);

        Item *item = findItemByName(inventoryList, itemName);
        if (item != NULL) {
            totalPrice += item->price * quantity;
            printf("Added %d %s to your cart.\n", quantity, itemName);
        } else {
            printf("Item '%s' not found in inventory.\n", itemName);
        }

        printf("\nDo you want to buy more items? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nTotal Price: %.2f rupees\n", totalPrice);

    saveCustomerToFile(&customer);
    saveInventoryToFile(inventoryList);

    freeLinkedList(inventoryList);

    return 0;
}
