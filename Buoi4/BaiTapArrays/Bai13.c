//Đếm số chẵn và lẻ trong mảng.
// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

int main() {
    int array_size;
    int chan = 0, le = 0;
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
        if (*(array+i)%2==0) chan++;
        else le++;
        }
        free(array);
        printf("Chan : %d so, Le: %d so", chan, le);
    }
    return 0;
}
