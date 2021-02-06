#include <bits/stdc++.h>
using namespace std;

int getMaxArea(int start, int end, vector<int>& height) {
    if (start > end) return 0;
    if (start == end) return height[start] * 1;

    int mid = (start + end) / 2;
    int ret = max(getMaxArea(start, mid - 1, height), getMaxArea(mid+1, end, height));
    int l = mid, r = mid, h = height[mid];
    ret = max(ret, h * 1);
    while (l > start || r < end) {
        if (l != start && r != end) {
            if (height[l-1] < height[r+1]) {
                h = min(h, height[++r]);
            } else {
                h = min(h, height[--l]);
            }
        } else {
            if (l == start && r < end) {
                h = min(h, height[++r]);
            }
            if (l > start && r == end) {
                h = min(h, height[--l]);
            }    
        }
        ret = max(ret, h * (r - l + 1));
    }
    return ret;
}

int main(void) {
    int n;
    cin >> n;
    vector<int> height(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> height[i];
    }
    cout << getMaxArea(0, n-1, height) << "\n";
    return 0;
}