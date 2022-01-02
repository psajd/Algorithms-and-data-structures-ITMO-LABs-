#include <stdio.h>
#include <stdlib.h>

void check(int **arr, int root, int *flag, int min, int max) {
    if (arr[root][0] <= min || arr[root][0] >= max) {
        *flag = 1;
    }
    if (arr[root][1] != 0) {
        check(arr, arr[root][1], flag, min, arr[root][0]);
    }
    if (arr[root][2] != 0) {
        check(arr, arr[root][2], flag, arr[root][0], max);
    }
}

int main() {
    FILE *fin = fopen("check.in", "r");
    FILE *fout = fopen("check.out", "w");
    int n;
    fscanf(fin, "%d", &n);
    int **arr = malloc(3 * n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        arr[i] = calloc(3, sizeof(int));
        int key, l, r;
        fscanf(fin, "%d", &key);
        fscanf(fin, "%d", &l);
        fscanf(fin, "%d", &r);
        if (l != 0) l--;
        if (r != 0) r--;

        arr[i][0] = key;
        arr[i][1] = l;
        arr[i][2] = r;
    }

    int flag = 0;
    int min = -1000000001, max = 1000000001;
    if (n != 0) {
        check(arr, 0, &flag, min, max);
    }
    else {
        fprintf(fout, "YES");
        return 0;
    }
    if (!flag) {
        fprintf(fout, "YES");
    } else {
        fprintf(fout, "NO");
    }
    return 0;
}