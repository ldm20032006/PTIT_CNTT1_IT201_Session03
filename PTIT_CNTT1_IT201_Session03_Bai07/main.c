#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    printf("Nhap so hang (0 < rows < 1000): ");
    scanf("%d", &rows);
    printf("Nhap so cot (0 < cols < 1000): ");
    scanf("%d", &cols);
    
    if (rows <= 0 || rows >= 1000 || cols <= 0 || cols >= 1000) {
        printf("So hang hoac so cot khong hop le\n");
        return 1;
    }

    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }
    printf("Nhap %d x %d phan tu:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Nhap phan tu tai [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    int k;
    printf("Nhap so dong k (0 <= k < %d) de tinh tong: ", rows);
    scanf("%d", &k);
    if (k < 0 || k >= rows) {
        printf("Dong k khong hop le\n");
        for (int i = 0; i < rows; i++) {
            free(arr[i]);
        }
        free(arr);
        return 1;
    }

    long long sum = 0; // Sử dụng long long để tránh tràn số
    for (int j = 0; j < cols; j++) {
        sum += arr[k][j];
    }
    printf("Tong cac phan tu cua dong %d la: %lld\n", k, sum);

    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}