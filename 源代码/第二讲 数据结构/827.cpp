// 双链表————静态链表
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int e[N], l[N], r[N], idx;
// l[]记录左节点，r[]记录右节点

void init(void){// 初始化
    // 0表示左端点，1表示右端点
    r[0] = 1, l[1] = 0;
    idx = 2;
}

void add(int k, int x){// 在下标为k的点的右边，插入一个值为x的点
    e[idx] = x;
    
    l[idx] = k;// 设置新节点的左节点
    r[idx] = l[k];// 设置新节点的右节点

    // 以下两个操作不可互换
    l[r[k]] = idx;// 设置下标为k的后面一个节点的左节点
    r[k] = idx++;// 设置下标为k的节点的右节点
}

void remove(int k){// 删除第k个节点
    l[r[k]] = l[k];// 当前节点的右节点的左节点等于当前点的左节点
    r[l[k]] = r[k];// 当前节点的左节点的右节点等于当前点的右节点
}

int main(void){

    cin >> n;

    init();

    while(n--){
        string op;
        int k, x;
        cin >> op;

        if(op == "L"){
            cin >> x;
            add(0, x);
        }
        else if(op == "R"){
            cin >> x;
            add(l[1], x);
        }
        else if(op == "D"){
            remove(k + 1);
            // 因为idx从2开始，故写成k + 1
        }
        else if(op == "IL"){
            cin >> k >> x;
            add(l[k + 1], x);
        }
        else{
            cin >> k >> x;
            add(k + 1, x);
        }
    }

    for(int i = r[0]; ~i; i = r[i]) cout << e[i] << ' ';
    cout << endl;

    return 0;
}