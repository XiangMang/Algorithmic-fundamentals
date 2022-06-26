// 静态链表————数组模拟链表
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int head, e[N], ne[N], idx;
// head用来存储头节点
// e来存储单链表的数值
// ne来存储单链表的地址
// idx用来存储现在用到了哪个节点

void init(void){// 初始化操作
    head = -1;
    idx = 0;
}

void add_to_head(int x){// 将x插入到头节点
    e[idx] = x;
    // 存储当前节点的值
    ne[idx] = head;
    // 将新插入的结节指向head指向的值
    head = idx++;
    // 将头节点指向当前节点
}

void add(int k, int x){// 将x这个点插入到下标为k的点的后面
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

void remove(int k){// 将下标是k的节点的后面的点删掉
    ne[k] = ne[ne[k]];
}

int main(void){

    int m;

    cin >> m;

    init();

    while(m--){
        int k, x;
        char op;

        cin >> op;
        if(op == 'H'){
            cin >> x;
            add_to_head(x);
        }
        else if(op == 'D'){
            cin >> k;
            if(!k) head = ne[head];
            else remove(k - 1);
        }
        else{
            cin >> k >> x;
            add(k - 1, x);
        }
    }

    for(int i = head; ~i; i = ne[i]) cout << e[i] << ' ';
    cout << endl;

    return 0;
}