#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 100 + 1;
const int K_MAX = 100000 + 1;
int dp[N_MAX][K_MAX];
int w[N_MAX];
int v[N_MAX];

int main(void) {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - w[i] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
            }
        }
    }

    cout << dp[n][k] << "\n";
    return 0;
}