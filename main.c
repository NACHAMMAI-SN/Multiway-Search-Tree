#include "multiway_tree.h"
#include <stdio.h>
#include <stdlib.h>

void printMenu();
void insertKey(struct node **root);
void deleteKey(struct node **root);
void searchKey(struct node *root);
void printTree(struct node *root);
void exitProgram(struct node *root);

int main()
{
    struct node *root = NULL;
    int choice;

    do
    {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertKey(&root);
                break;
            case 2:
                deleteKey(&root);
                break;
            case 3:
                searchKey(root);
                break;
            case 4:
                printTree(root);
                break;
            case 5:
                exitProgram(root);
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}

void printMenu()
{
    printf("\nMenu:\n");
    printf("1. Insert a key\n");
    printf("2. Delete a key\n");
    printf("3. Search for a key\n");
    printf("4. Print the tree\n");
    printf("5. Exit\n");
}

void insertKey(struct node **root)
{
    int key;
    printf("Enter the key to insert: ");
    scanf("%d", &key);
    *root = insert(*root, key);
    printf("Key %d inserted successfully.\n", key);
}

void deleteKey(struct node **root)
{
    int key;
    printf("Enter the key to delete: ");
    scanf("%d", &key);
    *root = deleteValue(*root, key);
}

void searchKey(struct node *root)
{
    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);

    int result = search(root, key);

    if (result == 1)
    {
        printf("%d is found in the tree.\n", key);
    }
    else if (result == 0)
    {
        printf("%d is not found in the tree.\n", key);
    }
    else
    {
        printf("Error: Invalid search result.\n");
    }
}


void exitProgram(struct node *root)
{
    exit(EXIT_SUCCESS);
}
