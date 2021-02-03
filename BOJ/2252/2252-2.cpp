#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<int> inDegree(n+1,0);
    vector<vector<int>> graph(n+1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        inDegree[b]++;
    }
    int cnt = 0;
    while(1) {
        cnt++;
        for(int i = 1; i <= n; i++) {
            if(!inDegree[i]) {
                cout << i << " ";
                inDegree[i] = -1;
                for(int v : graph[i]) inDegree[v]--;
            }
        }
        if(cnt >= n) break;
        
    }
    cout << "\n";
    return 0;
}