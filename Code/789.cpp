#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int q[N];

int main(void){

    cin >> n >> m;

    for(int i = 0; i < n; i++) scanf("%d", &q[i]);

    while(m--){
        int x;
        scanf("%d", &x);

        // 区间[l, r]被划分为[l, mid]和[mid + 1, r]时使用。
        // 确定起始坐标
        int l = 0, r = n - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(q[mid] >= x) r = mid;
            else l = mid + 1;
            // 可以理解为查找查询第一个大于等于x的数
        }

        if(q[l] != x) cout << "-1 -1" << endl;
        else{
            cout << l << ' ';
            // 区间[l, r]被划分为[l, mid - 1]和[mid, r]时使用。
            // 确定末尾坐标
            int l = 0, r = n - 1;
            while(l < r){
                int mid = l + r + 1 >> 1;
                // 当范围为[l, r]，且l = r - 1时，如果mid = l + r，mid = l，
                // 范围为[l, r]，会进入死循环，故mid = l + r + 1;
                if(q[mid] <= x) l = mid;
                else r = mid - 1;
                // 可以理解为查找第一个小于等于x的数
            }

            cout << l << endl;
        }
    }

    return 0;
}