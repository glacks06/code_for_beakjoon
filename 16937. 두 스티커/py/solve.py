def size(h, w, a, b):
    sticker_size = int((a[0]*a[1]) + (b[0]*b[1]))
    if a[0]+b[0] <= w:
        if a[1] <= h and b[1] <= h: return sticker_size
    if a[0]+b[1] <= w:
        if a[1] <= h and b[0] <= h: return sticker_size

    if a[1]+b[1] <= h: 
        if a[0] <= w and b[0] <= w: return sticker_size
    if a[1]+b[0] <= h:
        if a[0] <= w and b[1] <= w: return sticker_size
    
    if a[1]+b[0] <= w:
        if a[0] <= h and b[1] <= h: return sticker_size
    if a[1]+b[1] <= w:
        if a[0] <= h and b[0] <= h: return sticker_size

    if a[0]+b[1] <= h:
        if a[1] <= w and b[0] <= w: return sticker_size
    if a[0]+b[0] <= h:
        if a[1] <= w and b[1] <= w: return sticker_size
    return 0

h, w = map(int, input().split())
n = int(input())

sticker = []
for i in range(n):
    sticker.append(list(map(int, input().split())))

mx = 0
for i in range(n):
    for j in range(i+1, n):
        v = size(h, w, sticker[i], sticker[j])
        if v > mx: mx = v
print(mx)
