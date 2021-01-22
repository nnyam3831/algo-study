// no.12015 가장 긴 증가하는 부분 수열 2

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binary_search(int start, int end, vector<int>& list, int target) {
    // 작거나 같아지는 거
    while(start < end) {
        int mid = (start + end) / 2;
        if (target > list[mid]){
            start = mid + 1;
        }else{
            end = mid;
        }
    }
    return start;
}

int main(void) {
    int n;
    cin >> n;
    vector<int> array(n);
    vector<int> result;
    for(int i = 0; i < n; i++) cin >> array[i];
    for(int i = 0; i < n; i++) {
        if(result.size() == 0) {
            result.push_back(array[i]);
            continue;
        }

        if(result[result.size() - 1] < array[i]) {
            result.push_back(array[i]);
            continue;    
        }

        int index = binary_search(0, result.size()-1, result, array[i]);
        result[index] = array[i];
    }
    cout << result.size() << "\n";
    return 0;
}