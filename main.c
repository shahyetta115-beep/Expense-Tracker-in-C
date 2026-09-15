#include <stdio.h>
#include <string.h>

struct Expense {
    float amount;
    char category[30];
};

void addExpense(struct Expense expenses[], int *count) {
    printf("\nEnter expense amount: Rs. ");
    scanf("%f", &expenses[*count].amount);

    printf("Enter category: ");
    scanf("%s", expenses[*count].category);

    (*count)++;

    printf("Expense added successfully!\n");
}

void viewExpenses(struct Expense expenses[], int count) {
    if (count == 0) {
        printf("\nNo expenses recorded.\n");
        return;
    }

    printf("\n========== EXPENSES ==========\n");

    for (int i = 0; i < count; i++) {
        printf("%d. %-15s Rs. %.2f\n",
               i + 1,
               expenses[i].category,
               expenses[i].amount);
    }
}

void totalExpenses(struct Expense expenses[], int count) {
    float total = 0;

    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }

    printf("\nTotal Spending: Rs. %.2f\n", total);
}

void highestExpense(struct Expense expenses[], int count) {
    if (count == 0) {
        printf("\nNo expenses recorded.\n");
        return;
    }

    int highest = 0;

    for (int i = 1; i < count; i++) {
        if (expenses[i].amount > expenses[highest].amount) {
            highest = i;
        }
    }

    printf("\nHighest Expense:\n");
    printf("%s - Rs. %.2f\n",
           expenses[highest].category,
           expenses[highest].amount);
}

void searchCategory(struct Expense expenses[], int count) {
    char category[30];
    int found = 0;

    printf("\nEnter category to search: ");
    scanf("%s", category);

    printf("\nExpenses in %s:\n", category);

    for (int i = 0; i < count; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            printf("Rs. %.2f\n", expenses[i].amount);
            found = 1;
        }
    }

    if (!found) {
        printf("No expenses found in this category.\n");
    }
}

int main() {
    struct Expense expenses[100];
    int count = 0;
    int choice;

    do {
        printf("\n========== EXPENSE TRACKER ==========\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Calculate Total Spending\n");
        printf("4. Show Highest Expense\n");
        printf("5. Search by Category\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;

            case 2:
                viewExpenses(expenses, count);
                break;

            case 3:
                totalExpenses(expenses, count);
                break;

            case 4:
                highestExpense(expenses, count);
                break;

            case 5:
                searchCategory(expenses, count);
                break;

            case 6:
                printf("\nThank you for using Expense Tracker!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}
