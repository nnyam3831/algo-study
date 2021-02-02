#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> cost(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i+1; j++) {
            cin >> dp[i][j];
            cost[i][j] = dp[i][j];
        }
    }
    
    int result = 0;
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < i+1; j++) {
            dp[i+1][j] = max(dp[i+1][j], cost[i+1][j] + dp[i][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], cost[i+1][j+1] + dp[i][j]);
        }
    }
    
    for(int i = 0; i < n; i++){
        result = max(result, dp[n-1][i]);
    }
    cout << result << "\n";
    return 0;
}
