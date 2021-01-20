#include <iostream>

using namespace std;

const int MAX = 10000 + 1;
const int MOD = 1000000007;

int dp[MAX];

int main(void) {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        dp[i] = 1;
    }
    for(int i = m; i <= n; i++) {
        dp[i] = (dp[i-m] + dp[i-1]) % MOD;
    }
    cout << dp[n] << "\n";
    
    return 0;
}