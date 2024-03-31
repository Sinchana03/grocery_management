#include <stdio.h>
#include "customer.h"   
#include "inventory.h"

int main() {
    printf("Welcome to the Grocery Billing System\n");

    struct Customer customer;
    getCustomerInfo(&customer);

    displayInventory();

    startBilling(&customer);

    return 0;
}
