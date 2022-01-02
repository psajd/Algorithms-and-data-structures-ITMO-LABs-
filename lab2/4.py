def antiqs(arr):
    for i in range(2, len(arr)):
        arr[i], arr[i // 2] = arr[i // 2], arr[i]
 
fin = open("antiqs.in")
fout = open("antiqs.out", "w")
 
n = int(fin.readline())
a = [x for x in range(1, n + 1)]
antiqs(a)
 
print(*a, file=fout)
