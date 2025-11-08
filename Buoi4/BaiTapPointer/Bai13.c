//13	Dùng con trỏ để tính tổng các phần tử mảng.
#include <stdio.h>

int main() {
    int array[5]={1,2,3,4,5};
    int sum = 0;
    int array_length = sizeof(array)/sizeof(array[0]);
    for (int i = 0; i<array_length;i++){
        sum+=*(array+i);
    }
    printf("Tong cac phan tu:%d",sum);
    return 0;
}
