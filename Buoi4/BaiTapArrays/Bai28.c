//Kiểm tra ma trận đối xứng.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int matrix[3][3];
    int i,j;
    int flag = 1;
    for (i = 0; i<3; i++){
        for (j = 0; j<3; j++){
            printf("Nhap gia tri cua phan tu matrix[%d][%d]\n",i+1,j+1);
            scanf("%d",&matrix[i][j]);
        }
    }
    for (i = 0; i<3; i++){
        for (j=0;j<3;j++){
            if (i!=j){
                if (matrix[i][j]!=matrix[j][i]) {
                    flag = 0;
                    break;
                }
            }
        }
    }
    if (flag) printf("Ma tran doi xung");
    else printf("Ma tran khong doi xung");
    return 0;
}
