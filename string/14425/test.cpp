#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, m;
    map<string, bool> table;
    cin >> n >> m;
    for(int i = 0 ; i < n; i++) {
        string input;
        cin >> input;
        table.insert(make_pair(input, true));
    }
    int result = 0;
    for(int j = 0; j < m; j++) {
        string input;
        cin >> input;
        if (table.find(input) != table.end()) result++;
    }
    cout << result << "\n";
    return 0;
}