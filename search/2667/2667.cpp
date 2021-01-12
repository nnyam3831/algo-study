#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 25 + 1;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

string map[MAX];

int dfs(int y, int x, int size){
    map[y][x] = '0';
    int ret = 1;
    for(int dir = 0; dir < 4; dir++){
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny < 0 || ny >= size || nx < 0 || nx >= size) continue;
        
        if(map[ny][nx] == '1'){
            ret += dfs(ny, nx, size);
        }
    }

    return ret;    
}

int main(void) {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> map[i];
    }    
    
    vector<int> result;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(map[i][j] == '1') {
                result.push_back(dfs(i, j, n));
            }
        }
    }
    
    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for(auto elem: result){
        cout << elem << "\n";
    }

    return 0;
}