// no.11053 가장 긴 증가하는 부분 수열 1

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> dp(n, 1);
    vector<int> array(n);
    int result = 0;
    for(int i = 0; i < n; i++) cin >> array[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(array[i] > array[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        result = max(result, dp[i]);
    }
    cout << result << "\n";
    return 0;
}

