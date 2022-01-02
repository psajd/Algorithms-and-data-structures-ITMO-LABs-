#include <stdio.h>
#include <string.h>
#include <stdlib.h>
double min(double a, double b){
    if (a < b){
        return a;
    }
    else{
        return b;
    }
}
int main() {
    FILE *fin = fopen("garland.in", "r");
    FILE *fout = fopen("garland.out", "w");

    int n;
    fscanf(fin, "%d", &n);
    double *a = calloc(n, sizeof(double));
    fscanf(fin, "%lf", &a[0]);

    double res = 1000000000.0, l = 0, r = a[0];

    while (l < r && r - l > 1e-9){
        a[1] = (l + r) / 2;
        a[n - 1] = 0;
        int isCorrect = 1;
        for (int i = 2; i < n; i++){
            a[i] = 2*a[i-1] - a[i-2] + 2;
            if (a[i] < 0){
                isCorrect = 0;
                l = a[1];
                break;
            }
        }
        if (!isCorrect)
            continue;
        r = a[1];
        res = min(res, a[n-1]);
    }
    fprintf(fout, "%0.2lf", res);
}