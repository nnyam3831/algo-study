#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> lis;
    
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if(lis.size() == 0) {
            lis.push_back(num);
            continue;
        }

        if(lis[lis.size()-1] < num) {
            lis.push_back(num);
            continue;
        }    

        for(int j = 0; j < lis.size(); j++) {
            if(num <= lis[j]) {
                lis[j] = num;
                break;    
            }
        }
    }

    cout << lis.size() << "\n";
    return 0;
}