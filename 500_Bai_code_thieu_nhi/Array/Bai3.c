#include <stdio.h>
void find_duplicate_element(int num[], int n){
    int new_size = n;
    int result[n];
    int a=0;
    for (int i=0; i<new_size; i++){
        for (int j=i+1; j<new_size; j++){
            if(num[i] == num[j]){
        
                for (int k=j; k<new_size-1; k++){
                    num[k] = num[k+1];     
                    // nếu num[i] = num[j] thì xóa num[j]
                    // đẩy các phần tử phía sau lên 1 ô, mảng bớt đi 1 phần tử, còn lại (l+1) phần tử 
                }
                new_size--; 
                j--;
                // Kiểm tra và lưu vào mảng kết quả
                int is_exist = 0;
                for (int n = 0; n<=a; n++) {
                    if (result[n] == num[i]) {
                        is_exist = 1;
                        break;
                    }
                }
                if (!is_exist) {
                    result[a] = num[i];
                    a++;
                }
            } 
        }
    }
    printf ("These duplicate element in the array:");
    printf("{");
    for (int i=0; i<a; i++){
        printf ("%d", result[i]);
        if (i<a-1) {
            printf (",");
        }
    }
    printf("}");
}

int main() {
    int nums[] = {3, 4, -7, 3, 1, 3, 1, -4, -2, -2};
    int n = sizeof(nums) / sizeof(nums[0]);
    find_duplicate_element(nums, n);

return 0;
}