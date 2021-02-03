#include <bits/stdc++.h>
using namespace std;

vector<string> result;
char vowels[] = {'a', 'e', 'i', 'o', 'u'};
void dfs(int index, int size, string current, vector<char> &target) {
    if(current.length() == size) {
        int cnt = 0;
        for(char c : vowels) {
            cnt += count(current.begin(), current.end(), c);
        }
        if(cnt >= 1 && size-cnt >=2) result.push_back(current);
        return;
    }

    for(int i = index; i < target.size(); i++) {
        dfs(i + 1, size, current + target[i], target);        
    }
}

int main(void) {
    int l, c;
    cin >> l >> c;
    vector<char> input;
    for(int i = 0; i < c; i++) {
        char c;
        cin >> c;
        input.push_back(c);
    }
    sort(input.begin(), input.end());
    dfs(0, l, "", input);
    for(auto e : result) cout << e << "\n";
    return 0;
}