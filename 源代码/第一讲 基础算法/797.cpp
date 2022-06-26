// 一维差分
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, k;
int a[N], b[N];

void insert(int l, int r, int c){
    b[l] += c;
    b[r + 1] -= c;
}

int main(void){

    scanf("%d%d", &n, &k);

    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for(int i = 1; i <= n; i++) insert(i, i, a[i]);

    while(k--){
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }

    for(int i = 1; i <= n; i++) b[i] += b[i - 1];

    for(int i = 1; i <= n; i++) printf("%d ", b[i]);

    return 0;
}