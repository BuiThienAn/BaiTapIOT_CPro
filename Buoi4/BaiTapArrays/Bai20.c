//Xóa phần tử tại vị trí k.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int array_size,k;
    printf("Nhap so phan tu cua mang \n");
    scanf("%d", &array_size);
    if (array_size <= 0) {
        printf("Kich thuoc mang phai la so duong!\n");
        return 1;
    };
    int *array = (int *)malloc(array_size*sizeof(int));
    printf("Nhap gia tri cua k:\n");
    scanf("%d",&k);
    
    if (array == NULL) return 1;
    else {
        for (int i = 0; i<array_size; i++){
        printf("Nhap so nguyen thu %d \n",(i+1));
        scanf("%d",(array+i));
        }
        for (int i = k; i< (array_size);i++){
            *(array+k)=*(array+k+1);
        }
        for (int i = 0; i<(array_size-1); i++){
        printf("%d;",*(array+i));
        }
        free(array);
    }
    return 0;
}
