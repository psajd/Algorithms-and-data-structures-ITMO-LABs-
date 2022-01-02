#define max(a,b) ((a >= b) ? a : b)
#include <stdlib.h>
#include <stdio.h>
void printArr(int a[],  int n){
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
 
void qsort2(int a[], long long l, long long r, long long k){
    if (l >= r) return;
    long long mid = a[(l + r) / 2];
    long long i = l, j = r, temp;
    while (i <= j){
        while (a[i] < mid)
            i++;
        while (a[j] > mid)
            j--;
        if (i <= j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if (k <= j) return qsort2(a, l, j, k);
    else return qsort2(a, i, r, k);
}
 
int main() {
    long long A, B, C, n, k;
    FILE * fin = fopen("kth.in", "r");
    FILE * fout = fopen("kth.out", "w");
 
    fscanf(fin, "%lld", &n);
    fscanf(fin, "%lld", &k);
    fscanf(fin, "%lld", &A);
    fscanf(fin, "%lld", &B);
    fscanf(fin, "%lld", &C);
    int *a = malloc(n*sizeof(int));
    fscanf(fin, "%d", &a[0]);
    fscanf(fin, "%d", &a[1]);
 
    for (long long i = 2; i < n; i++)
        a[i] = A*a[i-2] + B * a[i-1] + C;
 
    qsort2(a, 0, n-1, k-1);
 
    fprintf(fout, "%d", a[k-1]);
}
