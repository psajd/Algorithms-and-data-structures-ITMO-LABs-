fin = open("smallsort.in")
fout = open("smallsort.out", "w")
n = int(fin.readline())
arr_num = list(map(int, fin.readline().split()))
 
for i in range(n-1):
    for j in range(i+1, n):
        if arr_num[i] > arr_num[j]:
            arr_num[i], arr_num[j] = arr_num[j], arr_num[i]
print(*arr_num, file=fout)
