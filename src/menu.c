#include <stdio.h>
#include <stdbool.h>

#include "menu.h"
#include "book.h"

void menu(void){

    bool running = true;
    int option;

    while (running){

        printf("==============================\n");
        printf("      Library Management      \n");
        printf("==============================\n");
        printf("1. Add book\n");
        printf("2. Show all books\n");
        printf("3. Search book by ID\n");
        printf("4. Edit a book by ID\n");
        printf("5. Delete a book by ID\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        switch (option){
            case 1:
            {
                Book newBook;
                newBook = inputBook();
                saveBook(newBook);
                break;
            }
            case 2:
                readBooks();
                break;
            case 3:
            {
                int id;
                printf("Enter the ID: ");
                scanf("%d", &id);
                searchBookById(id);
                break;
            }
            case 4:
            {
                int id;
                printf("Enter the ID: ");
                scanf("%d", &id);
                editBook(id);
                break;
            }
            case 5:
            {
                int id;
                printf("Enter the ID: ");
                scanf("%d", &id);
                deleteBook(id);
                break;
            }
            case 6:
            {
                running = false;
                break;
            }
            default:
                printf("Invalid option.\n");
        }
    }
    
}