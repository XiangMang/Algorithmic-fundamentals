// 二维前缀和
#include <iostream>

using namespace std;

const int N = 1010;
int n, m, q;
int a[N][N], s[N][N];

int main(){

    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
    }

    for(int i = 1; i <= n; i++){//求前缀和
        for(int j = 1; j <= m; j++){
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
            // i和j分别减去一次
        }
    }

    while(q--){//计算子矩阵
        int x1, x2, y1, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%d\n", s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
        // 减去左上角的坐标值
    }

    return 0;
}