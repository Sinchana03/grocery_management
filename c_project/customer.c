#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "customer.h"

#define CUSTOMER_PATH "customers.csv"

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
    fgets(customer->name, MAX_NAME_LENGTH, stdin);
    customer->name[strcspn(customer->name, "\n")] = '\0'; 

    printf("Enter customer phone number: ");
    fgets(customer->phoneNumber, MAX_PHONE_NUMBER_LENGTH, stdin);
    customer->phoneNumber[strcspn(customer->phoneNumber, "\n")] = '\0'; 

    printf("Enter customer email: ");
    fgets(customer->email, MAX_EMAIL_LENGTH, stdin);
    customer->email[strcspn(customer->email, "\n")] = '\0';
}

void saveCustomerToFile(Customer *customer) {
    FILE *file = fopen(CUSTOMER_PATH, "a");
    if (file == NULL) {
        perror("Error opening customer file");
        printf("Please check file permissions or directory existence.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s,%s,%s\n", customer->name, customer->phoneNumber, customer->email);

    fclose(file);
}
