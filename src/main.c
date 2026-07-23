#include "book.h"

int main(void){
    Book newBook = inputBook();

    saveBook(newBook);

    printBook(newBook);

    return 0;
}