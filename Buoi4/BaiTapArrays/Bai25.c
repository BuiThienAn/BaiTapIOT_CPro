//Tính tổng phần tử ở vị trí chẵn.
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
        if (i%2==0){
            sum +=*(array+i);
        }
        }
        printf("Tong cac phan tu o vi tri chan: %d", sum);
        free(array);
    }
    return 0;
}
