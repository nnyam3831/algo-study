// 최단거리라서 BFS가 더 쉬운데 DFS로 가지잘치면 통과되긴함

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
const int INF = 987654321;
int n, m;
vector<string> map;
int dp[101][101];

int dfs(int y, int x, vector<vector<int>> &visited, int cnt) {
    if(y == n-1 && x == m-1) {
        return cnt + 1;
    }
    visited[y][x] = 1;

    int ret = INF;
    for(int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if(visited[ny][nx] || map[ny][nx] == '0') continue;
        if(dp[ny][nx] <= cnt + 1) continue;
        dp[ny][nx] = cnt + 1;
        ret = min(ret, dfs(ny, nx, visited, cnt + 1));
    }
    visited[y][x] = 0; 
    return ret;
}

int main(void) {
    cin >> n >> m;
    vector<vector<int>> visited(n,vector<int>(m,0));

    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m; j++){
            dp[i][j] = INF;
        }
    }
    for(int i = 0; i < n; i++) {
        string row;
        cin >> row;
        map.push_back(row);
    }    
    cout <<  dfs(0, 0, visited, 0) << "\n";
    
    return 0;
}