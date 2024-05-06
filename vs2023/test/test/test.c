#include <stdio.h>
int global = 2019;//全局变量
int main()
{
    int local = 2018;//局部变量
    int global = 2020;//局部变量
    printf("global = %d\n", global);
    return 0
};