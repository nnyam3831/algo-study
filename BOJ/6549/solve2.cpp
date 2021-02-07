// using stack
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (true) {
        int n;
        cin >> n;
        if (!n) break;
        vector<int> h(n);
        for (int i = 0; i < n; i++) cin >> h[i];

        ll answer = 0;
        stack<int> s;
        for(int i = 0; i < n; i++) {
            while(!s.empty() && h[s.top()] > h[i]) {
                int height = h[s.top()];
                s.pop();
                int width = i;
                if (!s.empty()) {
                    width = i - s.top() - 1;
                }
                answer = max(answer, 1LL * height * width);
            }
            s.push(i);
        }
        
        while(!s.empty()) {
            int height = h[s.top()];
            s.pop();
            int width = n;
            if(!s.empty()) {
                width = n - s.top() - 1;
            }
            answer = max(answer, 1LL * height * width);
        }
        cout << answer << "\n";
    }
    return 0;
}