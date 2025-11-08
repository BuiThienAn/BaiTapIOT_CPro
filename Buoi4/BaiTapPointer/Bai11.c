//11	Khai báo con trỏ trỏ đến biến int và in địa chỉ, giá trị.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 4;
    int *p=&a;
    printf("Dia chi cua a: %x\n",p);
    printf("Gia tri cua a: %d\n",*p);
    return 0;
}
