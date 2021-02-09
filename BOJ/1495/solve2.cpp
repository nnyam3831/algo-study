#include <bits/stdc++.h>
using namespace std;

bool dp[100+1][1000+1];
int main(void) {
    int n, s, m;
    cin >> n >> s >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    dp[0][s] = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= m; j++) {
            if (!dp[i][j]) continue;
            if (j + v[i] <= m) dp[i+1][j+v[i]] = true;
            if (j - v[i] >= 0) dp[i+1][j-v[i]] = true;
        }
    }
    int result = -1;
    for(int i = m; i >= 0; i--) {
        if (dp[n][i]) {
            result = i;
            break;
        }
    }
    cout << result << "\n";
    return 0;
}