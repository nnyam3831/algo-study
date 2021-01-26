#include <iostream>

using namespace std;

const int MAX = 1000 + 1;
const int MOD = 10007;
int dp[MAX];

int main(void) {
    dp[1] = 1, dp[2] = 2;
    int n;
    cin >> n;
    for(int i = 3; i <= n; i++) {
        dp[i] = (dp[i-2] + dp[i-1]) % MOD;
    }
    cout << dp[n] << "\n";
    return 0;
}