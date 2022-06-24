#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, k, q[N];

int quick_sort(int l, int r, int k){
    if(l >= r) return q[l];
    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while(i < j){
        while(q[++i] < x);
        while(q[--j] > x);
        if(i < j) swap(q[i], q[j]);
    }
    int sl = j - l + 1;
    if(k <= sl) return quick_sort(l, j, k);
    return quick_sort(j + 1, r, k - sl);
}

int main(void){

    cin >> n >> k;

    for(int i = 0; i < n; i++) scanf("%d", &q[i]);

    printf("%d\n", quick_sort(0, n - 1, k));

    return 0;
}