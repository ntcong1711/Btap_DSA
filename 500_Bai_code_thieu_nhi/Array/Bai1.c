#include <stdio.h>
// Hàm tìm kiếm.
int findPair (int nums[], int target, int n){
int found = 0;
  for (int i=0; i<n-1; i++){
    for (int j=i+1; j<n; j++){
      if (nums[i] + nums [j] == target){
        printf ("Pair found (%d, %d)\n", nums[i], nums[j]);
        found = 1;
      }
    }
  }
  if (found == 0){
    printf ("Pair not found.");
  }
return 0;
}

int main(){
  int nums [100];
  printf ("Nhập các số nguyên khác nhau, mỗi số cách nhau bằng dấu phẩy\n");
  printf ("num = "); 

// Lưu các số được người dùng nhập vào.
  int n = 0;
  while (scanf("%d", &nums[n]) == 1){
    n++;
    char c = getchar();       
    if (c == ',') continue;
    if (c == '\n') break;
  }

  int target;
  printf ("target = ");
  scanf ("%d", &target);

// Gọi hàm tìm kiếm.
  findPair (nums, target, n);
return 0;
}
