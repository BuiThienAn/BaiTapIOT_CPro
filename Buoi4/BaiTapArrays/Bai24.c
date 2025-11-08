//Đảo thứ tự từng nhóm 3 phần tử.
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
        int temp;
        for (int i = 0; i<array_size; i++){
            if (i % 3 == 0){
               temp = *(array+i);
               *(array+i)=*(array+i+2);
               *(array+i+2)=temp;
            };
        }
        for (int i = 0; i<array_size; i++){
        printf("%d;",*(array+i));
        }        
        free(array);
    }
    return 0;
}
