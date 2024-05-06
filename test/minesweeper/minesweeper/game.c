#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set) {
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col) {
	int i = 0;
	int j = 0;
	printf("------扫雷游戏------\n");
	for (j = 0; j <= col; j++) {
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++) {
		printf("%d ", i);
		for (j = 1; j <= col; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("--------------------\n");
}

void SetMine(char board[ROWS][COLS], int row, int col) {
	int count = EASY_COUNT;
	while (count) {
		int x = rand()%row+1;
		int y = rand()%col+1;
		if (board[x][y] == '0') {
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char board[ROWS][COLS],int x,int y) {
	/*return (board[x - 1][y] +
			board[x - 1][y - 1] +
			board[x][y + 1] +
			board[x + 1][y - 1] +
			board[x + 1][y] +
			board[x + 1][y + 1] +
			board[x][y - 1] +
			board[x - 1][y + 1] -
			8 * '0');*/
	
	//使用循环
	int i = 0;
	int j = 0;
	int n = 0;
	for ( i = -1; i <= 1; i++) {
		for (j = -1; j <= 1; j++) {
			n = n + board[x+i][y+j];
		}
	}
	return (n - 9 * '0');

}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	int x = 0;
	int y = 0;
	int win = 0;//非雷的个数
	while (win<row*col-EASY_COUNT) {
		printf("请输入要排查的坐标 >");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (show[x][y] != '*') {
				printf("该坐标被排查过了\n");
			}
			else {
				//如果是雷
				if (mine[x][y] == '1') {
					printf("很遗憾, 你没了\n");
					DisplayBoard(mine, ROW, COL);
					break;
				}
				//如果不是雷
				else {
					win++;
					//字符加减是ASCII码的运算
					//统计mine数组xy坐标周围有几个雷
					int count = get_mine_count(mine, x, y);
					show[x][y] = count + '0';//把坐标转换为数字字符
					DisplayBoard(show, ROW, COL);
					//作弊
					//DisplayBoard(mine, ROW, COL);
				}
			}
		}
		else {
			printf("输入坐标不合法, 请重新输入\n");
		}
		if (win == row * col - EASY_COUNT) {
		printf("      ---nb---      \n");
		DisplayBoard(mine, ROW, COL);
		}
	}
}