// Topology Sort

#include <bits/stdc++.h>
using namespace std;

vector<int> result;

void dfs(int index, vector<int> &visited, vector<vector<int>> &graph) {
    visited[index] = 1;
    for(int v : graph[index]) {
        if(!visited[v]) dfs(v, visited, graph);
    }
    result.push_back(index);
    return;
}

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    vector<int> visited(n+1, 0);
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) dfs(i, visited, graph);
    }
    reverse(result.begin(), result.end());
    for(auto e : result) cout << e << " ";
    cout << "\n";
    return 0;
}