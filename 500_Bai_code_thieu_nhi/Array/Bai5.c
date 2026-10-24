#include <stdio.h>

// Hàm tìm, in tất cả các mảng con có tổng bằng 0 và tìm độ dài lớn nhất của các mảng con
void find_Print_Subarray(int nums[], int n, int target) {
    int found = 0;
    int length_max = 0;
    int a = 0, b=0;   
    // a và b là vị trí trên mảng ban đầu của phần tử đầu và cuối trong mảng con có độ dài lớn nhất

    // Duyệt 2 vòng lặp lồng nhau:
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            if (sum == target) {
                found = 1;
                // Tính chiều dài của mảng con
                if(j - i +1 >= length_max){
                    length_max = j - i +1;
                    a = i;
                    b = j;
                }
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
        printf("Subarray with s sum of %d does not exist\n", target);
    }
    // In mảng con có chiều dài lớn nhất
    printf("The longest subarray is {");
    for(int k=a; k<=b; k++){
        printf("%d", nums[k]);
        if (k < b) {
            printf(", ");
        }
    }
    printf(" } having length %d \n", length_max);
}

int main() {
    int nums[] = { 5, 6, -5, 5, 3, 5, 3, -2, 0 };
    int n = sizeof(nums) / sizeof(nums[0]);
    int target = 8;
  
    printf("The subarrays with a sum of %d are:\n", target);
    find_Print_Subarray(nums, n, target);
    
return 0;
}