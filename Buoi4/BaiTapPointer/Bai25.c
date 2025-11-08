//25	Dùng con trỏ để cộng hai ma trận.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int matrixA[3][3], matrixB[3][3], matrixC[3][3];
    int i,j;
    int *pA=(int *)matrixA, *pB=(int *)matrixB, *pC=(int *)matrixC;
    int totalElements=3*3;
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
    for (i = 0; i<totalElements; i++){
        *(pC+i)=*(pA+i)+*(pB+i);
    }
    for (i = 0; i<3;i++){
        printf("%d %d %d\n",matrixC[i][0],matrixC[i][1],matrixC[i][2]);
    }
    return 0;
}
