//Tìm phần tử xuất hiện nhiều nhất.
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
        int currentElement, currentCount;
        int maxElement = array[0];
        int maxCount =  0;
        for (int i = 0; i<array_size; i++){
            currentElement = array[i];
            currentCount = 0;
            for (int j = 0; j < array_size; j++){
                if (array[j]==currentElement){
                    currentCount++;
                }
            }
            if (currentCount>maxCount){
                maxElement = array[i];
                maxCount=currentCount;
            }
        }
        printf("Phan tu co gia tri %d xuat hien nhieu nhat voi tan suat %d",maxElement, maxCount);
        free(array);
    }
    return 0;
}
