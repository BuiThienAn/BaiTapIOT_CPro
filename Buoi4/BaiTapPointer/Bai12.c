//12	Dùng con trỏ để hoán đổi hai số.
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 4, b=8;
    int *pA=&a, *pB=&b;
    swap(pA,pB);
    printf("a=%d, b=%d\n",a,b);
    return 0;
}
