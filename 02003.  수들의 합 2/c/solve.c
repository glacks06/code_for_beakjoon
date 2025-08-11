#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int s = 0, e = 0;
    int sum = a[e];
    int cnt = 0;

    while(e <= n-1){
        if (sum >= m){
            if(sum == m) cnt += 1;
            sum -= a[s];
            s += 1;
        }
        else if(sum < m || s == e){
            if(e+1 == n) break;
            e += 1;
            sum += a[e];
        }
    }
    printf("%d", cnt);
}
