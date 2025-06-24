#include <stdio.h>
#include <stdlib.h>

int findMax(int arr[], int n) {
    if (n <= 0) return -1;
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
int main() {
    int n;
    printf("Nhap so luong phan tu (0 < n <= 1000): ");
    scanf("%d", &n);

    if (n <= 0 || n > 1000) {
        printf("So luong phan tu khong hop le\n");
        return 1;
    }

    // Cấp phát bộ nhớ cho mảng
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Cap phat bo nho that bai\n");
        return 1;
    }

    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max = findMax(arr, n);
    if (max != -1) {
        printf("So lon nhat trong mang la: %d\n", max);
    } else {
        printf("Mang khong hop le\n");
    }

    // Giai phong bo nho cap phat
    free(arr);

    return 0;
}