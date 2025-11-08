//15	In kích thước kiểu dữ liệu thông qua con trỏ void.
#include <stdio.h>

int main() {
    int a = 4;
    void *p = &a;
    printf("Kich thuoc kieu du lieu thong qua con tro void: %d",sizeof(*(int *)p));
    return 0;
}
