// no.14003 가장 긴 증가하는 부분 수열 5

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findIndex(vector<long long>& list, long long target) {
    int start = 0, end = list.size() - 1;
    while (start < end) {
        int mid = (start + end) / 2;
        if (target > list[mid]) {
            start = mid + 1;
        }else{
            end = mid;
        }
    }
    return start;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<pair<long long, int>> array(n);
    vector<long long> temp;
    for(int i = 0; i < n; i++) {
        cin >> array[i].first;
        array[i].second = 0;
    }
    for(int i = 0; i < n; i++) {
        if (temp.size() == 0) {
            temp.push_back(array[i].first);
            continue;
        }

        if (temp[temp.size() - 1] < array[i].first) {
            temp.push_back(array[i].first);
            array[i].second = temp.size() - 1;
            continue;
        }

        int index = findIndex(temp, array[i].first);
        temp[index] = array[i].first;
        array[i].second = index;
    }
    vector<long long> result;
    int index = temp.size() - 1;
    for(int i = n - 1; i >= 0; i--) {
        if (index == -1) break;
        if (index == array[i].second) {
            result.push_back(array[i].first);
            index--;
        }
    }
    reverse(result.begin(), result.end());
    cout << result.size() << "\n";
    for(auto e : result) cout << e << " ";
    cout << "\n";
    return 0;
}