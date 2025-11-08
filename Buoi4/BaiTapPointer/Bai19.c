//19	So sánh địa chỉ của hai con trỏ trong cùng mảng.
#include <stdio.h>


int main() {
    int a[5] = {1,2,3,4,5};
    int *p1 = &a[0], *p2 = &a[1];
    if (p1 < p2) printf("p1<p2");
    else printf("p1>p2");
    return 0;
}
