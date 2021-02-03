#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
const int MAX = 16;
int w[MAX][MAX], dp[MAX][1 << MAX];

int tsp(int current, int visited, int start, int n) {
    if(visited == (1 << n) - 1) {
        return dp[current][visited] = w[current][start] ? w[current][start] : INF;
    }

    if(dp[current][visited]) return dp[current][visited];

    int ret = INF;
    for(int i = 0; i < n; i++) {
        if(visited & (1 << i) || w[current][i] == 0) continue;
        ret = min(ret, w[current][i] + tsp(i, visited | (1 << i), start, n));
    }
    return dp[current][visited] = ret;
}

int main(void) {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }
    int start = 0;
    
    cout << tsp(0, 1 << start, 0, n) << "\n";
    return 0;
}