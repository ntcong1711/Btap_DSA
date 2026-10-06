#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int A[8] = {32, 51, 27, 83, 66, 11, 45, 75};

    for (int i = 1; i < 8; i++) { 
        for (int j = i - 1; j >= 0; j--) { 
            if (A[j + 1] < A[j]) {
                swap(&A[j], &A[j + 1]);
            } else {
                break;
            }
        }
    }

    printf("Dãy mới là: ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}