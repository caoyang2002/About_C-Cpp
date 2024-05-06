#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//外部调用,需要先声明
//声明来自外部的变量
extern int a;
void test()
{
    printf("test-->%d\n", a);
}
int main()
{
    test();
    {
        printf("a=%d\n", a);
    }
    printf("a=%d\n", a);
}