#include <iostream>
#include <vector>

using namespace std;

class WordDictionary {
  private:
    class TrieNode {
      public:
        vector<TrieNode *> children;
        bool isWord;

        TrieNode() : children(26, nullptr), isWord(false) {}
        ~TrieNode() {
            for (auto child : children) {
                delete child;
            }
        }
    };

    TrieNode *root;

    bool searchInNode(const string &word, int index, TrieNode *node) {
        if (index == word.length())
            return node->isWord;

        char ch = word[index];
        if (ch != '.') {
            TrieNode *child = node->children[ch - 'a'];
            if (child && searchInNode(word, index + 1, child))
                return true;
        } else {
            for (auto child : node->children) {
                if (child && searchInNode(word, index + 1, child))
                    return true;
            }
        }
        return false;
    }

  public:
    WordDictionary() { root = new TrieNode(); }

    ~WordDictionary() { delete root; }

    void addWord(string word) {
        TrieNode *current = root;
        for (char ch : word) {
            if (!current->children[ch - 'a']) {
                current->children[ch - 'a'] = new TrieNode();
            }
            current = current->children[ch - 'a'];
        }
        current->isWord = true;
    }

    bool search(string word) { return searchInNode(word, 0, root); }
};