#include <iostream>
#include <vector>

using namespace std;

class Trie {
  private:
    vector<Trie *> letter;
    bool isWord;

  public:
    Trie() : letter(26, nullptr), isWord(false) {}

    ~Trie() {
        for (Trie *child : letter) {
            delete child;
        }
    }

    void insert(string word) {
        Trie *current = this;
        for (char ch : word) {
            int index = ch - 'a';
            if (!current->letter[index]) {
                current->letter[index] = new Trie();
            }
            current = current->letter[index];
        }
        current->isWord = true;
    }

    bool search(string word) {
        Trie *current = this;
        for (char ch : word) {
            current = current->letter[ch - 'a'];
            if (!current)
                return false;
        }
        return current->isWord;
    }

    bool startsWith(string prefix) {
        Trie *current = this;
        for (char ch : prefix) {
            current = current->letter[ch - 'a'];
            if (!current)
                return false;
        }
        return true;
    }
};