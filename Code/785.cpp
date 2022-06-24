// 快速排序模板
// 思想基于分治
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, q[N];

void quick_sort(int l, int r){
    if(l >= r) return ;
    // 判断边界
    int i = l - 1, j = r + 1, x = q[l + r >> 1] ;
    // 确定分界点
    while(i < j){
        while(q[++i] < x);
        while(q[--j] > x);
        if(i < j) swap(q[i], q[j]);
    }
    // 划分区间，通过x进行分区
    // 使得所有小于等于x都在左半边，所有大于等于x都在右半边
    quick_sort(l, j), quick_sort(j + 1, r);
    // 递归的给左右两边排序 
}

int main(void){

    scanf("%d", &n);

    for(int i = 0; i < n; i++) scanf("%d", &q[i]);

    quick_sort(0, n - 1);

    for(int i = 0; i < n; i++) printf("%d ", q[i]);

    return 0;
}