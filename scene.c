#define _CRT_SECURE_NO_WARNINGS
#include "scene.h"

void printBooks(const SeqList* s) {
	for (int i = 0; i < s->len; i++) {
		printf("%d	%s	%s	", s->list[i].id, s->list[i].bookName, s->list[i].authorName);
		printf("%s\n", s->list[i].isBorrow ? "已借出" : "未借出");
	}
}

void printBook1(const SeqList* s, int count) {
	Book book;
	if (getItem(s, count, &book)) {
		printf("%d %s %s %s\n", s->list[count - 1].id, s->list[count - 1].bookName, s->list[count - 1].authorName, s->list[count - 1].isBorrow ? "已借出" : "未借出");
		return;
	}
	printf("输入非法\n");
}

void printBook2(const Book* book) {
	printf("%d %s %s %s\n", book->id, book->bookName, book->authorName, book->isBorrow ? "已借出" : "未借出");
}

int scanf_get() {
	int get;
	printf("请输入书在库里的位置，起始位置为1\n两次均输入0则视作主动放弃\n");
	scanf("%d", &get);
	if (get == 0) {
		scanf("%d", &get);
		if (get == 0) {
			printf("已主动放弃\n");
			return 0;
		}
	}
	return get;
}

void addBook(SeqList* s) {
	system("cls");
	if ((s->len == s->max) && !expandSeqList(s, 1, true)) {
		printf("扩容失败\n");
		return;
	}
	printf("请分别输入书名、作者名以及书的id，使用空格分隔\n");
	printf("例子：西游记 吴承恩 1\n");
	if (scanf("%19s %19s %d", s->list[s->len].bookName, s->list[s->len].authorName, &s->list[s->len].id) != 3) {
		printf("有内容未被正常赋值！\n");
		return;
	}
	s->list[s->len].isBorrow = false;
	s->len++;
	printf("输入成功\n\n\n");
}

void removeBook(SeqList* s) {
	system("cls");
	int get = scanf_get();
	if (!get) return;
	Book book;
	if (!removeItem(s, get, &book)) {
		printf("输入非法\n");
		return;
	}
	printf("已移除图书 %s\n", book.bookName);
}

void getBook(const SeqList* s) {
	system("cls");
	int get = scanf_get();
	if (!get) return;
	Book book;
	if (!getItem(s, get, &book)) {
		printf("输入非法\n");
		return;
	}
	printBook2(&book);
}

void borrowTo(SeqList* s) {
	system("cls");
	int get = scanf_get();
	if (get < 1 || get > getLength(s)) return;
	if (s->list[get - 1].isBorrow) {
		printf("该书已借出\n");
		return;
	}
	s->list[get - 1].isBorrow = true;
	printf("成功借走\n");
}

void borrowBack(SeqList* s) {
	system("cls");
	int get = scanf_get();
	if (get < 1 || get > getLength(s)) return;
	if (!s->list[get - 1].isBorrow) {
		printf("该书已在库中\n");
		return;
	}
	s->list[get - 1].isBorrow = false;
	printf("成功归还\n");
}