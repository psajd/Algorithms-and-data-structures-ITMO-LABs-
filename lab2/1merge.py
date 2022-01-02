def merge_sort(arr, start, end):
    if end - start > 1:
        mid = (start + end)//2
        merge_sort(arr, start, mid)
        merge_sort(arr, mid, end)
        merge(arr, start, mid, end)
 
def merge(arr, start, mid, end):
 
    left_pointer = 0
    right_pointer = 0
    left = arr[start:mid]
    right = arr[mid:end]
    count = start
 
    while left_pointer + start < mid and right_pointer + mid < end:
        if left[left_pointer] < right[right_pointer]:
            arr[count] = left[left_pointer]
            left_pointer += 1
        else:
            arr[count] = right[right_pointer]
            right_pointer += 1
        count += 1
 
    while left_pointer + start < mid:
        arr[count] = left[left_pointer]
        left_pointer += 1
        count += 1
 
    while right_pointer + mid < end:
        arr[count] = right[right_pointer]
        right_pointer += 1
        count += 1
 
fin = open('sort.in')
fout = open('sort.out', "w")
n = int(fin.readline())
a = list(map(int, fin.readline().split()))
 
merge_sort(a, 0, n)
print(*a, file=fout)
