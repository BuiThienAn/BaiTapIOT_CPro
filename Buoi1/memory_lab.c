#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void stack_overflow(int count){
    char a[1024]; //1KB cho stack
    printf("%d\n",count); //Độ sâu 
    count++;
    stack_overflow(count); //infinite recurssion
};

void memory_leak(){
    char *a = (char*)malloc(1024*1024); //Không free() sau khi malloc -> Memory leak  
}

void out_of_memory(){
    int count = 0;
    while(1){
        char *a = (char*)malloc(1024*1024); //Liên tục cấp phát 1MB đến khi OUTOFMEMORY thì break
        count++;
        if (a == NULL){
            printf("OUT OF MEMORY! Het bo nho o lan cap phat thu %d \n",count);
            break;
        }
    }
}

int main(int argc, char *argv[]){
    if (argc!=2){
        printf("Input loi\n");
        return 1; //Return 1 = Chuong trinh chay loi
    }
    else if (strcmp(argv[1],"stack_overflow")==0){
        stack_overflow(1);
    }
    else if (strcmp(argv[1],"memory_leak")==0){
        memory_leak();
    }
    else if (strcmp(argv[1],"out_of_memory")==0){
        out_of_memory();
    }
    return 0;
}