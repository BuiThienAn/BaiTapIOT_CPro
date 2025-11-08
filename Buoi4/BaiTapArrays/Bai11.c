//Nhập 5 số nguyên, in tổng.
#include <stdio.h>

int main() {
    int a[5];
    int sum = 0;
    printf("Nhap 5 so nguyen \n");
    for (int i = 0; i<5; i++){
        printf("Nhap so nguyen thu %d \n",(i+1));
        scanf("%d",(a+i));
        sum = sum + a[i];
    }
    printf("Tong la: %d", sum);

    return 0;
}
