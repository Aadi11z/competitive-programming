#include <iostream>
#include <stdexcept>
#include <string>

struct TrieNode {
  TrieNode *children[26];
  bool leaf = false;

  TrieNode(const TrieNode &) = delete;
  TrieNode &operator=(const TrieNode &) = delete;

  TrieNode() {
    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
    }
  }

  ~TrieNode() {
    for (int i = 0; i < 26; i++) {
      delete children[i];
    }
  }
};

class Trie {
private:
  TrieNode *root = new TrieNode();

  static int character_index(char c) {
    if (c >= 'a' && c <= 'z')
      return c - 'a';
    if (c >= 'A' && c <= 'Z')
      return c - 'A';
    return -1;
  }

public:
  Trie() = default;

  Trie(const Trie &) = delete;
  Trie &operator=(const Trie &) = delete;

  ~Trie() { delete root; }

  void insert(const std::string &word) {
    for (char letter : word) {
      int index = character_index(letter);
      if (index == -1)
        throw std::invalid_argument("Trie accepts ASCII letters only");
    }
    TrieNode *current = root;
    for (char letter : word) {
      int index = character_index(letter);
      if (current->children[index] == nullptr) {
        current->children[index] = new TrieNode();
      }
      current = current->children[index];
    }
    current->leaf = true;
  }

  bool search(const std::string &word) {
    TrieNode *current = root;
    for (char letter : word) {
      int index = character_index(letter);
      if (index == -1)
        return false;
      if (current->children[index] == nullptr)
        return false;
      current = current->children[index];
    }
    return current->leaf;
  }

  bool starts_with(const std::string &prefix) {
    TrieNode *current = root;

    for (char letter : prefix) {
      int index = character_index(letter);
      if (index == -1)
        throw std::invalid_argument("Trie accepts ASCII letters only");

      if (current->children[index] == nullptr) {
        return false;
      }
      current = current->children[index];
    }
    return true;
  }
};

int main() {
  Trie trie;

  trie.insert("Cart");

  std::cout << trie.search("cart") << '\n';
  std::cout << trie.search("CART") << '\n';
  std::cout << trie.starts_with("Ca") << '\n';
  std::cout << trie.search("cart!") << '\n';

  return 0;
}
