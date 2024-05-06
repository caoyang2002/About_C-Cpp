#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void meun() {
	printf("*************************\n");
	printf("******** 1. play ********\n");
	printf("******** 0. exit ********\n");
	printf("*************************\n");
}

void game() {
	char mine[ROWS][COLS] = {0};//存放布置好的雷的信息
	char show[ROWS][COLS] = {0};//存放排查出的雷的信息
	//初始化数组内容为指定的内容
	//mine数组在没有布置雷的时候, 都是'0'
	InitBoard(mine,ROWS,COLS,'0');
	//show数组在没有排查雷的时候, 都是'*'
	InitBoard(show, ROWS, COLS,'*');
	//设置雷
	SetMine(mine,ROW,COL);

	//作弊
	//DisplayBoard(mine, ROW, COL);
	
	DisplayBoard(show, ROW, COL);

	//排查雷
	FindMine(mine, show, ROW, COL);

	//拓展
	//标记功能
	//自动排查空,到雷停止
}


int main() {
	
	int input = 0;
	//随机数的生成起点
	srand((unsigned int)(time(NULL)));
	do{
		meun();
		printf("请选择 >");
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("选择错误, 请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}