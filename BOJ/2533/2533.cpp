#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000 + 1;
vector<int> graph[MAX];
int dp[2][MAX];

int dfs(int node, bool isEA, int parent) {
    int ret = isEA;
    if (dp[ret][node] != -1) {
        return dp[ret][node];
    }

    if (isEA) {
        ret = 1;
        for(int v : graph[node]) {
            if (v != parent) {
                ret += min(dfs(v, true, node), dfs(v, false, node));
            }
        }
        return dp[1][node] = ret;   
    } else {
        ret = 0;
        for(int v : graph[node]) {
            if (v != parent) {
                ret += dfs(v, true, node);
            }
        }
        return dp[0][node] = ret;
    }
}

int main(void) {
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);        
    }
    memset(dp, -1, sizeof(dp));
    cout << min(dfs(1, true, -1),dfs(1, false, -1)) << "\n";
    return 0;
}