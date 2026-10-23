#include <stdio.h>

// Hàm tìm và in tất cả các mảng con có tổng bằng 0:
void find_Print_Subarray(int nums[], int n) {
    int found = 0;
    
    // Duyệt 2 vòng lặp lồng nhau:
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            if (sum == 0) {
                found = 1;
                // In kết quả:
                printf("{ ");
                for (int k = i; k <= j; k++) {
                    printf("%d", nums[k]);
                    if (k < j) {
                        printf(", ");
                    }
                }
                printf(" }\n");
            }
        }
    }
    
    if (!found) {
        printf("Subarray with zero-sum does not exist\n");
    }
}

int main() {
    int nums[] = { 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 };
    int n = sizeof(nums) / sizeof(nums[0]);
    
    printf("The subarrays with a sum of 0 are:\n");
    find_Print_Subarray(nums, n);
    
return 0;
}