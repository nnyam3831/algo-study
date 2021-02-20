#include <bits/stdc++.h>
using namespace std;

struct island {
    int value;
    vector<int> next;
};

const int MAX = 123456 + 1;
island tree[MAX];

long long dfs(int node) {
    long long ret = tree[node].value;
    for(int v : tree[node].next) {
        ret += dfs(v);
    }
    return ret > 0 ? ret : 0;
}

int main(void) {
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        tree[i].value = (c == 'W' ? -a : a);
        tree[b].next.push_back(i);
    }
    tree[1].value = 0;
    cout << dfs(1) << "\n";
    return 0;
}