#include <stdio.h>
void swap (int n, char A, char B, char C){
    if (n==1){
        printf ("Chuyển đĩa 1 từ %c sang %c \n", A, C);
        return;
    }
    swap (n-1, A, C, B);
    printf ("Chuyển đĩa %d từ %c sang %c \n", n, A, C);
    swap (n-1, B, A, C);
}
int main(){
    int n;
    printf ("Nhập số lượng đĩa: ");
    scanf ("%d", &n);
    swap(n, 'A', 'B', 'C');
return 0;
}
