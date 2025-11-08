//21	Dùng malloc để cấp phát mảng 10 phần tử int và in chúng.
#include <stdio.h>
#include <stdlib.h>


int main() {
    int *array = (int *)malloc(10*sizeof(int));
    if (array == NULL) return 1;
    else{
        for (int i = 0; i<10;i++){
            printf("Nhap gia tri cua phan tu %d\n",i+1);
            scanf("%d",(array+i));
        }
        printf("In mang:\n");
        for (int i = 0; i<10;i++){
            printf("%d; ",*(array+i));
        }        
    }
    return 0;
}
