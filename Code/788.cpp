#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int q[N], tmp[N];

long long merge_sort(int l, int r){
    if(l >= r) return 0;

    int mid = l + r >> 1;
    long long res = merge_sort(l, mid) + merge_sort(mid + 1, r);
    // 计算左右两侧内部的逆序对的数量

    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j <= r){
        if(q[i] <= q[j]) tmp[k++] = q[i++];
        // 不能写成q[i] < q[j]
        else{
            tmp[k++] = q[j++];
            res += mid - i + 1;
        }
    }
    // 计算分别位于左右两侧的逆序对的数量

    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r) tmp[k++] = q[j++];
    for(i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];
    // 还原数组

    return res;
}

int main(void){

    cin >> n;

    for(int i = 0; i < n; i++) scanf("%d", &q[i]);

    cout << merge_sort(0, n - 1) << endl;

    return 0;
}