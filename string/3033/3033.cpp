#include <bits/stdc++.h>
using namespace std;

const int MOD = 10000000;

inline int mod(long long n) {
    if(n >= 0) return n % MOD;
    return ((-n/MOD+1)*MOD + n) % MOD;
}

bool rabinKarp(int length, string text) {
    int h = 0, power = 1;
    vector<int> pos[MOD];
    for (int i = 0; i <= text.length()-length; i++) {
        if (i == 0) {
            for (int j = 0; j < length; j++) {
                h = mod(h + 1LL*text[length-j-1] * power);
                if (j < length - 1) power = mod(power * 2);
            }
        } else {
            h = mod(2 * (h - 1LL*text[i-1] * power) + text[i+length-1]);
        }
        if (!pos[h].empty()) {
            for (int p : pos[h]) {
                bool isMatched = true;
                for(int j = 0; j < length; j++) {
                    if (text[i+j] != text[p+j]) {
                        isMatched = false;
                        break;
                    }
                }
                if (isMatched) return true;
            }
        }
        pos[h].push_back(i);
    }
    return false;    
}

int main(void) {
    int l;
    string text;
    cin >> l >> text;
    int start = 0, end = l;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (rabinKarp(mid, text)) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }     
    }
    if (!start) cout << 0 << "\n";
    else cout << start - 1<< "\n";
    return 0;
}