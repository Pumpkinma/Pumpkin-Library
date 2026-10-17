#define _CRT_SECURE_NO_WARNINGS

#include "book.h"

Book createBook(int id, char bookName[], char author[]) {
	Book book;
	book.id = id;
	strcpy(book.bookName, bookName);
	strcpy(book.authorName, author);
	book.isBorrow = false;
	return book;
}