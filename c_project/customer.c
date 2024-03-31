#include <stdio.h>
#include <string.h>
#include "customer.h"

void getCustomerInfo(struct Customer *customer) {
    
    printf("Enter customer name: ");
    fgets(customer->name, MAX_NAME_LENGTH, stdin);
    strtok(customer->name, "\n");
    printf("Enter phone number: ");
    fgets(customer->phoneNumber, 15, stdin);
    strtok(customer->phoneNumber, "\n");
    printf("Enter email: ");
    fgets(customer->email, MAX_EMAIL_LENGTH, stdin);
    strtok(customer->email, "\n");
}
