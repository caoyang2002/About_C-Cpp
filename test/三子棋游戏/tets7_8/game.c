#define _CRT_SECURE_NO_WARNINGS

# include "game.h"
//游戏代码的实现
void IniBoard(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL],int row, int col) {
	int i = 0;
	for (i = 0; i < row; i++) {
		//打印数据
			//printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		int j = 0;
		for (j = 0; j < col; j++) {
			printf(" %c ", board[i][j]);
			if (j < col - 1) {
				printf("|");
			}
		}
		printf("\n");
		//打印分割信息
		if (i < row - 1) {
			//printf("---|---|---\n");
			int j = 0;
			for (j = 0; j < col; j++) {
				printf("---");
				if (j < col - 1) {
					printf("|");
				}
			}
			printf("\n");
		}
	}
}


//固定棋盘
//void DisplayBoard(char board[ROW][COL], int row, int col) {
//	int i = 0;
//	for (i = 0; i < row; i++) {
//		//打印数据
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//		if (i < row - 1) {
//			//打印分割信息
//			printf("---|---|---\n");
//		}
//	}
//}

void PlayerMove(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	printf("玩家下棋:\n");
	while (1) {
		printf("请输入坐标 >");
		scanf("%d %d", &x, &y);
		//坐标范围合法性判断
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			//如果没有被占用, 玩家可以下棋
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
				break;
			}
			else {
				printf("坐标被占用, 请重新选择!");
			}
		}
		else {
			printf("坐标输入错误, 请重新输入!");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col) {
	printf("电脑下棋:\n");
	int x = 0;
	int y = 0;
	while (1) {
		x = rand() % row;//0~2
		y = rand() % col;//0~2
		if (board[x][y] == ' ') {
			board[x][y] = '#';
			break;
		}
	}
} 

//如果满了就返回1, 不满就返回0
int IsFull(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}


char IsWin(char board[ROW][COL], int row, int col) {
	//判断行
	int i = 0;
	for (i = 0; i < row; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ') {
			return board[i][1];
		}
	
	}
	//判断列
	int j = 0;
	for (j = 0; j < row; j++) {
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ') {
			return board[1][j];
		}
	}
	//判断对角线1
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') {
		return board[1][1];
	}
	//判断对角线2
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ') {
		return board[1][1];
	}
	//平局
	if (IsFull(board, row, col)){
		return 'Q';
	}
	//游戏继续
	return 'C';
}