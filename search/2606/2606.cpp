#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100 + 1;
vector<int> computers[MAX];
int visited[MAX];

int dfs(int index) {
    visited[index] = 1;
    int ret = 1;
    for(int i = 0; i < computers[index].size(); i++) {
        int next = computers[index][i];
        if(!visited[next]) {
            ret += dfs(next); 
        }
    }

    return ret;
}

int main(void) {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        computers[a].push_back(b);
        computers[b].push_back(a);
    }

    cout << dfs(1) - 1 << "\n";
    
    return 0;
}