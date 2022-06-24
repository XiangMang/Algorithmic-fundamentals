#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;

int n;
vector<PII> segs;

void merge(vector<PII> & segs){
    vector<PII> res;

    sort(segs.begin(), segs.end());

    int l = -2e9, r = -2e9; // 边界值
    for(auto item : segs){ // 扫描所有的区间
        if(r < item.first){
            if(l != -2e9) res.push_back({l, r});
            l = item.first, r = item.second;
        }
        else r = max(r, item.second);
    }

    if(l != -2e9) res.push_back({l, r}); // 防止空区间

    segs = res;
}

int main(void){

    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }

    merge(segs);

    cout << segs.size() << endl;

    return 0;
}