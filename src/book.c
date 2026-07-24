#include "book.h"
#include <stdio.h>

Book inputBook (void){
    Book newBook;

    printf("Enter book ID: ");
    scanf("%d", &newBook.id);

    printf("Enter title: ");
    scanf(" %[^\n]", newBook.title);

    printf("Enter author: ");
    scanf(" %[^\n]", newBook.author);

    printf("Enter publication year: ");
    scanf("%d", &newBook.publicationYear);

    printf("Enter category: ");
    scanf(" %[^\n]", newBook.category);

    newBook.available = true;

    return newBook;
}

void printBook(Book book){
    printf("\n----- Book Information -----\n");
    printf("ID: %d\n", book.id);
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Publication Year: %d\n", book.publicationYear);
    printf("Category: %s\n", book.category);
    printf("Available: %s\n", book.available ? "Yes" : "No");
}

void saveBook(Book book){

    FILE *file = fopen("data/books.dat","ab");

    if (file == NULL){
        printf("Error opening file. \n");
        return;
    }

    fwrite(&book, sizeof(Book), 1, file);

    fclose(file);
}

void readBooks(void){

    Book book;

    FILE *file = fopen("data/books.dat","rb");

    if (file == NULL){
        printf("No books have been saved yet.\n");
        return;
    }

    while (fread(&book, sizeof(Book), 1, file) == 1){

        printBook(book);
    }

    fclose(file);

}

void searchBookById(int id){

    Book book;
    bool found = false;

    FILE *file = fopen("data/books.dat","rb");

    if (file == NULL){
        printf("Error opening file. \n");
        return;
    }

    while (fread(&book, sizeof(Book), 1, file) == 1){
        if(book.id == id){
            printBook(book);
            found = true;
            break;
        }
    }
    if (!found){
        printf("Book not found.\n");
    }

    fclose(file);
}
