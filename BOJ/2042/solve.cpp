#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll init(vector<ll> &arr, vector<ll> &tree, int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];

    int mid = (start + end) >> 1;
    return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);
}

void update(vector<ll> &tree, int node, int start, int end, int index, ll diff) {
    if (!(start <= index && index <= end)) {
        return;
    }

    tree[node] += diff;
    if (start != end) {
        int mid = (start + end) >> 1;
        update(tree, node * 2, start, mid, index, diff);
        update(tree, node * 2 + 1, mid + 1, end, index, diff);
    }
}

ll sum(vector<ll> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }

    if (left <= start && end <= right) {
        return tree[node];
    }

    int mid = (start + end) >> 1;
    return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right);
    
}

int main(void) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> arr(n);
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<ll> tree(tree_size, 0);
    init(arr, tree, 1, 0, n-1);
    for(int i = 0; i < m+k; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            ll diff = c - arr[b-1];
            arr[b-1] = c;
            update(tree, 1, 0, n-1, b-1, diff);
        } else {
            cout << sum(tree, 1, 0, n-1, b-1, c-1) << "\n";
        }
    }
    return 0;
}