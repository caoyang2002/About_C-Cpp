# 打印`X`图案

|  0   |  1   |  2   |  3   |  4   |  5   |
| :--: | :--: | :--: | :--: | :--: | :--: |
|  1   |  @   |  #   |  #   |  #   |  @   |
|  2   |  #   |  @   |  #   |  @   |  #   |
|  3   |  #   |  #   |  @   |  #   |  #   |
|  4   |  #   |  @   |  #   |  @   |  #   |
|  5   |  @   |  #   |  #   |  #   |  @   |

> 列 == 行   @
>
> 列+行-1 =输入  @


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a = 0;
    scanf("%d", &a);
    int i = 0;
    for (i = 0; i < a; i++) {
        int j = 0;
        for (j = 0; j < a; j++) {
            if (i == j ||i+j == a-1) {
                printf("@");
            }
            else {
                printf("#");
            }
        }
        printf("\n");
    }
    return 0;
}
```

