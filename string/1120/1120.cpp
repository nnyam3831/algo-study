#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string a, b;
    cin >> a >> b;
    int len_a = a.length(), len_b = b.length();
    int max_value = 0;
    for(int i = 0; i <= len_b - len_a; i++) {
        // compare
        int matched = 0;
        for(int j = 0; j < len_a; j++) {
            if(a[j] == b[j+i]) matched++;
        }
        max_value = max(max_value, matched);
    }
    int result = len_a - max_value;
    cout << result << "\n";
    return 0;
}