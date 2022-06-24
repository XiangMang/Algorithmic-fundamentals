#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m, x;
int a[N], b[N];

int main(void){

    cin >> n >> m >> x;

    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int j = 0; j < m; j++) scanf("%d", &b[j]);

    for(int i = 0, j = m - 1; i < n; i++){
        // i从前往后遍历，j从后往前遍历
        while(j >= 0 && a[i] + b[j] > x) j--;
        if(a[i] + b[j] == x){
            printf("%d %d\n", i, j);
            break;
        }
    }

    return 0;
}