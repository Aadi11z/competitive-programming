// Overkill for this particular 'Easy' but still interesting to see implementation
#include<bits/stdc++.h>
using namespace std;

struct AhoNode {
    int next[26] ={0};
    int fail = 0;
    vector<int> pattern_ids;
};

int numOfStrings(vector<string>& patterns, string word) {
    vector<AhoNode> trie(1);
    int n = patterns.size();

    for (int i = 0; i < n; i++) {
        int node = 0;

        for (char c : patterns[i]) {
            int idx = c - 'a';
            if (trie[node].next[idx] == 0) {
                trie[node].next[idx] = trie.size();
                trie.push_back(AhoNode());
            }
            node = trie[node].next[idx];
        }

        trie[node].pattern_ids.push_back(i);
    }

    queue<int> q;

    for (int i = 0; i < 26; i++) {
        if (trie[0].next[i] != 0) {
            q.push(trie[0].next[i]);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < 26; i++) {
            int v = trie[u].next[i];

            if (v != 0) {
                trie[v].fail = trie[trie[u].fail].next[i];

                for (int id : trie[trie[v].fail].pattern_ids) {
                    trie[v].pattern_ids.push_back(id);
                }

                q.push(v);
            }
            else {
                trie[u].next[i] = trie[trie[u].fail].next[i];
            }
        }
    }

    vector<bool> found(patterns.size(), false);
    int node = 0;

    for (char c : word) {
        int idx = c - 'a';
        node = trie[node].next[idx];

        for (int id : trie[node].pattern_ids) {
            found[id] = true;
        }
    }

    int ans = 0;

    for (bool x : found) {
        if (x) ans++;
    }

    return ans;
}

int main() {
    vector<string> patterns = {"he", "she", "hers"};
    string word = "ushers";

    int res = numOfStrings(patterns, word);
    cout << res << endl;
    
    return 0;
}