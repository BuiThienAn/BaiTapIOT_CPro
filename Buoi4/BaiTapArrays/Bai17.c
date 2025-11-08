//Tính trung bình cộng các phần tử.
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
        int sum = 0;
        for (int i = 0; i<array_size; i++){
        printf("Nhap so nguyen thu %d \n",(i+1));
        scanf("%d",(array+i));
        sum += *(array+i);
        }
        free(array);
        printf("Gia tri trung binh cong la: %.2f", ((float)sum/array_size));
    }
    return 0;
}
