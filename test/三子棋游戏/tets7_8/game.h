#pragma once
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

#define ROW 3
#define COL 3
//游戏代码的声明 (函数声明, 符号定义)
//初始化棋盘
void IniBoard(char board[ROW][COL], int row,int col);
//打印棋盘
void DisplayBoard(char board[ROW][COL],int row, int col);
//玩家下棋
 void PlayerMove(char board[ROW][COL],int row, int col);
 //电脑下棋  找没有下棋的位置随机下
 void ComputerMove(char board[ROW][COL], int row, int col);

 //判断输赢
 //玩家赢 '*'
 //电脑赢 '#'
 //平局'Q'
 //继续'C'
 char IsWin(char board[ROW][COL], int row, int col);