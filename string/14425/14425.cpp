#include <bits/stdc++.h>
using namespace std;

const int NUMBER_OF_ALPHABETS = 26;

class TrieNode {
public:
    bool isWord;
    TrieNode *children[NUMBER_OF_ALPHABETS];
    TrieNode() {
        isWord = false;
        for(int i = 0; i < NUMBER_OF_ALPHABETS; i++) children[i] = 0;
    }
};

class Trie {
private:
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    void Insert(string word) {
        TrieNode *node = root;
        for(char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isWord = true;
    }
    bool Find(string word) {
        TrieNode *node = root;
        for(char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }
        return node->isWord;
    }
};

int main(void) {
    int n, m;
    cin >> n >> m;
    Trie t = Trie();
    for(int i = 0; i < n; i++) {
        string input;
        cin >> input;
        t.Insert(input);
    }
    int result = 0;
    for(int i = 0; i < m; i++) {
        string input;
        cin >> input;
        if (t.Find(input)) result++;
    }
    cout << result << "\n";
    return 0;
}