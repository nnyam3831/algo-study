#include <iostream>

using namespace std;

const int MAX = 50 + 1;
const int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};
const int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};

int map[MAX][MAX];

void dfs(int y, int x) {
    map[y][x] = 0;
    for(int dir = 0; dir < 8; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(map[ny][nx] == 1) {
            dfs(ny, nx);
        }
    }
}

int main(void) {

    while(1) {
        int w, h;
        cin >> w >> h;
        if(w == 0 && h == 0) break;

        for(int y = 0; y < h; y++) {
            for(int x = 0; x < w; x++) {
                map[y][x] = 0;
            }
        }

        for(int y = 0; y < h; y++) {
            for(int x = 0; x < w; x++) {
                cin >> map[y][x];
            }
        }
        
        int result = 0;
        for(int y = 0; y < h; y++) {
            for(int x = 0; x < w; x++) {
                if (map[y][x] == 1) {
                    result++;
                    dfs(y, x);
                }
            }
        }

        cout << result << "\n";
    }

    return 0;
}