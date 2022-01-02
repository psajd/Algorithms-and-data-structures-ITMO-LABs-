fin = open("sortland.in")
fout = open("sortland.out", "w")
 
n = int(fin.readline())
arr_num = list(map(float, fin.readline().split()))
copy_array_num = arr_num.copy()
 
for i in range(n - 1):
    for j in range(i + 1, n):
        if copy_array_num[i] > copy_array_num[j]:
            copy_array_num[i], copy_array_num[j] = copy_array_num[j], copy_array_num[i]
 
citizens = [copy_array_num[0], copy_array_num[n // 2], copy_array_num[n-1]]
 
citez_id = [0]*3
 
for i in range(n):
    if citizens[0] == arr_num[i]:
        citez_id[0] = i + 1
    if citizens[1] == arr_num[i]:
        citez_id[1] = i + 1
    if citizens[2] == arr_num[i]:
        citez_id[2] = i + 1
 
print(*citez_id, file=fout)
