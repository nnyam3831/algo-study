#include <bits/stdc++.h>
using namespace std;

const int MOD = 10000000;

int mod(long long n) {
    if(n >= 0) return n % MOD;
    return ((-n/MOD+1)*MOD + n) % MOD;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string t,p;
    getline(cin, t);
    getline(cin, p);
    int n = t.length();
    int m = p.length();
    
    vector<int> result;
    int g = 0, h = 0, power = 1;
    for(int i = 0; i <= n-m; i++) {
        // 처음 해쉬값 계산
        if(i == 0) {
            for(int j = 0; j < m; j++) {
                g = mod(g + 1LL*p[m-1-j]*power);
                h = mod(h + 1LL*t[m-1-j]*power);
                if (j < m-1) power = mod(power*11);
            }
        } else {
            h = mod(2*(h - 1LL*t[i-1]*power) + t[i+m-1]);
        }

        // if(g == h) {
        //     bool isSame = true;
        //     for(int j = 0; j < m; j++) {
        //         if (p[j] != t[i+j]) {
        //             isSame = false;
        //             break;
        //         }
        //     }
        //     if (isSame) result.push_back(i+1);
        // }
        if(g == h) {
            result.push_back(i+1);
        }
    }

    cout << result.size() << "\n";
    for(int i : result) cout << i << " ";
    return 0;
}