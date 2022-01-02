#include <stdlib.h>
#include <stdio.h>
int partition(int arr[], int start, int end);
 
void QuickSort(int arr[], int start, int end){
    if (start < end){
        int pivot = partition(arr, start, end);
        QuickSort(arr, start, pivot);
        QuickSort(arr, pivot + 1, end);
    }
}
 
int partition(int arr[], int start, int end){
    int mid = arr[start + (rand() % (end - start))];
    int left_p = start;
    int right_p = end;
    int temp;
    while (left_p <= right_p){
        while (arr[left_p] < mid)
            left_p++;
        while (arr[right_p] > mid)
            right_p--;
        if (left_p >= right_p)
            break;
        temp = arr[left_p];
        arr[left_p] = arr[right_p];
        arr[right_p] = temp;
        left_p++;
        right_p--;
    }
    return right_p;
}
 
 
int findOrderStatistic(int array[], int k, int len) {
    int left = 0, right = len;
    while (1) {
        int mid = partition(array, left, right) + 1;
        if (mid == k)
            return array[mid];
        else if (k < mid)
            right = mid;
        else
            left = mid + 1;
    }
}
 
 
int main() {
    long long int n, k;
 
    FILE * fin = fopen("sort.in", "r");
    FILE * fout = fopen("sort.out", "w");
 
    fscanf(fin, "%lld", &n);
 
 
    int *a = malloc(sizeof(int) * (int) n);
    for (int i = 0; i < n; i++)
        fscanf(fin, "%d", &a[i]);
 
    QuickSort(a, 0, n-1);
    for (int i = 0; i < n; i++)
        fprintf(fout, "%d ", a[i]);
}
