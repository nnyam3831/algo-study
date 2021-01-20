#include <iostream>
#include <vector>
#include <map>
#include <memory.h>

using namespace std;

class TrieNode {
public:
    TrieNode() {
        isWord = false;
        memset(next, 0, sizeof(next));
    }
    bool isWord;
    TrieNode *next[26];    
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {
        clear(root);
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if(!node->next[index]) {
                node->next[index] = new TrieNode();
            }
            node = node->next[index];
        }
        node->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if(!node->next[index]) {
                return false;
            }
            node = node->next[index];
        }
        return node->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if(!node->next[index]) return false;
            
            node = node->next[index];
        }
        return true;
    }
private:
    TrieNode* root;
    int numOfNext = 26;
    void clear(TrieNode* root) {
        for(int i = 0; i < numOfNext; i++) {
            if(root->next[i]) {
                clear(root->next[i]);
            }
        }
        delete root;
    }
};

int main(void) {
    
    Trie* trie = new Trie();
    trie->insert("apple");
    cout << trie->search("apple");   // returns true
    cout << trie->search("app");     // returns false
    cout << trie->startsWith("app"); // returns true
    trie->insert("app");   
    cout << trie->search("app");     // returns true
    return 0;
}