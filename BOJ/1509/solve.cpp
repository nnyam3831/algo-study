#include <bits/stdc++.h>
using namespace std;

const int MAX = 2500 + 1;
const int INF = 987654321;
int d[MAX][MAX];
int dp[MAX];

int main(void) {
    string input;
    cin >> input;
    for(int dist = 0; dist < input.size(); dist++) {
        for(int i = 0; i < input.size() - dist; i++) {
            if (dist == 0) {
                d[i][i] = 1;
            } else if (dist == 1) {
                d[i][i+1] = input[i] == input[i+1];
            } else {
                d[i][i+dist] = input[i] == input[i+dist] && d[i+1][i+dist-1];
            }
        }
    }
    memset(dp, INF,sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i < input.size(); i++) {
        dp[i] = dp[i-1] + 1;
        for(int j = 0; j < i; j++) {
            if (d[j][i]) {
                if (j == 0) dp[i] = 1;
                else dp[i] = min(dp[i], dp[j-1] + 1);
            }
        }
    }
    cout << dp[input.size()-1] << "\n";
    return 0;
}