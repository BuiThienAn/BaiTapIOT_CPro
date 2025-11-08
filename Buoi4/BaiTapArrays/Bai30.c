//Nhân hai ma trận 3x3.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int matrixA[3][3], matrixB[3][3], matrixResult[3][3];
    int i,j,k,sum;
    for (i = 0; i<3; i++){
        for (j = 0; j<3; j++){
            printf("Nhap gia tri cua phan tu matrixA[%d][%d]\n",i+1,j+1);
            scanf("%d",&matrixA[i][j]);
        }
    }
    for (i = 0; i<3; i++){
        for (j = 0; j<3; j++){
            printf("Nhap gia tri cua phan tu matrixB[%d][%d]\n",i+1,j+1);
            scanf("%d",&matrixB[i][j]);
        }
    }    
    for (i = 0; i<3; i++){
        for (j=0;j<3;j++){
            sum=0;
            for (k=0;k<3;k++){
                sum +=matrixA[i][k]*matrixB[k][j];
            }
            matrixResult[i][j]=sum;
        }
    }
    for (i = 0; i<3;i++){
        printf("%d %d %d\n",matrixResult[i][0],matrixResult[i][1],matrixResult[i][2]);
    }
    return 0;
}
