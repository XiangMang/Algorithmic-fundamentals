// 一维前缀和
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int q[N], tmp[N];

int main(){

    cin >> n >> m;

    for(int i = 1; i <= n; i++) scanf("%d", &q[i]);

    for(int i = 1; i <= n; i++) tmp[i] = tmp[i - 1] + q[i];

    while(m--){
        int l, r;
        cin >> l >> r;
        printf("%d\n", tmp[r] - tmp[l - 1]);
    }

    return 0;
}