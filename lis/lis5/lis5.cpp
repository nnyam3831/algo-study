// no.14002 가장 긴 증가하는 부분 수열 4

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

int main(void) {
    int n;
    cin >> n;
    vector<pii> array(n);
    
    for(int i = 0; i < n; i++) {
        cin >> array[i].first;
        array[i].second = 0;
    }
    vector<int> result;
    for(int i = 0; i < n; i++) {
        if(result.size() == 0) {
                result.push_back(array[i].first);
                array[i].second = 1;
                continue;
        }

        if(result[result.size()-1] < array[i].first) {
                result.push_back(array[i].first);
                array[i].second = result.size();
                continue;
        }

        for(int j = 0; j < result.size(); j++) {
            if(array[i].first <= result[j]) {
                result[j] = array[i].first;
                array[i].second = j + 1;
                break;
            }
        }
    } 
    vector<int> temp;
    int index = result.size();
    for(int i = n-1; i >= 0; i--) {
        if(index == 0) break;
        if(index == array[i].second) {
            temp.push_back(array[i].first);
            index--;
        }
    }  
    reverse(temp.begin(), temp.end());
    cout << temp.size() << "\n";
    for(auto e : temp) cout << e << " ";
    return 0;
}