//18	Truyền con trỏ vào hàm để thay đổi giá trị biến gốc.
#include <stdio.h>

void tang(int *a){
    *a += 1;
}

int main() {
    int a = 4;
    tang(&a);
    printf("%d",a);
    return 0;
}
