// bfs
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100 + 1;
const int INF = 987654321;
set<int> graph[MAX];

int main(void) {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    int sum = INF;
    int result;
    for(int i = 1; i <= n; i++) {
        queue<int> q;
        vector<int> visited(n+1, 0);
        q.push(i);
        visited[i] = 1;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(int v : graph[cur]) {
                if (!visited[v]) {
                    visited[v] = visited[cur] + 1;
                    q.push(v);
                }
            }
        }
        int temp = 0;
        for(int j = 1; j <= n; j++) {
            if (i != j) temp += (visited[j] - 1);
        }
        if (temp < sum) {
            sum = temp;
            result = i;
        }
    }
    cout << result << "\n";
    return 0;
}