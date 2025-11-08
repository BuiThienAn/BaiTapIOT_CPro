//23	Dùng con trỏ để đảo ngược chuỗi.
#include <stdio.h>

void daoChuoi(int *array, int size){
    int temp;
    for (int i = 0; i<(size/2);i++){
        temp = *(array+i);
        *(array+i)=*(array+size-1-i);
        *(array+size-1-i) = temp;
    }
}


int main() {
    int array[5]={5,2,9,6,3};
    int size = sizeof(array)/sizeof(array[0]);
    daoChuoi(array,size);
    for (int i = 0; i<size; i++){
        printf("%d; ",*(array+i));
    }
    return 0;
}
