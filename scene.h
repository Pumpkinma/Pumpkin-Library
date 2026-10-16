#ifndef SCENE_H
#define SCENE_H

#include "SeqList.h"

void printBooks(const SeqList* s);
void printBook1(const SeqList* s, int count);
void printBook2(const Book* book);
int scanf_get();

void addBook(SeqList* s);
void removeBook(SeqList* s);
void getBook(const SeqList* s);
void borrowTo(SeqList* s);
void borrowBack(SeqList* s);

#endif // !SCENE_H