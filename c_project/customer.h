#ifndef CUSTOMER_H
#define CUSTOMER_H

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 15
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phoneNumber[MAX_PHONE_NUMBER_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Customer;

Customer* createCustomer(const char *name, const char *phoneNumber, const char *email);
void displayCustomerInfo(Customer *customer);
void freeCustomer(Customer *customer);
void getCustomerInfo(Customer *customer);

#endif /* CUSTOMER_H */
