//17	Dùng con trỏ để đếm số ký tự trong chuỗi.
#include <stdio.h>

int main() {
    char chuoi[]="Hello";
    char *p = chuoi;
    int count = 0, i = 0;
    while (*(p+i) != '\0'){
        count++;
        i++;
    }
    printf("So ky tu trong chuoi %d",count);
    return 0;
}
