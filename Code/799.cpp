#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N], s[N];
// s数组动态记录当前这个区间内每个数字出现多少次

int main(void){

    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    int res = 0;
    for(int i = 0, j = 0; i < n; i++){
        s[a[i]]++;
        while(s[a[i]] > 1){
            s[a[j]]--;
            j++;
        }
        res = max(res, i - j + 1);
    }

    printf("%d\n", res);

    return 0;
}