#ifndef BOOK_H
#define BOOK_H

#include <string.h>
#include <stdbool.h>

typedef struct Book {
	int id;
	char bookName[20];
	char authorName[20];
	bool isBorrow;
}Book;

Book createBook(int id, char bookName[], char author[]);

#endif // !BOOK_H