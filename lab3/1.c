#include <stdlib.h>
#include <stdio.h>
#include <iso646.h>
int isHeap(int arr[], int n){
    int flag = 1;

    for (int i = 0; i - 1 < n/2; i++){
        if (2*i + 1 < n)
            if (arr[i] > arr[2*i + 1]){
                flag = 0;
                break;
            }
        if (2 * i + 2 < n)
            if (arr[i] > arr[2*i + 2]){
                flag = 0;
                break;
            }
    }
    return flag;
}
int main() {

    FILE *fin = fopen("isheap.in", "r");
    FILE *fout = fopen("isheap.out", "w");

    int n;
    fscanf(fin, "%d", &n);
    int *arr = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        fscanf(fin, "%d", &arr[i]);

    int flag = isHeap(arr, n);

    if (flag)
        fprintf(fout, "YES");
    else
        fprintf(fout, "NO");

    return 0;
}