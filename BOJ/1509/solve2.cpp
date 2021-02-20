#include <bits/stdc++.h>
using namespace std;

const int MAX = 2500 + 1;
const int INF = 987654321;
int d[MAX][MAX];
int dp[MAX];

int dfs(int index, string target) {
    if (index >= target.size()) return 0;
    if (dp[index] != -1) return dp[index];
    
    int ret = INF;
    for(int i = 0; i < target.size(); i++) {
        if (i < index) continue;
        if (!d[index][i]) continue;

        ret = min(ret, dfs(i+1, target) + 1);
    } 
    return dp[index] = ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, input) << "\n";
    return 0;
}