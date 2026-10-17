#include "SeqList.h"

bool initSeqList(SeqList* s, int count) {
	s->list = (Book*)malloc(sizeof(Book) * count);
	if (!s->list) return false;
	s->len = 0;
	s->max = count;
	return true;
}

void destroySeqList(SeqList* s) {
	free(s->list);
	s->list = NULL;
	s->max = 0;
	s->len = 0;
}

void clearSeqList(SeqList* s) {
	s->len = 0;
}

bool isEmpty(const SeqList* s) {
	return s->len == 0;
}

bool isFull(const SeqList* s) {
	return s->max == s->len;
}

int getLength(const SeqList* s) {
	return s->len;
}

bool getItem(const SeqList* s, int count, Book* book) {
	if (count < 1 || count > s->len) return false;
	*book = s->list[count - 1];
	return true;
}

int insItem_reverse(SeqList* s, int locate, const Book* book) {
	if (locate < 1 || locate > getLength(s) + 1) return 1;
	if (isFull(s) && !expandSeqList(s, 1, true)) return 2;

	for (int i = s->len; i > locate - 1; i--) {
		s->list[i] = s->list[i - 1];
	}
	s->list[locate - 1] = *book;
	s->len++;
	return 0;
}

bool removeItem(SeqList* s, int locate, Book* book) {
	if (locate < 1 || locate > getLength(s)) return false;
	*book = s->list[locate - 1];

	for (int i = locate - 1; i < getLength(s) - 1; i++) {
		s->list[i] = s->list[i + 1];
	}
	s->len--;
	return true;
}

bool replaceItem(SeqList* s, int locate, const Book* book) {
	if (locate < 1 || locate > getLength(s)) return false;
	s->list[locate - 1] = *book;
	return true;
}

bool expandSeqList(SeqList* s, int count, bool isAdd_isnotMultiplication) {
	int cap;
	if (isAdd_isnotMultiplication) cap = s->max + count;
	else cap = s->max * count;
	Book* b = (Book*)realloc(s->list, sizeof(Book) * cap);
	if (!b) return false;
	s->list = b;
	s->max = cap;
	return true;
}