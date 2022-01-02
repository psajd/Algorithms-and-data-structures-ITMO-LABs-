#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
    if (a > b){
        return a;
    }
    else{
        return b;
    }
}

int check(int **arr, int strnum) {
    if (strnum == -1){
        return 0;
    }
    int a = check(arr, arr[strnum][1]);
    int b = check(arr, arr[strnum][2]);
    return max(a, b) + 1;

}

int main() {
    FILE *fin = fopen("height.in", "r");
    FILE *fout = fopen("height.out", "w");
    int n;
    fscanf(fin, "%d", &n);
    int **arr = malloc(3 * n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        arr[i] = calloc(3, sizeof(int));
        int key, l, r;
        fscanf(fin, "%d", &key);
        fscanf(fin, "%d", &l);
        fscanf(fin, "%d", &r);

        l--;
        r--;

        arr[i][0] = key;
        arr[i][1] = l;
        arr[i][2] = r;
        //printf("%d %d %d\n", key, l, r);
    }

    if (n != 0){
        int ans = check(arr, 0);
        fprintf(fout, "%d", ans);
    }
    else{
        fprintf(fout, "0");
    }

    return 0;
}