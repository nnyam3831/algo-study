#include <bits/stdc++.h>
using namespace std;

const int MAX = 10000 + 1;
const int INF = 987654321;
int dp[MAX];

int dfs(int money, vector<pair<int,int>> &candies) {
    if (money < 0) return -INF; 
    if (dp[money]) return dp[money];

    int ret = 0;
    for(int i = 0; i < candies.size(); i++) {
        int calorie = candies[i].second;
        int price = candies[i].first;
        ret = max(ret, calorie + dfs(money - price, candies));
    }
    return dp[money] = ret;
}

int main(void) {
    while (true) {
        int n;
        float m;
        cin >> n >> m;
        if (n == 0 && m == 0.00) break;

        vector<pair<int,int>> candies; 
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            int c;
            float p;
            cin >> c >> p;
            candies.push_back({(int)(p * 100), c});
        }
        cout << dfs((int)(m*100), candies) << "\n";
    }
    return 0;
}