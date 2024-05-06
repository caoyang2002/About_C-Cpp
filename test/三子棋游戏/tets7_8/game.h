#pragma once
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

#define ROW 3
#define COL 3
//��Ϸ��������� (��������, ���Ŷ���)
//��ʼ������
void IniBoard(char board[ROW][COL], int row,int col);
//��ӡ����
void DisplayBoard(char board[ROW][COL],int row, int col);
//�������
 void PlayerMove(char board[ROW][COL],int row, int col);
 //��������  ��û�������λ�������
 void ComputerMove(char board[ROW][COL], int row, int col);

 //�ж���Ӯ
 //���Ӯ '*'
 //����Ӯ '#'
 //ƽ��'Q'
 //����'C'
 char IsWin(char board[ROW][COL], int row, int col);