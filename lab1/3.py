fin = open("turtle.in")
fout = open("turtle.out", "w")
h, w = map(int, fin.readline().split())
coin_array = [[0] for i in range(h)]
 
for i in range(h):
    coin_array[i] = list(map(int, fin.readline().split()))
copy_coin_array = list(map(list, coin_array))
 
for i in range(h - 2, -1, -1):
    copy_coin_array[i][0] = coin_array[i][0] + copy_coin_array[i + 1][0]
for i in range(1, w):
    copy_coin_array[h-1][i] = coin_array[h-1][i] + copy_coin_array[h-1][i-1]
 
for i in range(h - 2, -1, -1):
    for j in range(1, w):
        copy_coin_array[i][j] = max(copy_coin_array[i+1][j], copy_coin_array[i][j-1]) + coin_array[i][j]
print(copy_coin_array[0][w-1], file=fout)
