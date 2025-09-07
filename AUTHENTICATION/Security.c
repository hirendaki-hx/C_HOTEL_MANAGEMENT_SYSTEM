#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "CUSTOMER/Customer.c"
#include "CUSTOMER/TABLES/Table.c"
#include "CUSTOMER/Queue.c"

// Predefined passwords for roles
#define ADMIN_PASSWORD "admin123"
#define DESC_PASSWORD "desc123"

void Admin();
void Reception();

void login() {
    char password[20];
    int attempts = 3;

    printf("===== Role-Based Login =====\n");
    printf("Enter your password to log in.\n");

    while (attempts > 0) {
        printf("Password: ");
        scanf("%s", password);

        if (strcmp(password, ADMIN_PASSWORD) == 0) {
            printf("Login successful! Welcome Admin.\n");
            Admin();
            return;
        } else if (strcmp(password, DESC_PASSWORD) == 0) {
            printf("Login successful! Welcome Desc.\n");
            Reception();
            return;
        } else {
            printf("Invalid password. You have %d attempt(s) left.\n", --attempts);
        }
    }

    printf("Too many failed attempts. Exiting...\n");
}


void Admin(){
    int choice = 0;
    int loop = 1;

    while (loop!=0){
        printf("Admin Pannel");
        // REWRITE:
        printf("/n 1. View Customers");
        printf("/n 2. View Queue");
        printf("/n 3. View Tables");
        printf("/n 4. Exit");

        switch(choice){
            case 1:
                displayCustomers();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:

                break;
            default:
                // goto REWRITE;
                break;

        }
    }
}

void Reception(){
    printf("Hello reception");
}
