#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 1000000 + 1;
const int MOD = 1000000007;
// 각각 a, ab, abc로 끝나는 케이스
int dp[MAX][3];

int main(void) {
    string input;
    cin >> input;
    int result = 0;
    for(int i = 1; i <= input.length(); i++) {
        char cur = input[i-1];
        if(cur == 'a') {
            dp[i][0] = (2 * dp[i-1][0] + 1) % MOD;
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-1][2];
        }
        if(cur == 'b') {
            int offset = 2 * (dp[i-1][1] ) * (dp[i-1][1] != 0) % MOD; 
            dp[i][1] = (dp[i-1][0] + offset) % MOD;
            dp[i][0] = dp[i-1][0];
            dp[i][2] = dp[i-1][2];

        }
        if(cur == 'c') {
            int offset = 2 * (dp[i-1][2]) * (dp[i-1][2] != 0) % MOD;
            dp[i][2] = (dp[i-1][1] + offset) % MOD;
            dp[i][1] = dp[i-1][1];
            dp[i][0] = dp[i-1][0];
        }
    }
    cout << dp[input.length()][2] << "\n";
    return 0;
}