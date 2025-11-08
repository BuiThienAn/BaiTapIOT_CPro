//16	Gán con trỏ p trỏ tới mảng a[5], in giá trị bằng p.
#include <stdio.h>

int main() {
    int a[5]={1,2,3,4,5};
    int *p = a;
    int sum = 0;
    for (int i = 0; i<5; i++){
        sum += *(p+i);
    }
    printf("Tong dung con tro p la: %d",sum);
    return 0;
}
