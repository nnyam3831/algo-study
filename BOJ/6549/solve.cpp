#include <bits/stdc++.h>
using namespace std;

int init(vector<int> &h, vector<int> &tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = start;
        return h[start];
    }
    
    int mid = (start + end) >> 1;
    int left = init(h, tree, node * 2, start, mid);
    int right = init(h, tree, node * 2 + 1, mid + 1, end);
    if (left < right) {
        tree[node] = tree[node * 2];
    }else{
        tree[node] = tree[node * 2 + 1];
    }
    return h[tree[node]];
}

int getMinHeightIndex(vector<int> &h, vector<int> &tree, int node, int start, int end, int left, int right) {
    if (end < left || right < start) {
        return -1;
    }

    if (left <= start && end <= right) {
        return tree[node];
    }
    
    int mid = (start + end) >> 1;
    int l = getMinHeightIndex(h, tree, node * 2, start, mid, left, right);
    int r = getMinHeightIndex(h, tree, node * 2 + 1, mid + 1, end, left, right);
    if (l == -1) return r; 
    if (r == -1) return l;
    
    if (h[l] < h[r]) return l;
    else return r;
}

long long getMaxArea(vector<int>& h, vector<int>& tree, int start, int end) {
    int index = getMinHeightIndex(h, tree, 1, 0, h.size()-1, start, end);
    long long area = (long long)(end - start + 1) * (long long)h[index];
    if (start < index) {
        long long left_area = getMaxArea(h, tree, start, index - 1);
        area = max(area, left_area);
    }
    if (index < end) {
        long long right_area = getMaxArea(h, tree, index + 1, end);
        area = max(area, right_area);
    }
    return area;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(1) {
        int n;
        cin >> n;
        if(n == 0) break;
        vector<int> h(n);
        for(int i = 0; i < n; i++) cin >> h[i];
        int depth = (int)ceil(log2(n));
        vector<int> tree(1 << (depth+1));
        init(h, tree, 1, 0, n-1);
        
        cout << getMaxArea(h, tree, 0, n-1) << "\n";
    }
    return 0;
}