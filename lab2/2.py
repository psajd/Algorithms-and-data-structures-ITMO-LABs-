def merge_sort(arr, start, end):
    if end - start > 1:
        mid = (start + end) // 2
        merge_sort(arr, start, mid)
        merge_sort(arr, mid, end)
        merge(arr, start, mid, end)
 
 
def merge(arr, start, mid, end):
    left_pointer = 0
    right_pointer = -1
    left = arr[start:mid]
    right = (arr[mid:end])[::-1]
    count = start
    while left_pointer + start < mid < right_pointer + 1 + end:
        if left[left_pointer][0] <= right[right_pointer][0]:
            arr[count] = left[left_pointer]
            left_pointer += 1
        else:  # Слияние двух массивов
            arr[count] = right[right_pointer]
            right_pointer -= 1
        count += 1
    if left_pointer + start > mid:
        while mid < right_pointer + 1 + end:
            arr[count] = right[right_pointer]  # доливание хвоста
            right_pointer -= 1
            count += 1
    else:
        while left_pointer + start < mid:
            arr[count] = left[left_pointer]  # доливание хвоста
            left_pointer += 1
            count += 1
 
 
file123 = open("race.in")
fout = open("race.out", "w")
n = int(file123.readline())
countries_racers = []
 
for i in range(n):
    countries_racers.append(file123.readline().split())
 
 
merge_sort(countries_racers, 0, len(countries_racers))
 
temp = countries_racers[0][0]
 
print("=== {0} ===".format(temp), file=fout)
for i in range(1, len(countries_racers[0])):
    print(countries_racers[0][i], file=fout)
 
for i in range(1, len(countries_racers)):
    if countries_racers[i][0] == countries_racers[i - 1][0]:
        print(countries_racers[i][1], file=fout)
    else:
        print("=== {0} ===".format(countries_racers[i][0]), file=fout)
        print(countries_racers[i][1],file=fout)
