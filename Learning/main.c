#include <stdio.h>
#include <string.h>

int main() {
    int n = 9;
    float* pFloat = (float*)&n;
    printf("n��ֵΪ: %d\n",n);
    printf("pFloat��ֵΪ: %f\n",*pFloat);
    *pFloat = 9.0;
    printf("num��ֵΪ: %d\n",n);
    printf("*pFloat��ֵΪ:%f\n",*pFloat);
    return 0;
}
// �������������Ĵ洢��ʽ��ͬ
//        n��ֵΪ: 9
//pFloat��ֵΪ: 0.000000
//num��ֵΪ: 1091567616
//*pFloat��ֵΪ:9.000000

