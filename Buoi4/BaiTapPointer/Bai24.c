//24	Viết hàm nhập ma trận dùng con trỏ 2 chiều.
// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

int **nhapMaTran(int rows, int columns){
    int **matrix=(int **)malloc(rows*sizeof(int*));
    if (matrix == NULL){
        printf("Loi bo nho cap phat cho hang\n");
        return NULL;
    }
    for (int i = 0; i<rows;i++){
        matrix[i]=(int *)malloc(columns*sizeof(int));
        if (matrix[i] == NULL){
            printf("Loi cap phat khi cap bo nho cho cot\n");
            for (int j = 0; j<i;j++){
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }
    for (int i = 0; i< rows; i++){
        for (int j = 0; j < columns; j++){
            printf("Nhap gia tri cua phan tu matrix[%d][%d]\n",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
    return matrix;
}


int main() {
    int rows, columns;
    printf("Nhap so hang va so cot cua matrix: \n");
    scanf("%d %d",&rows, &columns);
    if ((rows)<1||(columns<1)){
        printf("Hang va cot phai lon hon hoac bang 1\n");
        return 1;
    }
    int **matrix=nhapMaTran(rows, columns);
    if (matrix == NULL) return 1;
    for (int i = 0; i< rows; i++){
        for (int j = 0; j < columns; j++){
            printf("%d; ",matrix[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i<rows;i++){
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
