#include <stdio.h>

void find_largest_subarray(int nums[], int n) {
    int max_length = 0;
    // Hai mảng A và B để lưu vị trí đầu và cuối của mảng con có chiều dài lớn nhất
    int A[n] ,B[n];
    A[max_length] = -1, B[max_length] = -1;
    // Biến t để tăng chỉ số của mảng A B khi xh một mảng con khác cũng có chiều dài lớn nhất
    int t = 0;
    // Vòng lặp lồng nhau 
    for (int i = 0; i < n; i++) {
        int count_0 = 0;
        int count_1 = 0;

        for (int j = i; j < n; j++) {
            // Đếm số lượng số 0 và số 1 trong đoạn từ i đến j
            if (nums[j] == 0) {
                count_0 ++;
            } 
            else {
                count_1 ++;
            }
    
            if (count_0 == count_1) {
                int current_length = j - i + 1;
                if (current_length == max_length){
                    t++;
                    A[max_length + t] = i;
                    B[max_length + t] = j;

                }

                if (current_length > max_length) {
                    max_length = current_length;
                    A[max_length] = i;
                    B[max_length] = j;
                    t = 0; 
                }
            }
        }
    }

    // In kết quả mảng con lớn nhất tìm được
    if (max_length == 0) {
        printf("No such subarray exists.\n");
    } 

    else {
        printf("Largest subarray is ");
        for (int a = max_length; a <= max_length + t; a++){
            printf ("{");
            for (int k = A[a]; k <= B[a] ; k++) {
                printf("%d", nums[k]);
                if (k < B[a]) {
                    printf(", ");
                }
            }
            if (a < max_length + t){
                printf ("} và ");
            }
        }
        printf("} having length %d\n", max_length);
    }
}

int main() {
    int nums[] = { 0, 0, 1, 0, 1, 0, 0 };
    int n = sizeof(nums) / sizeof(nums[0]);

    find_largest_subarray(nums, n);
return 0;
}