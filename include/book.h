#ifndef BOOK_H
#define BOOK_H

#include <stdbool.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_CATEGORY_LENGTH 50

typedef struct {
    int id;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int publicationYear;
    char category[MAX_CATEGORY_LENGTH];
    bool available;
} Book;

Book inputBook(void);
void printBook(Book book);
void saveBook(Book book);
void readBooks(void);
void searchBookById(int id);

#endif