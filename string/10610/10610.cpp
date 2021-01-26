#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string input;
    cin >> input;
    bool isPossible = false;
    int sum = 0;
    for(int i = 0; i < input.length(); i++) {
        if (input[i] == '0') isPossible = true;
        sum += (input[i] - '0');
    }
    sort(input.begin(), input.end());
    reverse(input.begin(), input.end());
    if(isPossible && (sum % 3 == 0) && input[0] != '0') {
        cout << input << "\n";
    } else{
        cout << -1 << "\n";
    }
    return 0;
}