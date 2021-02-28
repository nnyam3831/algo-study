#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100 + 1;
const int MAX_K = 100000 + 1;
const int INF = 987654321;
int dp[MAX_N][MAX_K];
int w[MAX_N];
int v[MAX_K];
int n, k;

int dfs(int index, int weight) {
    if (weight > k) return -INF;
    if (index == n || weight == k) return 0;
    
    int &ret = dp[index][weight];
    if (ret != -1) return ret;
    
    ret = max(dfs(index + 1, weight + w[index]) + v[index], dfs(index + 1, weight));
    return ret;
}

int main(void) {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0) << "\n";
    return 0;
}