//Tìm giá trị lớn nhất trong mảng.
// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

int main() {
    int array_size;
    printf("Nhap so phan tu cua mang \n");
    scanf("%d", &array_size);
    if (array_size <= 0) {
        printf("Kich thuoc mang phai la so duong!\n");
        return 1;
    };
    int *array = (int *)malloc(array_size*sizeof(int));
    if (array == NULL) return 1;
    else {
        for (int i = 0; i<array_size; i++){
        printf("Nhap so nguyen thu %d \n",(i+1));
        scanf("%d",(array+i));
        }
        int max = array[0];
        for (int i = 0; i<array_size; i++){
        if (*(array+i) > max){
            max = *(array+i);
        }
        } 
        free(array);
        printf("Gia tri max la: %d", max);
    }
    return 0;
}
