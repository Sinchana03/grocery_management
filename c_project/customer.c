#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "customer.h"

Customer* createCustomer(const char *name, const char *phoneNumber, const char *email) {
    Customer *customer = (Customer*)malloc(sizeof(Customer));
    if (customer != NULL) {
        strncpy(customer->name, name, MAX_NAME_LENGTH);
        strncpy(customer->phoneNumber, phoneNumber, MAX_PHONE_NUMBER_LENGTH);
        strncpy(customer->email, email, MAX_EMAIL_LENGTH);
    }
    return customer;
}

void displayCustomerInfo(Customer *customer) {
    if (customer != NULL) {
        printf("\nCustomer Information:\n");
        printf("-----------------------------------\n");
        printf("Name: %s\n", customer->name);
        printf("Phone Number: %s\n", customer->phoneNumber);
        printf("Email: %s\n", customer->email);
        printf("-----------------------------------\n");
    } else {
        printf("Error: Customer information is NULL.\n");
    }
}

void freeCustomer(Customer *customer) {
    free(customer);
}

void getCustomerInfo(Customer *customer) {
    printf("Enter customer name: ");
    scanf("%s", customer->name);
    fgets(customer->name, MAX_NAME_LENGTH, stdin);
    customer->name[strcspn(customer->name, "\n")] = '\0'; 

    printf("Enter customer phone number: ");
    fgets(customer->phoneNumber, MAX_PHONE_NUMBER_LENGTH, stdin);
    customer->phoneNumber[strcspn(customer->phoneNumber, "\n")] = '\0'; 

    printf("Enter customer email: ");
    fgets(customer->email, MAX_EMAIL_LENGTH, stdin);
    customer->email[strcspn(customer->email, "\n")] = '\0';
}
