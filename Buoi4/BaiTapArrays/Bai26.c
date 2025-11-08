//Nhập ma trận 3x3, tính tổng đường chéo chính.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int matrix[3][3];
    int i,j;
    int sum = 0;
    for (i = 0; i<3; i++){
        for (j = 0; j<3; j++){
            printf("Nhap gia tri cua phan tu matrix[%d][%d]\n",i+1,j+1);
            scanf("%d",&matrix[i][j]);
            if (i == j) sum+=matrix[i][j];
        }
    }
   
    printf("Tong cua cac phan tu tren duong cheo chinh la: %d", sum);
    return 0;
}
