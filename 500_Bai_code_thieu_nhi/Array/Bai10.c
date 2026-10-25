#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void rearrange_array(int num[], int n) {
    for (int i = 1; i < n; i += 2) {
        // Nếu phần tử bên trái lớn hơn, đổi chỗ
        if (num[i] < num[i - 1]) {
            swap(&num[i], &num[i-1]);
        }
        // Nếu phần tử bên phải tồn tại và lớn hơn, đổi chỗ
        if (i + 1 < n && num[i] < num[i + 1]) {
            swap(&num[i], &num[i + 1]);
        }
    }
    // In kết quả
    printf("Output: { ");
    for (int i=0; i<n; i++) {
        printf("%d", num[i]);
        if (i < n-1) {
            printf(", ");
        }
    }
    printf(" }\n");
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(nums) / sizeof(nums[0]);

    rearrange_array(nums, n);

return 0;
}