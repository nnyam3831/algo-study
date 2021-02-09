#include <bits/stdc++.h>
using namespace std;

// i번째 index에서 현재 볼륨 j일때 마지막 볼륨의 최대값
int dp[100 + 1][1000 + 1];

int getMaxVolume(int i, int p, int n, vector<int>& v, int limit) {
    if (p > limit || p < 0) return -1;
    if (dp[i][p] != -2) return dp[i][p];
    if (i == n) return p;

    return dp[i][p] = max(getMaxVolume(i+1, p + v[i], n, v, limit), getMaxVolume(i+1, p-v[i], n, v, limit));
}

int main(void) {
    int n, s, m;
    cin >> n >> s >> m;
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            dp[i][j] = -2;
        }
    }
    cout << getMaxVolume(0, s, n, v, m) << "\n";
    return 0;
}