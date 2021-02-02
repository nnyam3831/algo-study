// O(NlogN)

#include <bits/stdc++.h>
using namespace std;

bool isPossible(int dist, vector<int>& pos, int c) {
    int cnt = 1, prev = pos[0];
    for(int i = 1; i < pos.size(); i++) {
        // 가능
        if (pos[i] - prev >= dist) {
            cnt += 1;
            prev = pos[i];
        }
    }
    return cnt >= c;
}

int main(void) {
    int n, c;
    cin >> n >> c;
    vector<int> pos(n);
    for(int i = 0; i < n; i++) cin >> pos[i];
    sort(pos.begin(), pos.end());
    int start = 0, end = pos[pos.size()-1];
    while(start <= end) {
        int mid = (start + end) / 2;
        if (isPossible(mid, pos, c)) {
            start = mid + 1;
        } else{
            end = mid - 1;
        }
    }
    cout << start - 1 << "\n";
    return 0;
}