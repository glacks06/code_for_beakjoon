import sys
sys.setrecursionlimit(10**6)

res = 0
h = []

def checkCost(l):
    global p
    sum = 0
    for i in l:
        sum += p[i]
    return sum


def f(l, sum):
    global n
    global t
    global p
    global res
    global t
    # print(l, type(l))
    base = True
    mx = 0
    if sum <= res: return 0
    if l in h: return 0
    h.append(l)
    
    l_length = len(l)
    for i in range(1, l_length-1):
        if l[i+1] < l[i]+t[l[i]]:
            base = False
            break

    if base: # 더이상 날짜를 쪼갤 수 없는 상태(base)
        if sum > res: res = sum
        return sum
    
    v = 0
    for i in l:
        if i == 0: continue

        temp = []
        for j in l: temp.append(j)
        temp.remove(i)
        v = f(temp, sum-p[i])
        if v > mx: mx = v
    return mx


n = int(input())

t = [0]
p = [0]
l = [0]
sum = 0
for i in range(n):
    ip = list(map(int, input().split()))
    t.append(ip[0])
    p.append(ip[1])
    if i+1+t[i+1] > n+1: continue
    l.append(i+1)
    sum += ip[1]

print(f(l, sum))