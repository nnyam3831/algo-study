#include <bits/stdc++.h>
using namespace std;

const int MAX = 50000 + 1;
vector<int> node[MAX];

int main(void) {
    int n, m;
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        node[min(a,b)].push_back(max(a,b));
    }

    return 0;
}