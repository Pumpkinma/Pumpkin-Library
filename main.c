#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "scene.h"

int main(void) {
	bool run = true;
	int get;
	SeqList s;
	bool settings[10];
	float version = 1.03;
	initSeqList(&s, 2);
	while (run) {
		printf("欢迎使用图书管理器 v%.2f\n请输入您要执行的操作\n\n", version);
		printf("1.添加图书\n2.查找图书并执行操作\n3.设置\n4.退出\n\n");
		printf("输入操作的序号即可\n");
		readInt(&get);

		switch (get) {
		case 1: addBook(&s); break;
		case 2: chooseBook(&s); break;
		case 3: setting(); break;
		case 4: run = false; break;
		default: system("cls"); break;
		}
	}
}