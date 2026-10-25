#include <stdio.h>
#include <limits.h>
void find_maximum_product(int num[], int n) {
    if (n < 2) {
        printf("The array must have at least 2 elements.\n");
        return;
    }

    int maxProd = INT_MIN;  // INT_MIN = -∞
    int a = -1;  // a = số lượng cặp có tích lớn nhất
    int A[n*n], B[n*n];  // 2 mảng A,B để lưu cặp số có tích lớn nhất (A[a]; B[a]) 
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int prod = num[i] * num[j];
            if (prod == maxProd) {
                a++;
                A[a] = num[i];
                B[a] = num[j];
            }
            if (prod > maxProd) {
                a = 0;
                maxProd = prod;
                A[a] = num[i];
                B[a] = num[j];
            }
        }
    }
    // In ra kết quả
    printf("Pais have maximum product: ");
    for (int i=0 ; i<=a; i++){
        printf ("(%d, %d)", A[i], B[i]);
        if (i<a){
        printf (" and ");
        }
    }
}

int main() {
    int nums[] = {-10, -3, 5, 6, -2};
    int n = sizeof(nums) / sizeof(nums[0]);

    find_maximum_product(nums, n);

return 0;
}