#include <bits/stdc++.h>
using namespace std;

struct Compare {
    bool operator() (const string &a, const string &b) const {
        if (a.length() == b.length()) return a < b;
        
        return a.length() < b.length();
    }
};

int main(void) {
    int n;
    cin >> n;
    set<string, Compare> input;
    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        input.insert(temp);
    }
    for(auto word : input) cout << word << "\n";

    return 0;
}