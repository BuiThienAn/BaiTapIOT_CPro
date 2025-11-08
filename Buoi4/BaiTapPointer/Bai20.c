//20	Dùng con trỏ để sao chép chuỗi (không dùng strcpy).
#include <stdio.h>

void copyChuoi(char *dest, char *src){
    while (*(src)!='\0'){
        *dest++=*src++;
    }
}

int main() {
    char dest[]="Hello", src[]="Phong";
    copyChuoi(dest,src);
    printf("%s",dest);
    return 0;
}
