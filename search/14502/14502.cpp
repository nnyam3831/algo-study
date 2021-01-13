#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 8 + 1;
const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int map[MAX][MAX];
int n, m;
int result;
vector<pair<int,int>> targets;

int simulate() {
    vector<vector<int> > test(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            test[i][j] = map[i][j];
        }
    }
    
    queue<pair<int,int>> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(test[i][j] == 2) q.push({i, j});
        }
    }

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(test[ny][nx] == 0) {
                test[ny][nx] = 2;
                q.push({ny, nx});
            }
        }
    }
    
    int ret = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(test[i][j] == 0) ret++;
        }
    }

    return ret;
}

void dfs(int index, int cnt) {
    int y = targets[index].first;
    int x = targets[index].second;
    map[y][x] = 1;
    cnt++;
    if(cnt == 3) {
        result = max(result, simulate());
        map[y][x] = 0;
        return;
    }
    for(int i = index + 1; i < targets.size(); i++) {
        dfs(i, cnt);
    }
    map[y][x] = 0;
    cnt--;
}

int main(void) {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            if(map[i][j] == 0) targets.push_back({i, j});
        }
    }

    for(int i = 0; i < targets.size(); i++) {
        dfs(i, 0);
    }    
    
    cout << result << "\n";
    
    return 0;
}