#include <iostream>

using namespace std;
const int MAX = 50 + 1;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

int map[MAX][MAX];
int n, m, k;

void dfs(int y, int x){
    map[y][x] = 0;
    for(int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny >= n || ny < 0 || nx >= m || nx < 0) continue;
        if(map[ny][nx] == 1) dfs(ny, nx);
    }
}

int main(void) {
    int t;
    cin >> t;
    for(int test = 0; test < t; test++){
        cin >> m >> n >> k;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                map[i][j] = 0;
            }
        }
        for(int i = 0; i < k; i++){
            int x, y;
            cin >> x >> y;
            map[y][x] = 1;
        }

        int result = 0;
        for(int y = 0; y < n; y++){
            for(int x = 0; x < m; x++){
                if(map[y][x] == 1){
                    result++;
                    dfs(y, x);
                }
            }
        }

        cout << result << "\n";
    }

    return 0;
}
