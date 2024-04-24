#include <stdio.h>
#include <string.h>
#include "login.h"
#include <stdbool.h>

bool addUser(const char *newUsername, const char *newPassword) {
 
    if (newUsername == NULL || newPassword == NULL) {
        fprintf(stderr, "Error: Null pointer detected.\n");
        return false;
    }

    size_t usernameLength = strlen(newUsername);
    size_t passwordLength = strlen(newPassword);
    if (usernameLength >= MAX_USERNAME_LENGTH || passwordLength >= MAX_PASSWORD_LENGTH) {
        fprintf(stderr, "Error: Username or password too long.\n");
        return false;
    }

    User user;
    strcpy(user.username, newUsername);
    strcpy(user.password, newPassword);
    printf("User '%s' added successfully.\n", user.username);

    return true;
}
