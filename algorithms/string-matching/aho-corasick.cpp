#include <bits/stdc++.h>
using namespace std;

class AhoCorasick {
private:
    struct Node {
        unordered_map<char, int> next;
        int fail = 0;
        vector<int> output;
    };
    vector<Node> trie;
    vector<string> patterns;

public:
    AhoCorasick()
    {
        trie.push_back(Node());
    }

    void insert(const string& word)
    {
        int node = 0;

        for (char c : word) {
            if (!trie[node].next.count(c)) {
                trie[node].next[c] = trie.size();
                trie.push_back(Node());
            }
            node = trie[node].next[c];
        }

        trie[node].output.push_back(patterns.size());
        patterns.push_back(word);
    }

    void buildFailureLinks()
    {
        queue<int> q;

        for (auto& [c, child] : trie[0].next) {
            trie[child].fail = 0;
            q.push(child);
        }

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (auto& [c, child] : trie[current].next) {
                int fallback = trie[current].fail;

                while (fallback != 0 && !trie[fallback].next.count(c)) {
                    fallback = trie[fallback].fail;
                }

                if (trie[fallback].next.count(c)) {
                    trie[child].fail = trie[fallback].next[c];
                } else {
                    trie[child].fail = 0;
                }

                for (int patternIndex : trie[trie[child].fail].output) {
                    trie[child].output.push_back(patternIndex);
                }

                q.push(child);
            }
        }
    }
    vector<pair<int, string>> search(const string& text)
    {
        vector<pair<int, string>> matches;
        int node = 0;
        int n = text.size();

        for (int i = 0; i < n; i++) {
            char c = text[i];

            while (node != 0 && !trie[node].next.count(c)) {
                node = trie[node].fail;
            }

            if (trie[node].next.count(c)) {
                node = trie[node].next[c];
            }

            for (int patternIndex : trie[node].output) {
                string matched = patterns[patternIndex];
                int startIndex = i - matched.size() + 1;
                matches.push_back({ startIndex, matched });
            }
        }
        return matches;
    }
};

int main()
{
    AhoCorasick ac;

    ac.insert("he");
    ac.insert("she");
    ac.insert("his");
    ac.insert("hers");

    ac.buildFailureLinks();

    string text = "ushers";

    auto matches = ac.search(text);

    for (auto& [index, word] : matches) {
        cout << "Word: " << word << " at " << index << endl;
    }

    return 0;
}