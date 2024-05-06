#define _CRT_SECURE_NO_WARNINGS


# include "game.h"
//������Ϸ���߼�
void menu() {
    printf("***************************************\n");
    printf("*************** 1. play ***************\n");
    printf("*************** 0. exit ***************\n");
    printf("***************************************\n");
}

void game() {
    char ret = 0;
    char board[ROW][COL] = { 0 };
    //��ʼ������
    IniBoard(board, ROW, COL);
    DisplayBoard(board,ROW,COL);
    //����
    while (1) {
        PlayerMove(board, ROW, COL);
        ret = IsWin(board,ROW,COL);//�ж���Ӯ
        if (ret != 'C') {
            break;
        }
        DisplayBoard(board, ROW, COL);
        ComputerMove(board, ROW, COL);
        ret = IsWin(board, ROW, COL);//�ж���Ӯ
        if (ret != 'C') {//�������ֵ����C������ѭ��
            break;
        }
        DisplayBoard(board, ROW, COL);
    }
    DisplayBoard(board, ROW, COL);
    if (ret == '*') {
        printf("���Ӯ\n");
    }
    else if (ret == '#') {
        printf("����Ӯ\n");
    }
    else {
        printf("ƽ��\n");
    }
  
}

int main() {
    srand((unsigned int)time(NULL));//������������������
    int input = 0;
    do {
        menu();
        printf("��ѡ�� >");
        scanf("%d", &input);
        switch (input)
        {case 1:
            game();
            break;
        case 0:
            printf("�˳���Ϸ\n");
            break;
        default:
            printf("ѡ�����");
            break;
        }
    } while (input);//��ӡ�˵�
    return 0;
}
