//Chèn phần tử vào vị trí bất kỳ.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int array_size,x,k;
    printf("Nhap so phan tu cua mang \n");
    scanf("%d", &array_size);
    if (array_size <= 0) {
        printf("Kich thuoc mang phai la so duong!\n");
        return 1;
    };
    int *array = (int *)malloc(array_size*sizeof(int));
    printf("Chen phan tu co gia tri bao nhieu vao vi tri thu may:\n");
    scanf("%d %d",&x,&k);
    
    if (array == NULL) return 1;
    else {
        for (int i = 0; i<array_size; i++){
        printf("Nhap so nguyen thu %d \n",(i+1));
        scanf("%d",(array+i));
        }
        *(array+k-1) = x;
        for (int i = 0; i<array_size; i++){
        printf("%d;",*(array+i));
        }
        free(array);
    }
    return 0;
}
