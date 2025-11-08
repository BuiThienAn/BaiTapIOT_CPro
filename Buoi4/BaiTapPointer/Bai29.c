//29	Dùng con trỏ để xử lý ma trận động NxM.
#include <stdio.h>
#include <stdlib.h>

int **createMatrix(int rows, int columns){
    int **matrix=(int **)malloc(rows*sizeof(int*));
    if (matrix == NULL){
        printf("Khong the cap phat bo nho\n");
        return NULL;
    }
    for (int i = 0; i<rows; i++){
        matrix[i]=(int*)malloc(columns*sizeof(int));
        if (matrix[i] == NULL){
            printf("Khong the cap phat bo nho cot cho tung hang\n");
            for (int j = 0; j<i;j++){
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }
    
    return matrix;
}

void inputMatrix(int **matrix,int rows, int columns){
    for (int i = 0; i<rows; i++){
        for (int j = 0; j< columns;j++){
            printf("Nhap vao gia tri cua phan tu matrix[%d][%d]\n",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }    
};

void printMatrix(int** matrix, int rows, int columns){
    for (int i = 0; i<rows; i++){
        for (int j = 0; j< columns;j++){
            printf("%d; ",matrix[i][j]);
        }
        printf("\n");
    }    
}

void freeMatrix(int** matrix, int rows, int columns){
    for (int i = 0; i<rows; i++){
        free(matrix[i]);
    }
    free(matrix);
}    


int main() {
    int rows, columns;
    printf("Nhap vao so hang va cot cua ma tran muon tao\n");
    scanf("%d %d", &rows, &columns);
    int **matrix=createMatrix(rows,columns);
    if (matrix == NULL) {
        printf("Khong the khoi tao ma tran, chuong trinh ket thuc.\n");
        return 1;
    }
    inputMatrix(matrix,rows,columns);
    printMatrix(matrix,rows,columns);
    freeMatrix(matrix, rows,columns);
    return 0;
}
