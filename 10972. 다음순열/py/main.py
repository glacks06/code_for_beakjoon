def f(l, idx, v):
    res = l[0:idx]
    res.append(v)
    for i in range(1, len(l)+1):
        if not(i in res): res.append(i)
    return res

def prints(l):
    for i in l:
        print(i, end=' ')
def change_num(l, idx):
    v = 1
    while True:
        t = True
        for i in range(idx):
            if v+l[idx] == l[i]: 
                t = False
                break
        if t == False:
            v += 1
        else:
            return f(l, idx, l[idx]+v)

n = int(input())
a = list(map(int, input().split()))

temp = []
temp.append(a[0])
temp2 = []
for i in range(n, 0, -1):
    temp2.append(i)
    if i == a[0]: continue
    temp.append(i)

if a == temp2: print(-1)
elif a == temp:
    a[0] += 1
    prints(f(a, 1, 1))
else:
    mx = a[len(a)-1]
    for i in range(n-2, -1, -1):
        if a[i] > mx: mx = a[i]

        if a[i] < a[i+1]:
            a = change_num(a, i)
            break
    prints(a)