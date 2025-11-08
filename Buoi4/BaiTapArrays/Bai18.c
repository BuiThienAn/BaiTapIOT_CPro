//Gộp hai mảng A và B thành C.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int array_size_A, array_size_B;
    printf("Nhap so phan tu cua mang A va B (cach nhau khoang trang): \n");
    scanf("%d %d", &array_size_A, &array_size_B);
    if ((array_size_A <= 0) ||(array_size_B <= 0)) {
        printf("Kich thuoc mang phai la so duong!\n");
        return 1;
    };
    int array_size_C = array_size_A + array_size_B;
    int *array_A = (int *)malloc(array_size_A*sizeof(int));
    int *array_B = (int *)malloc(array_size_B*sizeof(int));
    int *array_C = (int *)malloc(array_size_C*sizeof(int));
    if ((array_A == NULL) || (array_B == NULL) || (array_C == NULL)) return 1;
    else {
        printf("Nhap phan tu mang A\n");
        for (int i = 0; i<array_size_A; i++){
            printf("Nhap so nguyen thu %d: ",(i+1));
            scanf("%d",(array_A+i));
        }
        printf("Nhap phan tu mang B\n");
        for (int i = 0; i<array_size_B; i++){
            printf("Nhap so nguyen thu %d: ",(i+1));
            scanf("%d",(array_B+i));
        }
        for (int i = 0; i<array_size_C; i++){
            if (i<array_size_A){
                *(array_C+i) = *(array_A+i);
            }
            else {
                *(array_C+i)=*(array_B+i-array_size_A);
            }
        }
        
        printf("\nMang C sau khi gop:\n");
        for (int i = 0; i < array_size_C; i++) {
            printf("%d ", *(array_C + i)); 
        }
                
        free(array_A);
        free(array_B);
        free(array_C);
    }
    return 0;
}
