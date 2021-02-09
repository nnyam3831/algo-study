#include <bits/stdc++.h>
using namespace std;

const int MAX = 2000 + 1;
int dp[MAX][MAX];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n;
    vector<int> array(n+1);
    for(int i = 1; i <= n; i++) cin >> array[i];
    cin >> m;
    for(int dist = 0; dist <= n; dist++) {
        for(int i = 1; i <= n - dist; i++) {
            if (dist == 0) dp[i][i+dist] = 1;
            else if (dist == 1) dp[i][i+dist] = array[i] == array[i+dist];
            else {
                if (array[i] == array[i+dist] && dp[i+1][i+dist-1]) {
                    dp[i][i+dist] = 1;
                }
            }
        }
    }
    for(int i = 0; i < m; i++) {
        // query
        int s, e;
        cin >> s >> e;
        cout << dp[s][e] << "\n";
    }
    return 0;
}