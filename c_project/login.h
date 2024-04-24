#ifndef LOGIN_H
#define LOGIN_H
#include <stdbool.h>

#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

bool addUser(const char *newUsername, const char *newPassword);

#endif // LOGIN_H
