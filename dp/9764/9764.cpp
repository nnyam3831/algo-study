#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 2000 + 1;
const int MOD = 100999;
int dp[MAX][MAX];

int main(void) {
    for(int i = 0; i <= 2000; i++) {
        dp[i][i] = 1;
        dp[0][i] = 1;
    }
    for(int i = 1; i <= 2000; i++) {
        for(int j = 1; j <= 2000; j++) {
            if (i < j) {
                dp[i][j] = dp[i][j-1];
            } else {
                dp[i][j] = (dp[i][j-1] + dp[i-j][j-1]) % MOD;
            }
        }
    }    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << dp[n][n] << "\n";
    }
    return 0;
}