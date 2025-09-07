#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Table {
    int tableNumber;
    int capacity;
    char diningStatus[15];  // "Dining" or "Not Dining"
    char customerID[10];    // "-" if not occupied
    struct Table *next;
} Table;

Table *tableHead = NULL;

void initializeTables() {
    FILE *file = fopen("Tables.csv", "w");
    if (!file) {
        printf("Error creating Tables.csv file.\n");
        return;
    }

    // Write the header for the CSV file
    fprintf(file, "TableNumber,Capacity,DiningStatus,CustomerID\n");

    // Initialize 12 tables with appropriate capacities
    for (int i = 1; i <= 12; i++) {
        int capacity = (i <= 4) ? 4 : (i <= 8) ? 8 : 12;
        fprintf(file, "%d,%d,Not Dining,-\n", i, capacity);

        // Add table to the linked list
        Table *newTable = (Table *)malloc(sizeof(Table));
        newTable->tableNumber = i;
        newTable->capacity = capacity;
        strcpy(newTable->diningStatus, "Not Dining");
        strcpy(newTable->customerID, "-");
        newTable->next = tableHead;
        tableHead = newTable;
    }

    fclose(file);
    printf("Tables initialized successfully.\n");
}

void loadTables() {
    FILE *file = fopen("Tables.csv", "r");
    if (!file) {
        printf("No Tables.csv file found. Initializing new tables.\n");
        initializeTables();
        return;
    }

    char line[100];

    // Skip the header line explicitly
    fgets(line, sizeof(line), file); // Read the header line and discard it

    // Read the table data
    while (fgets(line, sizeof(line), file)) {
        Table *newTable = (Table *)malloc(sizeof(Table));
        if (sscanf(line, "%d,%d,%[^,],%s", &newTable->tableNumber, &newTable->capacity, 
               newTable->diningStatus, newTable->customerID) == 4) {
            newTable->next = tableHead;
            tableHead = newTable;
        } else {
            printf("Error reading line: %s", line);
        }
    }

    fclose(file);
}

void displayTables() {
    if (!tableHead) {
        printf("No tables available.\n");
        return;
    }

    printf("=====================================================\n");
    printf("| %-12s | %-8s | %-12s | %-10s |\n", 
           "Table Number", "Capacity", "Dining Status", "Customer ID");
    printf("=====================================================\n");

    Table *current = tableHead;
    while (current) {
        printf("| %-12d | %-8d | %-12s | %-10s |\n", 
               current->tableNumber, current->capacity, 
               current->diningStatus, current->customerID);
        current = current->next;
    }

    printf("=====================================================\n");
}

void updateTableStatus(int tableNumber, const char *diningStatus, const char *customerID) {
    Table *current = tableHead;
    while (current) {
        if (current->tableNumber == tableNumber) {
            // Update the table's dining status and customer ID
            strcpy(current->diningStatus, diningStatus);
            strcpy(current->customerID, customerID);

            // Open the CSV file in write mode to rewrite it completely
            FILE *file = fopen("Tables.csv", "w");
            if (!file) {
                printf("Error opening Tables.csv for updating.\n");
                return;
            }

            // Write the header
            fprintf(file, "TableNumber,Capacity,DiningStatus,CustomerID\n");

            // Write the updated table data back to the file
            Table *temp = tableHead;
            while (temp) {
                fprintf(file, "%d,%d,%s,%s\n", temp->tableNumber, temp->capacity, 
                        temp->diningStatus, temp->customerID);
                temp = temp->next;
            }

            fclose(file);
            printf("Table %d updated successfully.\n", tableNumber);
            return;
        }
        current = current->next;
    }
    printf("Table not found.\n");
}
