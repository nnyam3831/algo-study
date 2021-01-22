#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1000 + 1;

int dp[MAX][MAX];

int main(void) {
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c;
            cin >> c;
            dp[i][j] = c - '0';
        }
    }    
    int result = 0;
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(dp[i][j]) {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
            }    
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            result = max(result, dp[i][j] * dp[i][j]);
        }
    }
    cout << result << "\n";

    return 0;
}