//Kiểm tra giá trị x có trong mảng không.
// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

int main() {
    int array_size, x;
    int flag = 0;
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
        printf("Nhap gia tri x can tim:\n");
        scanf("%d",&x);
        for (int i = 0; i<array_size; i++){
        if (*(array+i) == x){
            flag = 1;
            break;
            }
        } 
        free(array);
        if (flag) printf("Co gia tri x trong mang");
        else printf("Khong co gia tri x trong mang");
    }
    return 0;
}
