#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> sum(n, 0);
    vector<int> array(n);
    for(int i = 0; i < n; i++) { 
        cin >> array[i];
        sum[i] = array[i];
    };
    int result = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(array[i] > array[j]) {
                sum[i] = max(sum[i], sum[j] + array[i]);
            }
        }
        result = max(result, sum[i]);
    }
    cout << result << "\n";
    return 0;
}