def changeCheckState(v, check):
    if v <= 2:
        for i in range(3):
            check[v][i] = 1
    elif v <= 5:
        for i in range(3):
            check[i][v-3] = 1
    elif v == 6:
        for i in range(3): check[i][i] = 1
    else:
        for i in range(3): check[i][2-i] = 1



def magic(goal):
    t_a = [[0 for _ in range(3)] for _ in range(3)]
    t_sums = []
    check = [[0 for _ in range(3)] for _ in range(3)]
    for i in range(3):
        for j in range(3): t_a[i][j] = t_a[i][j]
    for i in range(8): 
        t_sums.append(sums[i])
        if sums[i] == goal:
            changeCheckState(i, check)
    
    # for i in range(3):
    #     for j in range(3):

    

a = []
for _ in range(3):
    a.append(list(map(int, input().split())))

sums = [0 for _ in range(8)]

sum3 = 0; sum4 = 0
for i in range(3):
    sum1 = 0; sum2 = 0
    for j in range(3):
        sum1 += a[i][j]
        sum2 += a[j][i]
    sum3 += a[i][i]; sum4 += a[i][2-i]
    sums[i] = sum1; sums[i+3] = sum2
sums[6] = sum3
sums[7] = sum4

print(sums)

# magic()