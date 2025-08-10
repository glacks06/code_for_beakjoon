#include <stdio.h>

int size(int h, int w, int a[2], int b[2]) {
    int sticker_size = a[0]*a[1] + b[0]*b[1];

    if (a[0] + b[0] <= w) 
        if (a[1] <= h && b[1] <= h) return sticker_size;
    if (a[0] + b[1] <= w) 
        if (a[1] <= h && b[0] <= h) return sticker_size;
    
    if (a[1] + b[1] <= h) 
        if (a[0] <= w && b[0] <= w) return sticker_size;
    if (a[1] + b[0] <= h) 
        if (a[0] <= w && b[1] <= w) return sticker_size;
    
    if (a[1] + b[0] <= w) 
        if (a[0] <= h && b[1] <= h) return sticker_size;
    if (a[1] + b[1] <= w) 
        if (a[0] <= h && b[0] <= h) return sticker_size;
    
    if (a[0] + b[1] <= h) 
        if (a[1] <= w && b[0] <= w) return sticker_size;
    if (a[0] + b[0] <= h)
        if (a[1] <= w && b[1] <= w) return sticker_size;
    return 0;
}

int main() {
    int h, w, n, i, j;
    int sticker[100][2];
    int mx = 0;

    scanf("%d %d", &h, &w);
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d %d", &sticker[i][0], &sticker[i][1]);
    }

    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            int v = size(h, w, sticker[i], sticker[j]);
            if (v > mx) mx = v;
    }}

    printf("%d\n", mx);
}
#include <stdio.h>

int size(int h, int w, int a[2], int b[2]) {
    int sticker_size = a[0]*a[1] + b[0]*b[1];

    if (a[0] + b[0] <= w) 
        if (a[1] <= h && b[1] <= h) return sticker_size;
    if (a[0] + b[1] <= w) 
        if (a[1] <= h && b[0] <= h) return sticker_size;
    
    if (a[1] + b[1] <= h) 
        if (a[0] <= w && b[0] <= w) return sticker_size;
    if (a[1] + b[0] <= h) 
        if (a[0] <= w && b[1] <= w) return sticker_size;
    
    if (a[1] + b[0] <= w) 
        if (a[0] <= h && b[1] <= h) return sticker_size;
    if (a[1] + b[1] <= w) 
        if (a[0] <= h && b[0] <= h) return sticker_size;
    
    if (a[0] + b[1] <= h) 
        if (a[1] <= w && b[0] <= w) return sticker_size;
    if (a[0] + b[0] <= h)
        if (a[1] <= w && b[1] <= w) return sticker_size;
    return 0;
}

int main() {
    int h, w, n, i, j;
    int sticker[100][2];
    int mx = 0;

    scanf("%d %d", &h, &w);
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d %d", &sticker[i][0], &sticker[i][1]);
    }

    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            int v = size(h, w, sticker[i], sticker[j]);
            if (v > mx) mx = v;
    }}

    printf("%d\n", mx);
}
