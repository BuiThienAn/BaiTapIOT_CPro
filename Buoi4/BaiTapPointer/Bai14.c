//14	Tạo hàm nhập và in mảng bằng con trỏ.
#include <stdio.h>

void nhapMang(int *array, int size){
    for (int i = 0; i<size; i++){
        printf("Nhap gia tri cua phan tu thu %d\n", i+1);
        scanf("%d",(array+i));
    }
}

void inMang(int *array, int size){
    for (int i =0; i<size;i++){
       printf("array[%d]=%d\n",i,*(array+i)); 
    }
}

int main() {
    int array[5];
    int size = sizeof(array)/sizeof(array[0]);
    nhapMang(array,size);
    inMang(array,size);
    return 0;
}
