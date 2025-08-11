#include <stdio.h>

int contains(int arr[], int value, int start, int end) {
    for (int i = start; i <= end; i++) 
        if (arr[i] == value) return 1;
    return 0;
}
void f(int l[], int idx, int v, int size){
    l[idx] = v;
    int t = idx+1;
    int s = 0, e = idx;
    for(int i = 1; i < size+1; i++){
        if(contains(l, i, s, e) == 0) {
            l[t++] = i;
            e++;
        }
    }
}
void slice(int* source, int idx, int* result, int* result_size) {
    *result_size = idx;
    for (int i = 0; i < idx; i++)
        result[i] = source[i];
}
int arrays_equal(int arr1[], int arr2[], int size) {
    for (int i = 0; i < size; i++) 
        if (arr1[i] != arr2[i]) return 0;
    return 1;
}
void prints(int arr[], int size) {
    for (int i = 0; i < size; i++) 
        printf("%d ", arr[i]);
}
void change_num(int l[], int idx, int n){
    int v = 1;
    while(1){
        int t = 1;
        for(int i = 0; i < idx; i++){
            if(v+l[idx] == l[i]){
                t = 0;
                break;
            }
        }
        if (t == 0) v += 1;
        else {
            f(l, idx, l[idx]+v, n);
            break;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int temp1[n];
    int temp2[n];
    temp1[0] = a[0];
    int idx = 1;
    for(int i = n; i > 0; i--){
        temp2[n-i] = i;
        if(i == a[0]) continue;
        temp1[idx] = i;
        idx++;
    }

    if(arrays_equal(a, temp2, n)) printf("-1");
    else if(arrays_equal(a, temp1, n)){
        a[0] += 1;
        f(a, 1, 1, n);
        prints(a, n);
    }
    else{
        for(int i = n-2; i > -1; i--){
            if(a[i] < a[i+1]){
                change_num(a, i, n);
                break;
            }
        }
        prints(a, n);
    }
}
