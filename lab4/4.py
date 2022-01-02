def bisect_right(a, x, length):
    left = 0
    right = length
    while left < right:
        mid = (left + right) // 2
        if x < a[mid]:
            right = mid
        else:
            left = mid + 1
    if left - 1 >= 0 and a[left - 1] == x:
        return left
    else:
        return -1


def bisect_left(a, x, length):
    left = 0
    right = length
    while left < right:
        mid = (left + right) // 2
        if a[mid] < x:
            left = mid + 1
        else:
            right = mid
    if left <= n - 1 and a[left] == x:
        return left + 1
    else:
        return -1


fin = open("binsearch.in", "r")
fout = open("binsearch.out", "w")

n = int(fin.readline())
arr = list(map(int, fin.readline().split()))
keys = int(fin.readline())
keysArr = list(map(int, fin.readline().split()))

for i in range(keys):
    print(bisect_left(arr, keysArr[i], n), bisect_right(arr, keysArr[i], n), file=fout)