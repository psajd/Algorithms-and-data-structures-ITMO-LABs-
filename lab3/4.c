#include <stdlib.h>
#include <stdio.h>
#include <iso646.h>
#include <string.h>

typedef struct {
    int *arr;
    int len;
    int *linesArr;
    int linesCnt;
} heap;

int isHeap(int arr[], int n) {
    int flag = 1;

    for (int i = 0; i - 1 < n / 2; i++) {
        if (2 * i + 1 < n)
            if (arr[i] > arr[2 * i + 1]) {
                flag = 0;
                break;
            }
        if (2 * i + 2 < n)
            if (arr[i] > arr[2 * i + 2]) {
                flag = 0;
                break;
            }
    }
    return flag;
}

void print_arr(int arr[], int n, FILE *fout) {
    for (int i = n - 1; i >= 0; i--)
        fprintf(fout, "%d ", arr[i]);
    fprintf(fout, "\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void siftDown(heap *a, int index) {
    int left, j, right;
    while (2 * index + 1 < a->len) {
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

void siftUp(heap *a, int index) {
    while (a->arr[index] < a->arr[(index - 1) / 2]) {
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

void insert(heap *a, int key) {
    a->len = a->len + 1;
    a->arr[a->len - 1] = key;
    siftUp(a, a->len - 1);
}

void buildHeap(heap *a) {
    for (int i = a->len; i >= 0; i--) {
        siftDown(a, i);
    }
}

void heapSort(heap *a) {
    for (int i = a->len - 1; i >= 0; i--)
        a->arr[i] = extractMin(a);
}

void decreaseKey(heap *a, int prev, int curr) {
    int i;
    for (i = 0; i < a->len; i++) {
        if (a->arr[i] == prev) {
            a->arr[i] = curr;
            break;
        }
    }
    siftUp(a, i);
}

int main() {
    heap a;
    FILE *fin = fopen("priorityqueue.in", "r");
    FILE *fout = fopen("priorityqueue.out", "w");
    a.arr = calloc(1000 * 1000, sizeof(int));
    a.linesArr = calloc(1000 * 1000, sizeof(int));
    a.len = 0;
    a.linesCnt = 0;
    char str[20];
    while (fscanf(fin, "%s", str) != EOF) {
        int key;
        a.linesCnt++;
        if (!strcmp(str, "push")) {
            fscanf(fin, "%d", &key);
            insert(&a, key);
            a.linesArr[a.linesCnt] = key;
        } else if (!strcmp(str, "extract-min")) {
            if (a.len > 0) {
                fprintf(fout, "%d\n", extractMin(&a));
                str[0] = '\0';
            }
            else{
                fprintf(fout, "*\n");
                str[0] = '\0';
            }
        } else if (!strcmp(str, "decrease-key")) {
            int x, curr;
            fscanf(fin, "%d", &x);
            fscanf(fin, "%d", &curr);
            int prev = a.linesArr[x];
            a.linesArr[x] = curr;
            decreaseKey(&a, prev, curr);
        }
    }
}