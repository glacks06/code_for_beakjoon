#include <stdio.h>


int arrays_equal(int arr1[], int arr2[], int size) {
    for (int i = 0; i < size; i++) 
        if (arr1[i] != arr2[i]) return 0;
    return 1;
}
void prints(int arr[], int size) {
    for (int i = 0; i < size; i++) 
        printf("%d ", arr[i]);
    printf("\n");
}

int h[40000][16];
int h_len = 0;
int t[15], p[15];

void append(int l[], int n, int idx){
    for(int i = 0; i < n; i++)
        h[idx][i] = l[i];
}
int isBase(int arr[], int size){
    for(int i = 0; i < size; i++){
        // if(arr[i]+t[i]-1 > size) return 0;
        if(arr[i] != 0){
            for(int j = i+1; j < size; j++){
                if(arr[j] != 0 && arr[j] < arr[i]+t[i]) return 0;
            }
        }
    }
    return 1;
}

int f(int l[], int sum, int n) {
    // prints(l, n);
    int mx = 0;

    for(int i = 0; i < h_len; i++){
        if(arrays_equal(l, h[i], n)) return 0;
    }
    append(l, n, h_len);
    h_len++;
    
    if(isBase(l, n)) {
        // prints(l, n);
        // printf("# %d\n", sum);
        return sum;
    }
    
    int v = 0;
    for(int i = 0; i < n; i++){
        if(l[i] == 0) continue;
        int temp[n];
        for(int j = 0; j < n; j++) temp[j] = l[j];
        temp[i] = 0;
        v = f(temp, sum-p[i], n);
        // printf("# %d\n", v);
        if (v > mx) mx = v;
    }
    return mx;
}

int main() {
    int n;
    scanf("%d", &n);
    int sum = 0;
    int l[n];
    for(int i = 0; i < n; i++){
        scanf("%d %d", &t[i], &p[i]);
        l[i] = i+1;
        if(l[i]+t[i]-1 > n) l[i] = 0;
        else sum += p[i];
    }
    printf("%d", f(l, sum, n));
}