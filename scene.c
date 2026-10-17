#define _CRT_SECURE_NO_WARNINGS
#include "scene.h"

void printBooks(const SeqList* s) {
	for (int i = 0; i < s->len; i++) {
		printf("%d\t%d\t%s\t%s\t", i + 1, s->list[i].id, s->list[i].bookName, s->list[i].authorName);
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

int scanf_get_zero() {
	int get;
	printf("两次均输入0则视作主动放弃\n");
	if ((!scanf("%d", &get) || get == 0) && (!scanf("%d", &get) || get == 0)) {
		printf("已主动放弃");
		end();
		return 0;
	}
	return get;
}

void readInt(int* out) {
	int get;
	while (!scanf("%d", &get)) {
		int e;
		while ((e = getchar()) != '\n' && e != EOF);
	}
	*out = get;
}

void end() {
	printf("\n\n\n");
}

void addBook(SeqList* s) {
	system("cls");
	if (isFull(s) && !expandSeqList(s, 1, true)) {
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
	printf("输入成功");
	end();
}

void setting() {
	system("cls");
	printf("当前为设置界面，由于还没有任何选项，目前为空");
	end();
}

void chooseBook(SeqList* s) {
	system("cls");
	printBooks(s);
	int get, i;
	printf("输入书籍的地址来选中该书\n");
	get = scanf_get_zero();
	if (!get) return;

	Book book;
	if (!getItem(s, get, &book)) {
		printf("输入非法\n");
		return;
	}
	i = get;
	printf("输入序号进行操作\n");
	printf("1.图书信息更改\n2.图书删除\n3.图书的借出与归还\n");
	do {
		readInt(&get);
	} while (get != 1 && get != 2 && get != 3);

	switch (get) {
	case 1: replaceBook(s, i); break;
	case 2: removeBook(s, i); break;
	case 3: borrowBook(s, i); break;
	}
}

//略显臃肿
void replaceBook(SeqList* s, int locate) {
	printf("请依次输入id，书名，作者名\n");
	int id;
	char bookName[20], author[20];
	if (scanf("%d %19s %19s", &id, &bookName, &author) < 3) {
		printf("输入有误\n");
		return;
	}
	Book book = createBook(id, bookName, author);
	replaceItem(s, locate, &book);
	end();
}

void removeBook(SeqList* s, int locate) {
	Book book;
	if (!removeItem(s, locate, &book)) return;
	printf("移除成功");
	end();
}

void borrowBook(SeqList* s, int locate) {
	if (s->list[locate - 1].isBorrow) {
		s->list[locate - 1].isBorrow = false;
		printf("成功归还\n");
		return;
	}
	s->list[locate - 1].isBorrow = true;
	printf("成功借出\n");
	end();
}