#include <stdio.h>
void merge_sort_arrays(int X[], int Y[], int m, int n) {
    int length = m + n;
    int Z[length];
    int i = 0, j = 0, k = 0;
    // So sánh lần lượt 1 phần tử của mảng X với 1 phần tử của mảng Y
    while (i < m && j < n) {
        if (X[i] <= Y[j]) {
            Z[k++] = X[i++];
        } 
        else {
            Z[k++] = Y[j++];
        }
    }
    // Chép nốt các phần tử còn lại của mảng X vào mảng Z (nếu có)
    while (i < m) {
        Z[k++] = X[i++];
    }
    // Chép nốt các phần tử còn lại của mảng Y vào mảng Z (nếu có)
    while (j < n) {
        Z[k++] = Y[j++];
    }

    // In kết quả mảng X
    printf("X[] = { ");
    for (int k = 0; k < m; k ++) {
        printf("%d", Z[k]);
        if (k < m - 1) {
            printf(", ");
        }
    }
    printf(" }\n");

    // In kết quả mảng X
    printf("Y[] = { ");
    for (int k = m; k < length; k ++) {
        printf("%d", Z[k]);
        if (k < length - 1) {
            printf(", ");
        }
    }
    printf(" }\n");
}

int main() {
    int X[] = {1, 4, 7, 8, 10};
    int Y[] = {2, 3, 9};
    int m = sizeof(X) / sizeof(X[0]);
    int n = sizeof(Y) / sizeof(Y[0]);

    merge_sort_arrays(X, Y, m, n);

return 0;
}