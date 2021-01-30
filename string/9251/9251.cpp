#include<bits/stdc++.h>
using namespace std;

int main(void) {
    string a, b;
    cin >> a >> b;
    int len_a = a.length(), len_b = b.length();
    vector<vector<int>> table(len_a + 1, vector<int>(len_b + 1, 0));
    for(int i = 1; i <= len_a; i++) {
        for(int j = 1; j <= len_b; j++) {
            if(a[i-1] == b[j-1]) {
                table[i][j] = table[i-1][j-1] + 1;
            } else {
                table[i][j] = max(table[i][j-1], table[i-1][j]);
            }
        }
    }
    int i = len_a, j = len_b, current = table[len_a][len_b];
    vector<char> result;
    while (table[i][j]) {
        if (table[i-1][j] == current) {
            i--;
        } else if (table[i][j-1] == current) {
            j--;
        } else {
            result.push_back(a[i-1]);
            i--; j--;
            current = table[i][j];
        }
    }
    reverse(result.begin(), result.end());
    cout << result.size() << "\n";
    for(auto e : result) cout << e;
    cout << "\n";
    return 0;
}