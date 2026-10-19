#include <stdio.h>
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int quick_sort (int A[], int n, int i, int j  ){
    int pivot = 0;
    i = pivot + 1;
    j = pivot + n - 1;
    int ix = i;
    int jx = j; 
    while (ix < jx ){
    for (int a = ix; a<n; a++){
        if (A[a] > A[pivot]){
        ix = a;
        break;
        }
    }
    for (int b = jx; b > pivot; b--){
        if (A[b] < A[pivot]) 
        jx = b;
        break;
        }
    if (ix < jx){
        swap(&A[ix], &A[jx]);
    }
    else{
        swap(&A[ix], &A[pivot]);
    }
    
    }
}



int main() {
    int A[13] = {101, 23, 57, 13, 25, 121, 87, 36, 13, 204, 111, 89, 59};

    
return 0;
}