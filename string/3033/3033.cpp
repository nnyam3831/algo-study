#include <bits/stdc++.h>
using namespace std;

const int MOD = 100003;

inline int mod(long long n) {
    if(n >= 0) return n % MOD;
    return ((-n/MOD+1)*MOD + n) % MOD;
}

// bool rabinKarp(int length, string text) {
//     int h = 0, power = 1;
//     vector<int> table[MOD];
//     bool found = false;
//     for(int i = 0; i <= text.length() - length; i++) {
//         string target = text.substr(i, length);
//         if (i == 0) {
//             for(int j = 0; j < length; j++) {
//                 h = mod(h + 1LL*text[length-j-1] * power);
//                 if(j < length - 1) power = mod(2 * power);
//             }
//         } else h = mod(2 * (h - 1LL*text[i-1] * power) + text[i+length-1]);

//         // cout << target << " " << i << " " << length << " " << h << "\n";
//         if (!table[h].empty()) {
//             for(int index : table[h]) {
//                 bool isMatched = true;
//                 for(int j = 0; j < length; j++) {
//                     if(text[i+j] != text[index+j]) {
//                         isMatched = false;
//                         break;
//                     }
//                 }
//                 if(isMatched) {
//                     found = true;
//                     break;
//                 }
//             }
//         }
//         if(found) break;
//         table[h].push_back(i);
//     }
//     return found;
// }

int main(void) {
    int l;
    string text;
    cin >> l >> text;
    int length = text.length();
    int start = 0, end = length-1;
    while (start + 1 < end) {
        int mid = (start + end) / 2;
        // check if this length is valid
        // if (rabinKarp(mid, text)) {
        //     start = mid;
        // } else {
        //     end = mid;
        // }
        int h = 0, power = 1;
        vector<int> table[MOD];
        bool found = false;
        for(int i = 0; i <= l - mid; i++) {
            if (i == 0) {
                for(int j = 0; j < mid; j++) {
                    h = mod(h + 1LL*text[mid-j-1] * power);
                    if(j < mid - 1) power = mod(2 * power);
                }
            } else h = mod(2 * (h - 1LL*text[i-1] * power) + text[i+mid-1]);

            // cout << target << " " << i << " " << mid << " " << h << "\n";
            if (!table[h].empty()) {
                for(int index : table[h]) {
                    bool isMatched = true;
                    for(int j = 0; j < mid; j++) {
                        if(text[i+j] != text[index+j]) {
                            isMatched = false;
                            break;
                        }
                    }
                    if(isMatched) {
                        found = true;
                        break;
                    }
                }
            }
            if(found) break;
            table[h].push_back(i);
        }
        (found ? start : end) = mid;
    }
    cout << start << "\n";
    return 0;
}