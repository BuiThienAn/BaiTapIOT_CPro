//30	Dùng con trỏ void để viết hàm swap tổng quát cho mọi kiểu.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(void *a, void *b, int size){
    void *c = malloc(size);
    memcpy(c,a,size);
    memcpy(a,b,size);
    memcpy(b,c,size);
    free(c);
}

int main(){
    int a=4, b=2;
    if (sizeof(a)!=sizeof(b)){
        printf("Phai cung kieu du lieu!\n");
        return 1;
    }
    swap(&a, &b, sizeof(a));
    printf("Gia tri cua a = %d; b=%d",a,b);
    
    return 0;
}
