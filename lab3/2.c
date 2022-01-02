#include <stdlib.h>
#include <stdio.h>
#include <iso646.h>
#include <string.h>

typedef struct {
    int *arr;
    int len;
}heap;

void print_arr(int arr[], int n, FILE *fout){
    for (int i = n - 1; i >= 0; i--)
        fprintf(fout, "%d ", arr[i]);
    fprintf(fout, "\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void siftDown(heap *a, int index){
    int left, j, right;
    while (2 * index + 1 < a->len){
        left = 2 * index + 1;
        right = 2 * index + 2;
        j = left;
        if (right < a->len and a->arr[right] < a->arr[left])
            j = right;
        if (a->arr[index] <= a->arr[j])
            break;
        swap(&a->arr[index], &a->arr[j]);
        index = j;
    }
}

void siftUp(heap *a, int index){
    while (a->arr[index] < a->arr[(index - 1) / 2]){
        swap(&a->arr[index], &a->arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

int extractMin(heap *a) {
    int min = a->arr[0];
    a->arr[0] = a->arr[a->len - 1];
    a->len = a->len - 1;
    siftDown(a, 0);
    return min;
}

void insert(heap *a, int key){
    a->len = a->len + 1;
    a->arr[a->len - 1] = key;
    siftUp(a, a->len - 1);
}

void buildHeap(heap *a){
    for (int i = a->len; i >= 0; i--){
        siftDown(a, i);
    }
}

void heapSort(heap *a){
    for (int i = a->len - 1; i >= 0; i--)
        a->arr[i] = extractMin(a);
}

int main() {
    heap a;
    FILE *fin = fopen("sort.in", "r");
    FILE *fout = fopen("sort.out", "w");

    fscanf(fin, "%d", &a.len);
    a.arr = calloc(a.len, sizeof(a.len));
    int tmp = a.len;

    for (int i = 0; i < a.len; i++)
        fscanf(fin, "%d", &a.arr[i]);

    buildHeap(&a);
    heapSort(&a);
    print_arr(a.arr, tmp, fout);
}