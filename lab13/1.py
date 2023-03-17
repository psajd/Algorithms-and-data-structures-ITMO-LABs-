file_in = open("search1.in", "r")
file_out = open("search1.out", "w")

sub = file_in.readline()
sub = sub[:len(sub) - 1]
str = file_in.readline()

arr = []

for i in range(len(str) - len(sub) + 1):

    flag = True
    for j in range(i, i + len(sub)):
        if (sub[j - i] != str[j]):
            flag = False
            break

    if (flag):
        arr.append(i + 1)

print(len(arr), file=file_out)
print(*arr, file=file_out)