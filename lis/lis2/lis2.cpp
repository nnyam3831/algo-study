// no.11722 가장 긴 감소하는 부분 수열

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> array(n);
    vector<int> dp(n, 1);
    for(int i = 0; i < n; i++) cin >> array[i];
    int result = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(array[i] < array[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        result = max(result, dp[i]);
    }
    cout << result << "\n";
    return 0;
}