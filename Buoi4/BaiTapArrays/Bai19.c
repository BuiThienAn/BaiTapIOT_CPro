//Sắp xếp mảng tăng dần.
#include <stdio.h>
#include <stdlib.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void bubbleSort(int arr[], int n) {
    int i, j;
    int swapped = 0; // Cờ để check vòng lặp đấy có hoán đổi không 
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            // Nếu phần tử trước > phần tử sau -> hoán đổi
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }

        // Nếu sau 1 vòng lặp 'i' mà không có hoán đổi nào (swapped == false)
        // -> mảng đã được sắp xếp xong, không cần lặp tiếp.
        if (swapped == 0) {
            break;
        }
    }
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Hàm chính
int main() {
    int array_size;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &array_size);

    if (array_size <= 0) {
        printf("Kich thuoc mang phai la so duong!\n");
        return 1; // Thoát lỗi
    }

    // Cấp phát bộ nhớ động cho mảng
    int *array = (int *)malloc(array_size * sizeof(int));
    if (array == NULL) {
        printf("Loi cap phat bo nho!\n");
        return 1; // Thoát lỗi
    }

    // Nhập dữ liệu cho mảng
    printf("Nhap %d so nguyen:\n", array_size);
    for (int i = 0; i < array_size; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("\nMang ban dau:\n");
    printArray(array, array_size);

    // Gọi hàm sắp xếp
    bubbleSort(array, array_size);

    printf("\nMang sau khi sap xep tang dan:\n");
    printArray(array, array_size);

    free(array);

    return 0;
}
