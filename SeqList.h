#ifndef SEQLIST_H
#define SEQLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "book.h"

typedef struct SeqList {
	Book* list;
	int max;
	int len;
}SeqList;

bool initSeqList(SeqList* s, int count);
void destroySeqList(SeqList* s);
void clearSeqList(SeqList* s);
bool isEmpty(const SeqList* s);
bool isFull(const SeqList* s);
int getLength(const SeqList* s);
bool getItem(const SeqList* s, int count, Book* b);
int insItem_reverse(SeqList* s, int locate, const Book* book);
bool removeItem(SeqList* s, int locate, Book* book);
bool replaceItem(SeqList* s, int locate, const Book* book);
bool expandSeqList(SeqList* s, int count, bool isAdd_isnotMultiplication);

#endif
