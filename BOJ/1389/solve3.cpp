// dfs
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100 + 1;
const int INF = 987654321;
vector<int> graph[MAX];

void dfs(int index, vector<int> &visited, int depth) {
    visited[index] = depth;

    for(int v : graph[index]) {
        // visited가 -1이면 그냥 들어감
        if (visited[v] == -1) {
            dfs(v, visited, depth + 1);
        } else {
        // visited보다 depth + 1가 작으면 다시 탐색함
            if (visited[v] > depth + 1) {
                dfs(v, visited, depth + 1);
            }     
        }
    }
}

int main(void) {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int sum = INF;
    int result;
    for(int i = 1; i <= n; i++) {
        vector<int> visited(n+1, -1);
        dfs(i, visited, 0);
        int temp = 0;
        for(int v : visited) temp += v;
        if (temp < sum) {
            sum = temp;
            result = i;
        }
    }
    cout << result << "\n";
    return 0;
}

