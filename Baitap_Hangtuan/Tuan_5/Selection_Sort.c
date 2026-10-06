#include <stdio.h>
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int A[13] = {101, 23, 57, 13, 25, 121, 87, 36, 13, 204, 111, 89, 59};

    for (int i = 0; i < 13 - 1; i++) {
        int idx = i; 
        for (int j = i + 1; j < 13; j++) {
            if (A[j] < A[idx]) {
                idx = j; 
            }
        }
        if (idx != i) {
            swap(&A[i], &A[idx]);
        }
        for (int i = 0; i < 13; i++) {
            printf("%d ", A[i]);
        }
        printf("\n");
    }

    printf("Dãy sau khi xắp sếp là: ");
    for (int i = 0; i < 13; i++) {
        printf("%d ", A[i]);
    }
return 0;
}