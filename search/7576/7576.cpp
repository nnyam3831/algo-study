#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1000 + 1;
int map[MAX][MAX];
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
struct info {
    int y;
    int x;
    int day;
};

int main(void){
    int n, m;
    cin >> m >> n;
    queue<info> q;
    
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            if(map[i][j] == 1) q.push({i, j, 0});
        }
    }

    int result = 0;
    while(!q.empty()){
        int curY = q.front().y; 
        int curX = q.front().x;
        int day = q.front().day;
        q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int ny = curY + dy[dir];
            int nx = curX + dx[dir];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(map[ny][nx] == 0){
                q.push({ny, nx, day + 1});
                map[ny][nx] = 1;
            }
        }
        result = max(result, day);
    }

    // check

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (map[i][j] == 0) {
                result = -1;
                break;
            }
        }
    }

    cout << result << "\n";

    return 0;
}