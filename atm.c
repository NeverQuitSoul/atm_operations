#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 100

// Structure for a customer node
typedef struct Customer {
    char name[NAME_LENGTH];
    int amount;
    struct Customer* next;
} Customer;

// Queue front and rear
Customer* front = NULL;
Customer* rear = NULL;

// Enqueue: Add a customer to the queue
void addCustomer(char name[], int amount) {
    Customer* newCustomer = (Customer*)malloc(sizeof(Customer));
    strcpy(newCustomer->name, name);
    newCustomer->amount = amount;
    newCustomer->next = NULL;

    if (rear == NULL) {
        front = rear = newCustomer;
    } else {
        rear->next = newCustomer;
        rear = newCustomer;
    } 
if(amount<100 || (amount%100 !=0)){
printf("Invalid Amount");
} else {
    printf("Customer %s added with withdrawal amount %d.\n", name, amount);
}
}

// Dequeue: Process the first customer
void processCustomer() {
    if (front == NULL) {
        printf("Queue is empty. No customer to process.\n");
        return;
    }

    printf("Processing customer: %s\n", front->name);
    printf("Withdrawal Amount: %d\n", front->amount);

    // Simulate successful transaction
    Customer* temp = front;
    front = front->next;

    // If queue becomes empty
    if (front == NULL)
        rear = NULL;

    printf("Transaction successful for %s. Removing from queue.\n", temp->name);
    free(temp);
}

// Display queue
void displayQueue() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    Customer* temp = front;
    printf("\n--- ATM Queue ---\n");
    while (temp != NULL) {
        printf("Customer: %s | Amount: %d\n", temp->name, temp->amount);
        temp = temp->next;
    }
    printf("------------------\n");
}

// Menu
int main() {
    int choice, amount;
    char name[NAME_LENGTH];

    while (1) {
        printf("\nATM Transaction Queue System\n");
        printf("1. Add Customer\n");
        printf("2. Process Withdrawal\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume newline left by scanf

        switch (choice) {
            case 1:
                printf("Enter customer name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline
                printf("Enter withdrawal amount: ");
                scanf("%d", &amount);
                addCustomer(name, amount);
                break;
            case 2:
                processCustomer();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                printf("Exiting ATM System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
