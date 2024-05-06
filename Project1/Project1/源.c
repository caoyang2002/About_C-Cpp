#include <stdio.h>

int jump(int n) {
    if (n > 2) {

        int x = 0;
        int y = n - 1;
        
        jump(y);
        x += y;
    }
    else if (n <= 2 && n > 0) {
        int x = (n = 2 ? 2 : 1);
    }
    else {
        int x = 0;
        return x;
    }
}

int main() {
    int nm = 6;
    int num = jump(nm);
    printf("%d", num);
    return 0;
}
