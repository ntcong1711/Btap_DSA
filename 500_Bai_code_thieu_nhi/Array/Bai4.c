#include <stdio.h>
void find_largest_subarray(int num[], int n){
    int new_size = n;
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
                
            } 
        }
    }
    printf ("The largest subarray:");
    printf("{");
    for (int i=0; i<new_size; i++){
        printf ("%d", num[i]);
        if (i<new_size-1) {
            printf (",");
        }
    }
    printf("}");
}

int main() {
    int nums[] = {2, 0, 2, 1, 4, 3, 1, 0};
    int n = sizeof(nums) / sizeof(nums[0]);
    find_largest_subarray(nums, n);

return 0;
}