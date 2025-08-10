n, m = map(int, input().split())
a = list(map(int, input().split()))

s = 0; e = 0
sum = a[e]
cnt = 0

while e <= n-1:
    if sum >= m:
        if sum == m: cnt += 1
        sum -= a[s]
        s += 1
    elif sum < m or s == e:
        if e+1 == n: break
        e += 1
        sum += a[e]
print(cnt)