#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//获取一个月的天数
int is_leap_year(int y) {
    return ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0));
}
int main() {
    int y = 0;
    int m = 0;
    int d = 0;
    int days[13] = { 1,31,28,31,30,31,30,31,31,30,31,30,31 };
    while (scanf("%d %d", &y, &m) == 2) {
        d = days[m];
        if ((is_leap_year(y)==1) && (m == 2)) {
            d++;
        }
        printf("%d",d);
    }
    return 0;
}