//22	Viết hàm trả về con trỏ trỏ tới phần tử lớn nhất trong mảng.
#include <stdio.h>

int *timMax(int *array, int size){
    int max = *array;
    int maxPosition = 0;
    for (int i = 0; i<size;i++){
        if (*(array+i)>max){
            max = *(array+i);
            maxPosition = i;
        }
    }
    return (array+maxPosition);
}


int main() {
    int array[5]={5,2,9,6,3};
    int size = sizeof(array)/sizeof(array[0]);
    int *p=timMax(array, size);
    printf("Gia tri lon nhat trong mang la: %d", *p);
    return 0;
}
