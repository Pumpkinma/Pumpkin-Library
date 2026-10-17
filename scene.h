#ifndef SCENE_H
#define SCENE_H

#include "SeqList.h"

void printBooks(const SeqList* s);
void printBook1(const SeqList* s, int count);
void printBook2(const Book* book);
int scanf_get_zero();
void readInt(int* locate);
void end();

void addBook(SeqList* s);
void setting();
void chooseBook(SeqList* s);

void replaceBook(SeqList* s, int locate);
void removeBook(SeqList* s, int locate);
void borrowBook(SeqList* s, int locate);

#endif // !SCENE_H