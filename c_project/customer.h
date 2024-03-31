#ifndef CUSTOMER_H
#define CUSTOMER_H

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50

struct Customer {
    char name[MAX_NAME_LENGTH];
    char phoneNumber[15];
    char email[MAX_EMAIL_LENGTH];
};

void getCustomerInfo(struct Customer *customer);
void startBilling(struct Customer *customer);

#endif // CUSTOMER_H
