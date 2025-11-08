//Loại bỏ phần tử trùng lặp.
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
    int *new_array = (int *)malloc(array_size*sizeof(int));
    
    if ((array == NULL)||(new_array == NULL)) return 1;
    else {
        for (int i = 0; i<array_size; i++){
        printf("Nhap so nguyen thu %d \n",(i+1));
        scanf("%d",(array+i));
        }
        int j = 0;
        printf("Mang moi la:\n");
        for (int i = 0; i<array_size; i++){
        if (*(array+i) != *(array+i+1)){
            *(new_array+j) = *(array+i);
            printf("%d;",*(new_array+j));
            j++;
            }
        }
        free(array);
        free(new_array);
    }
    return 0;
}
