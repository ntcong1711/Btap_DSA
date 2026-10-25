#include <stdio.h>
// Hàm đổi chỗ hai phần tử
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Hàm sắp xếp mảng 
void sort(int A[], int n) {
    int a = 0;
    int b = 0;
    int c = n - 1;

    while (b <= c) {
        if (A[b] == 0) {
            swap(&A[a], &A[b]);
            a++;
            b++;
        } 
        else if (A[b] == 1) {
            b++;
        } 
        else { 
            swap(&A[b], &A[c]);
            c--;
        }
    }
    // In kết quả
    printf("{ ");
    for (int i = 0; i < n; i++) {
        printf("%d", A[i]);
        if (i < n - 1) printf(", ");
    }
    printf(" }\n");
}

int main() {
    int A[] = {0, 1, 2, 2, 1, 0, 0, 2, 0, 1, 1, 0};
    int n = sizeof(A) / sizeof(A[0]);
    // Gọi hàm sắp xếp
    sort(A, n);
    
return 0;
}