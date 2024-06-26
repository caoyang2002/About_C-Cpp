#define _CRT_SECURE_NO_WARNINGS


# include "game.h"
//测试游戏的逻辑
void menu() {
    printf("***************************************\n");
    printf("*************** 1. play ***************\n");
    printf("*************** 0. exit ***************\n");
    printf("***************************************\n");
}

void game() {
    char ret = 0;
    char board[ROW][COL] = { 0 };
    //初始化棋盘
    IniBoard(board, ROW, COL);
    DisplayBoard(board,ROW,COL);
    //下棋
    while (1) {
        PlayerMove(board, ROW, COL);
        ret = IsWin(board,ROW,COL);//判断输赢
        if (ret != 'C') {
            break;
        }
        DisplayBoard(board, ROW, COL);
        ComputerMove(board, ROW, COL);
        ret = IsWin(board, ROW, COL);//判断输赢
        if (ret != 'C') {//如果返回值不是C就跳出循环
            break;
        }
        DisplayBoard(board, ROW, COL);
    }
    DisplayBoard(board, ROW, COL);
    if (ret == '*') {
        printf("玩家赢\n");
    }
    else if (ret == '#') {
        printf("电脑赢\n");
    }
    else {
        printf("平局\n");
    }
  
}

int main() {
    srand((unsigned int)time(NULL));//设置随机数的生成起点
    int input = 0;
    do {
        menu();
        printf("请选择 >");
        scanf("%d", &input);
        switch (input)
        {case 1:
            game();
            break;
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("选择错误");
            break;
        }
    } while (input);//打印菜单
    return 0;
}
