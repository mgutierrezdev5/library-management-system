#ifndef BOOK_H
#define BOOK_H

#include <stdbool.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_CATEGORY_LENGTH 50
#define MAX_BORROWER_LENGTH 100
#define MAX_DATE_LENGTH 11

typedef struct {
    int id;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int publicationYear;
    char category[MAX_CATEGORY_LENGTH];
    char borrower[MAX_BORROWER_LENGTH];
    char loanDate[MAX_DATE_LENGTH];
    bool available;
} Book;

Book inputBook(void);
void printBook(Book book);
void saveBook(Book book);
void readBooks(void);
void searchBookById(int id);
void editBook(int id);
void deleteBook(int id);
void borrowBook(int id);
void returnBook(int id);

#endif