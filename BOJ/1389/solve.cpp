// 플로이드 와샬
#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
const int MAX = 100 + 1;
int d[MAX][MAX];

int main(void) {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        d[a][b] = 1;
        d[b][a] = 1;
    }    

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    int result = 0;
    int sum = INF;
    for(int i = 1; i <= n; i++) {
        int temp = 0;
        for(int j = 1; j <= n; j++) {
            temp += d[i][j];
        }
        if (temp < sum) {
            sum = temp;
            result = i;
        }
    }
    cout << result << "\n";
    return 0;
}