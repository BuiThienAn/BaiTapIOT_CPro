//27	Viết chương trình dùng con trỏ hàm để mô phỏng máy tính đơn giản.
#include <stdio.h>

double cong(double a, double b){
    return a+b;
}

double tru(double a, double b){
    return a-b;
}

double nhan(double a, double b){
    return a*b;
}

double chia(double a, double b){
    if (b == 0){
        printf("Khong the chia 0!\n");
        return 0.00;
    }
    return a/b;
}

int main(){
    int choice;
    double (*phepToan[4])(double, double);
    phepToan[0]=cong;
    phepToan[1] = tru;
    phepToan[2] = nhan;
    phepToan[3] = chia;
    double a,b;
    printf("nhap vao 2 gia tri a, b:\n");
    scanf("%lf %lf",&a,&b);
    printf("\nChon phep tinh ban muon:\n");
    printf("0: Cong (a + b)\n");
    printf("1: Tru (a - b)\n");
    printf("2: Nhan (a * b)\n");
    printf("3: Chia (a / b)\n");
    printf("Lua chon cua ban (0-3): ");
    scanf("%d", &choice);
    
    if (choice < 0 || choice > 3) {
        printf("Lua chon khong hop le!\n");
        return 1; 
    }
    
    double result = phepToan[choice](a,b);
    printf("Ket qua %.2lf", result);
    return 0;
}
