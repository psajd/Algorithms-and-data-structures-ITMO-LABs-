from random import randint
def quick_sort(arr, start, end):
    if start < end:
        pivot = partition(arr, start, end)
        quick_sort(arr, start, pivot)
        quick_sort(arr, pivot + 1, end)
 
 
def partition(arr, start, end):
    mid = arr[randint(start, end)]
    left_p = start
    right_p = end
 
    while left_p <= right_p:
        while arr[left_p] < mid:
            left_p += 1
        while arr[right_p] > mid:
            right_p -= 1
        if left_p >= right_p:
            break
        arr[left_p], arr[right_p] = arr[right_p], arr[left_p]
        left_p += 1
        right_p -= 1
 
    return right_p
 
 
fin = open('sort.in')
fout = open('sort.out', "w")
 
n = int(fin.readline())
a = list(map(int, fin.readline().split()))
 
quick_sort(a, 0, n - 1)
print(*a, file=fout)
