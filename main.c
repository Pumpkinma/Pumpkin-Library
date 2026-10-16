#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "scene.h"

int main(void) {
	bool run = true;
	int get;
	SeqList s;
	initSeqList(&s, 2);
	while (run) {
		printf("欢迎使用图书管理器\n请输入您要执行的操作\n\n");
		printf("1.添加图书\n2.移除图书\n3.按顺序查找图书（输入顺序）\n4.查看所有图书\n5.借出图书\n6.归还图书\n7.退出\n\n");
		printf("输入操作的序号即可\n");
		if (!scanf("%d", &get)) break;

		switch (get) {
		case 1: addBook(&s); break;
		case 2: removeBook(&s); break;
		case 3: getBook(&s); break;
		case 4: printBooks(&s); break;
		case 5: borrowTo(&s); break;
		case 6: borrowBack(&s); break;
		case 7: run = false; break;
		default: break;
		}
	}
}