fin = open("radixsort.in")
fout = open("radixsort.out", "w")

n, m, k = map(int, fin.readline().split())
strings = []

for i in range(n):
    tmp = fin.readline()
    if tmp[-1] == '\n':
        strings.append(tmp[:m])
    else:
        strings.append(tmp)


for j in range(m - 1, -1, -1):

    if k == 0:
        break

    c = 1500 * [0]
    b = n * [0]

    for i in range(n):
        c[ord(strings[i][j])] += 1

    for i in range(1, 1000):
        c[i] = c[i] + c[i - 1]

    for i in range(n - 1, -1, -1):
        b[c[ord(strings[i][j])] - 1] = strings[i]
        c[ord(strings[i][j])] -= 1

    strings = b
    k -= 1

for i in range(n):
    print(strings[i], file=fout)

# print("\n=========\n", file=fout)